#include <AFMotor.h>
// #include <NewPing.h>
AF_DCMotor motor1(3);
AF_DCMotor motor2(4);
int echo = 9;
int trig = 10;
int irPin1 = A0;
int irPin2 = A2;

double distance = 0;
double duration = 0;
int irValue1 = 0;           
int irValue2 = 0;


void setup() {
  Serial.begin(9600);
  SpeedUp();
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(irPin1, INPUT);
  pinMode(irPin2, INPUT);
  delay(1000);
  Serial.println("Start!");

}

void loop() {
  distance = measureDistance();
  Serial.println(distance);
  irValue1 = analogRead(irPin1);
  irValue2 = analogRead(irPin2);
  Serial.print("irValue1: ");
  Serial.println(irValue1);
  Serial.print("irValue2: ");
  Serial.println(irValue2);
  delay(1000);
}

double measureDistance() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration / 2) / 28.5;
  return distance;
}

void Forward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}

void Backward() {
  motor1.run(BACKWARD);
  
  motor2.run(BACKWARD);
  
}
void Left() {
  motor2.run(BACKWARD);
  motor1.run(FORWARD);
  
}
void Right(){
  motor2.run(FORWARD);
  motor1.run(BACKWARD);
  
}
  void Stop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  }
  void SpeedUp(){
    motor1.setSpeed(255);
    motor2.setSpeed(255);
  }
  void SpeedDown(){
    motor1.setSpeed(100);
    motor2.setSpeed(100);
  }
