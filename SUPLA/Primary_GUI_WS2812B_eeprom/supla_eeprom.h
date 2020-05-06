

#ifndef SUPLA_EEPROM_H
#define SUPLA_EEPROM_H

void Pokaz_zawartosc_eeprom();
void czyszczenieEEPROM(void);

void save_wifi_ssid(String save);
void save_wifi_pass(String save);
void save_login(String save);
void save_login_pass(String save);
void save_supla_server(String save);
void save_supla_id(String save);
void save_supla_pass(String save);
void save_supla_hostname(String save);
void save_guid(void);
void save_supla_button_type(int nr, String save);
void save_supla_relay_flag(int nr, String save);
void save_supla_relay_state(int nr, String save);
void save_supla_ws2812(String save);
void save_supla_ws2812_red(String save);
void save_supla_ws2812_green(String save);
void save_supla_ws2812_blue(String save);
void save_supla_ws2812_brightness(String save);

String read_wifi_ssid(void);
String read_wifi_pass(void);
String read_login(void);
String read_login_pass(void);
String read_supla_server(void);
String read_supla_id(void);
String read_supla_pass(void);
String read_supla_hostname(void);
String read_guid(void);
String read_supla_ws2812(void);
String read_supla_ws2812_red(void);
String read_supla_ws2812_green(void);
String read_supla_ws2812_blue(void);
String read_supla_ws2812_brightness(void);

int read_supla_button_type(int nr);
int read_supla_relay_flag(int nr);
int read_supla_relay_state(int nr);

#endif //SUPLA_EEPROM_H

