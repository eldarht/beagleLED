/**
 * @file Beaglebone.hpp class file for Beaglebone
 */
#include <array>
#include <cstdint>
#include "Led.hpp"

/**
 * @class Beaglebone 
 * @short Represents the beaglebone black
 */
class Beaglebone{
private:
  /// GPIO Leds
  std::array<Led, 4> leds{
    Led(std::pair<int,int>(1,21)),
      Led(std::pair<int,int>(2,22)),
      Led(std::pair<int,int>(2,23)),
      Led(std::pair<int,int>(2,24))
      };
  
public:
  /**
   * @brief gets an led by its nr or relative position
   * @param led_nr its position in the leds array
   * @return An Led
   */
  Led getLed(int led_nr);

  /**
   * @brief converts a pair to position for GPIO signal
   * @details Taks a pair representing the GPIO block and position 
   * within the block and converts it to a number that can be used 
   * as GIPO Signal.
   * @param gpioPosition GPIO block and position within block
   * @return integer corresponding to GPIO Signal
   */
  int convertGpioPositionToAbsolute(std::pair<int, int> gpioPosition);
};
