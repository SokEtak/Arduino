//Recommend with L293D driver motor control shield/AF Motor
#include <AFMotor.h>

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
//Modifiable Function(Add More Logic)
void loop() {
  distance = measureDistance();
  Serial.println(distance);
  ir_RightValue = analogRead(ir_RightPin);
  ir_LeftValue = analogRead(ir_LeftPin);
  Serial.print("ir_RightValue: ");
  Serial.println(ir_RightValue);
  Serial.print("ir_LeftValue: ");
  Serial.println(ir_LeftValue);
  delay(1000);//wait 1 second
  //write your logic here(e.g,if ir_right detected white color:do something,...)
  
}
//function to get object distance
double measureDistance() {
  digitalWrite(trig_Pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_Pin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 28.5;
  return distance;
}

void forward() {
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
