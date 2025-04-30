int trigPin = 9;
int echoPin = 10;
 
long duration;
float distanceCm;

void setup() {
  Serial.begin(9600); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Clear trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send 10 microsecond pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echoPin
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance and converti to cm(centimeter)
  distanceCm = duration * 0.034 / 2;

  // Print distance
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");
  //delay 500ms(1/2 second)
  delay(500);
}
