# ESP32_RCWController_Test


ESP32/ESP-WROOM-32とRCWControllerを接続するテストプログラムです。<br>
RCWControllerは、Michio Onoさん作成のiOSで動作するゲームパッド風インターフェイスを持ったコントローラーアプリです。

### 必要な物 ###
* ESP32/ESP-WROOM-32<br>
* [RCWController](http://rcwcontroller.micutil.com "Title") (ここからダウンロードして下さい。)
* Arduino IDE (1.8.0で動作確認をしました。)<br>
* [Arduino core for ESP32 WiFi chip](https://github.com/espressif/arduino-esp32 "Title")
* iPhone/iPad/iPod Touch

私は、ESP32-DevKitCとiPod Touchで動作確認をしました。

### 使い方 ###
 1. iPhone/iPad/iPod TouchにRCWControllerをインストールして下さい。
 2. ESP32にスケッチを書き込み後、シリアルモニタを開くとIPアドレスとポート番号が表示されるのでメモしておいて下さい。
 3. ESP32の電源を入れた状態でiPhone/iPad/iPod Touchの設定を開きWiFiを選択すると、ESP32-RCWCというアクセスポイントが表示されるので接続します。
パスワードは　esp32pass　です。<br>
 4. RCWControllerを起動して、真ん中の赤いONボタン押します。<br>
![画像1](images/RCWController1.png)<br><br>
 5. IPアドレスの設定が出るので先ほどメモしたIPアドレスとポート番号を指定してConnectボタンを押します。<br>
![画像2](images/RCWController2.png)<br><br>
 6. うまく接続出来ればRCWControllerを操作するとArduino IDEのシリアルモニタに受信データが表示されます。<br><br>
![画像3](images/RCWController3.png)<br><br>
<br>

### RCWControllerデータフォーマット ###

1 - 2バイト目: ボタン <br>
　UP: 0x0001<br>
　DOWN: 0x0002<br>
　RIGHT: 0x0004<br>
　LEFT: 0x0008<br>
　Y button: 0x0010<br>
　A button: 0x0020<br>
　B button: 0x0040<br>
　X button: 0x0100<br>
　L1: 0x0200<br>
　L2: 0x0400<br>
　R1: 0x0800<br>
　R2: 0x1000<br>
　START: 0x0003<br>
　SELECT: 0x000C<br>
<br>
3 - 4バイト目: 左アナログスティック<br>
　左右: 1-255 (Neutral=128) <br>
　上下: 1-255 (Neutral=128)<br>
<br>
5 - 6バイト目: 右アナログスティック<br>
　左右: 1-255 (Neutral=128) <br>
　上下: 1-255 (Neutral=128)<br>
<br>
7 - 9バイト目: アクセラレータ<br>
　X軸: 1-255 (Neutral=128) <br>
　Y軸: 1-255 (Neutral=128)<br>
　Z軸: 1-255 (Neutral=128)<br>
<br>
10バイト目: 設定（向き、設定）<br>
　7 - 6 bit目: アクセラレータ設定 (0-3)<br>
　5 bit目: 左アナログ (0-1)<br>
　4 bit目: 右アナログ (0-1)<br>
　3-1 bit目: iOSデバイス向き (1-4)<br>



---
RCWController since 2016-02-17 / Copyright Micono Utilities. All Rights Reserved
