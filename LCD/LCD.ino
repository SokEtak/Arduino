#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LCD_ADDRESS 0x3F  // Change to 0x27 if needed
int trigPin = 10;
int echoPin = 7;
int s = A8;

LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Wire.begin();  // Start I2C communication
  lcd.init();    // Initialize the LCD
  lcd.backlight(); // Turn on backlight
  lcd.setCursor(0, 0);

  Serial.begin(9600); // Initialize Serial Monitor
  pinMode(s, INPUT);
}

void loop() {
  float distance = getDistance(); // Measure distance

  // Display on Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Display on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm");

  delay(500);
}

float getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  int duration = pulseIn(echoPin, HIGH);
  float distance = (duration * 0.0343) / 2;
  return distance;
}
