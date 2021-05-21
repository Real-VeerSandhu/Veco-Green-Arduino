#include <SimpleDHT.h>

int msensor = A1;
int msvalue = 0;
int led = 13;
boolean flag  = false;

int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);

void setup() {
  Serial.begin(9600);
  pinMode(msensor, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  

  Serial.println("=================================");
  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
  
  Serial.println("Sensors: ");
//  Serial.print((int)temperature); Serial.print(" *C, "); 
//  Serial.print((int)humidity); Serial.println(" H");
  Serial.print("Temperature (*C) "); Serial.println((int)temperature);
  Serial.print("Humidity (%) "); Serial.println((int)humidity);
  msvalue = analogRead(msensor);
  float a = msvalue;
//  Serial.print("Moisture "); Serial.println(msvalue);
  Serial.print("Moisture (%) "); Serial.println((a/1000)*100);

  
//
//  if (humidity > 70) {
//    Serial.println("Substances: Compost");
//  } else {
//    Serial.println("Substances: N / A");
//  }

    delay(1500);

}
