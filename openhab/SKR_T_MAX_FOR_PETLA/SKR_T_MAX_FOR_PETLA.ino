#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>



//PIERWSZA LITERA FUNKCJA S-PRZEŁĄCZNIK, H-GRZEJNIK, R-ROLETA
//PIERWSZA CYFRA- POZIOM 0-PARTER, 1-PIETRO
//2CYFRA POMIESZCZENIE 1-SALON, 2-KUCHNIA 3-ŁAZIENKA, 4-KORYTARZ, 5-SCHOWEK, 6-PRACOWNIA 7-SYPIALNIA, 8-1POKÓJ, 9-2POKÓJ
//
//OGRZEWANIE SZT.9
//SALON
const int H011B = 2;
const int H011 = 22;
String H011_1("H011#1");
String H011_0("H011#0");
//ŁAZIENKA
const int H031B = 2;
const int H031 = 23;
String H031_1("H031#1");
String H031_0("H031#0");
//KORYTARZ
const int H041B = 2;
const int H041 = 24;
String H041_1("H041#1");
String H041_0("H041#0");
//SCHOWEK
const int H051B = 2;
const int H051 = 25;
String H051_1("H051#1");
String H051_0("H051#0");
//PRACOWNIA
const int H061B = 2;
const int H061 = 26;
String H061_1("H061#1");
String H061_0("H061#0");
//ŁAZIEKA
const int H131B = 2;
const int H131 = 27;
String H131_1("H131#1");
String H131_0("H131#0");
//POKÓJ DZIECIĘCY1
const int H181B = 2;
const int H181 = 28;
String H181_1("H181#1");
String H181_0("H181#0");
//POKÓJ DZIECIĘCY2
const int H191B = 2;
const int H191 = 29;
String H19_1("H19#1");
String H19_0("H19#0");
//SYPIALNIA
const int H171B = 2;
const int H171 = 30;
String H171_1("H171#1");
String H171_0("H171#0");



//PIERWSZA LITERA FUNKCJA S-PRZEŁĄCZNIK, H-GRZEJNIK, R-ROLETA
//PIERWSZA CYFRA- POZIOM 0-PARTER, 1-PIETRO
//2CYFRA POMIESZCZENIE 1-SALON, 2-KUCHNIA 3-ŁAZIENKA, 4-KORYTARZ, 5-SCHOWEK, 6-PRACOWNIA 7-SYPIALNIA, 8-1POKÓJ, 9-2POKÓJ
//ROLETY SZT.7
//SALON
const int R011B = 2;
const int R011 = 31;
String R011_1("R011#1");
String R011_0("R011#0");
//KUCHNIA
const int R021B = 2;
const int R021 = 32;
String R021_1("R021#1");
String R021_0("R021#0");
//PRACOWNIA
const int R061B = 2;
const int R061 = 33;
String R061_1("R061#1");
String R061_0("R061#0");
//ŁAZIENKA PIETRO
const int R131B = 2;
const int R131 = 34;
String R131_1("R131#1");
String R131_0("R131#0");
//POKÓJ DZIECKA1
const int R181B = 2;
const int R181 = 35;
String R181_1("R181#1");
String R181_0("R181#0");
//POKÓJ DZIECKA2
const int R191B = 2;
const int R191 = 36;
String R191_1("R191#1");
String R191_0("R191#0");
//SYPIALNIA
const int R171B = 2;
const int R171 = 37;
String R171_1("R171#1");
String R171_0("R171#0");



