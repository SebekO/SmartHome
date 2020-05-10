/* *************************************************************************

   Dzieki kolegom @wojtas567 i @Duch__ powstała ta wersja.


   Wszystkie potrzebne modyfikacja znajdują się w pliku "supla_settings.h"

 * *************************************************************************
*/


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

#define DRD_TIMEOUT 5// Number of seconds after reset during which a subseqent reset will be considered a double reset.
#define DRD_ADDRESS 0 // RTC Memory Address for the DoubleResetDetector to use
DoubleResetDetector drd(DRD_TIMEOUT, DRD_ADDRESS);

int nr_button = 0;
int nr_relay = 2;
int invert = 0;
int nr_ds18b20 = 0;
int nr_dht = 0;
int dht_channel[MAX_DHT];
int ds18x20_channel[MAX_DS18B20];
int relay_button_channel[MAX_RELAY];


unsigned char _red = 0;
unsigned char _green = 255;
unsigned char _blue = 0;
unsigned char _color_brightness = 100;
unsigned char _brightness = 10;
 
// int color_brightness = 100;
int WS2812_ilosc;



double temp_html;
double humidity_html;

const char* Config_Wifi_name = CONFIG_WIFI_LOGIN;
const char* Config_Wifi_pass = CONFIG_WIFI_PASSWORD;

const char* www_username;
const char* www_password;
const char* update_path = UPDATE_PATH;

WiFiClient client;
ESP8266WebServer httpServer(80);
ESP8266HTTPUpdateServer httpUpdater;
ETSTimer led_timer;

// Setup a DHT instance
// DHT dht(DHTPIN, DHTTYPE);
DHT dht_sensor[MAX_DHT] = {
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
  { 0, 0 },
};

// Setup a DS18B20 instance
//OneWire oneWire(DS18B20PIN);
//DallasTemperature sensors(&oneWire);

OneWire ds18x20[MAX_DS18B20] = { 0, 0, 0, 0, 0, 0, 0, 0 };
//const int oneWireCount = sizeof(ds18x20) / sizeof(OneWire);
DallasTemperature sensor[MAX_DS18B20];
DeviceAddress deviceAddress;

//SUPLA ****************************************************************************************************

char Supla_server[MAX_SUPLA_SERVER];
char Location_id[MAX_SUPLA_ID];
char Location_Pass[MAX_SUPLA_PASS];
//*********************************************************************************************************






#include <Adafruit_NeoPixel.h>


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(WS2812_ilosc, PIN_WS2812, NEO_GRB + NEO_KHZ800);

// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

void get_rgbw_value(int channelNumber, unsigned char *red, unsigned char *green, unsigned char *blue, unsigned char *color_brightness, unsigned char *brightness) {

  *brightness = _brightness;
  _color_brightness=read_supla_ws2812_brightness().toInt();
  _red   = read_supla_ws2812_red().toInt();
  _green = read_supla_ws2812_green().toInt();
  _blue  = read_supla_ws2812_blue().toInt();
  *red = _red;
  *green = _green;
  *blue = _blue;

}

void set_rgbw() {
  
     pixels.setBrightness(byte(_color_brightness));          
     for (int i = 0; i < WS2812_ilosc; i++) {          
          pixels.setPixelColor(i,byte( _red), byte(_green),byte( _blue)); // Dioda "i" oraz skladowe RGB    
     }   
     pixels.show(); // Wysylamy dane do lancucha      
 
     Serial.println("Change color ");      
}

void set_rgbw_value(int channelNumber, unsigned char red, unsigned char green, unsigned char blue, unsigned char color_brightness, unsigned char brightness) {

    _brightness = brightness;
    _color_brightness= color_brightness;
  
    _red = red;
    _green = green;
    _blue = blue;  
    save_supla_ws2812_red(String(red));
    save_supla_ws2812_green(String(green));
    save_supla_ws2812_blue(String(blue));    
    save_supla_ws2812_brightness(String(color_brightness));
    set_rgbw();
  
}




