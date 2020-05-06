
#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>
//OGRZEWANIE SZT.9
//SALON
const int Heating_GF_Living = 2;
String Heating_GF_Living_ON_COMMAND("Heating_GF_Living#1");
String Heating_GF_Living_OFF_COMMAND("Heating_GF_Living#0");
//ŁAZIENKA
const int Heating_GF_Bath = 2;
String Heating_GF_Bath_ON_COMMAND("Heating_GF_Bath#1");
String Heating_GF_Bath_OFF_COMMAND("Heating_GF_Bath#0");
//KORYTARZ
const int Heating_GF_Corridor = 2;
String Heating_GF_Corridor_ON_COMMAND("Heating_GF_Corridor#1");
String Heating_GF_Corridor_OFF_COMMAND("Heating_GF_Corridor#0");
//SCHOWEK
const int Heating_GF_Stash = 2;
String Heating_GF_Stash_ON_COMMAND("Heating_GF_Stash#1");
String Heating_GF_Stash_OFF_COMMAND("Heating_GF_Stash#0");
//PRACOWNIA
const int Heating_GF_Office = 2;
String Heating_GF_Office_ON_COMMAND("Heating_GF_Office#1");
String OHeating_GF_Office_OFF_COMMAND("Heating_GF_Office#0");
//ŁAZIEKA
const int Heating_FF_Bath = 2;
String Heating_FF_Bath_ON_COMMAND("Heating_FF_Bath#1");
String Heating_FF_Bath_OFF_COMMAND("Heating_FF_Bath#0");
//POKÓJ DZIECIĘCY1
const int Heating_FF_Child = 2;
String Heating_FF_Child_ON_COMMAND("Heating_FF_Child#1");
String Heating_FF_Child_OFF_COMMAND("Heating_FF_Child#0");
//POKÓJ DZIECIĘCY2
const int Heating_FF_Child1 = 2;
String Heating_FF_Child1_ON_COMMAND("Heating_FF_Child1#1");
String Heating_FF_Child1_OFF_COMMAND("Heating_FF_Child1#0");
//SYPIALNIA
const int Heating_FF_Bed = 2;
String Heating_FF_Bed_ON_COMMAND("Heating_FF_Bed#1");
String Heating_FF_Bed_OFF_COMMAND("Heating_FF_Bed#0");



//ROLETY SZT.7
//SALON
const int Shutter_GF_Living = ;
String Shutter_GF_Living_ON_COMMAND("Shutter_GF_Living#1");
String Shutter_GF_Living_OFF_COMMAND("Shutter_GF_Living#0");
//KUCHNIA
const int Shutter_GF_Kitchen = ;
String Shutter_GF_Kitchen_ON_COMMAND("Shutter_GF_Kitchen#1");
String Shutter_GF_Kitchen_OFF_COMMAND("Shutter_GF_Kitchen#0");
//PRACOWNIA
const int Shutter_GF_Office = ;
String Shutter_GF_Office_ON_COMMAND("Shutter_GF_Office#1");
String Shutter_GF_Office_OFF_COMMAND("Shutter_GF_Office#0");
//ŁAZIENKA PIETRO
const int Shutter_FF_Bath = ;
String Shutter_FF_Bath_ON_COMMAND("Shutter_FF_Bath#1");
String Shutter_FF_Bath_OFF_COMMAND("Shutter_FF_Bath#0");
//POKÓJ DZIECKA1
const int Shutter_FF_Child = ;
String Shutter_FF_Child_ON_COMMAND("Shutter_FF_Child#1");
String Shutter_FF_Child_OFF_COMMAND("Shutter_FF_Child#0");
//POKÓJ DZIECKA2
const int Shutter_FF_Child1 = ;
String Shutter_FF_Child1_ON_COMMAND("Shutter_FF_Child1#1");
String Shutter_FF_Child1_OFF_COMMAND("Shutter_FF_Child1#0");
//SYPIALNIA
const int Shutter_FF_Bed = ;
String Shutter_FF_Bed_ON_COMMAND("Shutter_FF_Bed#1");
String Shutter_FF_Bed_OFF_COMMAND("Shutter_FF_Bed#0");



