/**
 * BlePad もぐら叩きゲーム サンプル
 *
 * BlePadのゲームコントローラ画面（十字キー U/D/L/R と A/Bボタン）を使った
 * もぐら叩きゲーム。LED上の6箇所のいずれかがランダムに光り（＝もぐら）、
 * 対応するボタンを押すとスコアが加算され、次のもぐらが出現する。
 *
 * 事前準備：MakeCodeエディタで「Bluetooth」拡張を追加すること
 * （追加すると自動的にBluetooth対応ファームウェアに切り替わり、Radio機能とは排他になる）。
 *
 * 注意：micro:bit v1（RAM 16KB）はBluetooth拡張だけでメモリを多く消費するため、
 * 常時稼働する forever ループ等を追加するとメモリ不足（エラー020）で
 * クラッシュしやすい。そのため本サンプルは制限時間の監視は行わず、
 * イベントハンドラ（接続/切断/UART受信）のみで完結する構成にしている。
 */

// もぐらの出現位置と対応するボタン識別子（インデックスで対応付け）・LED座標
// レイアウト：A/U/B を上段、L/Rを中段、Dを下段に配置（ゲームパッド風の見た目にする）
const BUTTON_CHARS = "UDLRAB"
let posX: number[] = [2, 2, 0, 4, 0, 4]
let posY: number[] = [0, 4, 2, 2, 0, 0]

let activeIndex = -1
let score = 0

// もぐらの出現間隔（ミリ秒）。連打による見た目のちらつきを防ぐための短い間だけ待つ
const SPAWN_DELAY_MS = 300

// 現在光っているもぐらを消す
function clearMole() {
    if (activeIndex >= 0) {
        led.unplot(posX[activeIndex], posY[activeIndex])
    }
    activeIndex = -1
}

// ランダムな位置にもぐらを出現させる
function spawnMole() {
    activeIndex = Math.randomRange(0, BUTTON_CHARS.length - 1)
    led.plot(posX[activeIndex], posY[activeIndex])
}

// BLE UART（Nordic UART Service互換）サービスを開始する
bluetooth.startUartService()

// BlePadと接続したらスコアをリセットしてゲームを開始する
bluetooth.onBluetoothConnected(function () {
    score = 0
    basic.showIcon(IconNames.Happy)
    basic.pause(500)
    basic.clearScreen()
    spawnMole()
})

// BlePadと切断したら、もぐらを消して最終スコアを表示する
bluetooth.onBluetoothDisconnected(function () {
    clearMole()
    basic.showNumber(score)
    basic.showIcon(IconNames.Sad)
})

// BlePadからのボタン入力を処理する
// コントローラ画面は押下時に "+識別子\n" を送信する仕様のため、押下時のみを対象とする
bluetooth.onUartDataReceived(serial.delimiters(Delimiters.NewLine), function () {
    let line = bluetooth.uartReadUntil(serial.delimiters(Delimiters.NewLine))
    if (line.length >= 2 && line.charAt(0) == "+" && activeIndex >= 0) {
        let key = line.charAt(1)
        if (key == BUTTON_CHARS.charAt(activeIndex)) {
            score += 1
            clearMole()
            basic.pause(SPAWN_DELAY_MS)
            spawnMole()
        }
    }
})

// 起動時は未接続状態を示す
basic.showIcon(IconNames.Sad)