void setup() {
  Serial.begin(74880);
  delay(100);

 
  Serial.println();
  Serial.print("PIN WS2812b : ");
  Serial.println(PIN_WS2812);
  EEPROM.begin(EEPROM_SIZE);
  delay(100);
  pinMode(PIN_WS2812,OUTPUT);
  pixels.begin(); // Inicjalizacja biblioteki
  pixels.clear();
 
  if ('1' != char(EEPROM.read(EEPROM_SIZE - 1))) {
    czyszczenieEEPROM();
    first_start();
    save_guid();
  }

  supla_board_configuration();

  if (drd.detectDoubleReset()) {
    drd.stop();
    gui_color = GUI_GREEN;
    Tryb_konfiguracji();
  }
  else gui_color = GUI_BLUE;

  delay(5000);
  drd.stop();



  String www_username1 = String(read_login().c_str());
  String www_password1 = String(read_login_pass().c_str());

  www_password = strcpy((char*)malloc(www_password1.length() + 1), www_password1.c_str());
  www_username = strcpy((char*)malloc(www_username1.length() + 1), www_username1.c_str());

  //  Pokaz_zawartosc_eeprom();
  read_guid();
  int Location_id = read_supla_id().toInt();
  strcpy(Supla_server, read_supla_server().c_str());
  strcpy(Location_Pass, read_supla_pass().c_str());
  WS2812_ilosc = read_supla_ws2812().toInt();


  pixels.updateLength(WS2812_ilosc);
  Serial.print("Ilość diod : ");
  Serial.println(pixels.numPixels());
  
  

  SuplaDevice.setStatusFuncImpl(&status_func);
  if (String(read_wifi_ssid().c_str()) == 0
      || String(read_wifi_pass().c_str()) == 0
      || String(read_login().c_str()) == 0
      || String(read_login_pass().c_str()) == 0
      || String(read_supla_server().c_str()) == 0
      || String(read_supla_id().c_str()) == 0
      || String(read_supla_pass().c_str()) == 0
     ) {

    gui_color = GUI_GREEN;

    Tryb_konfiguracji();
  }

  read_guid();
  my_mac_adress();


  //  SuplaDevice.setStatusFuncImpl(&status_func);
  SuplaDevice.setName(read_supla_hostname().c_str());
  SuplaDevice.addRgbController();  
  supla_ds18b20_start();
  supla_dht_start();
  /*
     // CHANNEL0 - TWO RELAYS (Roller shutter operation)
    SuplaDevice.addRollerShutterRelays(5,     // 46 - ﻿﻿Pin number where the 1st relay is connected
                                       13);    // 47 - ﻿Pin number where the 2nd relay is connected


    SuplaDevice.setRollerShutterButtons(0,    // 0 - Channel Number
                                        14,   // 20 - Pin where the 1st button is connected
                                        12);  // 21 - Pin where the 2nd button is connected

  */

  SuplaDevice.begin(GUID,              // Global Unique Identifier
                    mac,               // Ethernet MAC address
                    Supla_server,  // SUPLA server address
                    Location_id,                 // Location ID
                    Location_Pass);

  Serial.println();
  Serial.println("Uruchamianie serwera...");
  WiFi.mode(WIFI_STA);

  createWebServer();

  httpUpdater.setup(&httpServer, UPDATE_PATH, www_username, www_password);
  httpServer.begin();
    pixels.clear();
    pixels.show();
}

//*********************************************************************************************************

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    WiFi_up();
  }
  else httpServer.handleClient();


  SuplaDevice.iterate();

}
//*********************************************************************************************************

// Supla.org ethernet layer
int supla_arduino_tcp_read(void *buf, int count) {
  _supla_int_t size = client.available();

  if ( size > 0 ) {
    if ( size > count ) size = count;
    return client.read((uint8_t *)buf, size);
  };

  return -1;
};

int supla_arduino_tcp_write(void *buf, int count) {
  return client.write((const uint8_t *)buf, count);
};

bool supla_arduino_svr_connect(const char *server, int port) {
  return client.connect(server, 2015);
}

bool supla_arduino_svr_connected(void) {
  return client.connected();
}

void supla_arduino_svr_disconnect(void) {
  client.stop();
}

void supla_arduino_eth_setup(uint8_t mac[6], IPAddress *ip) {
  WiFi_up();
}


SuplaDeviceCallbacks supla_arduino_get_callbacks(void) {
  SuplaDeviceCallbacks cb;

  cb.tcp_read = &supla_arduino_tcp_read;
  cb.tcp_write = &supla_arduino_tcp_write;
  cb.eth_setup = &supla_arduino_eth_setup;
  cb.svr_connected = &supla_arduino_svr_connected;
  cb.svr_connect = &supla_arduino_svr_connect;
  cb.svr_disconnect = &supla_arduino_svr_disconnect;
  cb.get_temperature = &get_temperature;
  cb.get_temperature_and_humidity = &get_temperature_and_humidity;
  cb.get_rgbw_value = &get_rgbw_value;
  cb.set_rgbw_value = &set_rgbw_value;
  cb.read_supla_relay_state = &read_supla_relay_state;
  cb.save_supla_relay_state = &save_supla_relay_state;

  return cb;
}
//*********************************************************************************************************

