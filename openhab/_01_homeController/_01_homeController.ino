
void setup() {
  Serial.begin(9600);
  initializeNetwork();
  initializeSalonLed();


}

void loop() {
  checkSalonLed();
  checkNetwork();
}
String SALON_LED_REMOTE_COMMAND("salonled#");
const int SALON_LED_BUTTON_PIN = 2;
const int SALON_LED_RELAY_PIN = 3;

const int SALON_LED_AFTER_CHANGE_DELAY = 500;

int salonLedButtonState;
int salonLedState = LOW;

void initializeSalonLed() {
    pinMode(SALON_LED_BUTTON_PIN, INPUT);
    pinMode(SALON_LED_RELAY_PIN, OUTPUT);
    setSalonLedState(HIGH);
  
}

void checkSalonLed() {
  salonLedButtonState = digitalRead(SALON_LED_BUTTON_PIN);
  if (salonLedButtonState == HIGH) {
    toogleSalonLed();   
    delay(SALON_LED_AFTER_CHANGE_DELAY);
  }
}

void setSalonLedState(int state) {
     digitalWrite(SALON_LED_RELAY_PIN, state);
      salonLedState = state;
          sendTcpState(SALON_LED_REMOTE_COMMAND + state);
}

void toogleSalonLed() {
  if (salonLedState == LOW) {
      setSalonLedState(HIGH);
    } else {
      setSalonLedState(LOW);
    }
}
#include <SPI.h>         // needed for Arduino versions later than 0018
#include <Ethernet.h>
#include <EthernetUdp.h>         // UDP library from: bjoern@cs.stanford.edu 12/30/2008

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

IPAddress ip(192, 168, 1, 5);
IPAddress responseIp(192, 168, 0, 12);  //IP number to send response (Ip of OpenHab Server)
unsigned int responsePort = 25001;      //  port to send response -set in OpenHab configuration
unsigned int localPort = 8888;      // local port to listen on
EthernetServer server(localPort);
EthernetClient client;
char packetBuffer[UDP_TX_PACKET_MAX_SIZE]; //buffer to hold incoming packet,
char  ReplyBuffer[] = "acknowledged";       // a string to send back

void initializeNetwork() {
  Ethernet.begin(mac, ip);
}

void checkNetwork() {  
  EthernetClient client = server.available();
  if (client) {
    String clientMsg ="";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        clientMsg+=c;//store the recieved chracters in a string
        if (c == '#') {
          Serial.println("Message from Client:"+clientMsg);//print it to the serial
          executeRemoteCommand(clientMsg);
          client.stop();
        }
      }
    }
    
  }
  delay(10);
}

void executeRemoteCommand(String command) {
  if (command == SALON_LED_REMOTE_COMMAND) {
    toogleSalonLed();

  }

}

void sendTcpState(String command) {

if (client.connect(responseIp, responsePort)) {
    Serial.println("connected");//report it to the Serial
    Serial.println("sending Message:"+command);//log to serial
    client.print(command);//send the message
    client.stop();
  }
  else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
}
