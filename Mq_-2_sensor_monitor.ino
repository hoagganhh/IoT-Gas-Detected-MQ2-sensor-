#define BLYNK_TEMPLATE_ID "TMPL66LKAHoaF"
#define BLYNK_TEMPLATE_NAME "esp32 gas detect mq2"
#define BLYNK_AUTH_TOKEN "m39zxpLk7bf_hE4_yPay6xlV4abBEedT"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
char ssid[] = "LAPTOP-8J75CQDF 6204";  
char pass[] = "12345678"; 

BlynkTimer timer;
int pinValue = 0;

#define Buzzer 27  
#define LedRed 2  
#define Sensor 36 

void setup() {
  Serial.begin(115200);
  pinMode(LedRed, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(Sensor, INPUT);
  
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  
  timer.setInterval(100L, notification);
}

BLYNK_WRITE(V0) {
  pinValue = param.asInt();  
}

void notification() {
  int sensorRaw = analogRead(Sensor); 
  Serial.println(sensorRaw);
  
  int sensor = map(sensorRaw, 0, 4095, 0, 100);  
  
  if (pinValue == 1) {
    if (sensor <= 50) {
      digitalWrite(LedRed, LOW);
      digitalWrite(Buzzer, LOW);
      Serial.println("Gas value: Normal");
    } else if (sensor > 50) {
      Blynk.logEvent("gas_leak", "Warning! Gas leak detected");
      digitalWrite(LedRed, HIGH);
      digitalWrite(Buzzer, HIGH);
      Serial.println("Gas value: High");
    }
    Blynk.virtualWrite(V1, sensor);
  } else {
    digitalWrite(LedRed, LOW);
    digitalWrite(Buzzer, LOW);
  } 
}

void loop() {
  Blynk.run();
  timer.run();
}