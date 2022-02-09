#include "EspMQTTClient.h"
#include "BLEDevice.h"
#include <sstream>

// Watchdog timer
#include <esp_task_wdt.h>
#define WDT_TIMEOUT 5

// EEPROM
#include <EEPROM.h>
//#define EEPROM	// if uncommented EEPROM STORAGE IS USED
#define EEPROM_SIZE 4 // 1 float 

// libs for motor controll
#include <motor.h>
#include <ESP32Encoder.h>

bool shutter_move = false;

int shutter_state = 0;

int64_t shutter_real_pos = 0;
int64_t shutter_up_pos = 0;
int64_t shutter_down_pos = 20000;

float mqtt_pos = 0;
float real_pos = shutter_real_pos / (shutter_down_pos - shutter_up_pos);

ESP32Encoder motorEncoder;

// keyboard
#define KEYBOARD_BUT1 14
#define KEYBOARD_BUT2 27
#define KEYBOARD_BUT3 26 //reserved

bool keyboard_overvrite = false;

// MQTT
EspMQTTClient client(
	"WIFI_SSID",	 	// SSID
	"WIFI_PASSWORD", 	// PASSWORD
	"192.168.137.89",	// MQTT Broker server ip
	"ESP32",		 	// Can be omitted if not needed
	"password",		 	// Can be omitted if not needed
	"ESP32",		 	// Client name that uniquely identify your device
	1883			 	// The MQTT port
);

// The remote service we wish to connect to.
static BLEUUID serviceUUID("0000ffe0-0000-1000-8000-00805f9b34fb");
// The characteristic of the remote service we are interested in.
static BLEUUID charUUID("0000ffe4-0000-1000-8000-00805f9b34fb");
//static BLEUUID char2UUID("0000ffe9-0000-1000-8000-00805f9b34fb");
static boolean doConnect = false;
static boolean connected = false;
static boolean doScan = false;
static BLERemoteCharacteristic *pRemoteCharacteristic;
static BLEAdvertisedDevice *myDevice;
static void notifyCallback(
	BLERemoteCharacteristic *pBLERemoteCharacteristic,
	uint8_t *pData, size_t length, bool isNotify)
{
	/*
Serial.print("Notify callback for characteristic ");
Serial.print(pBLERemoteCharacteristic->getUUID().toString().c_str());
Serial.print(" of data length ");
Serial.println(length);
Serial.print("data: ");
Serial.println((char *)pData);
*/
	String str;
	if (length >= 16 && client.isConnected())
	{
		float temp = *(float *)pData;
		float hum = *(float *)(pData + 4);
		float pres = *(float *)(pData + 8);
		float lx = *(float *)(pData + 12);
		str = "Temperature: " + String(temp) + " Humidity: " + String(hum) +
			  " Presurre: " + String(pres) + " Illuminance: " + String(lx);
		Serial.println(str);
		client.publish("Temperature", String(temp));
		client.publish("Humidity", String(hum));
		client.publish("Pressure", String(pres));
		client.publish("Illuminance", String(lx));
	}
}

class MyClientCallback : public BLEClientCallbacks
{
	void onConnect(BLEClient *pclient)
	{

	}
	void onDisconnect(BLEClient *pclient)
	{
		connected = false;
		Serial.println("onDisconnect");
		doScan = true;
	}
};

