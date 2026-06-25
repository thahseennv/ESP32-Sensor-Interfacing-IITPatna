// No library needed for basic rotary encoder reading

// Define encoder pins
#define CLK 25                       // Clock pin (A)
#define DT  26                       // Data pin (B)
#define SW  27                       // Switch pin (push button)

int counter = 0;                     // Stores current position
int lastCLKState;                    // Previous CLK state
int currentCLKState;                 // Current CLK state
bool buttonPressed = false;          // Button state

void setup() {
  Serial.begin(115200);             // Start serial monitor

  pinMode(CLK, INPUT);              // CLK as input
  pinMode(DT, INPUT);               // DT as input
  pinMode(SW, INPUT_PULLUP);        // SW as input with pullup (LOW when pressed)

  lastCLKState = digitalRead(CLK);  // Read initial CLK state

  Serial.println("Rotate encoder to change counter...");
}

void loop() {
  currentCLKState = digitalRead(CLK);  // Read current CLK state

  // If CLK state changed, encoder was rotated
  if (currentCLKState != lastCLKState) {

    // If DT is different from CLK, rotating clockwise
    if (digitalRead(DT) != currentCLKState) {
      counter++;                     // Increment counter
      Serial.print("Clockwise | Counter: ");
    } else {
      counter--;                     // Decrement counter
      Serial.print("Anticlockwise | Counter: ");
    }
    Serial.println(counter);         // Print updated counter
  }

  lastCLKState = currentCLKState;   // Save current state for next loop

  // Check if button is pressed (LOW because of INPUT_PULLUP)
  if (digitalRead(SW) == LOW) {
    if (!buttonPressed) {            // Avoid multiple triggers
      Serial.println("Button Pressed! Counter reset to 0");
      counter = 0;                   // Reset counter on button press
      buttonPressed = true;
    }
  } else {
    buttonPressed = false;           // Reset button flag when released
  }
}
