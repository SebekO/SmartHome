SUPLA firmware v2.0 compiled by @Zybi
for board by @Espablo V.2 https://forum.supla.org/viewtopic.php?f=24&t=340

Firmware for ESP module with flash size 4MByte

PORTS SETTINGS:

Relay1      	- GPIO4
Relay2      	- GPIO13
BUTTON    	- GPIO5  pull up / CFG MODE
Sensor1    	- GPIO14 pull up / turn on/off relay1 (mode "switch" or "button")
Sensor2    	- GPIO12 pull up / turn on/off relay2 (mode "switch" or "button")
DHT11      	- GPIO2  thermometer and humidity sensor
LED_Config 	- GPIO15 


Initial parameters for "ESP Falsh Download Tool":

CreystalFreq 26M
SPI SPEED 40 MHz
SPI MODE QIO
BAUDRATE 11520
FLASH SIZE 32Mbit (4MByte)

lightswitch_x2_DHT11_4096_eagle.flash.bin ------------> 0x00000
lightswitch_x2_DHT11_4096_eagle.irom0text.bin --------> 0x40000


// CFG MODE - BUTTON

To bring the device into configuration mode, press and hold button for at least 5 sec.
When in configuration mode, the device goes into Access Point mode.


In order to enter or change the settings, you need to:

- Sign in at https://cloud.supla.org (registration is free of charge)
- Connect to WiFi called „SUPLA-ESP8266” from any computer with a wireless network card and Internet browser.
- Open access page: http://192.168.4.1
- Enter user name and password to the WiFi through which the device will get Internet access.
- Enter Server address, Location ID and Location Password, which will be provided once you sign in at cloud.supla.org