bool connectToServer()
{
	Serial.print("Forming a connection to ");
	Serial.println(myDevice->getAddress().toString().c_str());
	BLEClient *pClient = BLEDevice::createClient();
	Serial.println(" - Created client");
	pClient->setClientCallbacks(new MyClientCallback());
	// Connect to the remove BLE Server.
	pClient->connect(myDevice); // if you pass BLEAdvertisedDevice instead of address, it will be recognized type of peer device address (public or private)
	Serial.println(" - Connected to server");
	// Obtain a reference to the service we are after in the remote BLE server.
	BLERemoteService *pRemoteService = pClient->getService(serviceUUID);
	if (pRemoteService == nullptr)
	{
		Serial.print("Failed to find our service UUID: ");
		Serial.println(serviceUUID.toString().c_str());
		pClient->disconnect();
		return false;
	}
	Serial.println(" - Found our service");
	// Obtain a reference to the characteristic in the service of the remote BLE server.
	pRemoteCharacteristic = pRemoteService->getCharacteristic(charUUID);
	if (pRemoteCharacteristic == nullptr)
	{
		Serial.print("Failed to find our characteristic UUID: ");
		Serial.println(charUUID.toString().c_str());
		pClient->disconnect();
		return false;
	}
	Serial.println(" - Found our characteristic");
	// Read the value of the characteristic.
	if (pRemoteCharacteristic->canRead())
	{
		std::string value = pRemoteCharacteristic->readValue();
		Serial.print("The characteristic value was: ");
		Serial.println(value.c_str());
	}
	if (pRemoteCharacteristic->canNotify())
		pRemoteCharacteristic->registerForNotify(notifyCallback);
	connected = true;
	return true;
}

/**
 * Scan for BLE servers and find the first one that advertises the service we are looking for.
 */
class MyAdvertisedDeviceCallbacks : public BLEAdvertisedDeviceCallbacks
{
	/**
 * Called for each advertising BLE server.
 */
	void onResult(BLEAdvertisedDevice advertisedDevice)
	{
		// We have found a device, let us now see if it contains the service we are looking for.
		if (advertisedDevice.getAddress().toString() == "62:00:a1:1e:88:21")
		{
			BLEDevice::getScan()->stop();
			Serial.print("BLE Advertised Device found: ");
			Serial.println(advertisedDevice.toString().c_str());
			myDevice = new BLEAdvertisedDevice(advertisedDevice);
			doConnect = true;
			doScan = false;
		} // Found our server
	}	  // onResult

	
};		  // MyAdvertisedDeviceCallbacks

void setup()
{
	Serial.begin(115200);

	// motor controll
	motorEncoder.attachFullQuad(25, 33);
	motorEncoder.clearCount();

#ifdef EEPROM
	EEPROM.begin(EEPROM_SIZE);
	real_pos = EEPROM.readFloat(0);

	if (real_pos < 0.0f || real_pos > 1.0f ) { // check value
		real_pos = 0.0f;
	}
#endif 

	A_motor_init();

	

	shutter_move = false;
	A_soft_stop();

	// keyboard controll
	pinMode(KEYBOARD_BUT1, INPUT_PULLUP);
	pinMode(KEYBOARD_BUT2, INPUT_PULLUP);

	// Optionnal functionnalities of EspMQTTClient :
	client.enableDebuggingMessages();										   // Enable debugging messages sent to serial output
	client.enableHTTPWebUpdater();											   // Enable the web updater. User and password default to values of MQTTUsername and MQTTPassword. These can be overrited with enableHTTPWebUpdater("user", "password").
	client.enableLastWillMessage("TestClient/lastwill", "I am going offline"); // You can activate the retain flag by setting the third parameter to true


	BLEDevice::init("");
	BLEScan *pBLEScan = BLEDevice::getScan();
	pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
	pBLEScan->setInterval(1349);
	pBLEScan->setWindow(449);
	pBLEScan->setActiveScan(false);
	doScan = true;
	//pBLEScan->start(5, false);

	// Watchdog timer setup
	esp_task_wdt_init(WDT_TIMEOUT, true);
	esp_task_wdt_add(NULL);
}

// This function is called once everything is connected (Wifi and MQTT)
// WARNING : YOU MUST IMPLEMENT IT IF YOU USE EspMQTTClient
void onConnectionEstablished()
{
	client.isConnected();
	client.subscribe("Shutter_com", [](const String &payload)
					{
						Serial.println("Shutter command:" + String(shutter_state));
						if (payload == "STOP")
						{
							Serial.println("Stoping");
							shutter_state = (int)((shutter_real_pos / ((float)(shutter_down_pos - shutter_up_pos))) * 100);
							mqtt_pos = (float)shutter_state / 100;
						}
						else
						{
							shutter_state = payload.toInt();
							mqtt_pos = (float)shutter_state / 100;
						}
					});
#ifdef EEPROM
	real_pos = EEPROM.readFloat(0);
	shutter_state = (int)((real_pos) * 100);
	client.publish("Shutter", String(shutter_state));
#endif
}

