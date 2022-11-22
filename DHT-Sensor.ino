//Importing Library
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN  11     //Pin which is connected to the DHT sensor.
#define DHTTYPE           DHT11     // DHT 11 

DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;

void setup() {
  Serial.begin(9600); 
  // Initialize device.
  dht.begin();
  Serial.println("DHTxx Unified Sensor Example");
  // Print temperature sensor details.
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.println("Temperature");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" *C");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" *C");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" *C");  
  Serial.println("------------------------------------");
  // Print humidity sensor details.
  dht.humidity().getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.println("Humidity");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println("%");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println("%");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println("%");  
  Serial.println("------------------------------------");
  // Set delay between sensor readings based on sensor details. 
  delayMS = sensor.min_delay / 1000; 
}

void loop() { 
  delay(delayMS);
  sensors_event_t event;  
  dht.temperature().getEvent(&event); /* Read temperature value */    
  if (isnan(event.temperature)) { /* If temperature value is not a number */
    Serial.println("Error reading temperature!");
  }
  else {
    Serial.print("Temperature : ");
    Serial.print(event.temperature);
    Serial.println(" *C");
  } 
  dht.humidity().getEvent(&event);  /* Read humidity value */
  if (isnan(event.relative_humidity)) { /* If humidity value is not a number */
    Serial.println("Error reading humidity!");
  }
  else {
    Serial.print("Humidity : ");
    Serial.print(event.relative_humidity);
    Serial.println("%");
  }        
}
