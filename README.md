========== ПОДДЕРЖИВАЕМЫЕ ПЛАТФОРМЫ ==========
Все платформы на базе ESP

========== НАСТРОЙКИ ==========
Настройки сети WiFi
![image](https://user-images.githubusercontent.com/117163683/199227124-82bb6573-3631-4f3d-8a78-cd7a92644cc4.png)

========== ДЛЯ ТЕХ КТО ХОЧЕТ ДОРАБОТАТЬ ПРОШИВКУ ==========
Для наименования датчиков следует использовать следующие имена :

 Температура: T*, TEMP*, BMPT*, DHTT*, DSW*, DS18T*, TEMPC, BATTEMP
  Влажность: H*, RH, RH*, DHTH*, HUM, HUMID
  Давление: BMPP*, MMHG, HPA, PRESS
  Осадки: RAIN, RAIN
  Скорость(ветер): WS, WS*, KMH, WIND
  Азимут(направление): DEG, DIR
  Напряжение: U*, V*, VOLT, VCC, UACC, VBAT, BATVOLT
  Сила тока: I
  Мощность: P, P*, W, W
  Электроэнергия: WH, KWH, WH*, KWH
  Водосчетчики: WM, WM* (ХВС=CWM, ГВС=HWM)
  Освещенность: L*, LUX, LIGHT
  Радиация: R*, RAD
  Логический(реле): S*, RL*, GPIO*, OUTPUT*, SIM*, RELAY
  Сетевой трафик: RX, TX, RX*, TX
  Концентрация: CO, CO2, CO*, CH4, PPM
  Время(работы): NOW, TIME, UPTIME, CURTIME, WORKTIME
  Сигнал(уровень): DBM, RSSI, WIFI, GSM, SIGNAL
  Индекс УФ: UV, UV
  Заряд батареи: MB2BAT, BATCHARGE
  Пыль(частицы): PM, PM*, DUST
  Точка росы: DP, DP*, DEW
  Местоположение: LAT, LON, ALT (широта, долгота, высота) размещения датчика
[*]- порядковый номер датчика

Чтобы сервер нас понял мы должны отправлять данные в определенном виде:
Формат пакета данных:
  #MAC[#NAME]\n
  #mac1#value1[#time1][#name1]\n
  ...
  #macN#valueN[#timeN][#nameN]\n
  ##
  -------------------
  \n - спецсимвол конца строки - код 10(0A).
  ## - признак окончания пакета данных (после него разрыв соединения), в [ ] заключен необязательный параметр.

Время отправки данных на сервер составляет 7 мин
Поменять можно здесь:
![image](https://user-images.githubusercontent.com/117163683/199226982-8201557b-9a74-498c-a588-8f0d24dd8c58.png)

