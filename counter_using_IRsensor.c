#include <Wire.h>                // Library for I2C communication
#include <LiquidCrystal_I2C.h>   // Library for I2C LCD display

#define IR_ENTRY 26              // GPIO 26 connected to entry IR sensor
#define IR_EXIT  27              // GPIO 27 connected to exit IR sensor

LiquidCrystal_I2C lcd(0x27, 16, 2);
// Creates an LCD object
// 0x27 = I2C address of LCD
// 16 = number of columns
// 2 = number of rows

int count = 0;                   // Stores the number of people inside
int lastCount = 1;               // Stores previous count value for LCD update

void setup() {                   // Runs once when ESP32 starts

  Serial.begin(115200);          // Starts serial communication

  lcd.init();                    // Initializes the LCD
  lcd.backlight();               // Turns on LCD backlight

  pinMode(IR_ENTRY, INPUT);      // Sets entry IR sensor pin as input
  pinMode(IR_EXIT, INPUT);       // Sets exit IR sensor pin as input
}

void loop() {                    // Runs repeatedly

  if (digitalRead(IR_ENTRY) == LOW) {
    // Checks if entry sensor is triggered
    // Most IR sensors output LOW when an object is detected

    count++;                     // Increases people count by 1

    delay(300);                  // Debounce delay to avoid multiple counts
  }

  else if (digitalRead(IR_EXIT) == LOW) {
    // Checks if exit sensor is triggered

    if (count > 0)
      count--;                   // Decreases count only if count is greater than 0

    delay(300);                  // Debounce delay
  }

  if (count != lastCount) {
    // Updates LCD only when count changes

    lcd.clear();                 // Clears previous LCD content

    lcd.setCursor(0, 0);         // Moves cursor to first row, first column
    lcd.print("People Inside:");
    // Displays heading

    lcd.setCursor(0, 1);         // Moves cursor to second row, first column
    lcd.print(count);
    // Displays current people count

    lastCount = count;
    // Saves current count as previous count
  }
}
