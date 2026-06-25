// HC-05 uses UART communication
// ESP32 has multiple UART ports, we use UART2

#define RXD2 16                      // ESP32 RX2 pin connected to HC-05 TX
#define TXD2 17                      // ESP32 TX2 pin connected to HC-05 RX

void setup() {
  Serial.begin(115200);             // Serial monitor
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);  // HC-05 default baud rate is 9600

  Serial.println("Bluetooth Ready. Pair HC-05 and send data...");
}

void loop() {
  // If data received from Bluetooth (phone/PC)
  if (Serial2.available()) {
    char received = Serial2.read();  // Read incoming character
    Serial.print("Received: ");
    Serial.println(received);        // Print to serial monitor

    // Echo back to Bluetooth device
    Serial2.print("ESP32 got: ");
    Serial2.println(received);
  }

  // If data typed in serial monitor, send via Bluetooth
  if (Serial.available()) {
    char toSend = Serial.read();     // Read from serial monitor
    Serial2.print(toSend);           // Send via Bluetooth
    Serial.print("Sent: ");
    Serial.println(toSend);
  }
}
