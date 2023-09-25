/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/DigitalReadSerial
*/

// digital pin 2 has a pushbutton attached to it. Give it a name:

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(2, INPUT);
  // Configure pin 3 and 4 as outputs
  pinMode (3, OUTPUT);
  pinMode (4, OUTPUT);

}

unsigned long lastButtonPressTime = 0; // Variable to store the time of the last button press

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(2);
  unsigned long currentTime = millis(); // Get the current time
  // introduce the if else statement for the two LEDs
if (buttonState == LOW) {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    Serial.println(buttonState);
    lastButtonPressTime = currentTime; // Update the last button press time
    delay(1000);  // delay in between reads for stability

  }
  else {
    // Check if the LEDs should be turned off due to a timeout
    if (currentTime - lastButtonPressTime >= 10000) { // 10 seconds timeout
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
    } else {
    digitalWrite(3, LOW);   // Turn off the LED when the button is not pressed
    digitalWrite(4, HIGH);
    }
    Serial.println(buttonState);
    delay(1000);  // delay in between reads for stability
   }
}