#include <dht.h>              // Includes the DHT sensor library

#define dataPin 27            // Defines GPIO pin 27 as the data pin connected to DHT22

dht DHT;                      // Creates an object named DHT of type dht

void setup() {                // Runs once when the ESP32 starts
  Serial.begin(115200);         // Starts serial communication at 115200 baud rate
}

void loop() {                 // Runs repeatedly after setup()

  int readData = DHT.read22(dataPin);  
  // Reads data from the DHT22 sensor connected to dataPin
  // The return value (readData) indicates whether reading was successful

  float t = DHT.temperature;  
  // Stores the temperature value read from the sensor into variable t

  float h = DHT.humidity;     
  // Stores the humidity value read from the sensor into variable h

  // Printing the temperature value on the Serial Monitor
  Serial.print("Temperature = ");  
  // Prints the text "Temperature = "

  Serial.print(t);            
  // Prints the temperature value

  Serial.print(" *C ");       
  // Prints the temperature unit (degrees Celsius)

  // Printing the humidity value on the Serial Monitor
  Serial.print("    Humidity = ");  
  // Prints the text "Humidity = "

  Serial.print(h);            
  // Prints the humidity value

  Serial.println(" % ");      
  // Prints the humidity unit (%) and moves to the next line

  delay(2000);                
  // Waits for 2000 milliseconds (2 seconds)
  // DHT22 should not be read too frequently
}
