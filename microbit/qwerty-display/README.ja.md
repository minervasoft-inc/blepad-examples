# micro:bit QWERTY文字表示サンプル

[English README is here](README.md)

## 概要

BlePad アプリの QWERTY キーボード画面でタップした文字を、micro:bit の LED に
スクロール表示するサンプルです。BlePad と micro:bit が実際に BLE UART で
通信できていることを、最も手軽に確認できます。

## 必要なもの

- micro:bit（v1 / v2）
- スマートフォン（BlePad アプリ）

追加パーツは不要です。

## セットアップ手順

1. [MakeCode for micro:bit](https://makecode.microbit.org/) で新規プロジェクトを作成する
2. 左下の「拡張機能」から `bluetooth` を検索して追加する
   - 追加すると Bluetooth 対応ファームウェアに切り替わります（Radio機能とは排他）
3. エディタ右上で「JavaScript」表示に切り替え、[main.ts](main.ts) の内容を貼り付ける
4. micro:bit に書き込む（.hexファイルをダウンロードしてmicro:bitにドラッグ&ドロップ）

## BlePad側の操作方法

1. BlePad アプリを起動し、スキャン画面から対象の micro:bit に接続する
2. 標準送信画面を「QWERTY」に切り替える
3. 任意のキーをタップすると、押した文字が micro:bit の LED にスクロール表示される

接続に成功すると笑顔アイコン、切断すると悲しい顔アイコンが表示されます。

## 動画

（後日追加予定）
