#include <array>
#include <cstdint>
#include "Led.hpp"

class Beaglebone{
private:
  std::array<Led, 4> leds{
    Led(std::pair<int,int>(1,21)),
      Led(std::pair<int,int>(2,22)),
      Led(std::pair<int,int>(2,23)),
      Led(std::pair<int,int>(2,24))
      };
  
public:
  Led getLed(int led_nr);
  int convertGpioPositionToAbsolute(std::pair<int, int> gpioPosition);
};
