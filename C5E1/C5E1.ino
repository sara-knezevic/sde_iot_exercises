#include <DHT.h>
#include <DHT_U.h>

#define DHT_PIN 2
#define DHT_TYPE DHT22

DHT dht(DHT_PIN, DHT_TYPE);

float dhtTemp = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2001);
  dhtTemp = dht.readTemperature();

  Serial.print(dhtTemp);
  Serial.println(" Celsius");

  delay(5000);
}
