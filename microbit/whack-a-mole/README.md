# micro:bit Whack-a-Mole Sample

[日本語版 README はこちら](README.ja.md)

## Overview

A whack-a-mole game played on the micro:bit's LED display, using BlePad's game
controller screen (the D-pad — U/D/L/R — and the A/B buttons). It's a fun way
to confirm that BlePad correctly distinguishes between multiple button inputs.

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

## How to play

Switch BlePad's standard control screen to "Controller". When an LED lights up
at one of the positions below, press the corresponding button to score a point.

```
A  .  U  .  B
.  .  .  .  .
L  .  .  .  R
.  .  .  .  .
.  .  D  .  .
```

| LED position | Corresponding button |
|---|---|
| Top-left | A |
| Top-center | U (D-pad up) |
| Top-right | B |
| Middle-left | L (D-pad left) |
| Middle-right | R (D-pad right) |
| Bottom-center | D (D-pad down) |

1. Launch the BlePad app and connect to the target micro:bit from the scan screen
2. The game starts automatically on connection, and an LED lights up at random at one of the 6 positions
3. Pressing the matching button scores a point and spawns the next mole (there's no time limit)
4. Disconnecting ends the game and shows the final score as a number

Note: the micro:bit v1 (16KB RAM) already uses a large portion of its memory just for the
Bluetooth extension, so this sample deliberately omits a time-limit watcher and stays
purely event-driven to keep its memory footprint small.

## Video

https://github.com/user-attachments/assets/90d18364-a758-455c-992a-982220569121
