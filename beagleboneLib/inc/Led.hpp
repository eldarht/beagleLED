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
  
enum LedState{
  Led_off = 0,
  Led_on = 1
};

class Led{
private:
  // Position is determined by <GPIO block, internal offset>
  std::pair<int,int> gpioPosition;
  LedState state;
public:
  Led(std::pair<int,int> gpioPosition, LedState state = Led_off);
  LedState toggle(); // Toggle LED on/off returning the new state
  LedState getState();
  std::pair<int,int> getGpioPosition();
};
