#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

//OGRZEWANIE SZT.9
//SALON
const int H011B = 2;
const int H011 = 9;
String H011_1("H011_1");
String H011_0("H011_0");
//ŁAZIENKA
const int H031B = 2;
const int H031 = 8;
String H031_1("H031_1");
String H031_0("H031_0");
//KORYTARZ
const int H041B = 2;
const int H041 = 7;
String H041_1("H041_1");
String H041_0("H041_0");
//SCHOWEK
const int H051B = 2;
const int H051 = 6;
String H051_1("H051_1");
String H051_0("H051_0");
//PRACOWNIA
const int H061B = 2;
const int H061 = 5;
String H061_1("H061_1");
String H061_0("H061_0");
//ŁAZIEKA
const int H131B = 2;
const int H131 = 3;
String H131_1("H131_1");
String H131_0("H131_0");
//POKÓJ DZIECIĘCY1
const int H181B = 2;
const int H181 = 30;
String H181_1("H181_1");
String H181_0("H181_0");
//POKÓJ DZIECIĘCY2
const int H191B = 2;
const int H191 = 30;
String H191_1("H191_1");
String H191_0("H191_0");
//SYPIALNIA
const int H171B = 2;
const int H171 = 30;
String H171_1("H171_1");
String H171_0("H171_0");

const int AFTER_CHANGE_DELAY = 500;

//OGRZEWANIE
//SALON
int H011BS;
int H011S = LOW;
//ŁAZIENKA
int H031BS;
int H031S = LOW;
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




//numer IP komputera na ktĂłrym jest uruchomiony serwer mqtt
byte mqtt_server[] = { 192, 168, 1, 103 };
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

IPAddress ip(192, 168, 1, 5);


void setup() {
  Serial.begin(9600);
  initializeMqtt();
  initializeOut();
  initializeNetwork();
}
void loop() {
 checkH011SS();
 checkH031SS();
 checkH041SS();
 checkH051SS();
 checkH061SS();
 checkH131SS();
 checkH181SS();
 checkH191SS();
 checkH171SS();
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
  boolean publishState = mqtt_client.publish("/heaterIn", ssid);
  Serial.print(" published: ");
  Serial.println(publishState);
}

void initializeMqtt()
{
  if (mqtt_client.connect("arduinoClient", "admin", "admin")) {
    mqtt_client.subscribe("/heater");
    Serial.println(" MQTT connect OK");
  } else {
    Serial.println(" MQTT connect failed");
  }
}

void checkMqtt()
{
  mqtt_client.loop();
}

void executeRemoteCommand(String command) {
  Serial.println(command);
 //OGRZEWANIE
  //SALON
  if (command == H011_1) {
    H011SS(HIGH);
  }
  if (command == H011_0) {
    H011SS(LOW);
  }
  //ŁAZIENKA
  if (command == H031_1) {
    H031SS(HIGH);
  }
  if (command == H031_0) {
    H031SS(LOW);
  }
  //KORYTARZ
    if (command == H041_1) {
    H041SS(HIGH);
  }
  if (command == H041_0) {
    H041SS(LOW);
  }
  //SCHOWEK
  if (command == H051_1) {
    H051SS(HIGH);
  }
  if (command == H051_0) {
    H051SS(LOW);
  }
  //PRACOWNIA
    if (command == H061_1) {
    H061SS(HIGH);
  }
  if (command == H061_0) {
    H061SS(LOW);
  }
  //ŁAZIENKA
  if (command == H131_1) {
    H131SS(HIGH);
  }
  if (command == H131_0) {
    H131SS(LOW);
  }
  //POKÓJ DZIECIĘCY1
    if (command == H181_1) {
    H181SS(HIGH);
  }
  if (command == H181_0) {
    H181SS(LOW);
  }
  //POKÓJ DZIECIĘCY2
  if (command == H191_1) {
    H191SS(HIGH);
  }
  if (command == H191_0) {
    H191SS(LOW);
  }
  //SYPIALNIA
    if (command == H171_1) {
    H171SS(HIGH);
  }
  if (command == H171_0) {
    H171SS(LOW);
  }
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
  H011SS(LOW);
  H031SS(LOW);
  H041SS(LOW);
  H051SS(LOW);
  H061SS(LOW);
  H131SS(LOW);
  H181SS(LOW);
  H191SS(LOW);
  H171SS(LOW);

}
void checkH011SS(){
  H011BS = digitalRead(H011B);
  if (H011BS == LOW) {
    toogleH011();
    delay(AFTER_CHANGE_DELAY);
  }
}
void H011SS(int state) {
  digitalWrite(H011, state);
  H011S = state;
  if (state == LOW) {
    sendMqttState(H011_0);
  } else {
    sendMqttState(H011_1);
  }
}
void toogleH011() {
  if (H011S == LOW) {
    H011SS(HIGH);
  } else {
    H011SS(LOW);
  }
}




