#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

#include <AFMotor.h>
#include <Dabble.h>

// AFMotor Setup
AF_DCMotor motor2(2);  
AF_DCMotor motor3(3);  

void setup() {
  Serial.begin(115200);
  //You can choose another pin
  Dabble.begin(9600, 10, 9); // RX = 9, TX = 10
  motor2.setSpeed(300);
  motor3.setSpeed(300);
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
  else{
    stopMoving();
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
  motor2.run(FORWARD);
  motor3.run(FORWARD);
}

void moveBackward() {
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
}

void turnLeft() {
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
}

void turnRight() {
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
}

void stopMoving() {
  motor2.run(RELEASE);
  motor3.run(RELEASE);
}
