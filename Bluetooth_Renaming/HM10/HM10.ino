#include <SoftwareSerial.h>

SoftwareSerial HM10(10, 11); // RX, TX

void setup() {
  Serial.begin(9600);
  HM10.begin(9600);
  
  Serial.println("Changing HM-10 name...");
  changeName("NMP"); // Change "NewName" to your desired name
}

void loop() {
  // Nothing here
}

void changeName(String newName) {
  // AT Command to change the name
  HM10.print("AT+NAME" + newName + "\r\n");
  delay(1000); // Wait for the command to process

  // Read response
  while (HM10.available()) {
    Serial.write(HM10.read());
  }
  Serial.println("Name changed to: " + newName);
}