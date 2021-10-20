/**
 * @file Led.hpp Class file for Led
 */

/* 
 * The LEDs on the beagebone black are arranged in GPIO blocks.
 * Each GPIO block has a size of 32 and the LEDs related
 * GPIO SIGNAL is based on the block nr and internal offset
 *
 * This file uses the Linux sysfs GPIO to communicate with 
 * the LEDs as it does not assume that drivers are pressent or
 * can autodetect the LEDs. 
 */


#include <utility>

/**
 * Set of possible states an Led can be in
 */
enum LedState{
  Led_off = 0,
  Led_on = 1
};

/**
 * @short Represents an Led on the beaglebone black
 */
class Led{
private:
  /// Pair representing the GPIO block and position within it where the Led is positioned
  std::pair<int,int> gpioPosition;
  /// The curren state of the Led
  LedState state;
public:
  /**
   * @brief constructs an led given its position
   * @param gpioPosition position on the board \see Led::gpioPosition
   * @param state its state during construction \see LedState
   */
  Led(std::pair<int,int> gpioPosition, LedState state = Led_off);

  /**
   * @brief changes the state of the led on/off
   * @return new LedState
   */
  LedState toggle();

  /**
   * @brief gets the current state of the Led
   * @return the state
   */
  LedState getState();

  /**
   * @brief gets the GPIO block nr and internal position
   * @brief the position
   */ 
  std::pair<int,int> getGpioPosition();
};
