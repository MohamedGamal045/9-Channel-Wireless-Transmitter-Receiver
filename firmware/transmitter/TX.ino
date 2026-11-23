// === MG Engineer - 7CH TX Air Link for APM ===
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const byte address[] = "NODE1";

// 7-Channel Struct matching your requested setup
struct JoyData {
  uint16_t throttle; // Channel 3 (A1)
  uint16_t yaw;      // Channel 4 (A0)
  uint16_t pitch;    // Channel 2 (A3)
  uint16_t roll;     // Channel 1 (A2)
  uint16_t pot;      // Channel 5 (A7)
  bool sw1;          // Channel 6 (D9)
  bool sw2;          // Channel 7 (D10)
};

JoyData myData;

void setup() {
  Serial.begin(9600);
  Serial.println("=== MG Engineer 7CH TX Starting ===");

  // Initialize switches with internal pull-up resistors
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);

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
  // Read joysticks & pot and map directly to APM PWM range (1000 to 2000)
  myData.throttle = map(analogRead(A1), 0, 1023, 1000, 2000); // CH3
  myData.yaw      = map(analogRead(A0), 0, 1023, 1000, 2000); // CH4
  myData.pitch    = map(analogRead(A3), 0, 1023, 1000, 2000); // CH2
  myData.roll     = map(analogRead(A2), 0, 1023, 1000, 2000); // CH1
  myData.pot      = map(analogRead(A7), 0, 1023, 1000, 2000); // CH5
  
  // Read digital switches (Inverted due to INPUT_PULLUP)
  myData.sw1 = !digitalRead(9);  // CH6
  myData.sw2 = !digitalRead(10); // CH7

  // Send data continuously
  bool success = radio.write(&myData, sizeof(JoyData));

  if (success) {
    // Print all states to Serial Monitor
    Serial.print("TX OK | Thr: "); Serial.print(myData.throttle);
    Serial.print(" | Yaw: "); Serial.print(myData.yaw);
    Serial.print(" | Pit: "); Serial.print(myData.pitch);
    Serial.print(" | Rol: "); Serial.print(myData.roll);
    Serial.print(" | Pot: "); Serial.print(myData.pot);
    Serial.print(" | SW1: "); Serial.print(myData.sw1);
    Serial.print(" | SW2: "); Serial.println(myData.sw2);
  } else {
    Serial.println("TX FAILED -> No response from RX");
  }

  delay(50); // 20 times per second
}