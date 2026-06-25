#define SOIL_PIN 34          // Defines GPIO 34 as the analog input pin for the soil moisture sensor

void setup() {               // Runs once when the ESP32 starts
  Serial.begin(115200);      // Starts serial communication at 115200 baud rate
}

void loop() {                // Runs repeatedly after setup

  float moist = analogRead(SOIL_PIN);
  // Reads the analog value from the soil moisture sensor
  // ESP32 ADC range is typically 0 to 4095

  float moist_percentage = (4095 - moist) / 4096 * 100;
  // Converts the sensor reading into an approximate moisture percentage
  // Higher moisture generally gives a lower ADC value
  // 0 = dry, 100 = wet (depending on sensor calibration)

  Serial.print("Moisture: ");
  // Prints the label "Moisture: "

  Serial.println(moist);
  // Prints the raw ADC value read from the sensor

  Serial.print("Moisture Percentage: ");
  // Prints the label "Moisture Percentage: "

  Serial.print(moist);
  // Prints the moisture value
  // NOTE: This should probably be moist_percentage instead of moist

  Serial.println("%");
  // Prints the percentage symbol and moves to the next line

  delay(500);
  // Waits for 500 milliseconds before taking the next reading
}