//swiatła 22
//SALON
/STÓŁ
const int Light_GF_Living_Tablee_button = ;
const int Light_GF_Living_Table = ;
String Light_GF_Living_Table_ON_COMMAND("Light_GF_Living_Table#1");
String Light_GF_Living_Table_OFF_COMMAND("Light_GF_Living_Table#0");
/KINKIET LED
const int Light_GF_Living_LED_button = ;
const int Light_GF_Living_LED_Table = ;
String Light_GF_Living_LED_ON_COMMAND("Light_GF_Living_LED#1");
String Light_GF_Living_LED_OFF_COMMAND("Light_GF_Living_LED#0");
//KUCHNIA
/SUFIT
const int Light_GF_Kitchen_Ceiling_button = ;
const int Light_GF_Kitchen_Ceiling = ;
String Light_GF_Kitchen_Ceiling_ON_COMMAND("Light_GF_Kitchen_Ceiling#1");
String Light_GF_Kitchen_Ceiling_OFF_COMMAND("Light_GF_Kitchen_Ceiling#0");
/BLAT
const int Light_GF_Kitchen_Table_button = ;
const int Light_GF_Kitchen_Table = ;
String Light_GF_Kitchen_Table_ON_COMMAND("Light_GF_Kitchen_Table#1");
String Light_GF_Kitchen_Table_OFF_COMMAND("Light_GF_Kitchen_Table#0");
/BLAT1
const int Light_GF_Kitchen_Table1_button = ;
const int Light_GF_Kitchen_Table1 = ;
String Light_GF_Kitchen_Table1_ON_COMMAND("Light_GF_Kitchen_Table1#1");
String Light_GF_Kitchen_Table1_OFF_COMMAND("Light_GF_Kitchen_Table1#0");
//ŁAZIENKA
/SUFIT
const int Light_GF_Bath_Ceiling_button = ;
const int Light_GF_Bath_Ceiling = ;
String Light_GF_Bath_Ceiling_ON_COMMAND("Light_GF_Bath_Ceiling#1");
String Light_GF_Bath_Ceiling_OFF_COMMAND("Light_GF_Bath_Ceiling#0");
/LUSTRO
const int Light_GF_Bath_Mirror_button = ;
const int Light_GF_Bath_Mirror = ;
String Light_GF_Bath_Mirror_ON_COMMAND("Light_GF_Bath_Mirror#1");
String Light_GF_Bath_Mirror_OFF_COMMAND("Light_GF_Bath_Mirror#0");
/KABINA
const int Light_GF_Bath_Shower_button = ;
const int Light_GF_Bath_Shower = ;
String Light_GF_Bath_Shower_ON_COMMAND("Light_GF_Bath_Shower#1");
String Light_GF_Bath_Shower_OFF_COMMAND("Light_GF_Bath_Shower#0");
//KORYTARZ
/SCHODY
const int Light_GF_Corridor_Stairs_button = ;
const int Light_GF_Corridor_Stairs = ;
String Light_GF_Corridor_Stairs_ON_COMMAND("Light_GF_Corridor_Stairs#1");
String Light_GF_Corridor_Stairs_OFF_COMMAND("Light_GF_Corridor_Stairs#0");
/SUFIT
const int Light_GF_Corridor_Ceiling_button = ;
const int Light_GF_Corridor_Ceiling = ;
String Light_GF_Corridor_Ceiling_ON_COMMAND("Light_GF_Corridor_Ceiling#1");
String Light_GF_Corridor_Ceiling_OFF_COMMAND("Light_GF_Corridor_Ceiling#0");
/KINKIET LED
const int Light_GF_Corridor_LED_button = ;
const int Light_GF_Kitchen_Table = ;
String Light_GF_Corridor_LED_ON_COMMAND("Light_GF_Corridor_LED#1");
String Light_GF_Corridor_LED_OFF_COMMAND("Light_GF_Corridor_LED#0");
/KINKIET LED1
const int Light_GF_Corridor_LED1_button = ;
const int Light_GF_Corridor_LED1 = ;
String Light_GF_Corridor_LED1_ON_COMMAND("Light_GF_Corridor_LED1#1");
String Light_GF_Corridor_LED1_OFF_COMMAND("Light_GF_Corridor_LED1#0");
/GANEK
const int Light_GF_Corridor_Lobby_button = ;
const int Light_GF_Corridor_Lobby = ;
String Light_GF_Corridor_Lobby_ON_COMMAND("Light_GF_Corridor_Lobby#1");
String Light_GF_Corridor_Lobby_OFF_COMMAND("Light_GF_Corridor_Lobby#0");
//SCHOWEK
/SUFIT
const int Light_GF_Stash_Ceiling_button = ;
const int Light_GF_Stash_Ceiling = ;
String Light_GF_Stash_Ceiling_ON_COMMAND("Light_GF_Stash_Ceiling#1");
String Light_GF_Stash_Ceiling_OFF_COMMAND("Light_GF_Stash_Ceiling#0");
//PRACOWNIA
/SUFIT
const int Light_GF_Office_Ceiling_button = ;
const int Light_GF_Office_Ceiling = ;
String Light_GF_Office_Ceiling_ON_COMMAND("Light_GF_Office_Ceiling#1");
String Light_GF_Office_Ceiling_OFF_COMMAND("Light_GF_Office_Ceiling#0");
//ŁAZIENKA PIERWSZE PIĘTRO
/LUSTRO
const int Light_FF_Bath_Mirror_button = ;
const int Light_FF_Bath_Mirror = ;
String Light_FF_Bath_Mirror_ON_COMMAND("Light_FF_Bath_Mirror#1");
String Light_FF_Bath_Mirror_OFF_COMMAND("Light_FF_Bath_Mirror#0");
/KABINA
const int Light_FF_Bath_Schower_button = ;
const int Light_FF_Bath_Schower = ;
String Light_FF_Bath_Schower_ON_COMMAND("Light_FF_Bath_Schower#1");
String Light_FF_Bath_Schower_OFF_COMMAND("Light_FF_Bath_Schower#0");
//POKÓJ DZIECIĘCY1
/SUFIT
const int Light_FF_Child_Ceiling_button = ;
const int Light_FF_Child_Ceiling = ;
String Light_FF_Child_Ceiling_ON_COMMAND("Light_FF_Child_Ceiling#1");
String Light_FF_Child_Ceiling_OFF_COMMAND("Light_FF_Child_Ceiling#0");
//POKÓJ DZIECIĘCY2
/SUFIT
const int Light_FF_Child1_Ceiling_button = ;
const int Light_FF_Child1_Ceiling = ;
String Light_FF_Child1_Ceiling_ON_COMMAND("Light_FF_Child1_Ceiling#1");
String Light_FF_Child1_Ceiling_OFF_COMMAND("Light_FF_Child1_Ceiling#0");
//SYPIALNIA
/SUFIT
const int Light_FF_Bed_Ceiling_button = ;
const int Light_FF_Bed_Ceiling = ;
String Light_FF_Bed_Ceiling_ON_COMMAND("Light_FF_Bed_Ceiling#1");
String Light_FF_Bed_Ceiling_OFF_COMMAND("Light_FF_Bed_Ceiling#0");
/LED
const int Light_FF_Bed_LED_button = ;
const int Light_FF_Bed_LED = ;
String Light_FF_Bed_LED_ON_COMMAND("Light_FF_Bed_LED#1");
String Light_FF_Bed_LED_OFF_COMMAND("Light_FF_Bed_LED#0");
//KORYTARZ NA PIĘTRZE
/SCHODY
const int Light_FF_Corridor_Stairs_button = ;
const int Light_FF_Corridor_Stairs = ;
String Light_FF_Corridor_Stairs_ON_COMMAND("Light_FF_Corridor_Stairs#1");
String Light_FF_Corridor_Stairs_OFF_COMMAND("Light_FF_Corridor_Stairs#0");
/SUFIT
const int Light_FF_Corridor_Ceiling_button = ;
const int Light_FF_Corridor_Ceiling = ;
String Light_FF_Corridor_Ceiling_ON_COMMAND("Light_FF_Corridor_Ceiling#1");
String Light_FF_Corridor_Ceiling_OFF_COMMAND("Light_FF_Corridor_Ceiling#0");


