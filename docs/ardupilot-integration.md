# ArduPilot-Compatible Integration

## What is verified

The receiver writes 1000–2000 µs PWM pulses using the Arduino Servo library. This is a conventional interface for RC receivers and autopilot RC-input circuitry.

The source maps seven receiver outputs as follows:

1. Roll
2. Pitch
3. Throttle
4. Yaw
5. Potentiometer
6. Switch 1
7. Switch 2

## What is not verified

No evidence in the source establishes the pin assignment of an ArduPilot board, RC receiver input convention, flight controller configuration, channel reversal, mode assignments, or vehicle behavior.

Actual ArduPilot setup must be validated on the bench with a suitable simulator or flight-controller hardware before any powered vehicle operation.
