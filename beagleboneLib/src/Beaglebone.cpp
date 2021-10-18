#include "Beaglebone.hpp"

Led Beaglebone::getLed(int led_nr){
  this->leds[led_nr];
}

int Beaglebone::convertGpioPositionToAbsolute(std::pair<int, int> gpioPosition){
  return gpioPosition.first * 32 + gpioPosition.second;
}
