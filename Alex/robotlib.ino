#include <AFMotor.h>

// Motor control
#define FRONT_LEFT   4 // M4 on the driver shield
#define FRONT_RIGHT  1 // M1 on the driver shield
#define BACK_LEFT    3 // M3 on the driver shield
#define BACK_RIGHT   2 // M2 on the driver shield

AF_DCMotor motorFL(FRONT_LEFT);
AF_DCMotor motorFR(FRONT_RIGHT);
AF_DCMotor motorBL(BACK_LEFT);
AF_DCMotor motorBR(BACK_RIGHT);

void move(float speed, int direction)
{
  int speed_scaled = (speed/100.0) * 255;
  motorFL.setSpeed(speed_scaled);
  motorFR.setSpeed(speed_scaled);
  motorBL.setSpeed(speed_scaled);
  motorBR.setSpeed(speed_scaled);

  switch(direction)
    {
      case BACK:
        motorFL.run(BACKWARD);
        motorFR.run(BACKWARD);
        motorBL.run(FORWARD);
        motorBR.run(FORWARD); 
      break;
      case GO:
        motorFL.run(FORWARD);
        motorFR.run(FORWARD);
        motorBL.run(BACKWARD);
        motorBR.run(BACKWARD); 
      break;
      case CW:
        motorFL.run(FORWARD);
        motorFR.run(FORWARD);
        motorBL.run(FORWARD);
        motorBR.run(FORWARD); 
      break;
      case CCW:
        motorFL.run(BACKWARD);
        motorFR.run(BACKWARD);
        motorBL.run(BACKWARD);
        motorBR.run(BACKWARD); 
      break;
      case STOP:
      default:
        motorFL.run(STOP);
        motorFR.run(STOP);
        motorBL.run(STOP);
        motorBR.run(STOP); 
    }
}

void stop()
{
  move(0, STOP);
}

void forwardForTime(unsigned long timeMs, float speed) {
  if (timeMs == 0) return;
  
  unsigned long startTime = millis();
  targetTime = startTime + timeMs;
  
  dir = (TDirection) FORWARD;
  move(speed, FORWARD);
}

void backwardForTime(unsigned long timeMs, float speed) {
  if (timeMs == 0) return;
  
  unsigned long startTime = millis();
  targetTime = startTime + timeMs;
  
  dir = (TDirection) BACKWARD;
  move(speed, BACKWARD);
}

void ccwForTime(unsigned long timeMs, float speed) {
  if (timeMs == 0) return;
  
  unsigned long startTime = millis();
  targetTime = startTime + timeMs;
  
  dir = (TDirection) LEFT;
  move(speed, LEFT);
}

void cwForTime(unsigned long timeMs, float speed) {
  if (timeMs == 0) return;
  
  unsigned long startTime = millis();
  targetTime = startTime + timeMs;
  
  dir = (TDirection) RIGHT;
  move(speed, RIGHT);
}