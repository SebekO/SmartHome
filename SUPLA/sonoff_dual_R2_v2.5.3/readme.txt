SUPLA firmware v2.5.3 compiled by @Zybi for "Sonoff dual R2" on ESP8285 chip.



PORT SETTINGS:
-------------------------------------------------------------------------------------------------
Relay1      - GPIO12 / channel "0" - with memory of relay state
-------------------------------------------------------------------------------------------------
Relay2      - GPIO5  / channel "1" - with memory of relay state
-------------------------------------------------------------------------------------------------
Button0     - GPIO0  / button on header to turn on/off Relay1 (mode "monostable")
-------------------------------------------------------------------------------------------------
Button1     - GPIO9  / button on header to turn on/off Relay2 (mode "monostable")
-------------------------------------------------------------------------------------------------
CFG_button  - GPIO10 / CFG button on the case (mode "monostable")
-------------------------------------------------------------------------------------------------
Sensor      - GPIO3  / channel "2" temperature sensor type DS18B20
-------------------------------------------------------------------------------------------------
LED_Config  - GPIO13 / built in LED diode
-------------------------------------------------------------------------------------------------



Initial parameters for "ESP Falsh Download Tool":
-------------------------------------------------------------------------------------------------
CrystalFreq     -       26M
SPI SPEED       -       40 MHz
SPI MODE        -       DOUT
BAUDRATE        -       115200
FLASH SIZE      -       8Mbit (1MByte)


sonoff_dual_R2_1024_eagle.flash.bin --------------> 0x00000
sonoff_dual_R2_1024_eagle.irom0text.bin ----------> 0x40000
esp_init_data_default.bin ------------------------> 0xFC000

-------------------------------------------------------------------------------------------------



To bring the device into configuration mode, press and hold CFG_button for at least 5 sec.
When in configuration mode, the device goes into Access Point mode.

In order to enter or change the settings, you need to:

- Sign in at https://cloud.supla.org (registration is free of charge)
- Connect to WiFi called „SUPLA-ESP8266” from any computer with a wireless network card and Internet browser.
- Open access page: http://192.168.4.1
- Enter user name and password to the WiFi through which the device will get Internet access.
- Enter Server and e-mail address, which will be provided once you sign in at cloud.supla.org

https://www.youtube.com/watch?v=-JpeCsb9YiE


Demo (YouTube):
https://youtu.be/UR4vKSUqHxw
