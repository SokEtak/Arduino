//You Must Include This library To Make It Work Properly
#include <Servo.h>

const int servoPin = 6;
Servo myServo;

void setup() {
  //Connect the servo motor to the Arduino, using digital pin 6 for the control signal
  myServo.attach(servoPin);
}

void loop() {
  // Move from 0 to 180 degrees(Forward)
  for (int angle = 0; angle <= 180; angle++) {
    myServo.write(angle);
    delay(15); // smooth movement
  }

  delay(500); // pause at end

  // Move from 180 to 0 degrees(Backward)
  for (int angle = 180; angle >= 0; angle--) {
    myServo.write(angle);
    delay(15);
  }

  delay(500); // pause at end
}
