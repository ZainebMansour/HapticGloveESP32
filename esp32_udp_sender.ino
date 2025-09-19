#include <WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "YourWiFi";      
const char* password = "YourPassword";

WiFiUDP udp;
const char* udpAddress = "192.168.1.100"; // PC/Unity IP
const int udpPort = 4210;

// Potentiometer pins
int potPins[5] = {34, 35, 32, 33, 25}; 
int values[5];

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  udp.begin(udpPort);
}

void loop() {
  for (int i = 0; i < 5; i++) {
    values[i] = analogRead(potPins[i]);
  }
  char buffer[64];
  sprintf(buffer, "%d,%d,%d,%d,%d", values[0], values[1], values[2], values[3], values[4]);
  
  udp.beginPacket(udpAddress, udpPort);
  udp.print(buffer);
  udp.endPacket();
  
  delay(50);
}
