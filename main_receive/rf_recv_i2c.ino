// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

void i2c_setup() {
  Wire.begin(); // join i2c bus (address optional for master)
}

byte x = 0;

void i2c_send(String data) {
  Wire.beginTransmission(8); // transmit to device #8
//  String J1X = "0750";
//  String J1Y = "0873";
//  String J2X = "0200";
//  String J2Y = "1005";
//  String data = J1Y + J1X + J2Y + J2X;
  Wire.write(data.c_str());   // sends five bytes
  Wire.endTransmission();    // stop transmitting

  delay(500);
}