void loop()
{
	// Watchdog timer reset
	esp_task_wdt_reset();

	// EEPROM
#ifdef EEPROM
	if (EEPROM.readFloat(0) != real_pos)
	EEPROM.writeFloat(0,real_pos);
	EEPROM.commit();
#endif 

	client.loop();

	// motor controll
	shutter_real_pos = motorEncoder.getCount();
	real_pos = shutter_real_pos / ((float)(shutter_down_pos - shutter_up_pos));
	
	if (client.isConnected()) {
		if (mqtt_pos > (real_pos + 0.005f))
		{
			shutter_move = true;
			A_turn_counterclockwise(100);
			shutter_state = (int)((real_pos) * 100);
			client.publish("Shutter", String(shutter_state));
			Serial.println("Moving DOWN");
		}
		else if (mqtt_pos < (real_pos - 0.005f))
		{
			shutter_move = true;
			A_turn_clockwise(100);
			shutter_state = (int)((real_pos) * 100);
			client.publish("Shutter", String(shutter_state));
			Serial.println("Moving UP");
			//Serial.println("Status:" + String(real_pos, 4));
		}
		else
		{
			shutter_move = false;
			A_soft_stop();
		}
	}
		

	// keyboard support
	if (digitalRead(KEYBOARD_BUT1) == LOW)
	{
		Serial.println("KEYBOARD_UP");
		keyboard_overvrite = true;
		A_turn_clockwise(100);
		//A_turn_counterclockwise(100);
		while (digitalRead(KEYBOARD_BUT1) == LOW)
		{
			shutter_real_pos = motorEncoder.getCount();
			real_pos = shutter_real_pos / ((float)(shutter_down_pos - shutter_up_pos));			
			shutter_state = (int)(real_pos * 100);
			mqtt_pos = real_pos;
			if (client.isConnected()) {
				client.publish("Shutter", String(shutter_state));
			}
			
			if (real_pos < 0.01f)
			{ //shutter_state < 0.05f
				Serial.println("STOP_UP");
				A_soft_stop();
			}
			delay(10);
			esp_task_wdt_reset();
		}
	}
	if (digitalRead(KEYBOARD_BUT2) == LOW)
	{
		Serial.println("KEYBOARD_DOWN");
		keyboard_overvrite = true;
		//A_turn_clockwise(100);
		A_turn_counterclockwise(100);
		while (digitalRead(KEYBOARD_BUT2) == LOW)
		{
			shutter_real_pos = motorEncoder.getCount();
			real_pos = shutter_real_pos / ((float)(shutter_down_pos - shutter_up_pos));
			shutter_state = (int)(real_pos * 100);
			mqtt_pos = real_pos;
			if (client.isConnected()) {
				client.publish("Shutter", String(shutter_state));
			}
			if (real_pos >= 0.995f)
			{ //shutter_state >= 0.95f
				Serial.println("STOP_DOWN");
				A_soft_stop();
			}
			delay(10);
			esp_task_wdt_reset();
		}
	}
	if (keyboard_overvrite == true)
	{
		keyboard_overvrite = false;
		A_soft_stop();
		delay(10);
		
	}

	if (doConnect == true)
	{
		if (connectToServer())
		{
			Serial.println("We are now connected to the BLE Server.");
		}
		else
		{
			Serial.println("We have failed to connect to the server; there is nothin more we will do.");
		}
		doConnect = false;
	}
	// If we are connected to a peer BLE Server, update the characteristic each time we are reached
	// with the current time since boot.
	if (connected)
	{
		// if connection was established

	}
	else if (doScan && !shutter_move) // check if shutter is moving
	{
		if (client.isConnected()) {
			Serial.println("Scaning");
			BLEDevice::getScan()->start(1); // this is just example to start scan after disconnect, most likely there is better way to do it in arduino
		}
	}
	delay(100);



}