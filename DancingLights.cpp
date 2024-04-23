#include <Arduino.h>

int patternType = 1; // Default pattern type

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  
  Serial.begin(9600); // Initialize serial communication
  Serial.println("Setup completed.");
}

void loop() {
  if (Serial.available() > 0) {
    // Read the raw serial input
    String input = Serial.readStringUntil('\n');
    Serial.print("Received: ");
    Serial.println(input);

    patternType = input.toInt(); // Convert input to integer
    Serial.print("Pattern ");
    Serial.print(patternType);
    Serial.println(" selected.");

    // Check if the patternType is within the valid range (1 to 5)
    if (patternType < 1 || patternType > 5) {
      Serial.println("Invalid pattern selected.");
      return; // Exit loop and wait for new input
    }
  }

  int i;

  // Check the pattern type and execute the corresponding pattern
  switch (patternType) {
    case 1:
      Serial.println("Executing Pattern 1: Alternating Blink");
      // Pattern 1: Alternating Blink
      for (i = 2; i <= 9; i += 2) {
        digitalWrite(i, HIGH);
        delay(250);
        digitalWrite(i, LOW);
      }
      break;

    case 2:
      Serial.println("Executing Pattern 2: Chase");
      // Pattern 2: Chase
      for (i = 2; i <= 9; i++) {
        digitalWrite(i, HIGH);
        delay(100);
        digitalWrite(i, LOW);
      }
      break;

    case 3:
      Serial.println("Executing Pattern 3: Double Flash");
      // Pattern 3: Double Flash
      for (i = 2; i <= 9; i++) {
        digitalWrite(i, HIGH);
      }
      delay(200);
      for (i = 2; i <= 9; i++) {
        digitalWrite(i, LOW);
      }
      delay(200);
      for (i = 2; i <= 9; i++) {
        digitalWrite(i, HIGH);
      }
      delay(200);
      for (i = 2; i <= 9; i++) {
        digitalWrite(i, LOW);
      }
      break;

    case 4:
      Serial.println("Executing Pattern 4: Random Blink");
      // Pattern 4: Random Blink
      for (i = 0; i < 10; i++) {
        int pin = random(2, 10); // Generate random pin number between 2 and 9
        digitalWrite(pin, HIGH);
        delay(200);
        digitalWrite(pin, LOW);
      }
      break;

    case 5:
      Serial.println("Executing Pattern 5: Breathe");
      // Pattern 5: Breathe
      for (i = 0; i < 255; i++) {
        analogWrite(2, i);
        analogWrite(9, 255 - i);
        delay(10);
      }
      for (i = 255; i >= 0; i--) {
        analogWrite(2, i);
        analogWrite(9, 255 - i);
        delay(10);
      }
      break;

    default:
      break; // Should not reach here
  }
}