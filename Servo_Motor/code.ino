#include <ESP32Servo.h>      // Library for controlling servo motors with ESP32

Servo myServo;               // Creates a Servo object named myServo

void setup() {              // Runs once when the ESP32 starts

  myServo.attach(13);
  // Attaches the servo signal wire to GPIO 13
  // This pin will generate the PWM signal required by the servo
}

void loop() {               // Runs repeatedly after setup()

  myServo.write(0);
  // Rotates the servo to 0 degrees

  delay(1000);
  // Waits for 1 second

  myServo.write(90);
  // Rotates the servo to 90 degrees (middle position)

  delay(1000);
  // Waits for 1 second

  myServo.write(180);
  // Rotates the servo to 180 degrees

  delay(1000);
  // Waits for 1 second before repeating the cycle
}