//PIERWSZA LITERA FUNKCJA S-PRZEŁĄCZNIK, H-GRZEJNIK, R-ROLETA
//PIERWSZA CYFRA- POZIOM 0-PARTER, 1-PIETRO
//2CYFRA POMIESZCZENIE 1-SALON, 2-KUCHNIA 3-ŁAZIENKA, 4-KORYTARZ, 5-SCHOWEK, 6-PRACOWNIA 7-SYPIALNIA, 8-1POKÓJ, 9-2POKÓJ
//swiatła 22
//SALON
//STÓŁ
const int S011B = 2;
const int S011 = 38;
String S011_1("S011#1");
String S011_0("S011#0");
//KINKIET LED
const int S012B = 2;
const int S012 = 39;
String S012_1("S012#1");
String S012_0("S012#0");
//KUCHNIA
//SUFIT
const int S021B = 2;
const int S021 = 40;
String S021_1("S021#1");
String S021_0("S021#0");
//BLAT
const int S022B = 2;
const int S022 = 41;
String S022_1("S022#1");
String S022_0("S022#0");
//BLAT1
const int S023B = 2;
const int S023 = 42;
String S023_1("S023#1");
String S023_0("S023#0");
//ŁAZIENKA
//SUFIT
const int S031B = 2;
const int S031 = 43;
String S031_1("S031#1");
String S031_0("S031#0");
//LUSTRO
const int S032B = 2;
const int S032 = 44;
String S032_1("S032#1");
String S032_0("S032#0");
//KABINA
const int S033B = 2;
const int S033 = 45;
String S033_1("S033#1");
String S033_0("S033#0");
//KORYTARZ
//SCHODY
const int S041B = 2;
const int S041 = 46;
String S041_1("S041#1");
String S041_0("S041#0");
//SUFIT
const int S042B = 2;
const int S042 = 47;
String S042_1("S042#1");
String S042_0("S042#0");
//KINKIET LED
const int S043B = 2;
const int S043 = 48;
String S043_1("S043#1");
String S043_0("S043#0");
//KINKIET LED1
const int S044B = 2;
const int S044 = 49;
String S044_1("S044#1");
String S044_0("S044#0");
//GANEK
const int S045B = 2;
const int S045 = 50;
String S045_1("S045#1");
String S045_0("S045#0");
//SCHOWEK
//SUFIT
const int S051B = 2;
const int S051 = 51;
String S051_1("S051#1");
String S051_0("S051#0");
//PRACOWNIA
//SUFIT
const int S061B = 2;
const int S061 = 52;
String S061_1("S061#1");
String S061_0("S061#0");
//ŁAZIENKA PIERWSZE PIĘTRO
//LUSTRO
const int S131B = 2;
const int S131 = 53;
String S131_1("S131#1");
String S131_0("S131#0");
//KABINA
const int S132B = 2;
const int S132 = 51;
String S132_1("S132#1");
String S132_0("S132#0");
//POKÓJ DZIECIĘCY1
//SUFIT
const int S181B = 2;
const int S181 = 52;
String S181_1("S181#1");
String S181_0("S181#0");
//POKÓJ DZIECIĘCY2
//SUFIT
const int S191B = 2;
const int S191 = 53;
String S191_1("S191#1");
String S191_0("S191#0");
//SYPIALNIA
//SUFIT
const int S171B =2 ;
const int S171 = 54;
String S171_1("S171#1");
String S171_0("S171#0");
//LED
const int S172B = 2;
const int S172 = 55;
String S172_1("S172#1");
String S172_0("S172#0");
//KORYTARZ NA PIĘTRZE
//SCHODY
const int S141B = 2;
const int S141 = 56;
String S141_1("S141#1");
String S141_0("S141#0");
//SUFIT
const int S142B =2 ;
const int S142 = 57;
String S142_1("S142#1");
String S142_0("S142#0");



//PIERWSZA LITERA FUNKCJA S-PRZEŁĄCZNIK, H-GRZEJNIK, R-ROLETA
//PIERWSZA CYFRA- POZIOM 0-PARTER, 1-PIETRO
//2CYFRA POMIESZCZENIE 1-SALON, 2-KUCHNIA 3-ŁAZIENKA, 4-KORYTARZ, 5-SCHOWEK, 6-PRACOWNIA 7-SYPIALNIA, 8-1POKÓJ, 9-2POKÓJ
//STANY
//OGRZEWANIE
//SALON
int H011BS;
int H011S = LOW;
//ŁAZIENKA
int H021BS;
int H021S = LOW;
//KORYTARZ
int H041BS;
int H041S = LOW;
//SCHOWEK
int H051BS;
int H051S = LOW;
//PRACOWNIA
int H061BS;
int H061S = LOW;
//ŁAZIENKA FF
int H131BS;
int H131S = LOW;
//POKÓJ DZIECIĘCY1
int H181BS;
int H181S = LOW;
//POKÓJ DZIECIĘCY2
int H191BS;
int H191S = LOW;
//SYPIALNIA
int H171BS;
int H171S = LOW;



