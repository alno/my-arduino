#ifndef _URM37_INCLUDED_
#define _URM37_INCLUDED_

#include "Stream.h"

class URM37 {
public:
  URM37(Stream * stream);

  /**
   * Get distance from sensor in centimeters.
   */
  int getDistance();

  /**
   * Get temperature from sensor in decimal of graduces
   */
  int getTemperature();

private:
  void sendCommand(uint8_t cmd);
  void waitResult();

private:
  Stream * stream;
};

#endif
