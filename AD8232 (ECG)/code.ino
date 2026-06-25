// No library needed for AD8232

// Define pins
#define ECG_PIN  34                  // Analog output of AD8232
#define LO_PLUS  32                  // Leads-off detection positive
#define LO_MINUS 33                  // Leads-off detection negative

void setup() {
  Serial.begin(115200);             // Start serial monitor

  pinMode(LO_PLUS, INPUT);          // Leads-off detection pins as input
  pinMode(LO_MINUS, INPUT);         // Leads-off detection pins as input

  Serial.println("ECG Monitor Ready. Place electrodes correctly.");
}

void loop() {
  // Check if electrodes are connected properly
  if (digitalRead(LO_PLUS) == HIGH || digitalRead(LO_MINUS) == HIGH) {
    Serial.println("Electrodes not connected!");  // Lead-off detected
  } else {
    int ecgValue = analogRead(ECG_PIN);  // Read ECG signal (0-4095)
    Serial.println(ecgValue);            // Print raw value for Serial Plotter
  }

  delay(10);                         // 10ms delay = 100Hz sampling rate
}
