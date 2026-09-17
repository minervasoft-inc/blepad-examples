# ESP32 BLE Instrument Sample (Single Piezo Buzzer)

[日本語版 README はこちら](README.ja.md)

## Overview

A simple BLE instrument sample that turns BlePad's numpad screen (keys 0–9)
into a keyboard, using nothing more than an ESP32 and a single piezo buzzer.
It implements a NUS (Nordic UART Service) compatible BLE server on the ESP32,
using the same UUIDs as `arduino/BlePadUartTest/`.

## What you need

- ESP32 development board
- 1 piezo (passive) buzzer
  - Use a "passive" piezo buzzer/speaker that can play different pitches, not
    an "active" buzzer module with a built-in oscillator that only beeps at a fixed tone
- Breadboard and jumper wires
- A smartphone with the BlePad app

## Wiring

| ESP32 | Piezo buzzer |
|---|---|
| GPIO25 | Terminal 1 |
| GND | Terminal 2 |

No resistor is required. The GPIO pin can be changed via `BUZZER_PIN` at the
top of the sketch if it conflicts with your ESP32 board's pin layout.

## Setup

1. In Arduino IDE, install the ESP32 board package (v2.0.3 or later, since this uses `tone()`/`noTone()`)
2. Install the "NimBLE-Arduino" library (2.x) from the Library Manager
3. Open [ble-buzzer.ino](ble-buzzer.ino) and flash it to your ESP32
4. Check the initialization log in the Serial Monitor (115200bps)

## How to operate from BlePad

1. Launch the BlePad app and connect to `BlePad-ESP32-Buzzer` from the scan screen
2. Switch the standard control screen to "Numpad"
3. Hold down any key 0–9 to play the corresponding note (it stops when released)

### Key-to-note mapping

| Key | Note | Frequency |
|---|---|---|
| 0 | C4 (Do) | 262 Hz |
| 1 | D4 (Re) | 294 Hz |
| 2 | E4 (Mi) | 330 Hz |
| 3 | F4 (Fa) | 349 Hz |
| 4 | G4 (Sol) | 392 Hz |
| 5 | A4 (La) | 440 Hz |
| 6 | B4 (Ti) | 494 Hz |
| 7 | C5 (Do) | 523 Hz |
| 8 | D5 (Re) | 587 Hz |
| 9 | E5 (Mi) | 659 Hz |

## Video

(To be added)