void checkH031SS(){
  H031BS = digitalRead(H031B);
  if (H031BS == LOW) {
    toogleH031();
    delay(AFTER_CHANGE_DELAY);
  }
}
void H031SS(int state) {
  digitalWrite(H031, state);
  H031S = state;
  if (state == LOW) {
    sendMqttState(H031_0);
  } else {
    sendMqttState(H031_1);
  }
}
void toogleH031() {
  if (H031S == LOW) {
    H031SS(HIGH);
  } else {
    H031SS(LOW);
  }
}



void checkH041SS(){
  H041BS = digitalRead(H041B);
  if (H041BS == LOW) {
    toogleH041();
    delay(AFTER_CHANGE_DELAY);
  }
}
void H041SS(int state) {
  digitalWrite(H041, state);
  H041S = state;
  if (state == LOW) {
    sendMqttState(H041_0);
  } else {
    sendMqttState(H041_1);
  }
}
void toogleH041() {
  if (H041S == LOW) {
    H041SS(HIGH);
  } else {
    H041SS(LOW);
  }
}



void checkH051SS(){
  H051BS = digitalRead(H051B);
  if (H051BS == LOW) {
    toogleH051();
    delay(AFTER_CHANGE_DELAY);
  }
}
void H051SS(int state) {
  digitalWrite(H051, state);
  H051S = state;
  if (state == LOW) {
    sendMqttState(H051_0);
  } else {
    sendMqttState(H051_1);
  }
}
void toogleH051() {
  if (H051S == LOW) {
    H051SS(HIGH);
  } else {
    H051SS(LOW);
  }
}



void checkH061SS(){
  H061BS = digitalRead(H061B);
  if (H061BS == LOW) {
    toogleH061();
    delay(AFTER_CHANGE_DELAY);
  }
}
void H061SS(int state) {
  digitalWrite(H061, state);
  H061S = state;
  if (state == LOW) {
    sendMqttState(H061_0);
  } else {
    sendMqttState(H061_1);
  }
}
void toogleH061() {
  if (H061S == LOW) {
    H061SS(HIGH);
  } else {
    H061SS(LOW);
  }
}



void checkH131SS(){
  H131BS = digitalRead(H131B);
  if (H131BS == LOW) {
    toogleH131();
    delay(AFTER_CHANGE_DELAY);
  }
}
void H131SS(int state) {
  digitalWrite(H131, state);
  H131S = state;
  if (state == LOW) {
    sendMqttState(H131_0);
  } else {
    sendMqttState(H131_1);
  }
}
void toogleH131() {
  if (H131S == LOW) {
    H131SS(HIGH);
  } else {
    H131SS(LOW);
  }
}



void checkH181SS(){
  H181BS = digitalRead(H181B);
  if (H181BS == LOW) {
    toogleH181();
    delay(AFTER_CHANGE_DELAY);
  }
}
void H181SS(int state) {
  digitalWrite(H181, state);
  H181S = state;
  if (state == LOW) {
    sendMqttState(H181_0);
  } else {
    sendMqttState(H181_1);
  }
}
void toogleH181() {
  if (H181S == LOW) {
    H181SS(HIGH);
  } else {
    H181SS(LOW);
  }
}



void checkH191SS(){
  H191BS = digitalRead(H191B);
  if (H191BS == LOW) {
    toogleH191();
    delay(AFTER_CHANGE_DELAY);
  }
}
void H191SS(int state) {
  digitalWrite(H191, state);
  H191S = state;
  if (state == LOW) {
    sendMqttState(H191_0);
  } else {
    sendMqttState(H191_1);
  }
}
void toogleH191() {
  if (H191S == LOW) {
    H191SS(HIGH);
  } else {
    H191SS(LOW);
  }
}



void checkH171SS(){
  H171BS = digitalRead(H171B);
  if (H171BS == LOW) {
    toogleH171();
    delay(AFTER_CHANGE_DELAY);
  }
}
void H171SS(int state) {
  digitalWrite(H171, state);
  H171S = state;
  if (state == LOW) {
    sendMqttState(H171_0);
  } else {
    sendMqttState(H171_1);
  }
}
void toogleH171() {
  if (H171S == LOW) {
    H171SS(HIGH);
  } else {
    H171SS(LOW);
  }
}


