EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Module:Arduino_Nano_v2.x A1
U 1 1 61586B32
P 3400 5850
F 0 "A1" H 3400 4761 50  0000 C CNN
F 1 "STM32" H 3400 4670 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 3400 5850 50  0001 C CIN
F 3 "https://www.arduino.cc/en/uploads/Main/ArduinoNanoManual23.pdf" H 3400 5850 50  0001 C CNN
	1    3400 5850
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Male J3
U 1 1 6158B5E4
P 7050 1700
F 0 "J3" H 7158 1981 50  0001 C CNN
F 1 "DC-DC Conv" H 7200 1550 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 7050 1700 50  0001 C CNN
F 3 "~" H 7050 1700 50  0001 C CNN
	1    7050 1700
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Male J4
U 1 1 615A7C3A
P 8200 1600
F 0 "J4" H 8172 1574 50  0001 R CNN
F 1 "Bat_IN" H 8400 1450 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 8200 1600 50  0001 C CNN
F 3 "~" H 8200 1600 50  0001 C CNN
	1    8200 1600
	-1   0    0    -1  
$EndComp
$Comp
L Device:CP C1
U 1 1 615B15AB
P 7650 1400
F 0 "C1" V 7905 1400 50  0000 C CNN
F 1 "47u" V 7814 1400 50  0000 C CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.00mm" H 7688 1250 50  0001 C CNN
F 3 "~" H 7650 1400 50  0001 C CNN
	1    7650 1400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8000 1700 7850 1700
Wire Wire Line
	7800 1400 7850 1400
Wire Wire Line
	7850 1400 7850 1700
Connection ~ 7850 1700
Wire Wire Line
	7850 1700 7550 1700
Wire Wire Line
	7500 1400 7450 1400
Wire Wire Line
	7450 1400 7450 1600
Connection ~ 7450 1600
Wire Wire Line
	7450 1600 7250 1600
Wire Wire Line
	3500 6850 3500 6950
Wire Wire Line
	3400 6950 3400 6850
$Comp
L Moje:HM_BT4502 HM_BT4502
U 1 1 615F8D6F
P 4850 2450
F 0 "HM_BT4502" H 5178 2496 50  0000 L CNN
F 1 "HM_BT4502" H 5178 2405 50  0001 L CNN
F 2 "Moje:HM-BT4502" H 4900 2300 50  0001 C CNN
F 3 "" H 4900 2300 50  0001 C CNN
	1    4850 2450
	-1   0    0    -1  
$EndComp
Text GLabel 4050 6550 2    50   Input ~ 0
TX
Text GLabel 4050 6050 2    50   Input ~ 0
RX
Text GLabel 4050 6150 2    50   Input ~ 0
INT
Text GLabel 4050 5950 2    50   Input ~ 0
PDN
Text GLabel 4050 6450 2    50   Input ~ 0
WAKEUP
Text GLabel 5500 2250 2    50   Input ~ 0
RX
Text GLabel 5500 2350 2    50   Input ~ 0
TX
Text GLabel 5500 2450 2    50   Input ~ 0
WAKEUP
Text GLabel 5500 2550 2    50   Input ~ 0
PDN
Text GLabel 5500 2650 2    50   Input ~ 0
INT
Wire Wire Line
	3400 6950 3500 6950
Text GLabel 7100 2150 0    50   Input ~ 0
GND
Text GLabel 7100 2000 0    50   Input ~ 0
VCC
Text GLabel 3400 7150 3    50   Input ~ 0
GND
Text GLabel 8550 1400 0    50   Input ~ 0
VCC
$Comp
L Moje:BH1750 BH1750
U 1 1 6160A42E
P 3450 2450
F 0 "BH1750" H 3223 2496 50  0000 R CNN
F 1 "BH1750" H 3223 2405 50  0001 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 3300 2850 50  0001 C CNN
F 3 "" H 3300 2850 50  0001 C CNN
	1    3450 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 2900 3450 3200
Wire Wire Line
	4700 3000 4700 3200
Wire Wire Line
	4800 3000 4800 3200
Wire Wire Line
	4900 3000 4900 3200
Wire Wire Line
	5000 3000 5000 3200
Wire Wire Line
	7450 1800 7250 1800
Wire Wire Line
	7450 1800 7450 2000
Wire Wire Line
	7550 2150 7550 1700
Connection ~ 7550 1700
Wire Wire Line
	7550 1700 7250 1700
Wire Wire Line
	3400 7150 3400 6950
Connection ~ 3400 6950
$Comp
L Moje:BME280 BME280
U 1 1 6165F4E1
P 2100 2450
F 0 "BME280" H 1823 2496 50  0000 R CNN
F 1 "BME280" H 1823 2405 50  0001 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 1900 2800 50  0001 C CNN
F 3 "" H 1900 2800 50  0001 C CNN
	1    2100 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 2850 2100 3200
