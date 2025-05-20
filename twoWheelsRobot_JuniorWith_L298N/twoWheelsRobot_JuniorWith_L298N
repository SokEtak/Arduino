#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

//Left Motor
int in1 =13;
int in2 =12;

//Right Motor
int in3 = 11;
int in4 = 10;

// Movement Functions
void setup() {
  Serial.begin(9600);
  Dabble.begin(9600, 3); // RX = 3
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.println("Remote Control Ready!");
}

void loop() {
  handleButtonPress();
  //moveForward();
}
void moveForward() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
}

void moveBackward() {
  digitalWrite(in1, LOW); digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW); digitalWrite(in4, HIGH);
}

void turnLeft() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);  digitalWrite(in4, HIGH);
}

void turnRight() {
  digitalWrite(in1, LOW);  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
}

void stop() {
  digitalWrite(in1, LOW); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); digitalWrite(in4, LOW);
}

// Spin clockwise (turn right in place)
void clockwiseMove() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);  digitalWrite(in4, HIGH);
}

// Spin counterclockwise (turn left in place)
void anticlockwiseMove() {
  digitalWrite(in1, LOW);  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
}

// Handle gamepad button input
void handleButtonPress() {
  Dabble.processInput();
  if (GamePad.isUpPressed()) {
    // Serial.println("Forward");
    return moveForward();
  }
  else if (GamePad.isDownPressed()) {
    // Serial.println("Backward");
    return moveBackward();
  }
  else if (GamePad.isLeftPressed()) {
    // Serial.println("Left");
    // return turnLeft(); 
    return turnLeft();
  }
  else if (GamePad.isRightPressed()) {
    // Serial.println("Right");
    // return turnRight(); 
    return turnRight(); 
  }

  else if (GamePad.isSquarePressed()) {
    // Serial.println("Spin Counterclockwise");
    return turnLeft();
  }
  else if (GamePad.isCirclePressed()) {
    // Serial.println("Spin ClockwiseMove");
    return turnRight();
  }
  else {
    return stop();
  }
  delay(50);
}
