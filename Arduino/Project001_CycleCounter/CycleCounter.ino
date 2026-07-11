/*
----------------------------------------------------
Project 001 - Cycle Counter
Automation Lab

Author : Lkaita
Version : v1.0

Description
- Count button presses
- Blink LED
- Print cycle count
- Display TEST COMPLETE after 10 cycles
----------------------------------------------------
*/

const int buttonPin = 7;
const int ledPin = 8;

int count = 0;

bool lastButtonState = HIGH;

void setup() {

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);

  Serial.println("================================");
  Serial.println("     PAD TEST COUNTER");
  Serial.println("================================");
  Serial.println("Press Button...");
}

void loop() {

  bool currentButtonState = digitalRead(buttonPin);

  // Detect button press
  if (lastButtonState == HIGH && currentButtonState == LOW) {

    count++;

    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);

    Serial.print("Cycle : ");
    Serial.println(count);

    if (count >= 10) {

      Serial.println("--------------------");
      Serial.println("TEST COMPLETE!");
      Serial.println("--------------------");

      count = 0;
    }

    delay(200);   // Debounce
  }

  lastButtonState = currentButtonState;
}
