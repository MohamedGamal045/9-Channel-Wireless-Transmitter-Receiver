# Transmitter Documentation

The final transmitter firmware is [TX.ino](../firmware/transmitter/TX.ino).

## Inputs

- A1: throttle, channel 3
- A0: yaw, channel 4
- A3: pitch, channel 2
- A2: roll, channel 1
- A7: potentiometer, channel 5
- D9: switch 1, channel 6
- D10: switch 2, channel 7

## Physical 9-channel hardware

The PCB also provides:

- A4: Switch 3, proposed channel 8
- A5: Switch 4, proposed channel 9

These switches are physically present but are not read or transmitted by the original firmware. They are not included in the `JoyData` structure.

The transmitter PCB is also capable of using alternative suitable ADC or digital pins. Any pin change must update the PCB wiring, transmitter code, receiver output assignment, and payload structure consistently.

The switch values are inverted because `INPUT_PULLUP` makes a closed switch read low.

## Radio settings

- SPI
- CE: D7
- CSN: D8
- Address: `NODE1`
- RF channel: 76
- RF24 power: low
- Data rate: 1 Mbps
- Update interval: 50 ms

## Testing firmware

[TX_NRF_Test.ino](../firmware/testing/TX_NRF_Test.ino) sends only raw analog values for A0–A3. It is a radio communications test and does not represent the complete seven-channel payload.
