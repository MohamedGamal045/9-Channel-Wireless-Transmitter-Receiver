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

## Testing firmware

[RX_NRF_Test.ino](../firmware/testing/RX_NRF_Test.ino) receives and prints four raw analog values. It does not exercise the PWM outputs or failsafe behavior.
