#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2    // Пин, к которому подключен датчик DHT11
#define DHTTYPE DHT11   // Укажите тип датчика (DHT11 или DHT22)
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2); // Установите правильный адрес экрана

void setup() {
  lcd.begin(16, 2);
  lcd.backlight();

  dht.begin();
}

void loop() {
  // Считываем значения температуры и влажности с датчика
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Выводим значения на экран
  lcd.clear();  // Очищаем экран перед выводом новых значений

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");

  delay(2000); // Задержка в 2 секунды между обновлениями значений
}
