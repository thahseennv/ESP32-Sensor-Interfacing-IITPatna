#include <Wire.h>                    // I2C communication library
#include "MAX30105.h"                // MAX30102/MAX30105 sensor library
#include "heartRate.h"               // Heart rate calculation library

MAX30105 particleSensor;             // Create sensor object

// Variables for heart rate calculation
byte rateSpot = 0;                   // Index for rate array
long lastBeat = 0;                   // Time of last beat in ms
float beatsPerMinute;                // Calculated BPM
int beatAvg;                         // Average BPM
long delta;                          // Time between beats

// Array to store last 4 BPM readings for averaging
byte rates[4];

void setup() {
  Serial.begin(115200);              // Start serial monitor

  // Initialize sensor, if failed stop program
  if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) {
    Serial.println("MAX30102 not found! Check wiring.");
    while (true);
  }

  Serial.println("Place finger on sensor...");

  // Configure sensor settings
  particleSensor.setup();            // Default settings
  particleSensor.setPulseAmplitudeRed(0x0A);   // Low red LED brightness
  particleSensor.setPulseAmplitudeGreen(0);     // Turn off green LED
}

void loop() {
  long irValue = particleSensor.getIR();  // Read IR value from sensor

  // checkForBeat returns true when a heartbeat is detected
  if (checkForBeat(irValue) == true) {
    delta = millis() - lastBeat;     // Time since last beat
    lastBeat = millis();             // Update last beat time

    beatsPerMinute = 60 / (delta / 1000.0);  // Calculate BPM

    // Only store valid BPM readings (20-255)
    if (beatsPerMinute < 255 && beatsPerMinute > 20) {
      rates[rateSpot++] = (byte)beatsPerMinute;  // Store reading
      rateSpot %= 4;                              // Wrap around array

      // Calculate average of last 4 readings
      beatAvg = 0;
      for (byte x = 0; x < 4; x++) {
        beatAvg += rates[x];
      }
      beatAvg /= 4;
    }
  }

  // Print IR value and BPM to serial monitor
  Serial.print("IR="); Serial.print(irValue);
  Serial.print(", BPM="); Serial.print(beatsPerMinute);
  Serial.print(", Avg BPM="); Serial.println(beatAvg);

  // If IR value is low, no finger detected
  if (irValue < 50000) {
    Serial.println("No finger detected!");
  }
}