void createWebServer() {

  httpServer.on("/", []() {
    if (Modul_tryb_konfiguracji != 2) {
      if (!httpServer.authenticate(www_username, www_password))
        return httpServer.requestAuthentication();
    }
    httpServer.send(200, "text/html", supla_webpage_start(0));
  });

  httpServer.on("/set0", []() {
    if (Modul_tryb_konfiguracji != 2) {
      if (!httpServer.authenticate(www_username, www_password))
        return httpServer.requestAuthentication();
    }

    save_wifi_ssid(httpServer.arg("wifi_ssid"));
    save_wifi_pass(httpServer.arg("wifi_pass"));
    save_login( httpServer.arg("modul_login"));
    save_login_pass(httpServer.arg("modul_pass"));
    save_supla_server(httpServer.arg("supla_server"));
    save_supla_hostname(httpServer.arg("supla_hostname"));
    save_supla_id(httpServer.arg("supla_id"));
    save_supla_pass(httpServer.arg("supla_pass"));
    save_supla_ws2812(httpServer.arg("supla_ws2812"));

       // save_supla_ws2812(httpServer.arg("supla_pass"));

    if (nr_button > 0) {
      for (int i = 1; i <= nr_button; ++i) {
        String button = "button_set";
        button += i;
        save_supla_button_type(i, httpServer.arg(button));
      }
    }
    if (nr_relay > 0) {
      for (int i = 1; i <= nr_relay; ++i) {
        String relay = "relay_set";
        relay += i;
        save_supla_relay_flag(i, httpServer.arg(relay));
      }
    }

    httpServer.send(200, "text/html", supla_webpage_start(1));
  });

  //************************************************************

  httpServer.on("/firmware_up", []() {
    if (Modul_tryb_konfiguracji != 2) {
      if (!httpServer.authenticate(www_username, www_password))
        return httpServer.requestAuthentication();
    }
    httpServer.send(200, "text/html", supla_webpage_upddate());
  });

  //****************************************************************************************************************************************
  httpServer.on("/reboot", []() {
    if (Modul_tryb_konfiguracji != 2) {
      if (!httpServer.authenticate(www_username, www_password))
        return httpServer.requestAuthentication();
    }
    httpServer.send(200, "text/html", supla_webpage_start(2));
    delay(100);
    ESP.reset();
  }
               );
}

//****************************************************************************************************************************************
void Tryb_konfiguracji() {
  supla_led_blinking(LED_CONFIG_PIN, 100);
  my_mac_adress();
  Serial.println("Tryb konfiguracji");
  pixels.clear();
  WiFi.disconnect();
  delay(1000);
  WiFi.mode(WIFI_AP);
  WiFi.softAP(Config_Wifi_name, Config_Wifi_pass);
  delay(1000);
  Serial.println("Tryb AP");
  createWebServer();
  httpServer.begin();
  Serial.println("Start Serwera");
  Modul_tryb_konfiguracji = 2;
  while (1) {
    httpServer.handleClient();
    //    SuplaDevice.iterate();
  }
}

void Run_Offline(){
  
  _red   = read_supla_ws2812_red().toInt();
  _green = read_supla_ws2812_green().toInt();
  _blue  = read_supla_ws2812_blue().toInt();  
  _color_brightness = read_supla_ws2812_brightness().toInt();

  pixels.setBrightness(byte(_color_brightness));          
  for (int i = 0; i < WS2812_ilosc; i++) {          
          pixels.setPixelColor(i,byte( _red), byte(_green),byte( _blue)); // Dioda "i" oraz skladowe RGB    
  }   
  pixels.show(); // Wysylamy dane do lancucha      
 
  Serial.println("Display offline");      
}

void WiFi_up() {
  //  WiFi.setOutputPower(20.5);
   
  supla_led_blinking(LED_CONFIG_PIN, 500);
   
  WiFi.disconnect();
  WiFi.hostname(String(read_supla_hostname().c_str()));
  WiFi.softAPdisconnect(true);

  String esid = String(read_wifi_ssid().c_str());
  String epass = String(read_wifi_pass().c_str());
  Serial.println("WiFi init");
  Serial.print("SSID : ");
  Serial.println(esid);
  Serial.print("PASSWORD : ");
  Serial.println(epass);
  WiFi.mode(WIFI_STA);
  WiFi.begin(esid.c_str(), epass.c_str());
  Run_Offline();
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    
  }

  Serial.print("\nlocalIP: ");
  Serial.println(WiFi.localIP());
  Serial.print("subnetMask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("gatewayIP: ");
  Serial.println(WiFi.gatewayIP());
}

void first_start(void) {
  EEPROM.begin(EEPROM_SIZE);
  delay(100);
  EEPROM.write(EEPROM_SIZE - 1, '1');
  EEPROM.end();
  delay(100);
  save_login(DEFAULT_LOGIN);
  save_login_pass(DEFAULT_PASSWORD);
  save_supla_hostname(DEFAULT_HOSTNAME);

}

