#define LED_PIN 2          // GPIO 2 is connected to the onboard LED
                           // Change this pin number if your LED is connected elsewhere

void setup() {             // Runs once when the ESP32 starts

  pinMode(LED_PIN, OUTPUT);
  // Configures the LED pin as an output
}

void loop() {              // Runs repeatedly after setup()

  digitalWrite(LED_PIN, HIGH);
  // Turns the LED ON by applying HIGH (3.3V)

  delay(500);
  // Keeps the LED ON for 500 milliseconds (0.5 seconds)

  digitalWrite(LED_PIN, LOW);
  // Turns the LED OFF by applying LOW (0V)

  delay(500);
  // Keeps the LED OFF for 500 milliseconds (0.5 seconds)
}
