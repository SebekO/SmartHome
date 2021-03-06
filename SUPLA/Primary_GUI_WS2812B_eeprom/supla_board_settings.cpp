#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>

#include <EEPROM.h>
#include <DoubleResetDetector.h> //Bilioteka by Stephen Denne

#define SUPLADEVICE_CPP
#include <SuplaDevice.h>

#include <OneWire.h>
#include <DallasTemperature.h>
#include <DHT.h>

#include "supla_settings.h"
#include "supla_eeprom.h"
#include "supla_web_server.h"
#include "supla_board_settings.h"

extern "C" {
#include "user_interface.h"
}



void supla_board_configuration(void) {

   add_Relay(RELAYPIN);
   add_Relay(RELAYPIN1);
//  add_Relay_Invert(RELAYPIN);
  
  //  add_Relay_Button_Invert(RELAYPIN, 14, CHOICE_TYPE);
  //  add_Relay_Button_Invert(13, 12, CHOICE_TYPE);
  
  //add_Relay_Button(RELAYPIN, 14, CHOICE_TYPE);
//  add_Relay_Button(13, 12, CHOICE_TYPE);
  
  //  add_Roller_Shutter_Relays(RELAYPIN, 13);
  //  add_Roller_Shutter_Buttons(0, 14, 12);
  //  SuplaDevice.setRollerShutterFuncImpl(&supla_rs_SavePosition, &supla_rs_LoadPosition, &supla_rs_SaveSettings, &supla_rs_LoadSettings);
  
  //  add_Sensor(4);
  //  add_Sensor(16);
  
  //  add_DS18B20_Thermometer(2);
  //  add_DHT11_Thermometer(12);
  //  add_DHT22_Thermometer(4);
  
  //  SuplaDevice.addRelayButton(RELAYPIN, 14, INPUT_TYPE_BTN_MONOSTABLE, 0, SUPLA_BIT_RELAYFUNC_LIGHTSWITCH);

    add_Led_Config(LED_CONFIG_PIN);
}
