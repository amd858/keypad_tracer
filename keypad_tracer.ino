const int totalPins = 11;  // Adjust this based on the number of possible pins
int pins[totalPins] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; // Possible pins

void setup() {
  Serial.begin(115200);
  Serial.println("Starting Keypad Row/Col Detection...");
  
  // Set all pins as INPUT with PULLUP
  for (int i = 0; i < totalPins; i++) {
    pinMode(pins[i], INPUT_PULLUP);
  }
}

void loop() {
  Serial.println("\nTesting Rows & Columns...");
  delay(2000);

  for (int i = 0; i < totalPins; i++) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], LOW);  // Activate this pin

    for (int j = 0; j < totalPins; j++) {
      if (i != j) {  // Skip self-check
        pinMode(pins[j], INPUT_PULLUP);
        if (digitalRead(pins[j]) == LOW) {
          Serial.print("Connection Found: Pin ");
          Serial.print(pins[i]);
          Serial.print(" -> Pin ");
          Serial.println(pins[j]);
        }
      }
    }

    pinMode(pins[i], INPUT_PULLUP);  // Reset pin
  }
}