Text GLabel 5500 3200 2    50   Input ~ 0
GND
Wire Wire Line
	2100 2050 2100 1250
Text GLabel 5500 1250 2    50   Input ~ 0
VCC
Wire Wire Line
	3450 2000 3450 1250
Connection ~ 3450 1250
Wire Wire Line
	4850 1900 4850 1250
Text GLabel 5500 1450 2    50   Input ~ 0
SCL
Text GLabel 5500 1600 2    50   Input ~ 0
SDA
Wire Wire Line
	4250 2450 4250 1600
Wire Wire Line
	3000 1600 3000 2400
Wire Wire Line
	2850 1450 2850 2300
Wire Wire Line
	2600 2600 2600 1250
Wire Wire Line
	2450 2400 3000 2400
Wire Wire Line
	2450 2300 2850 2300
Wire Wire Line
	2700 2500 2700 3200
Wire Wire Line
	3450 1250 3900 1250
Wire Wire Line
	3750 2350 4100 2350
Wire Wire Line
	3750 2450 4250 2450
Wire Wire Line
	3750 2550 3900 2550
Wire Wire Line
	3900 2550 3900 1250
Connection ~ 2600 1250
Wire Wire Line
	2600 1250 3450 1250
Connection ~ 2700 3200
Wire Wire Line
	2700 3200 3450 3200
Wire Wire Line
	2100 3200 2700 3200
Wire Wire Line
	2100 1250 2600 1250
Wire Wire Line
	2450 2500 2700 2500
Wire Wire Line
	2450 2600 2600 2600
Wire Wire Line
	4700 3200 4800 3200
Connection ~ 4800 3200
Wire Wire Line
	4800 3200 4900 3200
Wire Wire Line
	4850 1250 5500 1250
Connection ~ 4900 3200
Wire Wire Line
	4900 3200 5000 3200
Connection ~ 5000 3200
Wire Wire Line
	5000 3200 5500 3200
Wire Wire Line
	4700 3200 3450 3200
Connection ~ 4700 3200
Connection ~ 3450 3200
Wire Wire Line
	4850 1250 3900 1250
Connection ~ 4850 1250
Connection ~ 3900 1250
Wire Wire Line
	4250 1600 5500 1600
Connection ~ 4250 1600
Wire Wire Line
	5250 2250 5500 2250
Wire Wire Line
	5250 2350 5500 2350
Wire Wire Line
	5250 2450 5500 2450
Wire Wire Line
	5250 2550 5500 2550
Wire Wire Line
	5250 2650 5500 2650
Wire Wire Line
	7550 2150 7100 2150
Wire Wire Line
	3000 1600 4250 1600
Wire Wire Line
	2850 1450 4100 1450
Wire Wire Line
	4100 2350 4100 1450
Connection ~ 4100 1450
Wire Wire Line
	4100 1450 5500 1450
Wire Wire Line
	4050 5950 3900 5950
Wire Wire Line
	3900 6050 4050 6050
Wire Wire Line
	4050 6150 3900 6150
Wire Wire Line
	3900 6450 4050 6450
Wire Wire Line
	4050 6550 3900 6550
Wire Wire Line
	7100 2000 7450 2000
$Comp
L Connector:Conn_01x02_Male J1
U 1 1 617DD5EE
P 8950 1900
F 0 "J1" H 8922 1874 50  0001 R CNN
F 1 "BAT_BYPAS" H 9050 1700 50  0000 C BNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 8950 1900 50  0001 C CNN
F 3 "~" H 8950 1900 50  0001 C CNN
	1    8950 1900
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Male J2
U 1 1 6195BB05
P 8950 1400
F 0 "J2" H 9058 1681 50  0001 C CNN
F 1 "VCC_SEL" H 9058 1590 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 8950 1400 50  0001 C CNN
F 3 "~" H 8950 1400 50  0001 C CNN
	1    8950 1400
	-1   0    0    1   
$EndComp
Wire Wire Line
	8550 1400 8750 1400
Wire Wire Line
	7450 1600 8000 1600
Text GLabel 7250 1250 0    50   Input ~ 0
VBAT
Wire Wire Line
	7250 1250 7450 1250
Wire Wire Line
	7450 1250 7450 1400
Connection ~ 7450 1400
Text GLabel 8550 1900 0    50   Input ~ 0
VBAT
Text GLabel 8550 2000 0    50   Input ~ 0
VCC
Wire Wire Line
	8550 1900 8750 1900
Wire Wire Line
	8750 2000 8550 2000
