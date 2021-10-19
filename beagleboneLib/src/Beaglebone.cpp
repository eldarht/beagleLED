#include "Beaglebone.hpp"

Led Beaglebone::getLed(int led_nr){
  return this->leds[led_nr];
}

int Beaglebone::convertGpioPositionToAbsolute(std::pair<int, int> gpioPosition){
  return (gpioPosition.first -1) * 32 + gpioPosition.second-1;
}
