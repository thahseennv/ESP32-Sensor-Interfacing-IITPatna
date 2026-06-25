const int PIR_PIN = 27;      // GPIO 27 is connected to the PIR motion sensor output

void setup() {               // Runs once when the ESP32 starts

  Serial.begin(115200);      // Starts serial communication at 115200 baud rate

  pinMode(PIR_PIN, INPUT);   // Configures the PIR sensor pin as an input
}

void loop() {                // Runs repeatedly after setup()

  int motion = digitalRead(PIR_PIN);
  // Reads the digital output from the PIR sensor
  // HIGH = Motion detected
  // LOW = No motion detected

  if (motion == HIGH) {
    // Checks if motion is detected

    Serial.println("Motion Detected!");
    // Prints a message when motion is detected
  }
  else {
    // Executes when no motion is detected

    Serial.println("No Motion");
    // Prints a message indicating no motion
  }

  delay(500);
  // Waits for 500 milliseconds before checking again
}
