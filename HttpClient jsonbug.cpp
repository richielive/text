#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>

WiFiClientSecure client;
HTTPClient http;

void opendata(){
  client.setInsecure();
  http.begin(client,"opendata.cwb.gov.tw",443,"/api/v1/rest/datastore/E-A0015-001?Authorization=<Token>&limit=1&offset=1&format=JSON&areaName=新北市");
  int httpcode = http.GET();
  if (httpcode > 0){
    Serial.print("GET!");
    // DynamicJsonDocument doc(4096);  //用arduino json 印出需要的物件
    // deserializeJson(doc, http.getString());
    // Serial.printf(doc["records"]["location"][0]["locationName"]); //地區
    Serial.print(http.getString());  //將整串json列印出來
  }
  else{
    Serial.println("請求失敗qq");
    Serial.printf("ERROR:");
    Serial.print(httpcode);
  }
  http.end();
}

void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);
  Serial.print("連線中");
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(1000);
  }
  Serial.print("WiFi連接成功!\n");
  opendata();
}

void loop(){
  
}

// 最後修改時間 2022/4/27 PM 10:56
