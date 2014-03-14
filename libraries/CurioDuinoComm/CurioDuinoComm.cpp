/* 
 * David Keck
 * filename: CurioDuinoComm.cpp
 * Implementation of CurioDuinoComm
 * For use with the CurioDuinoOBS software.
 * More information here: http://davidskeck.wordpress.com
 * or here http://github.com/davidskeck/CurioDuinoOBS
 */

// Include buzzer class
#include <../ZumoBuzzer/ZumoBuzzer.h>

// Include header file
#include "CurioDuinoComm.h"

 void CurioDuinoComm::send(String dataFormatted)
{ 
  // send string of sensor data
  Serial.println(dataFormatted);
}