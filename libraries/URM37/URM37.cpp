#include "URM37.h"
#include "Arduino.h"

URM37::URM37(Stream * stream): stream(stream) {
}

int URM37::getDistance() {
  sendCommand(0x22);
  waitResult();

  int header = stream->read(); // 0x22
  int high = stream->read();
  int low = stream->read();
  int sum = stream->read(); // sum

  if ( high == 0xFF )
    return 0;
  else
    return (high << 8) + low;
}

int URM37::getTemperature() {
  sendCommand(0x11);
  waitResult();

  int header = stream->read(); // 0x11
  int high = stream->read();
  int low = stream->read();
  int sum = stream->read(); // sum

  if ( high == 0xFF )
    return 0;
  else if (high & 0xF0)
    return - ((high & 0xF) << 8) - low;
  else
    return ((high & 0xF) << 8) + low;
}

void URM37::sendCommand(uint8_t cmd) {
  stream->write((uint8_t)cmd);
  stream->write((uint8_t)0x0);
  stream->write((uint8_t)0x0);
  stream->write((uint8_t)cmd);
}

void URM37::waitResult() {
  while(stream->available() < 4)
    delayMicroseconds(10);
}
