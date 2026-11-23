<div align="center">

<picture>
  <source media="(prefers-color-scheme: dark)" srcset="media/pcb/transmitter-layout-top.png">
  <img alt="Custom 9-channel transmitter PCB" src="media/pcb/transmitter-layout-top.png" width="72%">
</picture>

# 9-Channel Wireless Transmitter & Receiver

### Custom PCB Hardware · Embedded Firmware · nRF24L01+ · ArduPilot-Compatible PWM

[![C++](https://img.shields.io/badge/C%2B%2B-Embedded-blue?style=for-the-badge&logo=cplusplus&logoColor=white)](#)
[![Arduino](https://img.shields.io/badge/Arduino-Nano-00979D?style=for-the-badge&logo=arduino&logoColor=white)](#)
[![nRF24](https://img.shields.io/badge/nRF24L01%2B-2.4_GHz-6A1B9A?style=for-the-badge)](#)
[![PCB](https://img.shields.io/badge/Proteus-PCB_Design-FF9800?style=for-the-badge)](#)
[![PWM](https://img.shields.io/badge/PWM-1000%E2%80%932000_%CE%BCs-00ACC1?style=for-the-badge)](#)

**Designed, programmed, assembled, and tested by Mohamed Gamal**

[GitHub](https://github.com/MohamedGamal045) · [LinkedIn](https://www.linkedin.com/in/mohamedgamal045/) · [Portfolio](https://sites.google.com/view/mgengineer) · [YouTube](https://www.youtube.com/@mgengineer981)

</div>

---

> [!IMPORTANT]
> **Hardware status:** the physical PCB design includes space for **nine control positions**.
>
> **Firmware status:** the original final firmware implements **seven channels**. Channels 8 and 9 are controlled by physical switches on **A4/A5**, but they are not currently read or transmitted by the source code.

---

## Project at a Glance

<table>
  <tr>
    <td align="center" width="33%">
      <img src="media/pcb/transmitter-layout-top.png" width="100%">
      <b>Custom Transmitter PCB</b>
    </td>
    <td align="center" width="33%">
      <img src="media/pcb/receiver-layout-top.png" width="100%">
      <b>Custom Receiver PCB</b>
    </td>
    <td align="center" width="33%">
      <img src="media/images/20260709_000325.jpg" width="100%">
      <b>Bench Assembly</b>
    </td>
  </tr>
</table>

---

## Live Demonstrations

<table>
  <tr>
    <td width="33%">
      <img src="media/gifs/transmitter-operation.gif" width="100%">
      <p align="center"><b>Transmitter Operation</b></p>
    </td>
    <td width="33%">
      <img src="media/gifs/receiver-operation.gif" width="100%">
      <p align="center"><b>Receiver Operation</b></p>
    </td>
    <td width="33%">
      <img src="media/gifs/wireless-system-demo.gif" width="100%">
      <p align="center"><b>Wireless Bench Demo</b></p>
    </td>
  </tr>
</table>

---

## System Architecture

```mermaid
flowchart LR
    IN["Joysticks · Potentiometer · 4 switches"]
    TX["Arduino Nano<br/>TX Firmware"]
    RF["nRF24L01+<br/>2.4 GHz · 1 Mbps"]
    RX["Arduino Nano<br/>RX Firmware"]
    PWM["PWM Outputs<br/>1000–2000 µs"]
    FC["ArduPilot-compatible<br/>RC interface"]

    IN --> TX --> RF --> RX --> PWM --> FC

    style IN fill:#071a2b,stroke:#00d4ff,color:#ffffff
    style TX fill:#0b2545,stroke:#00d4ff,color:#ffffff
    style RF fill:#35105f,stroke:#c77dff,color:#ffffff
    style RX fill:#0b2545,stroke:#00d4ff,color:#ffffff
    style PWM fill:#004d40,stroke:#00e5ff,color:#ffffff
    style FC fill:#5a2a00,stroke:#ffb300,color:#ffffff
```

> The diagram shows the verified firmware data path. The additional A4/A5 switches are **hardware positions**, not yet integrated into the final packet.

---

## Channel Overview

### Programmed in the Current Firmware

| CH | Transmitter | Receiver Pin | PWM | Function |
|---:|---|---:|---|---|
| 1 | A2 | D10 | 1000–2000 µs | Roll |
| 2 | A3 | D9 | 1000–2000 µs | Pitch |
| 3 | A1 | D6 | 1000–2000 µs | Throttle |
| 4 | A0 | D5 | 1000–2000 µs | Yaw |
| 5 | A7 | D3 | 1000–2000 µs | Potentiometer |
| 6 | D9 | D4 | 1000 / 2000 µs | Switch 1 |
| 7 | D10 | D2 | 1000 / 2000 µs | Switch 2 |

### Physical Hardware Positions

| CH | Hardware Switch | Proposed TX Input | Current Firmware |
|---:|---|---|---|
| 8 | Switch 3 | A4 | Not implemented |
| 9 | Switch 4 | A5 | Not implemented |

The receiver PCB includes corresponding output and power socket areas. Nano pin assignment, PWM/supply function, voltage, polarity, and regulator requirements must be verified from the actual wiring before use.

---

## PCB Engineering

<table>
  <tr>
    <td align="center" width="50%">
      <img src="media/pcb/transmitter-schematic.png" width="100%">
      <b>Transmitter Schematic</b>
    </td>
    <td align="center" width="50%">
      <img src="media/pcb/transmitter-layout-bottom.png" width="100%">
      <b>Transmitter PCB Layout</b>
    </td>
  </tr>
  <tr>
    <td align="center" width="50%">
      <img src="media/pcb/transmitter-pcb-fabrication.png" width="100%">
      <b>Transmitter Fabrication Layer</b>
    </td>
    <td align="center" width="50%">
      <img src="media/pcb/receiver-pcb-fabrication.png" width="100%">
      <b>Receiver Fabrication Layer</b>
    </td>
  </tr>
</table>

### Hardware Resources

- [Proteus transmitter project](hardware/proteus/transmitter/MG_Transmitter_NRF_NANO-2.pdsprj)
- [Proteus receiver project](hardware/proteus/receiver/MG_Receiver_NRF_NANO-2.pdsprj)
- [Transmitter PCB PDFs](hardware/pcb-fabrication/transmitter/)
- [Receiver PCB PDFs](hardware/pcb-fabrication/receiver/)
- [Bundled nRF24L01 library](libraries/nRF24L01-master.zip)

---

## Firmware

<table>
  <tr>
    <th>Firmware</th>
    <th>Purpose</th>
  </tr>
  <tr>
    <td><a href="firmware/transmitter/TX.ino"><b>TX.ino</b></a></td>
    <td>Seven-channel final transmitter payload</td>
  </tr>
  <tr>
    <td><a href="firmware/receiver/RX.ino"><b>RX.ino</b></a></td>
    <td>Seven-channel PWM receiver and one-second failsafe</td>
  </tr>
  <tr>
    <td><a href="firmware/testing/TX_NRF_Test.ino"><b>TX_NRF_Test.ino</b></a></td>
    <td>Four-channel raw RF test</td>
  </tr>
  <tr>
    <td><a href="firmware/testing/RX_NRF_Test.ino"><b>RX_NRF_Test.ino</b></a></td>
    <td>Four-channel serial receive test</td>
  </tr>
</table>

---

## Communication Setup

| Parameter | Verified Value |
|---|---|
| Wireless device | nRF24L01+ |
| RF channel | 76 |
| Data rate | 1 Mbps |
| TX power | Low |
| Address | `NODE1` |
| CE / CSN | D7 / D8 |
| Packet interval | 50 ms |
| Output convention | 1000–2000 µs PWM |

---

## Receiver Failsafe

```text
NO PACKET FOR 1 SECOND
          |
          v
Throttle  = 1000 us
Roll      = 1500 us
Pitch     = 1500 us
Yaw       = 1500 us
Pot       = 1500 us
Switches  = 1000 us
```

This behavior is implemented in the receiver firmware. Add independent mechanical, electrical, or system-level protection for all external equipment.

---

## Build Gallery

<table>
  <tr>
    <td align="center"><img src="media/images/20260709_000429.jpg" width="100%"><br><b>Hand-etched PCB prototype</b></td>
    <td align="center"><img src="media/images/20260709_000315.jpg" width="100%"><br><b>Hardware assembly and programming</b></td>
  </tr>
  <tr>
    <td align="center"><img src="media/images/20260707_073728.jpg" width="100%"><br><b>PCB fabrication work</b></td>
    <td align="center"><img src="media/images/20260707_041734.jpg" width="100%"><br><b>Fabricated PCB preview</b></td>
  </tr>
</table>

---

## Documentation

- [System Architecture](docs/system-architecture.md)
- [Transmitter Documentation](docs/transmitter-documentation.md)
- [Receiver Documentation](docs/receiver-documentation.md)
- [Communication Overview](docs/communication-overview.md)
- [ArduPilot Integration](docs/ardupilot-integration.md)
- [Testing and Validation](docs/testing-and-validation.md)

---

## Safe Bench Usage

1. Disconnect motors or powered actuators.
2. Verify PWM with an oscilloscope or servo tester.
3. Confirm all channel directions and endpoints.
4. Check switch polarity and failsafe output.
5. Verify power, voltage, and connector polarity before external connections.
6. Reconnect powered equipment only after bench testing is complete.

---

<div align="center">

### Mohamed Gamal

**Mechatronics Engineering Technology · Embedded Systems · Electronics · PCB Design · Robotics · IoT**

[GitHub](https://github.com/MohamedGamal045) · [LinkedIn](https://www.linkedin.com/in/mohamedgamal045/) · [Portfolio](https://sites.google.com/view/mgengineer) · [YouTube](https://www.youtube.com/@mgengineer981)

**Designed. Developed. Tested. Engineered by Mohamed Gamal.**

</div>
