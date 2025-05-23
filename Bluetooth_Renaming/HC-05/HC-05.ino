#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX, TX

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  
  Serial.println("Changing HC-05 name...");
  changeName("Black_Bird"); // Change "NewName" to your desired name
}

void loop() {
  // Nothing here
}

void changeName(String newName) {
  // AT Command to change the name
  BTSerial.print("AT+NAME" + newName + "\r\n");
  delay(1000); // Wait for the command to process

  // Read response
  while (BTSerial.available()) {
    Serial.write(BTSerial.read());
  }
  Serial.println("Name changed to: " + newName);
}
