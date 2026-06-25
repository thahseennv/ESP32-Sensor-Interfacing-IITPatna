#include <ESP32Servo.h>              // ESP32 specific servo library

// Define servo pin
#define SERVO_PIN 13                 // PWM capable pin

Servo myServo;                       // Create servo object

void setup() {
  Serial.begin(115200);             // Start serial monitor

  myServo.attach(SERVO_PIN);        // Attach servo to pin
  Serial.println("Servo Motor Test");
}

void loop() {
  // Sweep from 0 to 180 degrees
  Serial.println("Moving to 0 degrees...");
  myServo.write(0);                  // Move to 0 degrees
  delay(1000);                       // Wait 1 second

  Serial.println("Moving to 90 degrees...");
  myServo.write(90);                 // Move to 90 degrees (center)
  delay(1000);                       // Wait 1 second

  Serial.println("Moving to 180 degrees...");
  myServo.write(180);                // Move to 180 degrees
  delay(1000);                       // Wait 1 second

  // Slow sweep from 0 to 180
  Serial.println("Slow sweep...");
  for (int angle = 0; angle <= 180; angle++) {
    myServo.write(angle);            // Write each angle one by one
    delay(15);                       // Small delay for smooth movement
  }

  // Slow sweep back from 180 to 0
  for (int angle = 180; angle >= 0; angle--) {
    myServo.write(angle);            // Write each angle one by one
    delay(15);                       // Small delay for smooth movement
  }
}
