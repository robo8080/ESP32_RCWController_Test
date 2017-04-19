/*
 * RCWController Test Program
 * for ESP-WROOM-32
 * 2017/4/3 by robo8080
 */
 
#include <WiFi.h>
#include <WiFiUdp.h>
#include "RCWController.h"

const char ssid[] = "ESP32-RCWC";  //  your network SSID (name)
const char pass[] = "esp32pass";  // your network password

WiFiUDP udp;
unsigned int localPort = 10000;
const int PACKET_SIZE = 256;
char packetBuffer[PACKET_SIZE];

void setup() {
  Serial.begin(115200);

  WiFi.softAP(ssid, pass);
  IPAddress myIP = WiFi.softAPIP();

  Serial.print("AP IP address: ");
  Serial.println(myIP);

  Serial.println("Starting UDP");
  udp.begin(localPort);
  Serial.print("Local port: ");
  Serial.println(localPort);

}

void loop() {
  int rlen;

  while (1) {
    rlen = udp.parsePacket();
    if(rlen<10) {
      delay(10);
      continue;
    }

    udp.read(packetBuffer, (rlen > PACKET_SIZE) ? PACKET_SIZE : rlen);
    memcpy( &controller.data[0], packetBuffer, sizeof(controller)); 
    Serial.printf("DATA:%02X %02X %d %d %d %d %d %d %d %02X\n\r",controller.data[0],controller.data[1],controller.data[2],controller.data[3],controller.data[4],
                                                               controller.data[5],controller.data[6],controller.data[7],controller.data[8],controller.data[9]);
    if (controller.status.A) { Serial.println("Button A : ON"); }
    else                     { Serial.println("Button A : OFF"); }
    Serial.printf("Left Analog LR : %d\n\r",controller.status.LeftAnalogLR);
  }
  
}
