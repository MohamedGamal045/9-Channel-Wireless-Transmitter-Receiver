# Receiver Documentation

The final receiver firmware is [RX.ino](../firmware/receiver/RX.ino).

## PWM output mapping

- D10: roll
- D9: pitch
- D6: throttle
- D5: yaw
- D3: potentiometer
- D4: switch 1
- D2: switch 2

Analog values and potentiometer values are written directly as microseconds. Boolean switch values become 2000 µs when pressed and 1000 µs otherwise.

## Failsafe

After one second without a received packet, the receiver drives throttle to 1000 µs and control channels to 1500 µs. Switch outputs return to 1000 µs.

## Physical 9-channel hardware

The receiver PCB includes output/channel power sockets beneath the programmed channel header area. The PCB photograph also shows CH7 and CH8 labels and an additional CHX area, but the exact active pin, connector, and supply assignments are not defined in the available firmware or text documentation.

The original firmware implements only seven PWM outputs. Channels 8 and 9 must be mapped to available Nano ADC/digital pins and added to the transmitted payload before they can produce PWM.

Before connecting equipment, verify:

- Channel 8 and channel 9 Nano pin numbers
- PWM versus power socket function
- Connector voltage
- Connector polarity
- Whether an external regulator or separate supply is required

## Testing firmware

[RX_NRF_Test.ino](../firmware/testing/RX_NRF_Test.ino) receives and prints four raw analog values. It does not exercise the PWM outputs or failsafe behavior.