Text GLabel 3300 4600 1    50   Input ~ 0
VIN
Text GLabel 3500 4600 1    50   Input ~ 0
3V3
Text GLabel 8550 1300 0    50   Input ~ 0
VIN
Text GLabel 8550 1500 0    50   Input ~ 0
3V3
Wire Wire Line
	8550 1500 8750 1500
Wire Wire Line
	8750 1300 8550 1300
$Comp
L Device:C C2
U 1 1 619821C2
P 1900 3650
F 0 "C2" H 2015 3696 50  0000 L CNN
F 1 "100n" H 2015 3605 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 1938 3500 50  0001 C CNN
F 3 "~" H 1900 3650 50  0001 C CNN
	1    1900 3650
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 61984403
P 2300 3650
F 0 "C3" H 2415 3696 50  0000 L CNN
F 1 "4,7u" H 2415 3605 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 2338 3500 50  0001 C CNN
F 3 "~" H 2300 3650 50  0001 C CNN
	1    2300 3650
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 61984715
P 3100 3650
F 0 "C4" H 3215 3696 50  0000 L CNN
F 1 "100n" H 3215 3605 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 3138 3500 50  0001 C CNN
F 3 "~" H 3100 3650 50  0001 C CNN
	1    3100 3650
	1    0    0    -1  
$EndComp
$Comp
L Device:C C5
U 1 1 61984DDE
P 3450 3650
F 0 "C5" H 3565 3696 50  0000 L CNN
F 1 "4,7u" H 3565 3605 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 3488 3500 50  0001 C CNN
F 3 "~" H 3450 3650 50  0001 C CNN
	1    3450 3650
	1    0    0    -1  
$EndComp
$Comp
L Device:C C6
U 1 1 619852EE
P 4650 3650
F 0 "C6" H 4765 3696 50  0000 L CNN
F 1 "100n" H 4765 3605 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 4688 3500 50  0001 C CNN
F 3 "~" H 4650 3650 50  0001 C CNN
	1    4650 3650
	1    0    0    -1  
$EndComp
$Comp
L Device:C C7
U 1 1 619855C5
P 5000 3650
F 0 "C7" H 5115 3696 50  0000 L CNN
F 1 "4,7u" H 5115 3605 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 5038 3500 50  0001 C CNN
F 3 "~" H 5000 3650 50  0001 C CNN
	1    5000 3650
	1    0    0    -1  
$EndComp
Text GLabel 5500 3400 2    50   Input ~ 0
VCC
Text GLabel 5500 3900 2    50   Input ~ 0
GND
Wire Wire Line
	5500 3400 5000 3400
Wire Wire Line
	1900 3400 1900 3500
Wire Wire Line
	2300 3500 2300 3400
Connection ~ 2300 3400
Wire Wire Line
	2300 3400 1900 3400
Wire Wire Line
	3100 3500 3100 3400
Connection ~ 3100 3400
Wire Wire Line
	3100 3400 2300 3400
Wire Wire Line
	3450 3500 3450 3400
Connection ~ 3450 3400
Wire Wire Line
	3450 3400 3100 3400
Wire Wire Line
	4650 3500 4650 3400
Connection ~ 4650 3400
Wire Wire Line
	4650 3400 3450 3400
Wire Wire Line
	5000 3500 5000 3400
Connection ~ 5000 3400
Wire Wire Line
	5000 3400 4650 3400
Wire Wire Line
	5500 3900 5000 3900
Wire Wire Line
	1900 3900 1900 3800
Wire Wire Line
	2300 3800 2300 3900
Connection ~ 2300 3900
Wire Wire Line
	2300 3900 1900 3900
Wire Wire Line
	3100 3800 3100 3900
Connection ~ 3100 3900
Wire Wire Line
	3100 3900 2300 3900
Wire Wire Line
	3450 3800 3450 3900
Connection ~ 3450 3900
Wire Wire Line
	3450 3900 3100 3900
Wire Wire Line
	4650 3800 4650 3900
Connection ~ 4650 3900
Wire Wire Line
	4650 3900 3450 3900
Wire Wire Line
	5000 3800 5000 3900
Connection ~ 5000 3900
Wire Wire Line
	5000 3900 4650 3900
$Comp
L Device:C C9
U 1 1 619F3563
P 4450 4700
F 0 "C9" H 4565 4746 50  0000 L CNN
F 1 "100n" H 4565 4655 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 4488 4550 50  0001 C CNN
F 3 "~" H 4450 4700 50  0001 C CNN
	1    4450 4700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C8
