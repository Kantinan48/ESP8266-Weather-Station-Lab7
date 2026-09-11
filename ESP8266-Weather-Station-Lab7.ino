#define BLYNK_TEMPLATE_ID "TMPL6fSq9AmQm"
#define BLYNK_TEMPLATE_NAME "Weather Station Lab7"
#define BLYNK_AUTH_TOKEN "DP0zxRzkcoRZOTdQpsLH0bgzAzPor4xo"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "@CMRU-SCI";    
char pass[] = ""; 

#define DHTPIN D4     
#define DHTTYPE DHT11
#define LDR_PIN D5    
#define RAIN_PIN D6   

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

int lastLdrState = -1;
int lastRainState = -1;

void checkRealtimeSensors() {
  int currentLdr = digitalRead(LDR_PIN);
  if (currentLdr != lastLdrState) {
    lastLdrState = currentLdr;
    if (currentLdr == HIGH) {
      Blynk.virtualWrite(V3, "กลางคืน");
    } else {
      Blynk.virtualWrite(V3, "กลางวัน");
    }
  }

  int currentRain = digitalRead(RAIN_PIN);
  if (currentRain != lastRainState) {
    lastRainState = currentRain;
    if (currentRain == LOW) {
      Blynk.virtualWrite(V4, "ฝนกำลังตก");
    } else {
      Blynk.virtualWrite(V4, "ฝนไม่ตก");
    }
  }
}

void sendDHTData() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (!isnan(h) && !isnan(t)) {
    float hic = dht.computeHeatIndex(t, h, false);
    Blynk.virtualWrite(V0, t);   
    Blynk.virtualWrite(V1, h);   
    Blynk.virtualWrite(V2, hic); 
  }
}

void setup() {
  Serial.begin(115200);
  
  pinMode(LDR_PIN, INPUT);
  pinMode(RAIN_PIN, INPUT);
  
  dht.begin();
  Blynk.begin(auth, ssid, pass);

  timer.setInterval(100L, checkRealtimeSensors);
  
  timer.setInterval(2000L, sendDHTData);
}

void loop() {
  Blynk.run();
  timer.run();
}