#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>

WiFiClient client;
HTTPClient http;

void opendata(){
  http.begin(client,"opendata.cwb.gov.tw",80,"/api/v1/rest/datastore/E-A0015-001?Authorization=<Token>&limit=1&offset=1&format=JSON&areaName=%E6%96%B0%E5%8C%97%E5%B8%82");
  int httpcode = http.GET();
  if (httpcode > 0){
    Serial.print("GET!");
    // DynamicJsonDocument doc(4096);
    // deserializeJson(doc, http.getString());
    // Serial.println(doc["records"]["location"][0]["locationName"].as<long>()); //地區
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