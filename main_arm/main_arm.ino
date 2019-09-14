// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output

  servo_setup();
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  String data = "";
  while (0 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    data += c;
//    Serial.print(c);         // print the character
  }
//  Serial.println("");
 
  Serial.println(data);
  int y1 = data.substring(0,4).toInt();
  int x1 = data.substring(4,8).toInt();
  int y2 = data.substring(8,12).toInt();
  int x2 = data.substring(12,16).toInt();
  Serial.println(y1);
  Serial.println(x1);
  Serial.println(y2);
  Serial.println(x2);

  servo_position(x1, y1, x2, y2);
}
