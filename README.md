# BlePad Examples

[日本語版 README はこちら](README.ja.md)

Example programs for trying out **BlePad**, a BLE UART (Nordic UART Service /
NUS compatible) remote control app for Android / iOS. Each example lets you
quickly confirm that BlePad is actually talking to a device over Bluetooth,
using cheap, easy-to-source hardware.

## Getting the app

- [App Store](https://apps.apple.com/app/blepad/id6787904993)
- [Google Play](https://play.google.com/store/apps/details?id=jp.co.minervasoft.blepad)

## Examples

| Example | Platform | What you need | Description |
|---|---|---|---|
| [microbit/qwerty-display](microbit/qwerty-display) | micro:bit | micro:bit only | Scrolls the characters you tap on BlePad's QWERTY screen across the LED display |
| [microbit/whack-a-mole](microbit/whack-a-mole) | micro:bit | micro:bit only | A whack-a-mole game played with BlePad's game controller screen |
| [esp32/ble-buzzer](esp32/ble-buzzer) | ESP32 | ESP32 + 1 piezo buzzer | A simple instrument played from BlePad's numpad screen |

Each example's folder has its own README with setup steps, wiring (if any),
and a demo video.

## License

[MIT](LICENSE) © Minerva, Inc.
