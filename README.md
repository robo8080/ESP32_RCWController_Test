# ESP32_RCWController_Test

---

ESP32/ESP-WROOM-32とRCWControllerを接続するテストプログラムです。<br>
RCWControllerは、Michio Onoさん作成のiOSで動作するゲームパッド風インターフェイスを持ったコントローラーアプリです。

### 必要な物 ###
* ESP32/ESP-WROOM-32<br>
* Arduino IDE (1.8.0で動作確認をしました。)<br>
* iPhone/iPad/iPod Touch
* [RCWController](http://rcwcontroller.micutil.com "Title") (ここからダウンロードして下さい。)

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

---
RCWController since 2016-02-17 / Copyright Micono Utilities. All Rights Reserved
