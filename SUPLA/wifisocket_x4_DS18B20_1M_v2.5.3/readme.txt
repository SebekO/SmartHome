v2.5.3 firmware compiled by@Zybi for ESP module with 1MByte flash.

Software v.2.5.3 allows you to use a new way to log devices using your smartphone and email, but only
on the latest server. Currently at beta-cloud.supla.org


PORT SETTINGS:

Relay1      - GPIO12 /channel 0 -with memory of relay state with the power on, reset or crash
Relay2      - GPIO13 /channel 1 -with memory of relay state with the power on, reset or crash
Relay3      - GPIO14 /channel 2 -with memory of relay state with the power on, reset or crash
Relay4      - GPIO16 /channel 3 -with memory of relay state with the power on, reset or crash

BTN1/CFG    - GPIO0  /pull-up -operate in two modes: CFG MODE and turn on/off Relay1 (mode "monostable")
BTN2        - GPIO2  /pull-up -turn on/off Relay2 (mode "monostable")
BTN3/Input1 - GPIO4  /pull-up -turn on/off Relay3 (mode "bistable" or "monostable")
BTN4/Input2 - GPIO5  /pull-up -turn on/off Relay4 (mode "bistable" or "monostable")

Thermometer - GPIO3  /(RX) channel 4 -sensor type DS18B20

LED Config  - GPIO15 /(LED diode with a serial resistor of 270-330 ohm attached to parallel resistor
            10k ohm between port and GND. In the config mode, the LED flashes rapidly and during normal
	    operation is off

Pull-up -> 4,7-10k a resistor connected between a port and a positive power supply voltage (+3,3 V).
Active control, a circuit to GND.

In "monostable" mode of BTNx - short press button to attach the relay.
In "bistable" mode of BTNx - a relay is switched when the button is pressed.


Initial parameters for "ESP Falsh Download Tool":

CrystalFreq      26M
SPI SPEED        40 MHz
SPI MODE         DIO
BAUDRATE         115200
FLASH SIZE       8Mbit (1MByte)

wifisocket_x4_DS_1024_eagle.flash.bin -----------------> 0x00000
wifisocket_x4_DS_1024_eagle.irom0text.bin -------------> 0x40000
esp_init_data_default.bin -----------------------------> 0xFC000


// CFG MODE -------------------------------------------------------------------------

To bring the device into configuration mode, press and hold button for at least 5 sec.
When in configuration mode, the device goes into Access Point mode.

In order to enter or change the settings, you need to:

- Sign in at https://cloud.supla.org (registration is free of charge)
- Connect to WiFi called „SUPLA-ESP8266” from any computer with a wireless network card and Internet browser.
- Open access page: http://192.168.4.1
- Enter user name and password to the WiFi through which the device will get Internet access.
- Enter Server address, Location ID and Location Password, which will be provided once you sign in at cloud.supla.org
- or add a new device from the app ... by email to yuor account:

https://www.youtube.com/watch?v=-JpeCsb9YiE
