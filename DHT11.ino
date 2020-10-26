#include <DHT.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

String send_data = "";
const int PIN_DHT = 8;
DHT dht(PIN_DHT,DHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C: 0x3F, 16x2 LCD

void setup() {
  //Serial start
  Serial.begin(9600);
  dht.begin();

  //LCD start
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("");
  lcd.setCursor(0, 1);
  lcd.print("");
  
}

void loop() {
  byte data;
  
  if (Serial.available() > 0){
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();
    data = Serial.read();
    
    //湿度、温度データを送る
    if (data == 'H'){
      Serial.print(String(humidity) + "\n");
      lcd.setCursor(0, 0);
      lcd.print(String(humidity) + " %");
    }
    if (data == 'T'){
      Serial.print(String(temperature) + "\n");
        lcd.setCursor(0, 1);
        lcd.print(String(temperature) + " C");
    }    
  }
}
