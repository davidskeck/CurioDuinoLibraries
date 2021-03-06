/* 
 * David Keck
 * filename: CurioDuinoData.cpp
 * Implementation of CurioDuinoData
 * For use with the CurioDuinoOBS software.
 * More information here: http://davidskeck.wordpress.com
 * or here http://github.com/davidskeck/CurioDuinoLibraries
 */

// Include reflectance array class
#include <../CurioDuinoReflectanceSensorArray/CurioDuinoReflectanceSensorArray.h>

// Include header file
#include "CurioDuinoData.h"

void CurioDuinoData::begin()
{
  isStarted = false;
  newSetSpeed = 75;
  byte pins[] = {4, 5};
  sensors.init(pins, NUM_SENSORS, 2000, QTR_NO_EMITTER_PIN);
}

void CurioDuinoData::update()
{
  // update edge sensors
  sensors.read(sensor_values);

  // update data struct
  leftEdge = (sensor_values[0] > QTR_THRESHOLD);
  rightEdge = (sensor_values[1] > QTR_THRESHOLD);
  battery = analogRead(BATTERY_SENSOR);
  leftObstacle = (!digitalRead(LEFT_OBST_SENSOR));
  middleObstacle = (!digitalRead(MIDDLE_OBST_SENSOR));
  rightObstacle = (!digitalRead(RIGHT_OBST_SENSOR));
  leftForward = (!digitalRead(DIR_L));
  rightForward = (!digitalRead(DIR_R));

  prepareData();
}

void CurioDuinoData::prepareData()
{
  // update formatted string for sending data
  dataFormatted = "";
  dataFormatted += leftEdge;
  dataFormatted += "LE";
  dataFormatted += rightEdge;
  dataFormatted += "RE";
  dataFormatted += battery;
  dataFormatted += "B";
  dataFormatted += leftObstacle;
  dataFormatted += "LO";
  dataFormatted += middleObstacle;
  dataFormatted += "MO";
  dataFormatted += rightObstacle;
  dataFormatted += "RO";
  dataFormatted += leftForward;
  dataFormatted += "LF";
  dataFormatted += rightForward;
  dataFormatted += "RF";
}

void CurioDuinoData::send()
{
  Serial.println(dataFormatted);
}

void CurioDuinoData::receive()
{
  if (Serial.available() > 0)
  { 
    // Capture serial read
    int serialIn;

    serialIn = Serial.read();

    // Check if less than minimum speed
    // If so, it is a boolean signal since
    // GUI will only send one of two signals
    if (serialIn < 75)
    {
      isStarted = serialIn;
    }
    // Not boolean, must be speed
    else
    {
      newSetSpeed = serialIn;
    }
  }
}