/*
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
  -------------------
  Формат пакета данных:
  #MAC[#NAME]\n
  #mac1#value1[#time1][#name1]\n
  ...
  #macN#valueN[#timeN][#nameN]\n
  ##
  -------------------
  \n - спецсимвол конца строки - код 10(0A).
  ## - признак окончания пакета данных (после него разрыв соединения), в [] заключен необязательный параметр.

*/
void Send() {

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);  // Подключаемся к wifi

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println(); // отправляем в Serial данные о подключении
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("MAC address: ");
  Serial.println(WiFi.macAddress());
  Serial.println();

  Serial.print("connecting to ");   // подключаемся к серверу
  Serial.println(host);

  // Используем WiFiClient для создания TCP соединения
  WiFiClient client;

  if (!client.connect(host, port)) {
    Serial.println("Server connection failed");
    return;
  }

  //-------отправляем данные-------
  Serial.println("Sending...");

  client.print("#");
  client.print(WiFi.macAddress()); // отправляем МАС
  client.print("#");
  client.print("Meteo_station"); // название устройства
  client.println();

  if (DT == 1) {
    bme.oneMeasurement();                          // Если используем принудительный мод - необходимо будить датчик для проведения измерения
    while (bme.isMeasuring());                     // И дождаться окончания текущего измерения , чтобы не взять устаревшие данные

    client.print("#");
    client.print("T1");
    client.print("#");
    Serial.println(bme.readTemperature());
    client.println(bme.readTemperature());
    /*
         client.print("#");
          client.print("T2");
           client.print("#");
        client.print(sensor.getTemp());
        Serial.print(sensor.getTemp());
    */
    client.print("#");
    client.print("HPA");
    client.print("#");
    Serial.println(pressureToMmHg(bme.readPressure()));
    client.println(pressureToMmHg(bme.readPressure()));
/*
    client.print("#");
    client.print("ALT");
    client.print("#");
    Serial.print(pressureToAltitude(pressure));
    client.println(pressureToAltitude(pressure));
*/
    client.print("#");
    client.print("H");
    client.print("#");
    Serial.println(bme.readHumidity());
    client.println(bme.readHumidity());
    
  } else if (DT == 0) {
    sensor.requestTemp(); // забераем температуру с градусника
    delay (70);
    sensor.readTemp();
    client.print("#");
    client.print("T2");
    client.print("#");
    client.print(sensor.getTemp());
    Serial.println(sensor.getTemp());
    client.println("##");
  }

  delay(10);

  // вообще на ответ нужно както реагировать
  Serial.print("Requesting: ");      // читаем ответ с и отправляем его в сериал
  while (client.available()) {
    String line = client.readStringUntil('\n');
    Serial.print(line);
  }
  client.stop();
  Serial.println();
  Serial.println("Closing connection");

  WiFi.disconnect(); // отключаемся от сети
  Serial.println("Disconnect WiFi.");
}
