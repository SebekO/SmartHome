#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

const int STOL_BUTTON_PIN = 6;
const int STOL_RELAY_PIN = 3;
const int OGRZEW_BUTTON_PIN = 5;
const int OGRZEW_RELAY_PIN = 2;
String STOL_ON_COMMAND("stol#1");
String STOL_OFF_COMMAND("stol#0");
String OGRZEW_ON_COMMAND("ogrzew#1");
String OGRZEW_OFF_COMMAND("ogrzew#0");
const int AFTER_CHANGE_DELAY = 500;

int stolButtonState;
int stolState = LOW;
int ogrzewButtonState;
int ogrzewState = LOW;

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
  checkStol();
  checkOgrzew();
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

void setStolState(int state) {
  digitalWrite(STOL_RELAY_PIN, state);
  stolState = state;
  if (state == LOW) {
    sendMqttState(STOL_OFF_COMMAND);
  } else {
    sendMqttState(STOL_ON_COMMAND);
  }
}

void checkOgrzew() {
  ogrzewButtonState = digitalRead(OGRZEW_BUTTON_PIN);
  if (ogrzewButtonState == LOW) {
    toogleOgrzew();
    delay(AFTER_CHANGE_DELAY);
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
void toogleStol() {
  if (stolState == LOW) {
    setStolState(HIGH);
  } else {
    setStolState(LOW);
  }
}


