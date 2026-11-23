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
- Two additional physical switch positions are present on the transmitter PCB: Switch 3 on A4 and Switch 4 on A5.
- These two switches are not read or transmitted by the final firmware and currently have no receiver PWM mapping.
- The receiver PCB includes additional channel/output power sockets beneath the existing channel outputs. Their active Nano pin assignments must be verified against the PCB wiring before firmware use.
- Both units use Arduino Nano-compatible pin numbering where D7/D8 are radio CE/CSN.
- The exact board revision and electrical schematic are only available through the hardware and Proteus materials.
- No ACK payload or bidirectional telemetry is implemented.
- No transmitter loss-of-link failsafe is implemented; the receiver is responsible for failsafe behavior.
