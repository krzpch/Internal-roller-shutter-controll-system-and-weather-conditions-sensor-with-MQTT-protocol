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
L ESP32_DevKit_V1_DOIT:ESP32_DevKit_V1_DOIT U1
U 1 1 619E55A4
P 1600 2850
F 0 "U1" H 1600 4431 50  0001 C CNN
F 1 "ESP32_DevKit_V1_DOIT" H 1600 1050 50  0000 C CNN
F 2 "ESP32_DevKit_V1_DOIT:esp32_devkit_v1_doit" H 1150 4200 50  0001 C CNN
F 3 "https://aliexpress.com/item/32864722159.html" H 1150 4200 50  0001 C CNN
	1    1600 2850
	1    0    0    -1  
$EndComp
Text GLabel 3950 1350 2    50   Input ~ 0
A_PWM
Text GLabel 3950 1850 2    50   Input ~ 0
B_PWM
Text GLabel 3950 1450 2    50   Input ~ 0
A_IN1
Text GLabel 3950 1550 2    50   Input ~ 0
A_IN2
Text GLabel 3950 1650 2    50   Input ~ 0
B_IN1
Text GLabel 3950 1750 2    50   Input ~ 0
B_IN2
Text GLabel 3950 2450 2    50   Input ~ 0
5V
Wire Wire Line
	3950 1350 3800 1350
Wire Wire Line
	3800 1450 3950 1450
Wire Wire Line
	3950 1550 3800 1550
Wire Wire Line
	3800 2450 3950 2450
Wire Wire Line
	3950 1750 3800 1750
Wire Wire Line
	3800 1650 3950 1650
Wire Wire Line
	3950 1850 3800 1850
$Comp
L Connector:Conn_01x08_Male MOTOR_CONTROLLER1
U 1 1 61A246F6
P 3600 1650
F 0 "MOTOR_CONTROLLER1" H 3650 2050 50  0000 C CNN
F 1 "Conn_01x08_Male" H 3708 2040 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 3600 1650 50  0001 C CNN
F 3 "~" H 3600 1650 50  0001 C CNN
	1    3600 1650
	1    0    0    -1  
$EndComp
Text GLabel 1750 4500 2    50   Input ~ 0
GND
Wire Wire Line
	1750 4500 1600 4500
Wire Wire Line
	1600 4500 1600 4250
Wire Wire Line
	1500 4250 1500 4500
Wire Wire Line
	1500 4500 1600 4500
Connection ~ 1600 4500
Text GLabel 1250 1150 0    50   Input ~ 0
5V
Wire Wire Line
	1250 1150 1500 1150
Wire Wire Line
	1500 1150 1500 1450
Text GLabel 2350 3250 2    50   Input ~ 0
A_PWM
Wire Wire Line
	2350 3250 2200 3250
Text GLabel 2350 3050 2    50   Input ~ 0
A_IN1
Text GLabel 2350 2950 2    50   Input ~ 0
A_IN2
Wire Wire Line
	2350 3050 2200 3050
Wire Wire Line
	2200 2950 2350 2950
Text GLabel 2350 3150 2    50   Input ~ 0
B_PWM
Wire Wire Line
	2350 3150 2200 3150
$Comp
L Connector:Conn_01x02_Male 5V_CONN1
U 1 1 61A2FBCE
P 3600 2350
F 0 "5V_CONN1" H 3700 2500 50  0000 C CNN
F 1 "5V_CONN" H 3708 2440 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 3600 2350 50  0001 C CNN
F 3 "~" H 3600 2350 50  0001 C CNN
	1    3600 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 2350 4000 2350
Wire Wire Line
	4000 2350 4000 2050
Wire Wire Line
	4000 2050 3800 2050
Text GLabel 2350 3350 2    50   Input ~ 0
A_ENC1
Wire Wire Line
	2350 3350 2200 3350
$Comp
L Connector:Conn_01x04_Male KEYBOARD1
U 1 1 61A5FF64
P 3450 3450
F 0 "KEYBOARD1" H 3550 3650 50  0000 C CNN
F 1 "Conn_01x04_Male" H 3558 3640 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 3450 3450 50  0001 C CNN
F 3 "~" H 3450 3450 50  0001 C CNN
	1    3450 3450
	1    0    0    -1  
