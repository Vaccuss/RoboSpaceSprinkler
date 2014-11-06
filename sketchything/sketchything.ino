#include <DHT.h>
#include <BH1750.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#define DHTPIN 4
#define DHTTYPE DHT11

OneWire onewire(6);
DallasTemperature sensor(&onewire);
BH1750 lightMeter;
DHT dht(DHTPIN, DHTTYPE);

void setup(){
  Serial.begin(9600);
  lightMeter.begin();
  Serial.println("Test god damn test");
  sensor.begin();
  dht.begin();
  
}

void loop(){
  delay(500);
  uint16_t lux = lightMeter.readLightLevel();
  float humid = dht.readHumidity();
  Serial.print("Humidity: ");
  Serial.println(humid);
  Serial.print("The lux is: ");
  Serial.println(lux);
  sensor.requestTemperatures();
  
  Serial.print("Temp: ") ;
  Serial.println(sensor.getTempCByIndex(0));
  




}
