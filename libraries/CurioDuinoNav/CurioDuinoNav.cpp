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

void CurioDuinoNav::turnLeft()
{
  motors.setSpeeds(-TURN_SPEED, TURN_SPEED);
  delay(TURN_DURATION);
}

void CurioDuinoNav::turnRight()
{
  motors.setSpeeds(TURN_SPEED, -TURN_SPEED);
  delay(TURN_DURATION);
}

void CurioDuinoNav::turnAround()
{
	turnRight();
	turnRight();
}

void CurioDuinoNav::goForward()
{
  motors.setSpeeds(FORWARD_SPEED, FORWARD_SPEED);
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