# System Architecture

## Verified data path

1. The transmitter reads joystick analog values from A0, A1, A2, A3, and A7.
2. It reads switches on D9 and D10 using internal pull-up resistors.
3. It maps four control analog values and a potentiometer value to 1000–2000.
4. It packs those values and both switch states into `JoyData`.
5. It sends the structure over nRF24L01+ to RF address `NODE1`.
6. The receiver reads the matching structure.
7. Servo-library writes send PWM pulses to D2–D6, D9, and D10.

## Source-level limitations

- The original final source implements seven channels.
- Both units use Arduino Nano-compatible pin numbering where D7/D8 are radio CE/CSN.
- The exact board revision and electrical schematic are only available through the hardware and Proteus materials.
- No ACK payload or bidirectional telemetry is implemented.
- No transmitter loss-of-link failsafe is implemented; the receiver is responsible for failsafe behavior.
