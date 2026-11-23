// === MG Engineer - 7CH RX Air Link for APM ===
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

RF24 radio(7, 8); // CE, CSN
const byte address[] = "NODE1";

// Struct must perfectly match the TX
struct JoyData {
  uint16_t throttle;
  uint16_t yaw;
  uint16_t pitch;
  uint16_t roll;
  uint16_t pot;
  bool sw1;
  bool sw2;
};

JoyData myData;

// APM Output Channels using Servo library
Servo apm_ch1; // Roll
Servo apm_ch2; // Pitch
Servo apm_ch3; // Throttle
Servo apm_ch4; // Yaw
Servo apm_ch5; // Pot
Servo apm_ch6; // SW1
Servo apm_ch7; // SW2

unsigned long lastRecvTime = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("=== MG Engineer 7CH RX Starting ===");

  // Attach APM channels to your requested Arduino pins
  apm_ch1.attach(10); // Roll
  apm_ch2.attach(9);  // Pitch
  apm_ch3.attach(6);  // Throttle
  apm_ch4.attach(5);  // Yaw
  apm_ch5.attach(3);  // Pot
  apm_ch6.attach(4);  // SW1
  apm_ch7.attach(2);  // SW2

  if (!radio.begin()) {
    Serial.println("Hardware Error: Check NRF connection!");
    while(1);
  }

  radio.setChannel(76); 
  radio.setPALevel(RF24_PA_LOW); 
  radio.setDataRate(RF24_1MBPS);
  radio.openReadingPipe(0, address);
  radio.startListening();
  
  Serial.println("RX Ready! Listening for data...");
}

void loop() {
  // If connection is active, read and output directly
  if (radio.available()) {
    radio.read(&myData, sizeof(JoyData));
    lastRecvTime = millis();
    
    // Write PWM signals to APM
    apm_ch1.writeMicroseconds(myData.roll);
    apm_ch2.writeMicroseconds(myData.pitch);
    apm_ch3.writeMicroseconds(myData.throttle);
    apm_ch4.writeMicroseconds(myData.yaw);
    apm_ch5.writeMicroseconds(myData.pot);
    
    // Convert boolean switch states to APM-compatible PWM (1000us or 2000us)
    apm_ch6.writeMicroseconds(myData.sw1 ? 2000 : 1000);
    apm_ch7.writeMicroseconds(myData.sw2 ? 2000 : 1000);

    // Print all states to Serial Monitor
    Serial.print("RX IN | Thr: "); Serial.print(myData.throttle);
    Serial.print(" | Yaw: "); Serial.print(myData.yaw);
    Serial.print(" | Pit: "); Serial.print(myData.pitch);
    Serial.print(" | Rol: "); Serial.print(myData.roll);
    Serial.print(" | Pot: "); Serial.print(myData.pot);
    Serial.print(" | SW1: "); Serial.print(myData.sw1);
    Serial.print(" | SW2: "); Serial.println(myData.sw2);
  }

  // Basic Failsafe: If signal lost for 1 second, secure the drone
  if (millis() - lastRecvTime > 1000) {
    apm_ch3.writeMicroseconds(1000); // ZERO Throttle
    apm_ch1.writeMicroseconds(1500); // Center Roll
    apm_ch2.writeMicroseconds(1500); // Center Pitch
    apm_ch4.writeMicroseconds(1500); // Center Yaw
    apm_ch5.writeMicroseconds(1500); // Center Pot
    apm_ch6.writeMicroseconds(1000); // Default SW1
    apm_ch7.writeMicroseconds(1000); // Default SW2
  }
}