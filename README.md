# Метеостанция для передачи данных на народный мониторинг
Метеостанция созданная на базе ESP8266 для передачи данных на narodmon.ru 


## Возможности
+ Использование любых платформ на базе ESP
+ Возможность использования датчика DS18B20 или BME280 
+ Низкое энергопотребление за счет режима сна 

## Настройки
+ Перед загрузкой прошивки следует ввести данные своего WiFi !!!
```C++
const char* ssid = "имя нашей сети";   //имя нашей сети
const char* password = "пароль";    //пароль от нее
```
+ Тип подключенного датчика :
```C++
#define DT 0     //Используемый датчик 0 -(DS18B20) , 1 -(BME280)
```
+ Время отправки данных на сервер
```C++
#define T1 7     //время отправки 7мин
```

## Пины подключения датчиков
+ BME280
```C++
SCL – D1
SDA – D2
```
+ Ds18b20
```C++
#define SENSOR_PIN D2
```

## Ссылки для менеджера плат
+ ESP8266- http://arduino.esp8266.com/stable/package_esp8266com_index.json
+ ESP32- https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

## Формат пакета данных
(Для тех кто захочет добавить свои датчики)
```C++
#MAC[#NAME]\n
  #mac1#value1[#time1][#name1]\n
  ...
  #macN#valueN[#timeN][#nameN]\n
  ##
  -------------------
  \n - спецсимвол конца строки - код 10(0A).
  ## - признак окончания пакета данных (после него разрыв соединения), в [] заключен необязательный параметр.
  ```