$EndComp
Text GLabel 2350 2450 2    50   Input ~ 0
BUT1
Text GLabel 2350 3550 2    50   Input ~ 0
BUT2
Text GLabel 2350 3450 2    50   Input ~ 0
BUT3
Wire Wire Line
	2350 3450 2200 3450
Wire Wire Line
	2200 3550 2350 3550
Wire Wire Line
	2350 2450 2200 2450
Text GLabel 4250 3350 2    50   Input ~ 0
BUT1
Text GLabel 4250 3450 2    50   Input ~ 0
BUT2
Text GLabel 4250 3550 2    50   Input ~ 0
BUT3
Text GLabel 4250 3650 2    50   Input ~ 0
GND
Text GLabel 2350 2850 2    50   Input ~ 0
B_IN1
Text GLabel 2350 2150 2    50   Input ~ 0
B_IN2
Wire Wire Line
	2350 2150 2200 2150
Wire Wire Line
	2350 2850 2200 2850
Text GLabel 2350 3650 2    50   Input ~ 0
B_ENC1
Wire Wire Line
	2350 3650 2200 3650
Wire Wire Line
	2200 3950 2350 3950
Wire Wire Line
	2350 3750 2200 3750
Text GLabel 2350 3950 2    50   Input ~ 0
B_ENC2
Text GLabel 2350 3750 2    50   Input ~ 0
A_ENC2
$Comp
L Device:C C1
U 1 1 61A8C4E8
P 3500 4450
F 0 "C1" H 3615 4496 50  0000 L CNN
F 1 "100n" H 3615 4405 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 3538 4300 50  0001 C CNN
F 3 "~" H 3500 4450 50  0001 C CNN
	1    3500 4450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 61A8E456
P 4050 4450
F 0 "C2" H 4165 4496 50  0000 L CNN
F 1 "100n" H 4165 4405 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 4088 4300 50  0001 C CNN
F 3 "~" H 4050 4450 50  0001 C CNN
	1    4050 4450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 61A8E822
P 4550 4450
F 0 "C3" H 4665 4496 50  0000 L CNN
F 1 "100n" H 4665 4405 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 4588 4300 50  0001 C CNN
F 3 "~" H 4550 4450 50  0001 C CNN
	1    4550 4450
	1    0    0    -1  
$EndComp
Text GLabel 4700 4700 2    50   Input ~ 0
GND
Wire Wire Line
	3500 4700 3500 4600
Wire Wire Line
	4050 4600 4050 4700
Connection ~ 4050 4700
Wire Wire Line
	4050 4700 3500 4700
Wire Wire Line
	4550 4600 4550 4700
Wire Wire Line
	4550 4700 4050 4700
Text GLabel 3500 4200 1    50   Input ~ 0
BUT1
Text GLabel 4050 4200 1    50   Input ~ 0
BUT2
Text GLabel 4550 4200 1    50   Input ~ 0
BUT3
Wire Wire Line
	3500 4200 3500 4300
Wire Wire Line
	4050 4300 4050 4200
Wire Wire Line
	4550 4200 4550 4300
Wire Wire Line
	4700 4700 4550 4700
Connection ~ 4550 4700
$Comp
L Device:R R1
U 1 1 61A9DA8B
P 4000 3650
F 0 "R1" V 4100 3650 50  0000 C CNN
F 1 "10k" V 4200 3650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 3930 3650 50  0001 C CNN
F 3 "~" H 4000 3650 50  0001 C CNN
	1    4000 3650
	0    1    1    0   
$EndComp
Wire Wire Line
	4150 3650 4250 3650
Wire Wire Line
	3650 3650 3850 3650
Wire Wire Line
	3650 3550 4250 3550
Wire Wire Line
	3650 3450 4250 3450
Wire Wire Line
	3650 3350 4250 3350
Wire Notes Line
	3050 4900 800  4900
Wire Notes Line
	3200 2950 5100 2950
