#define GAS_SENSOR_PIN 34      // GPIO 34 is connected to the analog output of the gas sensor
                               // ESP32 ADC1 pins range from GPIO 32 to GPIO 39

void setup() {                 // Runs once when the ESP32 starts

  Serial.begin(115200);        // Starts serial communication at 115200 baud rate
}

void loop() {                  // Runs repeatedly after setup()

  int rawValue = analogRead(GAS_SENSOR_PIN);
  // Reads the analog value from the gas sensor
  // ESP32 ADC range is typically 0 to 4095

  float voltage = (rawValue / 4095.0) * 3.3;
  // Converts the ADC reading into voltage
  // 0 ADC value = 0V
  // 4095 ADC value = 3.3V

  Serial.print("Raw ADC: ");
  // Prints the label "Raw ADC: "

  Serial.print(rawValue);
  // Prints the raw ADC value from the sensor

  Serial.print("  Voltage: ");
  // Prints the label "Voltage: "

  Serial.println(voltage);
  // Prints the calculated voltage and moves to the next line

  delay(500);
  // Waits 500 milliseconds before taking the next reading
}