//STANY
//OGRZEWANIE
/SALON
int Heating_GF_LivingButtonState;
int Heating_GF_LivingState = LOW;
/ŁAZIENKA
int Heating_GF_BathButtonState;
int Heating_GF_BathState = LOW;
/KORYTARZ
int Heating_GF_CorridorButtonState;
int Heating_GF_CorridorState = LOW;
/SCHOWEK
int Heating_GF_StashButtonState;
int Heating_GF_StashState = LOW;
/PRACOWNIA
int Heating_GF_OfficeButtonState;
int Heating_GF_OfficeState = LOW;
/ŁAZIENKA FF
int Heating_FF_BathButtonState;
int Heating_FF_BathState = LOW;
/POKÓJ DZIECIĘCY1
int Heating_FF_ChildButtonState;
int Heating_FF_ChildState = LOW;
/POKÓJ DZIECIĘCY2
int Heating_FF_Child1ButtonState;
int Heating_FF_Child1State = LOW;
/SYPIALNIA
int Heating_FF_BedButtonState;
int Heating_FF_BedState = LOW;



//ROLETY
/SALON
int Shutter_GF_LivingButtonState;
int Shutter_GF_LivingState = LOW;
/KUCHNIA
int Shutter_GF_KitchenButtonState;
int Shutter_GF_KitchenState = LOW;
/PRACOWNIA
int Shutter_GF_OfficeButtonState;
int Shutter_GF_OfficeState = LOW;
/ŁAZIENKA
int Shutter_FF_BathButtonState;
int Shutter_FF_BathState = LOW;
/POKÓJ DZIECIĘCY1
int Shutter_FF_ChildButtonState;
int Shutter_FF_ChildState = LOW;
/POKÓJ DZIECIĘCY2
int Heating_FF_Child1ButtonState;
int Heating_FF_Child1State = LOW;
/SYPIALNIA
int Shutter_FF_BedButtonState;
int Shutter_FF_BedState = LOW;



