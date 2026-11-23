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
