/* 
 * David Keck
 * filename: CurioDuinoNav.cpp
 * Implementation of CurioDuinoNav
 * For use with the CurioDuinoOBS software.
 * More information here: http://davidskeck.wordpress.com
 * or here http://github.com/davidskeck/CurioDuinoOBS
 */

// Include motor class
#include <../ZumoMotors/ZumoMotors.h>

// Include header file
#include "CurioDuinoNav.h"

void CurioDuinoNav::begin()
{
  forwardSpeed = 0;
}

void CurioDuinoNav::turnLeft()
{
  motors.setSpeeds(-TURN_SPEED, TURN_SPEED);
  // Random turn time from 300 - 400
  int rand = random (1, RANDOM_VARIANCE+1);
  delay(TURN_DURATION + rand);
}

void CurioDuinoNav::turnRight()
{
  motors.setSpeeds(TURN_SPEED, -TURN_SPEED);
  // Randum turn time from 300 - 400
  int rand = random (1, RANDOM_VARIANCE+1);
  delay(TURN_DURATION + rand);
}

void CurioDuinoNav::goForward()
{
  motors.setSpeeds(forwardSpeed, forwardSpeed);
}

void CurioDuinoNav::goReverse()
{
  motors.setSpeeds(-REVERSE_SPEED, -REVERSE_SPEED);
  delay(REVERSE_DURATION);
}

void CurioDuinoNav::stopMoving()
{
  motors.setSpeeds(0, 0);
}