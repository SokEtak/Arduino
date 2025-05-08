//Recommend with L293D driver motor control shield/AF Motor
#include <AFMotor.h>
//Motor Setup
AF_DCMotor motor1(1);
AF_DCMotor motor3(3);

int echoPin = 9;
int trig_Pin = 10;
int ir_RightPin = A0;
int ir_LeftPin = A1;

double distance = 0;
double duration = 0;
int ir_RightValue = 0;           
int ir_LeftValue = 0;

void setup() {
  Serial.begin(9600);
  speedUp();
  pinMode(trig_Pin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ir_RightPin, INPUT);
  pinMode(ir_LeftPin, INPUT);
  delay(1000);
  Serial.println("Start!");
}

//Modifiable Function(Add Some Logic)
void loop() {
  //outout betwen 1(detect white color) and 0 (detect black color)
  ir_RightValue = digitalRead(ir_RightPin);
  ir_LeftValue = digitalRead(ir_LeftPin);
  Serial.print("ir_RightValue: ");
  Serial.println(ir_RightValue);
  Serial.print("ir_LeftValue: ");
  Serial.println(ir_LeftValue);
  delay(1000);//wait 1 second
  //write your logic here(e.g,if ir_right detected white color:do something,...)
  
  //if both ir detected at the same time
  if(ir_RightValue == 1 && ir_LeftValue == 1){
     //move backward

      //wait

  }else if(ir_RightValue == 1){
    //move backward

    //wait

    //turn left 

    //wait

  }else if(ir_LeftValue == 1){
    //wait

    //turn right 

    //wait


  }else{
    //move forward
  }
  
  //get distance from ultrasonic
  double distance = measureDistance();

  //ulltra
  if(distance<=50){
    //do something
  }else if(){
    //do something
  }
  // add another logic here
  
}
//function to get object distance
double measureDistance() {
  digitalWrite(trig_Pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_Pin, LOW);
  duration = pulseIn(echoPin, HIGH);
  //distance in centimeters
  distance = (duration / 2) * 0.0343;

  return distance;
}

void moveForward() {
  motor1.run(FORWARD);
  motor3.run(FORWARD);
}

void backward() {
  motor1.run(BACKWARD);
  motor3.run(BACKWARD);
  
}
void left() {
  motor3.run(BACKWARD);
  motor1.run(FORWARD);
  
}
void right(){
  motor3.run(FORWARD);
  motor1.run(BACKWARD);
  
}
  void stop() {
  motor1.run(RELEASE);
  motor3.run(RELEASE);
  }

  void speedUp(){
    motor1.setSpeed(255);
    motor3.setSpeed(255);
  }
  void speedDown(){
    motor1.setSpeed(100);
    motor3.setSpeed(100);
  }

  void wait(int millisecond){
    delay(millisecond);
  }
