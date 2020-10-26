「DHT11センサー（温度、湿度センサー）による温度、湿度監視」

DHT11で読み取ったセンサーをaruduinoで読み取り。 読み取りは「DHT.h」のライブラリを使用。

読み取った値を「LiquidCrystal_I2C.h」のライブラリでLCM1602（LCDモジュール）へデータ送信して情報表示。 同時にUSB経由でRaspberryPiへシリアル通信にてデータ送信。

データ表示と同時にCSVファイルに出力⇒javascriptとHTMLで表示。
