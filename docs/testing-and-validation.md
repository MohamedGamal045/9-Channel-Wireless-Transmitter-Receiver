# Testing and Validation

## Source-supported tests

- nRF24L01 hardware initialization and serial status reporting
- Four-channel test transmitter and receiver for basic RF data transfer
- Serial output of received analog values
- Seven-channel payload transmission and PWM output generation
- Receiver failsafe activation after 1 second without traffic

## Media-supported activity

The original media collection includes photographs and two videos of PCB work, hardware setup, serial software, bench operation, and component testing.

No claim is made that the available media verifies every channel or a successful flight. A formal test log should record packet reception, PWM measurements, switch polarity, and failsafe voltage behavior.

## Safe bench procedure

1. Disconnect propulsion or actuators.
2. Measure PWM on an oscilloscope or compatible servo tester.
3. Verify the center and endpoint values for all channels.
4. Verify switch polarity and failsafe positions.
5. Power-cycle the transmitter and receiver while monitoring serial output.
6. Reconnect only after control-direction and failsafe behavior are confirmed.
