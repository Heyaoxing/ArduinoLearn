// Libraries
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#define LEDPIN 2                   //GPIO2
// WiFi settings
const char* ssid     = "CatDog";          //WiFi名为 602
const char* password = "aa135246A.";    //密码为 602602602

char codes[4];
char numbers[4];
String code_1 = "01111";
String code_2 = "00111";
String code_3 = "00011";
String code_4 = "00001";
String code_5 = "00000";
String code_6 = "10000";
String code_7 = "11000";
String code_8 = "11100";
String code_9 = "11110";
String code_0 = "11111";

void setup() {
  pinMode(LEDPIN, INPUT);
  // 初始化串口
  Serial.begin(115200);
  delay(10);
  // We start by connecting to a WiFi network

  Serial.print("Connecting to WIFI");
  Serial.println(ssid);
  //启动wifi连接，ssid为wifi名字，password为密码`
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


int counter = 0;
void loop() {

//  Serial.println(digitalRead(LEDPIN));
//  delay(100);

  if (analogRead(LEDPIN) > 0) {
    counter++;
  } else if (counter > 0) {
    process(counter);
    counter = 0;
  }

  delay(10);
}



int code_index = 0;
void process(int i) {
  char code = '0';
  if (i > 15) {
    Serial.println("长编码");
    code = '1';
  } else if (i > 5 && i < 15) {
    Serial.println("短编码");
    code = '0';
  }

  codes[code_index] = code;
  if (code_index == 4) {
    decoding();
    code_index = 0;
  } else {
    code_index++;
  }
}


int num_index = 0;
void decoding() {
  if (num_index == 4) {
    translation();
    num_index = 0;
  }

  Serial.println("解码");
  Serial.println(codes);
  if (strcmp(codes, "01111") == 0) {
    numbers[num_index] = '1';
    Serial.println("电码 1");
  } else if (strcmp(codes, "00111") == 0) {
    numbers[num_index] = '2';
    Serial.println("电码 2");
  } else if (strcmp(codes, "00011") == 0) {
    numbers[num_index] = '3';
    Serial.println("电码 3");
  } else if (strcmp(codes, "00001") == 0) {
    numbers[num_index] = '4';
    Serial.println("电码 4");
  } else if (strcmp(codes, "00000") == 0) {
    numbers[num_index] = '5';
    Serial.println("电码 5");
  } else if (strcmp(codes, "10000") == 0) {
    numbers[num_index] = '6';
    Serial.println("电码 6");
  } else if (strcmp(codes, "11000") == 0) {
    numbers[num_index] = '7';
    Serial.println("电码 7");
  } else if (strcmp(codes, "11100") == 0) {
    numbers[num_index] = '8';
    Serial.println("电码 8");
  } else if (strcmp(codes, "11110") == 0) {
    numbers[num_index] = '9';
    Serial.println("电码 9");
  } else if (strcmp(codes, "11111") == 0) {
    numbers[num_index] = '0';
    Serial.println("电码 0");
  } else {
    Serial.println("解码失败");
  }
  num_index++;
}

void translation() {
  Serial.println("翻译");
  Serial.println(numbers);
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
