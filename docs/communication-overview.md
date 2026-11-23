# Communication Overview

The project uses RF24 over SPI and nRF24L01+ RF hardware.

## Payload

The final firmware defines a C++ structure containing:

- Four PWM-formatted `uint16_t` control values
- One PWM-formatted `uint16_t` potentiometer value
- Two `bool` switch values

The transmitter and receiver structures must have identical field order and types. The test firmware uses a separate four-field structure and is not packet-compatible with the final firmware.

## Settings

- Address: `NODE1`
- RF channel: 76
- 1 Mbps data rate
- Low PA level
- Writing pipe on the transmitter
- Reading pipe 0 on the receiver

The final transmitter sends at approximately 20 Hz. No packet sequence number or transport checksum beyond nRF24L01+ features is included in the application structure.
