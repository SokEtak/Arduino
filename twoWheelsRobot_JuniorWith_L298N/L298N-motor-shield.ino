#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

#include <Dabble.h>

// Motor Pins
//Left Motor
int in1 = 8;
int in2 = 9;
int ena = 10;
//Right Motor
int in3 = 11;
int in4 = 12;
int enb = 5;

// Movement Functions
void moveForward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void moveBackward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnLeft() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnRight() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void speedUp() {
  analogWrite(ena, 255);
  analogWrite(enb, 255);
}

void speedDown() {
  analogWrite(ena, 100);
  analogWrite(enb, 100);
}

void setSpeed(int speed = 200) {
  if (speed > 255) {
    speed = 255;
  }
  analogWrite(ena, speed);
  analogWrite(enb, speed);
}

// Spin clockwise (turn right in place)
void clockwiseMove() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  speedUp();
}

// Spin counterclockwise (turn left in place)
void anticlockwiseMove() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  speedUp();
}

// Handle gamepad button input
void handleButtonPress() {
  if (GamePad.isUpPressed()) {
    Serial.println("Forward");
    moveForward();
  }
  else if (GamePad.isDownPressed()) {
    Serial.println("Backward");
    moveBackward();
  }
  else if (GamePad.isLeftPressed()) {
    Serial.println("Turn Left");
    turnLeft();
  }
  else if (GamePad.isRightPressed()) {
    Serial.println("Turn Right");
    turnRight();
  }
  else if (GamePad.isTrianglePressed()) {
    Serial.println("Spin Clockwise");
    clockwiseMove();
  }
  else if (GamePad.isSquarePressed()) {
    Serial.println("Spin Counterclockwise");
    anticlockwiseMove();
  }
  else if (GamePad.isCirclePressed()) {
    Serial.println("Speed Down");
    speedDown();
  }
  else if (GamePad.isCrossPressed()) {
    Serial.println("Speed Up");
    speedUp();
  }
  else {
    stop();
  }
}

void setup() {
  Serial.begin(9600);
  Dabble.begin(9600, 2, 3); // RX = 2, TX = 3

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enb, OUTPUT);
  setSpeed();
  Serial.println("Remote Control Ready!");
}

void loop() {
  Dabble.processInput();
  handleButtonPress();
}
