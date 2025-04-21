#include <Servo.h>

const int servoPin = 6;
Servo myServo;

void setup() {
  myServo.attach(servoPin);
}

void loop() {
  // Move from 0 to 180 degrees
  for (int angle = 0; angle <= 180; angle++) {
    myServo.write(angle);
    delay(15); // smooth movement
  }

  delay(500); // pause at end

  // Move from 180 to 0 degrees
  for (int angle = 180; angle >= 0; angle--) {
    myServo.write(angle);
    delay(15);
  }

  delay(500); // pause at end
}
