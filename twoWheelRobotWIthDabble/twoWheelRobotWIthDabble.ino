#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <AFMotor.h>
#include <Dabble.h>
//SoftwareSerial bluetooth(15, 14);
AF_DCMotor motor3(3);  
AF_DCMotor motor4(4);  

void setup() {
  Serial.begin(115200);
  Dabble.begin(9600,9,10);
  motor3.setSpeed(300);
  motor4.setSpeed(300);
  Serial.println("Start!");
}

void loop() {
// put your main code here, to run repeatedly:
Dabble.processInput();
if (GamePad.isUpPressed())
  {
    Serial.println("Up");
    moveForward();
  }else if (GamePad.isDownPressed())
  {
    Serial.println("Down");
    moveBackward();
  }else if (GamePad.isLeftPressed())
  {
    Serial.println("Left");
    turnLeft();
  }else if (GamePad.isRightPressed())
  {
    Serial.println("Right");
    turnRight();
  }else if (GamePad.isSquarePressed())
  {
    Serial.println("Square");
  }else if (GamePad.isCirclePressed())
  {
    Serial.println("Circle");
  }else if (GamePad.isCrossPressed())
  {
    Serial.println("Cross");
    stopMoving();
  }

  if (GamePad.isTrianglePressed())
  {
    Serial.println("Triangle");
  }

  if (GamePad.isStartPressed())
  {
    Serial.println("Start");
  }

  if (GamePad.isSelectPressed())
  {
    Serial.println("Select");
  }
}

void moveBackward() {
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void moveForward() {
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void turnLeft() {
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}

void turnRight() {
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}

void stopMoving() {
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}