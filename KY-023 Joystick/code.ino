// KY-023 has 2 analog axes (X, Y) and 1 digital button

// Define pins
#define VRX_PIN  34                  // X axis analog pin
#define VRY_PIN  35                  // Y axis analog pin
#define SW_PIN   32                  // Button pin

void setup() {
  Serial.begin(115200);             // Start serial monitor

  pinMode(SW_PIN, INPUT_PULLUP);    // Button uses internal pullup (LOW when pressed)

  Serial.println("Move joystick to see values...");
}

void loop() {
  int xValue = analogRead(VRX_PIN);  // Read X axis (0-4095)
  int yValue = analogRead(VRY_PIN);  // Read Y axis (0-4095)
  int swValue = digitalRead(SW_PIN); // Read button (LOW = pressed)

  // Print raw values
  Serial.print("X: "); Serial.print(xValue);
  Serial.print(" | Y: "); Serial.print(yValue);
  Serial.print(" | Button: ");

  // Center position is around 2048
  // Left/Right and Up/Down determined by value going above or below center
  if (xValue < 1000) {
    Serial.print("LEFT ");
  } else if (xValue > 3000) {
    Serial.print("RIGHT ");
  }

  if (yValue < 1000) {
    Serial.print("UP ");
  } else if (yValue > 3000) {
    Serial.print("DOWN ");
  }

  if (swValue == LOW) {
    Serial.print("PRESSED");         // Button pressed
  }

  Serial.println();

  delay(200);                        // Small delay for readable output
}
