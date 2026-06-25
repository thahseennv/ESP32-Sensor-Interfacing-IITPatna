const int hallPin = 27;      // GPIO 27 is connected to the Hall Effect sensor output

void setup() {               // Runs once when the ESP32 starts

  Serial.begin(115200);      // Starts serial communication at 115200 baud rate

  pinMode(hallPin, INPUT);   // Sets hallPin as an input pin
}

void loop() {                // Runs repeatedly after setup()

  int state = digitalRead(hallPin);
  // Reads the digital output from the Hall Effect sensor
  // HIGH = No magnet detected
  // LOW = Magnet detected (for most Hall sensor modules)

  if (state == LOW) {
    // Checks if a magnet is near the sensor

    Serial.println("🧲 Magnet detected!");
    // Prints message when a magnet is detected
  }
  else {
    // Executes when no magnet is detected

    Serial.println("No magnet");
    // Prints message indicating no magnetic field detected
  }

  delay(500);
  // Waits 500 milliseconds before taking the next reading
}