//PIERWSZA LITERA FUNKCJA S-PRZEŁĄCZNIK, H-GRZEJNIK, R-ROLETA
//PIERWSZA CYFRA- POZIOM 0-PARTER, 1-PIETRO
//2CYFRA POMIESZCZENIE 1-SALON, 2-KUCHNIA 3-ŁAZIENKA, 4-KORYTARZ, 5-SCHOWEK, 6-PRACOWNIA 7-SYPIALNIA, 8-1POKÓJ, 9-2POKÓJ
//ROLETY
//SALON
int R011BS;
int R011S = LOW;
//KUCHNIA
int R021BS;
int R021S = LOW;
//PRACOWNIA
int R061BS;
int R061S = LOW;
//ŁAZIENKA
int R131RS;
int R131S = LOW;
//POKÓJ DZIECIĘCY1
int R181BS;
int R181S = LOW;
//POKÓJ DZIECIĘCY2
int R191BS;
int R191S = LOW;
//SYPIALNIA
int R171BS;
int R171S = LOW;



//PIERWSZA LITERA FUNKCJA S-PRZEŁĄCZNIK, H-GRZEJNIK, R-ROLETA
//PIERWSZA CYFRA- POZIOM 0-PARTER, 1-PIETRO
//2CYFRA POMIESZCZENIE 1-SALON, 2-KUCHNIA 3-ŁAZIENKA, 4-KORYTARZ, 5-SCHOWEK, 6-PRACOWNIA 7-SYPIALNIA, 8-1POKÓJ, 9-2POKÓJ
//OSWIETLENIE
//SALON
//STÓŁ
int S011BS;
int S011S = LOW;
//KINKIET
int S012BS;
int S012S = LOW;
//KUCHNIA
//SUFIT
int S021BS;
int S021S = LOW;
//BLAT1
int S022BS;
int S022S = LOW;
//BLAT2
int S023BS;
int S023S = LOW;
//ŁAZIENKA
//SUFIT
int S031BS;
int S031S = LOW;
//LUSTRO
int S032BS;
int S032S = LOW;
//KABINA
int S033BS;
int S033S = LOW;
//KORYTARZ
//SCHODY
int S041BS;
int S041S = LOW;
//SUFIT
int S042BS;
int S042S = LOW;
//KINKIET1
int S043BS;
int S043S = LOW;
//KINKIET2
int S044BS;
int S044S = LOW;
//GANEK
int S045BS;
int S045S = LOW;
//SCHOWEK
//SUFIT
int S051BS;
int S051S = LOW;
//PRACOWNIA
//SUFIT
int S061BS;
int S061S = LOW;
//ŁAZIENKA
//LUSTRO
int S131BS;
int S131S = LOW;
//KABINA
int S132BS;
int S132S = LOW;
//POKÓJ DZIECIĘCY1
//SUFIT
int S181BS;
int S181S = LOW;
//POKÓJ DZIECIĘCY2
//SUFIT
int S191BS;
int S191S = LOW;
//SYPIALNIA
//SUFIT
int S171BS;
int S171S = LOW;
//LED
int S172BS;
int S172S = LOW;
//KORYTARZ
//SCHODY
int S141BS;
int S141S = LOW;
//SUFIT
int S142BS;
int S142S = LOW;



const int AFTER_CHANGE_DELAY = 500;

byte mqtt_server[] = { 192, 168, 1, 103 };
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

IPAddress ip(192, 168, 1, 5);


void setup() {
  for( int x = 0, y = 0, z=0; x<9, y<9, z<9; x++, y++, z++ ){
  Serial.begin(9600);
  initializeMqtt();
  initializeOut();
  initializeNetwork();
}
}
void loop() { 
//  checkS();
//  checkR();
//  checkH();
  checkMqtt();
}
void initializeNetwork() {
  Ethernet.begin(mac, ip);
}

void callback(char* topic, byte* payload, unsigned int length) {
  payload[length] = '\0';
  String strPayload = String((char*)payload);
  Serial.print("IN: ");
  Serial.println(strPayload);
  executeRemoteCommand(strPayload);
}

EthernetClient client;
PubSubClient mqtt_client(mqtt_server, 1883, callback, client);

void sendMqttState(String state) {
  Serial.print("STATE: ");
  Serial.print(state);
  /*
    konieczna weryfikacja czy mamy aktywne poĹ‚Ä…czenie
    jeĹ›li nie, trzeba je odnowiÄ‡
  */
  boolean connected = mqtt_client.connected();
  if (!connected) {
    initializeMqtt();
  }
  char ssid[state.length() + 1];
  state.toCharArray(ssid, state.length() + 1);
  boolean publishState = mqtt_client.publish("/GF_LivingIn", ssid);
  Serial.print(" published: ");
  Serial.println(publishState);
}

