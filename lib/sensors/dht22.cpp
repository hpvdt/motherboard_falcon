#include "dht22.h"

DHT_Unified dht(DHT_PIN, DHT_TYPE);

void setupDHT() {

    dht.begin();
    sensor_t sensor;
    delayMS = sensor.min_delay / 1000;

}
void DHT_measurements() {
    // hi

    // Get temperature event and print its value.
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature))
  {
    SerialUSB.println(F("Error reading temperature!"));
  }
  else
  {
    SerialUSB.print(F("Temperature: "));
    SerialUSB.print(event.temperature);
    SerialUSB.println(F("°C"));
  }
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity))
  {
    SerialUSB.println(F("Error reading humidity!"));
  }
  else
  {
    SerialUSB.print(F("Humidity: "));
    SerialUSB.print(event.relative_humidity);
    SerialUSB.println(F("%"));
  }

}