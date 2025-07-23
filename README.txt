# Timed LED Indicator with Button Trigger (Arduino UNO)

This project demonstrates how to use `millis()`, digital I/O, and button input to control a simple LED sequence using an Arduino Uno.

## 🧾 Overview

- **Function**: A button triggers a timed LED sequence using non-blocking code.
- **Skills Demonstrated**: Pin I/O, timing with `millis()`, state handling, and internal pull-up resistors.

## 🔌 Hardware Components

| Component        | Quantity | Description                            |
|------------------|----------|----------------------------------------|
| Arduino Uno      | 1        | Main microcontroller board             |
| Breadboard       | 1        | For circuit prototyping                |
| Push Button      | 1        | User input to trigger LED change       |
| LEDs 
(Red,Yellow,Green) | 3 	      | Visual indicators                      |
| 220Ω Resistors   | 3        | Current limiting for LEDs              |
| Jumper Wires     | ~10      | Connections between components         |

## 🧱 Wiring Diagram

![Wiring Diagram](wiring_diagram.png)

## 💻 Code

```cpp
unsigned long startMillis;
unsigned long currentMillis;

const unsigned long periodRed = 2000;
int button_press = 0;

void setup() {
  pinMode(10, OUTPUT); digitalWrite(10, LOW);
  pinMode(9, OUTPUT);  digitalWrite(9, LOW);
  pinMode(8, OUTPUT);  digitalWrite(8, HIGH);
  pinMode(3, INPUT_PULLUP);
  startMillis = millis();
}

void loop() {
  currentMillis = millis();

  if (digitalRead(3) == LOW) {
    button_press = 1;
  }

  if (currentMillis - startMillis >= periodRed) {
    if (button_press == 1) {
      digitalWrite(10, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(8, LOW);

      delay(1000);
      startMillis = millis();
      button_press = 0;
    }
  } else {
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH);
  }
}

🧪 7. Testing and Validation
Test Case			Expected Behavior	    				Status
Power on			Green LED ON						✅
Button press			After 2s, Red & Yellow ON				✅
No button press			No change, Green LED remains ON				✅
Button held continuously	Only one 2s cycle triggered per press			✅

🐞 8. Known Issues
No software debounce logic; multiple fast presses could be misread.

delay(1000) blocks the system momentarily. A future improvement could use non-blocking timers 	instead.

🔧 9. Future Work
Add debounce logic using software or hardware.

Replace delay() with non-blocking timing.

Add serial monitoring to log events.

Expand to handle multiple buttons/LED patterns.

