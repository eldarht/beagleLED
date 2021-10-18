#include <iostream>
#include "Led.hpp"
  
Led::Led(std::pair<int, int> gpioPosition, LedState state){
  this->gpioPosition = gpioPosition;
  this->state = state;
}

LedState Led::toggle(){
  //  TODO: update to use Linux sysfs to set board LED
  std::cout << "NOT Implemented\n";

  (this->state == Led_on) ? this->state = Led_off : this->state = Led_on;
  return this->state;
}

LedState Led::getState(){
  return this->state;
}

std::pair<int, int> Led::getGpioPosition(){
  return this->gpioPosition;
}

