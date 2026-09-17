/**
 * ble-buzzer.ino
 *
 * BlePadのテンキー画面（0〜9キー）で演奏できる、ESP32 + 圧電ブザー1個の
 * 簡易BLE楽器サンプル。NUS（Nordic UART Service）互換のBLEサーバーを実装し、
 * 0〜9キーにドレミファソラシド+2音を割り当てて、キーを押している間だけ
 * 対応する音を鳴らす。
 *
 * 必要ライブラリ：NimBLE-Arduino（バージョン2.x系、ライブラリマネージャからインストール）
 * 必要ボード環境：Arduino core for ESP32 v2.0.3以降（tone()/noTone()を使用するため）
 *
 * 配線：ESP32のBUZZER_PINで指定したピンと圧電（パッシブ）ブザーの一方の端子を接続し、
 *       もう一方の端子をGNDに接続する。抵抗は基本的に不要。
 */
#include <NimBLEDevice.h>

static const int BUZZER_PIN = 9;

// NUS（Nordic UART Service）互換のUUID。arduino/BlePadUartTest/と同じ値を使用する
static const char* SERVICE_UUID = "6E400001-B5A3-F393-E0A9-E50E24DCCA9E";
static const char* CHARACTERISTIC_UUID_RX = "6E400002-B5A3-F393-E0A9-E50E24DCCA9E";
static const char* CHARACTERISTIC_UUID_TX = "6E400003-B5A3-F393-E0A9-E50E24DCCA9E";

// 0〜9キーに割り当てる音階（ド・レ・ミ・ファ・ソ・ラ・シ・ド・レ・ミ）の周波数[Hz]
static const int NOTE_FREQ[10] = {
    262, 294, 330, 349, 392, 440, 494, 523, 587, 659
};

static NimBLEServer* pServer = nullptr;
// 現在鳴動中の音階（0〜9）。鳴っていない場合は-1
static int currentKey = -1;

// BlePadとの接続/切断を検知する
class ServerCallbacks : public NimBLEServerCallbacks {
    void onConnect(NimBLEServer* pServer, NimBLEConnInfo& connInfo) override {
        Serial.println("BlePadと接続しました");
    }

    void onDisconnect(NimBLEServer* pServer, NimBLEConnInfo& connInfo, int reason) override {
        Serial.println("BlePadと切断しました。広告を再開します");
        noTone(BUZZER_PIN);
        currentKey = -1;
        NimBLEDevice::startAdvertising();
    }
} serverCallbacks;

// BlePadからの受信データを処理し、ブザーの音を制御する
// テンキー画面は押下時に "+数字\n"、離上時に "-数字\n" を送信する仕様のため、
// 数字キー（0〜9）の押下・離上のみを音階再生の対象とする
class RxCallbacks : public NimBLECharacteristicCallbacks {
    void onWrite(NimBLECharacteristic* pCharacteristic, NimBLEConnInfo& connInfo) override {
        std::string value = pCharacteristic->getValue();
        if (value.size() < 2) {
            return;
        }
        char action = value[0];
        char key = value[1];
        if (key < '0' || key > '9') {
            return;
        }
        int index = key - '0';

        if (action == '+') {
            tone(BUZZER_PIN, NOTE_FREQ[index]);
            currentKey = index;
        } else if (action == '-' && currentKey == index) {
            noTone(BUZZER_PIN);
            currentKey = -1;
        }
    }
} rxCallbacks;

void setup() {
    Serial.begin(115200);
    pinMode(BUZZER_PIN, OUTPUT);

    NimBLEDevice::init("BlePad-ESP32-Buzzer");

    pServer = NimBLEDevice::createServer();
    pServer->setCallbacks(&serverCallbacks);

    NimBLEService* pService = pServer->createService(SERVICE_UUID);

    pService->createCharacteristic(
        CHARACTERISTIC_UUID_TX,
        NIMBLE_PROPERTY::NOTIFY
    );

    NimBLECharacteristic* pRxCharacteristic = pService->createCharacteristic(
        CHARACTERISTIC_UUID_RX,
        NIMBLE_PROPERTY::WRITE | NIMBLE_PROPERTY::WRITE_NR
    );
    pRxCharacteristic->setCallbacks(&rxCallbacks);

    pService->start();

    NimBLEAdvertising* pAdvertising = NimBLEDevice::getAdvertising();
    // NimBLEDevice::init()で設定した名前はGATT上のデバイス名にのみ反映され、
    // アドバタイズパケットには自動的には含まれないため、ここで明示的に設定する
    // （設定し忘れるとBlePadのスキャン結果（名前なし端末を除外する仕様）に表示されない）
    pAdvertising->setName("BlePad-ESP32-Buzzer");
    pAdvertising->addServiceUUID(SERVICE_UUID);
    pAdvertising->start();

    Serial.println("BLE UART 初期化完了。接続待機中...");
}

void loop() {
    // BLE通信はコールバック駆動のため、loop()内での処理は不要
}
