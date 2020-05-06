#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

const int HALOGEN_BUTTON_PIN = 6;
const int HALOGEN_RELAY_PIN = 52;
const int HALOGEN1_RELAY_PIN = 51;
const int HALOGEN2_RELAY_PIN = 50;
const int HALOGEN3_RELAY_PIN = 49;
String HALOGEN_ON_COMMAND("halogen#1");
String HALOGEN_OFF_COMMAND("halogen#0");
String HALOGEN1_ON_COMMAND("halogen#1");
String HALOGEN1_OFF_COMMAND("halogen#0");
String HALOGEN2_ON_COMMAND("halogen#1");
String HALOGEN2_OFF_COMMAND("halogen#0");
String HALOGEN3_ON_COMMAND("halogen#1");
String HALOGEN3_OFF_COMMAND("halogen#0");
const int AFTER_CHANGE_DELAY = 500;

int halogenButtonState;
int halogenState = LOW;

//numer IP komputera na którym jest uruchomiony serwer mqtt
byte mqtt_server[] = { 192,168, 1, 103 };
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

IPAddress ip(192, 168, 1, 5);


void setup() {
  Serial.begin(9600);
  initializeMqtt();
  initializeHalogen();
  initializeNetwork();
}

void loop() {
  checkHalogen();
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
konieczna weryfikacja czy mamy aktywne połączenie
jeśli nie, trzeba je odnowić
*/
  boolean connected = mqtt_client.connected();
  if (!connected) {
     initializeMqtt();
  }
  char ssid[state.length()+1];        
  state.toCharArray(ssid, state.length()+1);
  boolean publishState = mqtt_client.publish("/houseIn", ssid); 
  Serial.print(" published: ");
  Serial.println(publishState);
}

void initializeMqtt(){
  if (mqtt_client.connect("arduinoClient", "admin", "admin")) {
    mqtt_client.subscribe("/house");
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
  //halogen0
  if (command == HALOGEN_ON_COMMAND) {
    setHalogenState(HIGH);
  }
  if (command == HALOGEN_OFF_COMMAND) {
    setHalogenState(LOW);
  }
  //halogen1
  if (command == HALOGEN1_ON_COMMAND) {
    setHalogenState(HIGH);
  }
  if (command == HALOGEN1_OFF_COMMAND) {
    setHalogenState(LOW);
  }
  //halogen2
  if (command == HALOGEN2_ON_COMMAND) {
    setHalogenState(HIGH);
  }
  if (command == HALOGEN2_OFF_COMMAND) {
    setHalogenState(LOW);
  }
  //halogen3
  if (command == HALOGEN3_ON_COMMAND) {
    setHalogenState(HIGH);
  }
  if (command == HALOGEN3_OFF_COMMAND) {
    setHalogenState(LOW);
  }
}

void initializeHalogen() {
  //halogen0
    pinMode(HALOGEN_BUTTON_PIN, INPUT_PULLUP);
    pinMode(HALOGEN_RELAY_PIN, OUTPUT);
    setHalogenState(LOW);
    //haloge1
//    pinMode(HALOGEN1_BUTTON_PIN, INPUT_PULLUP);
    pinMode(HALOGEN1_RELAY_PIN, OUTPUT);
    setHalogenState(LOW);
    //halogen2
//    pinMode(HALOGEN_BUTTON_PIN, INPUT_PULLUP);
    pinMode(HALOGEN2_RELAY_PIN, OUTPUT);
    setHalogenState(LOW);
    //halogen3
//    pinMode(HALOGEN3_BUTTON_PIN, INPUT_PULLUP);
    pinMode(HALOGEN3_RELAY_PIN, OUTPUT);
    setHalogenState(LOW);
    
  
}
void checkHalogen() {
  halogenButtonState = digitalRead(HALOGEN_BUTTON_PIN);
  if (halogenButtonState == LOW) {
    toogleHalogen();   
   delay(AFTER_CHANGE_DELAY);
  }
}

void setHalogenState(int state) {
     digitalWrite(HALOGEN_RELAY_PIN, state);
      halogenState = state;
      if (state == LOW) {
        sendMqttState(HALOGEN_OFF_COMMAND);
      } else {
                sendMqttState(HALOGEN_ON_COMMAND);
      }
}
void setHalogen1State(int state) {
     digitalWrite(HALOGEN1_RELAY_PIN, state);
      halogenState = state;
      if (state == LOW) {
        sendMqttState(HALOGEN1_OFF_COMMAND);
      } else {
                sendMqttState(HALOGEN1_ON_COMMAND);
      }
}
void setHalogen2State(int state) {
     digitalWrite(HALOGEN2_RELAY_PIN, state);
      halogenState = state;
      if (state == LOW) {
        sendMqttState(HALOGEN2_OFF_COMMAND);
      } else {
                sendMqttState(HALOGEN2_ON_COMMAND);
      }
}
void setHalogen3State(int state) {
     digitalWrite(HALOGEN3_RELAY_PIN, state);
      halogenState = state;
      if (state == LOW) {
        sendMqttState(HALOGEN3_OFF_COMMAND);
      } else {
                sendMqttState(HALOGEN3_ON_COMMAND);
      }
}

void toogleHalogen() {
  if (halogenState == LOW) {
      setHalogenState(HIGH);
    } else {
      setHalogenState(LOW);
    }
}




