// === MG Engineer - RX Air Link Test ===
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const byte address[] = "NODE1";

struct JoyData {
  int16_t throttle;
  int16_t yaw;
  int16_t pitch;
  int16_t roll;
};

JoyData myData;

void setup() {
  Serial.begin(9600);
  Serial.println("=== Scorpion RX Test Starting ===");

  if (!radio.begin()) {
    Serial.println("Hardware Error: Check NRF connection!");
    while(1);
  }

  radio.setChannel(76); 
  radio.setPALevel(RF24_PA_LOW); // Must match TX
  radio.setDataRate(RF24_1MBPS);
  radio.openReadingPipe(0, address);
  radio.startListening();
  
  Serial.println("RX Ready! Listening for data...");
}

void loop() {
  if (radio.available()) {
    radio.read(&myData, sizeof(JoyData));
    
    Serial.print("RX RECEIVED -> Thr: "); Serial.print(myData.throttle);
    Serial.print(" | Yaw: "); Serial.print(myData.yaw);
    Serial.print(" | Pitch: "); Serial.print(myData.pitch);
    Serial.print(" | Roll: "); Serial.println(myData.roll);
  }
}