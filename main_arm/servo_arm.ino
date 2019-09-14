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
#define SERVO_CLAW_PIN 6

#define CLAW_SPEED 10

Servo servo_X;
Servo servo_Y;
Servo servo_Z;
Servo servo_CLAW;
// twelve servo objects can be created on most boards

int claw_movement = 0; // 0 = nothing, 1 = close, -1 = open
int claw_pos = 0;


void set_servo_X(int pos);
void set_servo_Y(int pos);
void set_servo_Z(int pos);
void set_servo_CLAW(int pos);

void servo_setup() {
  servo_X.attach(SERVO_X_PIN);
  servo_Y.attach(SERVO_Y_PIN);
  servo_Z.attach(SERVO_Z_PIN);
  servo_CLAW.attach(SERVO_CLAW_PIN);
}

void servo_position(int x1, int y1, int x2, int y2)
{
  int xDir = map(x1, 0, 1023, 0, 180);
  int yDir = map(y1, 0, 1023, 90, 180);
  int zDir = map(x2, 0, 1023, 90, 180);

  set_servo_X(xDir);
  set_servo_Y(yDir);
  set_servo_Z(zDir);

  // 0-410 = Close, 614-1023 = Open
  if (y2 >= 0 && y2 <= 410){
    claw_movement = -1;
  }
  else if (y2 >= 614 && y2 <= 1023)
  {
    claw_movement = 1;
  }
  else
    claw_movement = 0;

  claw_pos = claw_pos + (claw_movement * CLAW_SPEED);
  set_servo_CLAW(claw_pos);
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

void set_servo_CLAW(int pos)
{
  servo_CLAW.write(pos);
}