//OSWIETLENIE

int stolButtonState;
int stolState = LOW;
int ogrzewButtonState;
int ogrzewState = LOW;
int stolButtonState;
int stolState = LOW;
int ogrzewButtonState;
int ogrzewState = LOW;
int stolButtonState;
int stolState = LOW;
int ogrzewButtonState;
int ogrzewState = LOW;
int stolButtonState;
int stolState = LOW;
int ogrzewButtonState;
int ogrzewState = LOW;
int stolButtonState;
int stolState = LOW;
int ogrzewButtonState;
int ogrzewState = LOW;
int stolButtonState;
int stolState = LOW;
int ogrzewButtonState;
int ogrzewState = LOW;
int ogrzewButtonState;
int ogrzewState = LOW;
int ogrzewButtonState;
int ogrzewState = LOW;
int ogrzewButtonState;
int ogrzewState = LOW;
int ogrzewButtonState;
int ogrzewState = LOW;
int ogrzewButtonState;
int ogrzewState = LOW;
int ogrzewButtonState;
int ogrzewState = LOW;
int ogrzewButtonState;
int ogrzewState = LOW;
int ogrzewButtonState;
int ogrzewState = LOW;
int ogrzewButtonState;
int ogrzewState = LOW;
int ogrzewButtonState;
int ogrzewState = LOW;



const int AFTER_CHANGE_DELAY = 500;



void setup() {
  Serial.begin(9600);
  initializeMqtt();
  initializeOut();
  initializeNetwork();
}
void loop() {
  checkStol();
  checkOgrzew();
  checkMqtt();
}
void executeRemoteCommand(String command) {
  Serial.println(command);
  if (command == STOL_ON_COMMAND) {
    setStolState(HIGH);
  }
  if (command == STOL_OFF_COMMAND) {
    setStolState(LOW);
  }
  if (command == OGRZEW_ON_COMMAND) {
    setOgrzewState(HIGH);
  }
  if (command == OGRZEW_OFF_COMMAND) {
    setOgrzewState(LOW);
  }
}
void initializeOut() {
  pinMode(STOL_BUTTON_PIN, INPUT_PULLUP);
  pinMode(STOL_RELAY_PIN, OUTPUT);
  pinMode(OGRZEW_BUTTON_PIN, INPUT_PULLUP);
  pinMode(OGRZEW_RELAY_PIN, OUTPUT);
  setStolState(LOW);
  setOgrzewState(LOW);
}
void checkStol() {
  stolButtonState = digitalRead(STOL_BUTTON_PIN);
  if (stolButtonState == LOW) {
    toogleStol();
    delay(AFTER_CHANGE_DELAY);
  }
}
void checkOgrzew() {
  ogrzewButtonState = digitalRead(OGRZEW_BUTTON_PIN);
  if (ogrzewButtonState == LOW) {
    toogleOgrzew();
    delay(AFTER_CHANGE_DELAY);
  }
}

void setStolState(int state) {
  digitalWrite(STOL_RELAY_PIN, state);
  stolState = state;
  if (state == LOW) {
    sendMqttState(STOL_OFF_COMMAND);
  } else {
    sendMqttState(STOL_ON_COMMAND);
  }
}

void toogleStol() {
  if (stolState == LOW) {
    setStolState(HIGH);
  } else {
    setStolState(LOW);
  }
}

void setOgrzewState(int state) {
  digitalWrite(OGRZEW_RELAY_PIN, state);
  ogrzewState = state;
  if (state == LOW) {
    sendMqttState(OGRZEW_OFF_COMMAND);
  } else {
    sendMqttState(OGRZEW_ON_COMMAND);
  }
}

void toogleOgrzew() {
  if (ogrzewState == LOW) {
    setOgrzewState(HIGH);
  } else {
    setOgrzewState(LOW);
  }
}



