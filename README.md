# Метеостанция для передачи данных на народный мониторинг
Метеостанция созданная на базе ESP8266 для передачи данных на narodmon.ru 


## Возможности
+ Использование любых платформ на базе ESP
+ Возможность использования датчика DS18B20 или BME280 
+ Низкое энергопотребление за счет режима сна 

## Подключение датчиков
+ BME280 (Обязательно на 3.3v !!)
+ ![Снимок экрана 2022-11-10 122024](https://user-images.githubusercontent.com/117163683/201010099-c8a262ad-2368-44b4-a09b-d1a664f94d09.png)

+ Ds18b20 (Резистор подтяжки на 4.7кОм !!)
+ ![Снимок экрана 2022-11-10 123654](https://user-images.githubusercontent.com/117163683/201010123-53ee7d6c-163f-4d7e-9e31-859d69eb8c51.png)


## Настройки
+ Перед загрузкой прошивки следует ввести данные своего WiFi !!!
```C++
const char* ssid = "имя нашей сети";   //имя нашей сети
const char* password = "пароль";    //пароль от нее
```
+ Тип подключенного датчика :
```C++
const bool DT = 0 ;     //Используемый датчик 0 -(DS18B20) , 1 -(BME280)
```
+ Время отправки данных на сервер
```C++
const byte Time = 15 ;    //время отправки 15мин
```

## Ссылки для менеджера плат
+ ESP8266- http://arduino.esp8266.com/stable/package_esp8266com_index.json
+ ESP32- https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

# Для тех кто захочет добавить свои датчики

## Формат пакета данных

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
## Желательные имена датчиков
* Температура: T*, TEMP*, BMPT*, DHTT*, DSW*, DS18T*, TEMPC, BATTEMP
*  Влажность: H*, RH, RH*, DHTH*, HUM, HUMID
*  Давление: BMPP*, MMHG, HPA, PRESS
*  Осадки: RAIN, RAIN
*  Скорость(ветер): WS, WS*, KMH, WIND
*  Азимут(направление): DEG, DIR
*  Напряжение: U*, V*, VOLT, VCC, UACC, VBAT, BATVOLT
*  Сила тока: I
*  Мощность: P, P*, W, W
*  Электроэнергия: WH, KWH, WH*, KWH
*  Водосчетчики: WM, WM* (ХВС=CWM, ГВС=HWM)
*  Освещенность: L*, LUX, LIGHT
*  Радиация: R*, RAD
* Логический(реле): S*, RL*, GPIO*, OUTPUT*, SIM*, RELAY
*  Сетевой трафик: RX, TX, RX*, TX
*  Концентрация: CO, CO2, CO*, CH4, PPM
*  Время(работы): NOW, TIME, UPTIME, CURTIME, WORKTIME
*  Сигнал(уровень): DBM, RSSI, WIFI, GSM, SIGNAL
*  Индекс УФ: UV, UV
*  Заряд батареи: MB2BAT, BATCHARGE
*  Пыль(частицы): PM, PM*, DUST
*  Точка росы: DP, DP*, DEW
*  Местоположение: LAT, LON, ALT (широта, долгота, высота) размещения датчика
