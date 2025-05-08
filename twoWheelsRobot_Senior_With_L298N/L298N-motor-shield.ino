// Motor Pins

//Left Motor
int in1 = 8;
int in2 = 9;
int ena = 10;

//Right Motor
int in3 = 11;
int in4 = 12;
int enb = 5;

// Sensor Pins
int echoPin = 9;
int trig_Pin = 10;
int ir_RightPin = A0;
int ir_LeftPin = A1;

//variables
double distance = 0;
double duration = 0;
int ir_RightValue = 0;
int ir_LeftValue = 0;

//functions
double measureDistance() {//function to get object distance
  digitalWrite(trig_Pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_Pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_Pin, LOW);
  duration = pulseIn(echoPin, HIGH);
  //distance in centimeters
  distance = (duration / 2) * 0.0343;
  return distance;
}

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

void wait(int millisecond){
  delay(millisecond);
}

void setSpeed(int speed = 100){
  if(speed>255){
      speedUp();
  }
  analogWrite(ena, speed);
  analogWrite(enb, speed);
}

// Spin clockwise (turn right in place)
void clockwiseMove(){
  digitalWrite(in1, HIGH);  // Left motor forward
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);   // Right motor backward
  digitalWrite(in4, HIGH);
  speedUp();
}

// Spin counterclockwise (turn left in place)
void anticlockwiseMove(){
  digitalWrite(in1, LOW);   // Left motor backward
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);  // Right motor forward
  digitalWrite(in4, LOW);
  speedUp();
}

void getIRsValue(){
 // Output between 1 (detect white color) and 0 (detect black color)
  ir_RightValue = digitalRead(ir_RightPin);
  ir_LeftValue = digitalRead(ir_LeftPin);
  Serial.print("ir_RightValue: ");
  Serial.println(ir_RightValue);
  Serial.print("ir_LeftValue: ");
  Serial.println(ir_LeftValue);
}

void setup() {
  Serial.begin(9600);
  //Set Inital Motor Speed(0-255), Add Your Own Speed
  // setSpeed(128); //An example of setting the speed
  setSpeed();
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enb, OUTPUT);

  pinMode(trig_Pin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ir_RightPin, INPUT);
  pinMode(ir_LeftPin, INPUT);
  delay(1000);
  Serial.println("Start!");
}

//Modifiable Function
void loop() {
  //print detail about both ir sensor
  getIRsValue();
  
  //if both ir detected at the same time
  //if it 
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
  
  //get distance from ultrasonic via measureDistance funcion
  double distance = measureDistance();

  //ulltrasonic
  if(distance<=50){
    //do something
  }else if(distance>50){
  //   //do something
   }
  // add another logic here
}
