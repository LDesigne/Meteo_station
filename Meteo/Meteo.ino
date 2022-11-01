//==========НАСТРОЙКИ==========
#define SENSOR_PIN D2     //пин подключения дачика DS18B20
#define T1 7     //время отправки 7мин
#define DT 0     //Используемый датчик 0 -(DS18B20) , 1 -(BME280)
//#define BTN PIN D7
//--------------- Настройка датчика BME280
#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10
#define SEALEVELPRESSURE_HPA (1013.25)
//------------------ Настройки нашего WiFi
const char* ssid = "имя нашей сети";   //имя нашей сети
const char* password = "пароль";    //пароль от нее
//------------------
const char* host = "narodmon.ru";   //Адрес сервера
const int port = 8283;    //Порт через который мы подключаемся


//==========БИБЛЫ==========
//#include <ESP8266WiFi.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
//#include <TimerMs.h>
#include <microDS18B20.h>
#include <GyverPortal.h>

//GyverPortal portal;
//TimerMs tmr(300000, 1, 1);   //Раз в 5мин
//TimerMs tmr(600000, 1, 1);  //Раз в 10мин
MicroDS18B20<SENSOR_PIN> sensor;  // датчик на D2
Adafruit_BME280 bme; // I2C
//Adafruit_BME280 bme(BME_CS); // hardware SPI
//Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK); // software SPI
//uint8_t address[8];

void setup() {
  Serial.begin(115200);
  //tmr.start();   //Запускаем таймер
  //Send();   //Отправляем данные на сервер и в консоль
  //serialPrint();
 // if(BTN PIN){
    
 // }
}

void loop() {
  //if (tmr.tick()) {   //Проверяем значения таймера
  Send(); //Отправляем данные
  //Serial_Print();
  ESP.deepSleep(T1 * 6 * 10 ^ 7); //уходим в сон
  // serialPrint();
  //}
}
