#include <HardwareSerial.h>   // Library for using additional UART ports on ESP32

HardwareSerial GPS(1);        // Creates UART1 object named GPS

void setup() {

  Serial.begin(115200);       // Starts Serial Monitor communication

  // GPS.begin(baud rate, configuration, RX pin, TX pin)
  GPS.begin(9600, SERIAL_8N1, 16, 17);
  // Initializes GPS communication
  // 9600      -> Default baud rate of NEO-6M
  // SERIAL_8N1 -> 8 data bits, No parity, 1 stop bit
  // 16        -> ESP32 RX pin connected to GPS TX
  // 17        -> ESP32 TX pin connected to GPS RX

  Serial.println("NEO-6M GPS Initialized");
}

void loop() {

  while (GPS.available()) {
    // Checks if GPS has sent any data

    char c = GPS.read();
    // Reads one character from GPS module

    Serial.print(c);
    // Prints the received character to Serial Monitor
  }
}
