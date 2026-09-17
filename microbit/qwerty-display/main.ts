/**
 * BlePad QWERTY文字表示サンプル
 *
 * BlePadアプリのQWERTYキーボード画面でタップしたキーを受信し、
 * その文字をmicro:bitのLEDにスクロール表示する。
 *
 * 事前準備：MakeCodeエディタで「Bluetooth」拡張を追加すること
 * （追加すると自動的にBluetooth対応ファームウェアに切り替わり、Radio機能とは排他になる）。
 */

// BLE UART（Nordic UART Service互換）サービスを開始する
bluetooth.startUartService()

// BlePadと接続したときの合図として、笑顔アイコンを表示する
bluetooth.onBluetoothConnected(function () {
    basic.showIcon(IconNames.Happy)
})

// BlePadと切断したときの合図として、悲しい顔アイコンを表示する
bluetooth.onBluetoothDisconnected(function () {
    basic.showIcon(IconNames.Sad)
})

// BlePadからの受信データ（1行分）を処理する
// QWERTY画面は押下時に "+文字\n"、離上時に "-文字\n" を送信する仕様のため、
// 押下時（先頭が "+"）のみを対象にLED表示する
bluetooth.onUartDataReceived(serial.delimiters(Delimiters.NewLine), function () {
    let line = bluetooth.uartReadUntil(serial.delimiters(Delimiters.NewLine))
    if (line.length >= 2 && line.charAt(0) == "+") {
        basic.showString(line.charAt(1))
    }
})

// 起動時は未接続状態を示す
basic.showIcon(IconNames.Sad)
