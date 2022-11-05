//==========НАСТРОЙКИ==========
#define SENSOR_PIN D2     //пин подключения дачика DS18B20
const byte Time = 7 ;    //время отправки 7мин
const bool DT = 0 ;     //Используемый датчик 0 -(DS18B20) , 1 -(BME280)
//------------------ Настройки нашего WiFi
const char* ssid = "имя нашей сети";   //имя нашей сети
const char* password = "пароль";    //пароль от нее
//------------------
const char* host = "narodmon.ru";   //Адрес сервера
const int port = 8283;    //Порт через который мы подключаемся

//==========БИБЛЫ==========
#include <GyverBME280.h>
#include <microDS18B20.h>
#include <GyverPortal.h>

//GyverPortal portal;
GyverBME280 bme; 
MicroDS18B20<SENSOR_PIN> sensor;  // датчик на D2

void setup() {
  Serial.begin(115200);
  bme.setMode(FORCED_MODE);                      // По возможности используем принудительный режим с редким опросом
    bme.begin();                                      // Если на этом настройки окончены - инициализируем датчик
}

void loop() {
  Send(); //Отправляем данные
  ESP.deepSleep(Time*6e7); //уходим в сон
}
