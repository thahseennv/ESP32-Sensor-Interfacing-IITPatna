#include <Wire.h>

// ADXL337 is an analog accelerometer
// Connect X, Y, Z output pins to ESP32 analog pins
#define X_PIN 34
#define Y_PIN 35
#define Z_PIN 32

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Read raw analog values (0-4095 for 12-bit ADC)
  int rawX = analogRead(X_PIN);
  int rawY = analogRead(Y_PIN);
  int rawZ = analogRead(Z_PIN);

  // Convert to voltage (ESP32 ADC is 3.3V, 12-bit)
  float voltX = (rawX / 4095.0) * 3.3;
  float voltY = (rawY / 4095.0) * 3.3;
  float voltZ = (rawZ / 4095.0) * 3.3;

  // Convert voltage to acceleration in g
  // ADXL337: sensitivity ~330mV/g, zero-g at ~1.65V
  float accX = (voltX - 1.65) / 0.330;
  float accY = (voltY - 1.65) / 0.330;
  float accZ = (voltZ - 1.65) / 0.330;

  // Print values
  Serial.print("X: "); Serial.print(accX);
  Serial.print(" g | Y: "); Serial.print(accY);
  Serial.print(" g | Z: "); Serial.println(accZ);

  delay(500);
}
