#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

#include <AFMotor.h>
#include <Dabble.h>

// AFMotor Setup
AF_DCMotor motor1(1);  
AF_DCMotor motor2(2);  

void setup() {
  Serial.begin(115200);
  //You can choose another pin
  Dabble.begin(9600, 10, 9); // RX = 10, TX = 9

  motor1.setSpeed(300);
  motor2.setSpeed(300);
  Serial.println("Start!");
}

void loop() {
  Dabble.processInput();
  //D-Pad (Directional Pad)
  if (GamePad.isUpPressed()) {
    Serial.println("Up");
    moveForward();
  }
  else if (GamePad.isDownPressed()) {
    Serial.println("Down");
    moveBackward();
  }
  else if (GamePad.isLeftPressed()) {
    Serial.println("Left");
    turnLeft();
  }
  else if (GamePad.isRightPressed()) {
    Serial.println("Right");
    turnRight();
  }
  //Button Face(Skills)
  if (GamePad.isTrianglePressed()) {
    Serial.println("Triangle");
  }
  else if (GamePad.isSquarePressed()) {
    Serial.println("Square");
  }
  else if (GamePad.isCirclePressed()) {
    Serial.println("Circle");
  }
  else if (GamePad.isCrossPressed()) {
    Serial.println("Cross");
  }
  //Special Button
  if (GamePad.isStartPressed()) {
    Serial.println("Start");
  }
  else if (GamePad.isSelectPressed()) {
    Serial.println("Select");
  }
}

// Movement Functions
void moveForward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}

void moveBackward() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
}

void turnLeft() {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
}

void turnRight() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
}

void stopMoving() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