U 1 1 619F3C3A
P 4950 4700
F 0 "C8" H 5065 4746 50  0000 L CNN
F 1 "4,7u" H 5065 4655 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 4988 4550 50  0001 C CNN
F 3 "~" H 4950 4700 50  0001 C CNN
	1    4950 4700
	1    0    0    -1  
$EndComp
Text GLabel 5050 4950 2    50   Input ~ 0
GND
Wire Wire Line
	4450 4950 4450 4850
Wire Wire Line
	4950 4850 4950 4950
Wire Wire Line
	4950 4950 4450 4950
Wire Wire Line
	4450 4550 4450 4400
Wire Wire Line
	4450 4400 4950 4400
Wire Wire Line
	4950 4400 4950 4550
Wire Wire Line
	4950 5250 4950 5100
Wire Wire Line
	4950 5700 4950 5550
Wire Wire Line
	5050 5700 4950 5700
Text GLabel 5050 5700 2    50   Input ~ 0
GND
$Comp
L Device:C C11
U 1 1 619D0572
P 4950 5400
F 0 "C11" H 5065 5446 50  0000 L CNN
F 1 "4,7u" H 5065 5355 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 4988 5250 50  0001 C CNN
F 3 "~" H 4950 5400 50  0001 C CNN
	1    4950 5400
	1    0    0    -1  
$EndComp
$Comp
L Device:C C10
U 1 1 619BEB3A
P 4450 5400
F 0 "C10" H 4565 5446 50  0000 L CNN
F 1 "100n" H 4565 5355 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 4488 5250 50  0001 C CNN
F 3 "~" H 4450 5400 50  0001 C CNN
	1    4450 5400
	1    0    0    -1  
$EndComp
Connection ~ 4950 5700
Wire Wire Line
	5050 4950 4950 4950
Connection ~ 4950 4950
Wire Wire Line
	3300 4850 3300 4600
Wire Wire Line
	3500 4600 3500 4850
Text GLabel 5050 4400 2    50   Input ~ 0
VIN
Wire Wire Line
	5050 4400 4950 4400
Connection ~ 4950 4400
Text GLabel 5050 5100 2    50   Input ~ 0
3V3
Wire Wire Line
	5050 5100 4950 5100
Connection ~ 4950 5100
Wire Wire Line
	4450 5550 4450 5700
Wire Wire Line
	4450 5700 4950 5700
Wire Wire Line
	4450 5250 4450 5100
Wire Wire Line
	4450 5100 4950 5100
Wire Notes Line
	1450 950  6650 950 
Wire Notes Line
	6650 950  6650 4050
Wire Notes Line
	6650 4050 1450 4050
Wire Notes Line
	1450 4050 1450 950 
Text Notes 1500 1050 0    50   ~ 0
Sensors & BLE Module\n
Connection ~ 2200 5150
Wire Wire Line
	2200 4950 2200 5150
Text GLabel 2200 4950 1    50   Input ~ 0
VCC
Wire Wire Line
	2200 5150 2200 5250
Wire Wire Line
	1900 5150 2200 5150
Wire Wire Line
	1900 5250 1900 5150
Wire Wire Line
	2200 5550 2200 5750
Wire Wire Line
	1900 5550 1900 5650
$Comp
L Device:R R1
U 1 1 616D0045
P 2200 5400
F 0 "R1" H 2270 5446 50  0000 L CNN
F 1 "10k" H 2270 5355 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2130 5400 50  0001 C CNN
F 3 "~" H 2200 5400 50  0001 C CNN
	1    2200 5400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 616CC8F4
P 1900 5400
F 0 "R2" H 1970 5446 50  0000 L CNN
F 1 "10k" H 1970 5355 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1830 5400 50  0001 C CNN
F 3 "~" H 1900 5400 50  0001 C CNN
	1    1900 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 5750 2200 5750
Wire Wire Line
	1750 5650 1900 5650
Text GLabel 1750 5650 0    50   Input ~ 0
SDA
Text GLabel 1750 5750 0    50   Input ~ 0
SCL
Wire Wire Line
	1900 5650 2900 5650
Connection ~ 1900 5650
Wire Wire Line
	2900 5750 2200 5750
Connection ~ 2200 5750
Wire Notes Line
	1450 7450 1450 4200
Text Notes 1500 4300 0    50   ~ 0
Microcontroller\n
Text Notes 6900 1050 0    50   ~ 0
Power \n
Wire Notes Line
	1450 4200 5400 4200
Wire Notes Line
	5400 4200 5400 7450
Wire Notes Line
	5400 7450 1450 7450
Wire Notes Line
	9100 950  9100 2400
Wire Notes Line
	9100 2400 6850 2400
Wire Notes Line
	6850 2400 6850 950 
Wire Notes Line
	6850 950  9100 950 
$EndSCHEMATC
