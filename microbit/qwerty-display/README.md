# micro:bit QWERTY Character Display Sample

[日本語版 README はこちら](README.ja.md)

## Overview

This sample scrolls, on the micro:bit's LED display, the characters you tap on
the BlePad app's QWERTY keyboard screen. It's the quickest way to confirm that
BlePad and the micro:bit are actually communicating over BLE UART.

## What you need

- micro:bit (v1 / v2)
- A smartphone with the BlePad app

No additional parts are required.

## Setup

1. Create a new project at [MakeCode for micro:bit](https://makecode.microbit.org/)
2. Search for `bluetooth` under "Extensions" (bottom left) and add it
   - Adding it switches the firmware to the Bluetooth-enabled build (this is mutually exclusive with the Radio feature)
3. Switch to the "JavaScript" view in the top right of the editor, and paste in the contents of [main.ts](main.ts)
4. Flash it to your micro:bit (download the .hex file and drag it onto the micro:bit)

## How to operate from BlePad

1. Launch the BlePad app and connect to the target micro:bit from the scan screen
2. Switch the standard control screen to "QWERTY"
3. Tap any key — the character you pressed scrolls across the micro:bit's LED display

A happy face icon is shown on a successful connection, and a sad face icon on disconnect.

## Video

(To be added)
