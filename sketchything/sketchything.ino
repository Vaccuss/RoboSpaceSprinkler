
#include <BH1750.h>
#include <Wire.h>
#include <DHT.h>


BH1750 lightMeter;
#define DHT11_PIN 6


void setup(){
  Serial.begin(9600);
  lightMeter.begin();
  Serial.println("Test god damn test");
}

void loop(){
int lux = lightMeter.readLightLevel();
Serial.println(lux);





}