void initializeMqtt()
{
  if (mqtt_client.connect("arduinoClient", "admin", "admin")) {
    mqtt_client.subscribe("/GF_Living");
    Serial.println("MQTT connect OK");
  } else {
    Serial.println("MQTT connect failed");
  }
}

void checkMqtt()
{
  mqtt_client.loop();
}
void initializeOut() {
  //OGRZEWANIE SZT.9
  //SALON
  pinMode(H011, OUTPUT);
  pinMode(H011B, INPUT_PULLUP);
  //ŁAZIENKA
  pinMode(H031, OUTPUT);
  pinMode(H031B, INPUT_PULLUP);
  //KORYTARZ
  pinMode(H041, OUTPUT);
  pinMode(H041B, INPUT_PULLUP);
  //SCHOWEK
  pinMode(H051, OUTPUT);
  pinMode(H051B, INPUT_PULLUP);
  //PRACOWNIA
  pinMode(H061, OUTPUT);
  pinMode(H061B, INPUT_PULLUP);
  //ŁAZIENKA FF
  pinMode(H131, OUTPUT);
  pinMode(H131B, INPUT_PULLUP);
  //POKÓJ DZIECIĘCY1
  pinMode(H181, OUTPUT);
  pinMode(H181B, INPUT_PULLUP);
  //POKÓJ DZIECIĘCY2
  pinMode(H191, OUTPUT);
  pinMode(H191B, INPUT_PULLUP);
  //SYPIALNIA
  pinMode(H171, OUTPUT);
  pinMode(H171B, INPUT_PULLUP);


  
  //ROLETY SZT.7
  //SALON
  pinMode(R011, OUTPUT);
  pinMode(R011B, INPUT_PULLUP);
  //KUCHNIA
  pinMode(R021, OUTPUT);
  pinMode(R021B, INPUT_PULLUP);
  //PRACOWNIA
  pinMode(R061, OUTPUT);
  pinMode(R061B, INPUT_PULLUP);
  //ŁAZIENKA PIETRO
  pinMode(R131, OUTPUT);
  pinMode(R131B, INPUT_PULLUP);
  //POKÓJ DZIECKA1
  pinMode(R181, OUTPUT);
  pinMode(R181B, INPUT_PULLUP);
  //POKÓJ DZIECKA2
  pinMode(R191, OUTPUT);
  pinMode(R191B, INPUT_PULLUP);
  //SYPIALNIA
  pinMode(R171, OUTPUT);
  pinMode(R171B, INPUT_PULLUP);


  
  //ŚWIATŁA 22
  //SALON
  pinMode(S011, OUTPUT);
  pinMode(S011B, INPUT_PULLUP);
  //KINKIET LED
  pinMode(S012, OUTPUT);
  pinMode(S012B, INPUT_PULLUP);
  //KUCHNIA
  //SUFIT
  pinMode(S021, OUTPUT);
  pinMode(S021B, INPUT_PULLUP);
  //BLAT
  pinMode(S022, OUTPUT);
  pinMode(S022B, INPUT_PULLUP);
  //BLAT1
  pinMode(S023, OUTPUT);
  pinMode(S023B, INPUT_PULLUP);
  //ŁAZIENKA
  //SUFIT
  pinMode(S031, OUTPUT);
  pinMode(S031B, INPUT_PULLUP);
  //LUSTRO
  pinMode(S032, OUTPUT);
  pinMode(S032B, INPUT_PULLUP);
  //KABINA
  pinMode(S033, OUTPUT);
  pinMode(S033B, INPUT_PULLUP);
  //KORYTARZ
  //SCHODY
  pinMode(S041, OUTPUT);
  pinMode(S041B, INPUT_PULLUP);
  //SUFIT
  pinMode(S042, OUTPUT);
  pinMode(S042B, INPUT_PULLUP);
  //KINKIET LED1
  pinMode(S043, OUTPUT);
  pinMode(S043B, INPUT_PULLUP);
  //KINKIET LED2
  pinMode(S044, OUTPUT);
  pinMode(S044B, INPUT_PULLUP);
  //GANEK
  pinMode(S045, OUTPUT);
  pinMode(S045B, INPUT_PULLUP);
  //SCHOWEK
  //SUFIT
  pinMode(S051, OUTPUT);
  pinMode(S051B, INPUT_PULLUP);
  //PRACOWNIA
  //SUFIT
  pinMode(S061, OUTPUT);
  pinMode(S061B, INPUT_PULLUP);
  //ŁAZIENKA PIERWSZE PIĘTRO
  //LUSTRO
  pinMode(S131, OUTPUT);
  pinMode(S131B, INPUT_PULLUP);
  //KABINA
  pinMode(S132, OUTPUT);
  pinMode(S132B, INPUT_PULLUP);
  //POKÓJ DZIECIĘCY1
  //SUFIT
  pinMode(S181, OUTPUT);
  pinMode(S181B, INPUT_PULLUP);
  //POKÓJ DZIECIĘCY2
  //SUFIT
  pinMode(S191, OUTPUT);
  pinMode(S191B, INPUT_PULLUP);
  //SYPIALNIA
  //SUFIT
  pinMode(S171, OUTPUT);
  pinMode(S171B, INPUT_PULLUP);
  //LED
  pinMode(S172, OUTPUT);
  pinMode(S172B, INPUT_PULLUP);
  //KORYTARZ NA PIĘTRZE
  //SCHODY
  pinMode(S141, OUTPUT);
  pinMode(S141B, INPUT_PULLUP);
  //SUFIT
  pinMode(S142, OUTPUT);
  pinMode(S142B, INPUT_PULLUP);
  for( int x = 0, y = 0, z=0; x<9, y<9, z<9; x++, y++, z++ ){
    HxyzSS(LOW);
    RxyzSS(LOW);
    SxyzSS(LOW);
  }
}



