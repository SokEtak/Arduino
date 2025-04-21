int sensorPin = A0;       // Analog pin connected to SIG
int sensorValue = 0;      // Variable to store sensor value

void setup() {
  Serial.begin(9600);     // Start Serial Monitor
}

void loop() {
  sensorValue = analogRead(sensorPin);   // Read analog value
  Serial.print("Water Sensor Value: ");
  Serial.println(sensorValue);           // Print value

  if (sensorValue > 500) {
    Serial.println("💧 Water Detected!");
  } else {
    Serial.println("No Water.");
  }

  delay(1000);   // Wait 1 second
}
