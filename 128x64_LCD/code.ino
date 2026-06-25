#include <Wire.h>                    // I2C communication library
#include <Adafruit_GFX.h>           // Graphics library for displays
#include <Adafruit_SSD1306.h>       // SSD1306 OLED driver library

// Display dimensions in pixels
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// I2C address of OLED (most common is 0x3C, some modules use 0x3D)
#define OLED_ADDR 0x3C

// Create display object (-1 means no reset pin used)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);             // Start serial for debugging

  // Initialize OLED, if failed print error and stop
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println("OLED not found!");  // Check wiring or I2C address
    while (true);                       // Stop program here
  }

  display.clearDisplay();           // Clear any garbage on screen

  display.setTextSize(1);           // Text size 1 = smallest (6x8 pixels per char)
  display.setTextColor(WHITE);      // White text on black background

  display.setCursor(0, 0);          // Set cursor to top-left corner (x=0, y=0)
  display.println("Hello, ESP32!"); // Print first line

  display.setCursor(0, 20);         // Move cursor down to y=20
  display.println("128x64 OLED");   // Print second line

  display.setCursor(0, 40);         // Move cursor down to y=40
  display.println("IIT Patna!");    // Print third line

  display.display();                // Actually push buffer to screen (must call this!)
}

void loop() {
  // Nothing needed here
  // Everything is displayed once in setup()
}
