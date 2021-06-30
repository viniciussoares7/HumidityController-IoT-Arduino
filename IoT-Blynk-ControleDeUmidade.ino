#define BLYNK_PRINT Serial
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include <DHT.h>
char auth[] = " "; // Token pessoal.
char ssid[] = " "; //LOGIN DA REDE
char pass[] = " "; //SENHA DA REDE
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
declarado no aplicativo.
SimpleTimer timer;
WidgetLED LEDb1(V1);
WidgetLED LEDb2(V2);
void sendSensor()
{
float h = dht.readHumidity();
float t = dht.readTemperature();
Serial.print("temp: ");
Serial.println (t);
Serial.print("umid: ");
Serial.println (h);
if (isnan(h) || isnan(t)) {
Serial.println("Failed to read from DHT sensor!");
return; }
Blynk.virtualWrite(V5, h);
Blynk.virtualWrite(V6, t);
Blynk.virtualWrite(V0, t);
WidgetLED led1(V1);
if(h<50){
20
led1.on();
}
else{led1.off();}
}
void setup()
{
Serial.begin(9600);
Blynk.begin(auth, ssid, pass);
dht.begin();
timer.setInterval(1000L, sendSensor);
}
void loop()
{
Blynk.run(); // Initiates Blynk
timer.run(); // Initiates SimpleTimer
}
