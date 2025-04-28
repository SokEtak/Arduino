//Recommend with L293D driver motor control shield/AF Motor

#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

int echoPin = 9;
int trig_Pin = 10;
int irPin_Right = A0;
int irPin_Left = A2;

double distance = 0;
double duration = 0;
int irValue1 = 0;           
int irValue2 = 0;


void setup() {
  Serial.begin(9600);
  speedUp();
  pinMode(trig_Pin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(irPin_Right, INPUT);
  pinMode(irPin_Left, INPUT);
  delay(1000);
  Serial.println("Start!");

}
//Modifiable Function(Add More Logic)
void loop() {
  distance = measureDistance();
  Serial.println(distance);
  irValue1 = analogRead(irPin_Right);
  irValue2 = analogRead(irPin_Left);
  Serial.print("irValue1: ");
  Serial.println(irValue1);
  Serial.print("irValue2: ");
  Serial.println(irValue2);
  delay(1000);
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
  motor2.run(FORWARD);
}

void backward() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  
}
void left() {
  motor2.run(BACKWARD);
  motor1.run(FORWARD);
  
}
void right(){
  motor2.run(FORWARD);
  motor1.run(BACKWARD);
  
}
  void stop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  }
  void speedUp(){
    motor1.setSpeed(255);
    motor2.setSpeed(255);
  }
  void speedDown(){
    motor1.setSpeed(100);
    motor2.setSpeed(100);
  }
