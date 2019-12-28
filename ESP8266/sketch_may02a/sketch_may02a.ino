// Libraries
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
// WiFi settings
const char* ssid     = "CatDog";          //WiFi名为 602 
const char* password = "aa135246A.";    //密码为 602602602
int buzzer10=10;

void setup() {
  pinMode(buzzer10,INPUT);   //设置引脚为输出模式
    // 初始化串口
  Serial.begin(115200);
  delay(10);
  // We start by connecting to a WiFi network
  
  Serial.print("Connecting to WIFI");
  Serial.println(ssid);
  //启动wifi连接，ssid为wifi名字，password为密码
  WiFi.begin(ssid, password);
  //轮询等待wifi连接完成 即 wifi.status() 状态为 WL_CONNECTED（表示已经连接上了）
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
int i=0;
void loop() {
 if(digitalRead(buzzer10)) {
    Serial.print(i);
    i=i+1;
    delay(100);
  }
} 


void connection() {
    HTTPClient http;
    Serial.print("[HTTP] begin...\n");
    http.begin("https://www.feefish.com"); //HTTP
    http.setTimeout(2000);

    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    int httpCode = http.GET();

    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        Serial.print(payload);
      }
    } else {
      Serial.print("fail");
      Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();
//  system_soft_wdt_feed();
}
