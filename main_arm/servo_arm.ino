/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

#define SERVO_X_PIN 9
#define SERVO_Y_PIN 10
#define SERVO_Z_PIN 11

Servo servo_X;
Servo servo_Y;
Servo servo_Z;
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void servo_loop_X();
void servo_loop_Y();
void servo_loop_Z();
void set_servo_X();
void set_servo_Y();
void set_servo_Z();

void servo_setup() {
  servo_X.attach(SERVO_X_PIN);
  servo_Y.attach(SERVO_Y_PIN);
  servo_Z.attach(SERVO_Z_PIN);
}

void servo_loop() {
  set_servo_X(90);
  set_servo_Y(140);
  set_servo_Z(140);
  delay(1000);
//  servo_loop_X();
//  servo_loop_Y();
//  servo_loop_Z();
}

void set_servo_X(int pos)
{
  servo_X.write(pos);
}

void set_servo_Y(int pos)
{
  servo_Y.write(pos);
}

void set_servo_Z(int pos)
{
  servo_Z.write(pos);
}


void servo_loop_X() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    servo_X.write(pos);
    delay(15);
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo_X.write(pos);
    delay(15);
  }
}

void servo_loop_Y() {
  for (pos = 90; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    servo_Y.write(pos);
    delay(15);
  }
  for (pos = 180; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo_Y.write(pos);
    delay(15);
  }
}

void servo_loop_Z() {
  for (pos = 90; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    servo_Z.write(pos);
    delay(15);
  }
  for (pos = 180; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo_Z.write(pos);
    delay(15);
  }
}