void executeRemoteCommand(String command) {
  Serial.println(command);


  
  //OGRZEWANIE
  //SALON
  if (command == Hxyz_1) {
    HxyzSS(HIGH);
  }
  if (command == Hxyz_0) {
    HxyzSS(LOW);
  }
  
  //ROLETY
  //SALON
  if (command == Rxyz_1) {
    RxyzSS(HIGH);
  }
  if (command == Rxyz_0) {
    RxyzSS(LOW);
  }
  
  //SWIATŁA
  //SALON
  //STÓŁ
    if (command == Sxyz_1) {
    SxyzSS(HIGH);
  }
  if (command == Sxyz_0) {
    SxyzSS(LOW);
  }
}

void checkH(){

  HxyzBS = digitalRead(HxyzB);
  if (HxyzBS == LOW) {
    toogleHxyz();
    delay(AFTER_CHANGE_DELAY);
  }
}

  void checkR(){

  RxyzBS = digitalRead(RxyzB);
  if (RxyzBS == LOW) {
    toogleRxyz();
    delay(AFTER_CHANGE_DELAY);
  }
}
  void checkS(){

  SxyzBS = digitalRead(SxyzB);
  if (SxyzBS == LOW) {
    toogleSxyz();
    delay(AFTER_CHANGE_DELAY);
  } 
}
void HxyzSS(int state) {
  digitalWrite(Hxyz, state);
  HxyzS = state;
  if (state == LOW) {
    sendMqttState(Hxyz_0);
  } else {
    sendMqttState(Hxyz_1);
  }
}
void toogleHxyz() {
  if (HxyzS == LOW) {
    HxyzSS(HIGH);
  } else {
    HxyzSS(LOW);
  }
}
void RxyzSS(int state) {
  digitalWrite(Rxyz, state);
  RxyzS = state;
  if (state == LOW) {
    sendMqttState(Rxyz_0);
  } else {
    sendMqttState(Rxyz_1);
  }
}
void toogleRxyz() {
  if (RxyzS == LOW) {
    RxyzSS(HIGH);
  } else {
    RxyzSS(LOW);
  }
}
void SxyzSS(int state) {
  digitalWrite(Sxyz, state);
  SxyzS = state;
  if (state == LOW) {
    sendMqttState(Sxyz_0);
  } else {
    sendMqttState(Sxyz_1);
  }
}
void toogleSxyz() {
  if (SxyzS == LOW) {
    SxyzSS(HIGH);
  } else {
    SxyzSS(LOW);
  }
}

}

