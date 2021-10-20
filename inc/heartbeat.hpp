/**
 * \file heartbeat.hpp
 * Contains hearbeat function
 */

/**
 * \brief Creates a heartbeat signal
 * \details uses Linux sysfs to create a gpio device of Beaglebone Led[1] 
 * and sets its direction to out before writing to it in a loop, flashing the led.
 */  
void heartbeat();
