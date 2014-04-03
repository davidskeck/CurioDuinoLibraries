/* 
 * David Keck
 * filename: CurioDuinoNav.h
 * Library header file for CurioDuinoNav implementation
 * For use with the CurioDuinoOBS software.
 * More information here: http://davidskeck.wordpress.com
 * or here http://github.com/davidskeck/CurioDuinoOBS
 */

// Macro guard
#ifndef CurioDuinoNav_h
#define CurioDuinoNav_h

// Include arduino specific function
#include <Arduino.h>

// Forward declaration of class
class ZumoMotors;

// Motor speeds
#define REVERSE_SPEED     75 // 0 is stopped, 400 is full speed
#define TURN_SPEED        200

// Almost makes 90 degree turn
// todo: change to compass nav
#define REVERSE_DURATION  400 // ms

// Turn duration should be tuned to
// battery life. Current readings
// at reading of 715 on battery pin
// duration of 375 is 90 degrees.
// A reading of 700, the duration
// must be 390
#define TURN_DURATION     390 // ms

class CurioDuinoNav
{
private:
	int forwardSpeed;
	// Public to adhere to NASA's MSL rules of
	// only void return functions
public:

	// Member functions
	// Serves as a constructor
	// because Arduino constructors
	// are not advised.
	void begin();
	void turnRight();
	void turnLeft();
	void turnAround();
	void goForward();
	void goReverse();
	void stopMoving();
	void setSpeed(int newSpeed);

	// Data members
	ZumoMotors motors;
};
#endif