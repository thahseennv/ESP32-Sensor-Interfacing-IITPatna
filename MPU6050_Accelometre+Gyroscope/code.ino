#include <Wire.h>                 // Library for I2C communication
#include <Adafruit_MPU6050.h>     // Library for MPU6050 sensor
#include <Adafruit_Sensor.h>      // Adafruit unified sensor library

Adafruit_MPU6050 mpu;             // Creates an MPU6050 object named mpu

void setup() {                    // Runs once when the ESP32 starts

  Serial.begin(115200);           // Starts serial communication at 115200 baud rate

  if (!mpu.begin()) {             // Attempts to initialize the MPU6050 sensor

    Serial.println("MPU6050 not found!");
    // Prints an error message if the sensor is not detected

    while (1) delay(10);
    // Stops the program here and keeps checking every 10 ms
  }

  Serial.println("MPU6050 initialized");
  // Prints a success message if initialization is successful
}

void loop() {                     // Runs repeatedly after setup()

  sensors_event_t a, g, temp;
  // Creates three structures to store:
  // a = acceleration data
  // g = gyroscope data
  // temp = temperature data

  mpu.getEvent(&a, &g, &temp);
  // Reads the latest sensor values and stores them in the structures

  Serial.print("Accel X: ");
  // Prints label for X-axis acceleration

  Serial.print(a.acceleration.x);
  // Prints acceleration along X-axis (m/s²)

  Serial.print("  Y: ");
  // Prints label for Y-axis acceleration

  Serial.print(a.acceleration.y);
  // Prints acceleration along Y-axis (m/s²)

  Serial.print("  Z: ");
  // Prints label for Z-axis acceleration

  Serial.println(a.acceleration.z);
  // Prints acceleration along Z-axis (m/s²) and moves to next line

  Serial.print("Gyro X: ");
  // Prints label for X-axis angular velocity

  Serial.print(g.gyro.x);
  // Prints angular velocity along X-axis (rad/s)

  Serial.print("  Y: ");
  // Prints label for Y-axis angular velocity

  Serial.print(g.gyro.y);
  // Prints angular velocity along Y-axis (rad/s)

  Serial.print("  Z: ");
  // Prints label for Z-axis angular velocity

  Serial.println(g.gyro.z);
  // Prints angular velocity along Z-axis (rad/s) and moves to next line

  Serial.print("Temp: ");
  // Prints temperature label

  Serial.println(temp.temperature);
  // Prints temperature value in degrees Celsius

  delay(500);
  // Waits 500 milliseconds before taking the next reading
}
