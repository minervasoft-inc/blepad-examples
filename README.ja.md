# BlePad Examples

[English README is here](README.md)

BLE UART（Nordic UART Service / NUS 互換）経由で機器を操作するAndroid/iOSリモコンアプリ
**BlePad** の動作確認用サンプル集です。各サンプルは、安価で入手しやすいハードウェアを使い、
BlePadと実機がBluetoothで実際に通信できていることを手軽に確認できます。

## アプリの入手

- [App Store](https://apps.apple.com/jp/app/blepad/id6787904993)
- [Google Play](https://play.google.com/store/apps/details?id=jp.co.minervasoft.blepad&hl=ja)

## サンプル一覧

| サンプル | 対象プラットフォーム | 必要なもの | 概要 |
|---|---|---|---|
| [microbit/qwerty-display](microbit/qwerty-display) | micro:bit | micro:bitのみ | BlePadのQWERTY画面でタップした文字をLEDにスクロール表示 |
| [microbit/whack-a-mole](microbit/whack-a-mole) | micro:bit | micro:bitのみ | BlePadのゲームコントローラ画面で遊ぶもぐら叩きゲーム |
| [esp32/ble-buzzer](esp32/ble-buzzer) | ESP32 | ESP32 + 圧電ブザー1個 | BlePadのテンキー画面で演奏できる簡易楽器 |

各サンプルのフォルダには、セットアップ手順・配線（必要な場合）・デモ動画を記載した
READMEがあります。

## ライセンス

[MIT](LICENSE) © Minerva, Inc.
