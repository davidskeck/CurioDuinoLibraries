/* 
 * David Keck
 * filename: CurioDuinoComm.h
 * Library header file for CurioDuinoComm implementation
 * For use with the CurioDuinoOBS software.
 * More information here: http://davidskeck.wordpress.com
 * or here http://github.com/davidskeck/CurioDuinoOBS
 */

// Macro guard
#ifndef CurioDuinoComm_h
#define CurioDuinoComm_h

// Include arduino specific function
#include <Arduino.h>

// Forward declaration of class
class ZumoBuzzer;

class CurioDuinoComm
{
	// Public to adhere to NASA's MSL rules of
	// only void return functions
public:

	// Member functions
	// Send data string
	void send(String);

	// Data members
	ZumoBuzzer buzzer;
};
#endif