Wire Notes Line
	5100 2950 5100 4900
Wire Notes Line
	5100 4900 3200 4900
Wire Notes Line
	3200 4900 3200 2950
Wire Wire Line
	3800 1950 3950 1950
Text GLabel 3950 1950 2    50   Input ~ 0
GND
Text Notes 3250 1000 0    50   ~ 0
Motor controller & encoders\n
Text Notes 3250 3050 0    50   ~ 0
Buttons\n
Text Notes 850  1050 0    50   ~ 0
Microcontroller\n
Wire Notes Line
	800  900  3050 900 
Wire Notes Line
	3050 900  3050 4900
Wire Notes Line
	800  900  800  4900
$Comp
L Device:C C10
U 1 1 61D3DACF
P 2200 1250
F 0 "C10" H 2315 1296 50  0000 L CNN
F 1 "100n" H 2315 1205 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 2238 1100 50  0001 C CNN
F 3 "~" H 2200 1250 50  0001 C CNN
	1    2200 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C11
U 1 1 61D3E2E1
P 2650 1250
F 0 "C11" H 2765 1296 50  0000 L CNN
F 1 "4,7u" H 2765 1205 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 2688 1100 50  0001 C CNN
F 3 "~" H 2650 1250 50  0001 C CNN
	1    2650 1250
	1    0    0    -1  
$EndComp
Text GLabel 2800 1500 2    50   Input ~ 0
GND
Text GLabel 2800 1000 2    50   Input ~ 0
5V
Wire Wire Line
	2800 1000 2650 1000
Wire Wire Line
	2200 1000 2200 1100
Wire Wire Line
	2200 1400 2200 1500
Wire Wire Line
	2200 1500 2650 1500
Wire Wire Line
	2650 1400 2650 1500
Connection ~ 2650 1500
Wire Wire Line
	2650 1500 2800 1500
Wire Wire Line
	2650 1100 2650 1000
Connection ~ 2650 1000
Wire Wire Line
	2650 1000 2200 1000
Wire Notes Line
	5450 900  5450 2650
Wire Notes Line
	5450 2650 3200 2650
Wire Notes Line
	3200 2650 3200 900 
Wire Notes Line
	3200 900  5450 900 
Text GLabel 5000 1400 2    50   Input ~ 0
A_ENC1
Text GLabel 5000 1500 2    50   Input ~ 0
A_ENC2
Wire Wire Line
	5000 1400 4850 1400
Wire Wire Line
	5000 1500 4850 1500
Wire Wire Line
	4850 1600 5000 1600
Wire Wire Line
	5000 1700 4850 1700
Text GLabel 5000 1600 2    50   Input ~ 0
GND
Text GLabel 5000 2200 2    50   Input ~ 0
GND
Wire Wire Line
	5000 2300 4850 2300
Wire Wire Line
	4850 2200 5000 2200
Wire Wire Line
	5000 2100 4850 2100
Wire Wire Line
	5000 2000 4850 2000
Text GLabel 5000 2100 2    50   Input ~ 0
B_ENC2
Text GLabel 5000 2000 2    50   Input ~ 0
B_ENC1
$Comp
L Connector:Conn_01x04_Male ENCODER2
U 1 1 61D4C78E
P 4650 2100
F 0 "ENCODER2" H 4750 2350 50  0000 C CNN
F 1 "Conn_01x04_Male" H 4758 2290 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 4650 2100 50  0001 C CNN
F 3 "~" H 4650 2100 50  0001 C CNN
	1    4650 2100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male ENCODER1
U 1 1 61A6458E
P 4650 1500
F 0 "ENCODER1" H 4750 1750 50  0000 C CNN
F 1 "Conn_01x04_Male" H 4758 1690 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 4650 1500 50  0001 C CNN
F 3 "~" H 4650 1500 50  0001 C CNN
	1    4650 1500
	1    0    0    -1  
$EndComp
Text GLabel 5000 2300 2    50   Input ~ 0
5V
Text GLabel 5000 1700 2    50   Input ~ 0
5V
$EndSCHEMATC
