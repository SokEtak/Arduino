#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

#include <AFMotor.h>
#include <Dabble.h>

// AFMotor Setup
AF_DCMotor m1(2);  
AF_DCMotor m3(3);  

void setup() {
  Serial.begin(115200);
  //You can choose another pin
  Dabble.begin(9600, 10, 9); // RX = 9, TX = 10
  m1.setSpeed(300);
  m3.setSpeed(300);
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
  m1.run(FORWARD);
  m3.run(FORWARD);
}

void moveBackward() {
  m1.run(BACKWARD);
  m3.run(BACKWARD);
}

void turnLeft() {
  m1.run(BACKWARD);
  m3.run(FORWARD);
}

void turnRight() {
  m1.run(FORWARD);
  m3.run(BACKWARD);
}

void stopMoving() {
  m1.run(RELEASE);
  m3.run(RELEASE);
}
