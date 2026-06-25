#define BUTTON_INC 26   // Increment button
#define BUTTON_DEC 27   // Decrement button

int count = 0;          // Variable to store the count

void setup() {
  Serial.begin(115200);              // Start serial communication

  pinMode(BUTTON_INC, INPUT_PULLUP); // Button connected to GPIO 26
  pinMode(BUTTON_DEC, INPUT_PULLUP); // Button connected to GPIO 27

  Serial.println("Counter Started");
}

void loop() {

  // Check increment button
  if (digitalRead(BUTTON_INC) == LOW) {
    count++;                         // Increase count by 1
    Serial.print("Count = ");
    Serial.println(count);
    delay(200);                      // Debounce delay
  }

  // Check decrement button
  if (digitalRead(BUTTON_DEC) == LOW) {
    count--;                         // Decrease count by 1
    Serial.print("Count = ");
    Serial.println(count);
    delay(200);                      // Debounce delay
  }
}
