// === MG Engineer - TX Air Link Test ===
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const byte address[] = "NODE1";

// Simple struct for the 4 main joysticks
struct JoyData {
  int16_t throttle; // A1
  int16_t yaw;      // A0
  int16_t pitch;    // A3
  int16_t roll;     // A2
};

JoyData myData;

void setup() {
  Serial.begin(9600);
  Serial.println("=== Scorpion TX Test Starting ===");

  if (!radio.begin()) {
    Serial.println("Hardware Error: Check NRF connection!");
    while(1);
  }

  radio.setChannel(76); 
  radio.setPALevel(RF24_PA_LOW); // Keep LOW for desk testing
  radio.setDataRate(RF24_1MBPS);
  radio.openWritingPipe(address);
  radio.stopListening();
  
  Serial.println("TX Ready! Sending data...");
}

void loop() {
  // Read joysticks
  myData.throttle = analogRead(A1);
  myData.yaw      = analogRead(A0);
  myData.pitch    = analogRead(A3);
  myData.roll     = analogRead(A2);

  // Send data
  bool success = radio.write(&myData, sizeof(JoyData));

  if (success) {
    Serial.print("TX OK -> Thr: "); Serial.print(myData.throttle);
    Serial.print(" | Yaw: "); Serial.println(myData.yaw);
  } else {
    Serial.println("TX FAILED -> No response from RX");
  }

  delay(50); // 20 times per second
}