String read_rssi(void) {
  long rssi = WiFi.RSSI();
  return String(rssi) ;
}

void get_temperature_and_humidity(int channelNumber, double *temp, double *humidity) {
  *temp = dht_sensor[channelNumber].readTemperature();
  *humidity = dht_sensor[channelNumber].readHumidity();
  //  static uint8_t error;
  //  Serial.print("get_temperature_and_humidity - "); Serial.print(channelNumber); Serial.print(" -- "); Serial.print(*temp); Serial.print(" -- "); Serial.println(*humidity);
  if ( isnan(*temp) || isnan(*humidity) ) {
    *temp = -275;
    *humidity = -1;
    //    error++;
  }
  //  Serial.print("error - "); Serial.println(error);
}

double get_temperature(int channelNumber, double last_val) {
  double t = -275;
  if ( sensor[channelNumber].getDeviceCount() > 0 ) {
    sensor[channelNumber].requestTemperatures();
    t = sensor[channelNumber].getTempCByIndex(0);
    if (t == -127) t = -275;
  }
  return t;
}

void supla_led_blinking_func(void *timer_arg) {
  int val = digitalRead(LED_CONFIG_PIN);
  digitalWrite(LED_CONFIG_PIN, val == HIGH ? 0 : 1);
}

void supla_led_blinking(int led, int time) {

  os_timer_disarm(&led_timer);
  os_timer_setfn(&led_timer, supla_led_blinking_func, NULL);
  os_timer_arm (&led_timer, time, true);

}

void supla_led_blinking_stop(void) {
  os_timer_disarm(&led_timer);
  digitalWrite(LED_CONFIG_PIN, 1);
}

void supla_led_set(int ledPin) {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, 1);
}

void supla_ds18b20_start(void) {
  for (int i = 0; i < MAX_DS18B20; i++) {
    sensor[i].setOneWire(&ds18x20[i]);
    sensor[i].begin();
    if (sensor[i].getAddress(deviceAddress, 0)) sensor[i].setResolution(deviceAddress, TEMPERATURE_PRECISION);
  }
}

void supla_dht_start(void) {
  for (int i = 0; i < MAX_DHT; i++) {
    dht_sensor[i].begin();
  }
}

void add_Sensor(int sensor) {
  SuplaDevice.addSensorNO(sensor);
}

void add_Roller_Shutter_Buttons(int channel, int button1, int button2) {
  SuplaDevice.setRollerShutterButtons(channel, button1, button2);
}

void add_Roller_Shutter_Relays(int relay1, int relay2) {
  SuplaDevice.addRollerShutterRelays(relay1, relay2);
  //  SuplaDevice.setRollerShutterFuncImpl(&supla_rs_SavePosition, &supla_rs_LoadPosition, &supla_rs_SaveSettings, &supla_rs_LoadSettings);
}

void add_Led_Config(int led) {
  supla_led_set(led);
}

void add_Relay(int relay) {
  SuplaDevice.addRelay(relay);
  relay_button_channel[nr_relay] = relay;
  nr_relay++;
}

void add_Relay_Invert(int relay) {
  SuplaDevice.addRelay(relay, true);
  relay_button_channel[nr_relay] = relay;
  nr_relay++;
}

void add_DHT11_Thermometer(int thermpin) {
  int channel = SuplaDevice.addDHT11();
  dht_sensor[channel] = { thermpin, DHT11 };
  dht_channel[nr_dht] = channel;
  nr_dht++;
}

void add_DHT22_Thermometer(int thermpin) {
  int channel = SuplaDevice.addDHT22();
  dht_sensor[channel] = { thermpin, DHT22 };
  dht_channel[nr_dht] = channel;
  nr_dht++;
}

void add_DS18B20_Thermometer(int thermpin) {
  int channel = SuplaDevice.addDS18B20Thermometer();
  ds18x20[channel] = thermpin;
  ds18x20_channel[nr_dht] = channel;
  nr_ds18b20++;
}

void add_Relay_Button(int relay, int button, int type) {
  relay_button_channel[nr_relay] = relay;
  nr_button++;
  nr_relay++;
  if (type == CHOICE_TYPE) {
    int select_button = read_supla_button_type(nr_button);
    type = select_button;
  }

  SuplaDevice.addRelayButton(relay, button, type, read_supla_relay_flag(nr_relay));
}

void add_Relay_Button_Invert(int relay, int button, int type) {
  invert = 1;
  relay_button_channel[nr_relay] = relay;
  nr_button++;
  nr_relay++;
  if (type == CHOICE_TYPE) {
    int select_button = read_supla_button_type(nr_button);
    type = select_button;
  }

  SuplaDevice.addRelayButton(relay, button, type, read_supla_relay_flag(nr_relay), true);
}
