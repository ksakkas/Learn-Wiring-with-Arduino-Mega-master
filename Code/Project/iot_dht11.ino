#define BLYNK_PRINT Serial
 
#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266.h>

#include <DHT.h> 

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "-nUXFYr8jH5cGRN3y2MuTOAYFRzXYUwA";
 
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "vodafone_kostas";
char pass[] = "2682060434k";


#define DHTPIN D4          // What digital pin we're connected to
#define DHTPIN2 D3          // What digital pin we're connected to
#define DHTTYPE DHT11     // DHT 11<p>DHT dht(DHTPIN, DHTTYPE);
DHT dht(DHTPIN, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);

BlynkTimer timer;
float t;
float h;
float t2;
float h2;
void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(1000L, sendSensor);
}
 
void loop()
{
  Blynk.run();
  timer.run();
}
 
 
// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void sendSensor()
{
  h = dht.readHumidity();
  t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

   h2 = dht2.readHumidity();
  t2 = dht2.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
//  l = analogRead(LDR);
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, t);
  Blynk.virtualWrite(V6, h);
   Blynk.virtualWrite(V7, t2);
  Blynk.virtualWrite(V8, h2);
}
 