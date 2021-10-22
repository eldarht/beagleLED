#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <chrono>
#include <thread>
#include "heartbeat.hpp"

#ifdef __has_include
# if __has_include("Beaglebone.hpp")
#  include "Beaglebone.hpp"
#  define USING_BEAGLEBONE_LIB
# endif
#else
# pragma message("Your compiler does not support__has_include, source should be manually updated to support Beaglebone.hpp when relevant")
#endif
#include "log_formatter.hpp"

#define GPIO_PATH "/sys/class/gpio/"

#ifdef USING_BEAGLEBONE_LIB
Beaglebone beaglebone;
#endif

void heartbeat()
{
  using namespace std::this_thread;     // sleep_for, sleep_until
  using namespace std::chrono_literals; // ns, us, ms, s, h, etc.

  std::fstream fs;
  char log_buffer[DEFAULT_LOG_SIZE];
  log_formatter(INFO, log_buffer, DEFAULT_LOG_SIZE -1, "Starting LED flash\n");
  printf("%s\n", log_buffer);



#ifdef USING_BEAGLEBONE_LIB
  std::string gpioNr = std::to_string(beaglebone.convertGpioPositionToAbsolute(beaglebone.getLed(1).getGpioPosition()));
#else
  std::string gpioNr = std::to_string(53);
  
  log_formatter(WARNING, log_buffer, DEFAULT_LOG_SIZE -1, "Not yet using BeagleboneLib");
  printf("%s\n", log_buffer);
#endif
  
  fs.open(GPIO_PATH "export", std::fstream::out);
  if(!fs.is_open()){
    log_formatter(ERROR, log_buffer, DEFAULT_LOG_SIZE -1, "Could not write to GPIO \"export\"\n");
    printf("%s\n", log_buffer);
    return;
  }

  fs << gpioNr;
  fs.close();

  fs.open(GPIO_PATH "gpio"+gpioNr+"/direction", std::fstream::out);
  log_formatter(DEBUG, log_buffer, DEFAULT_LOG_SIZE -1, "Direction path was %sgpio%s/direction\n", GPIO_PATH, gpioNr);
  printf("%s\n", log_buffer);
    
  if(!fs.is_open()){
    log_formatter(ERROR, log_buffer, DEFAULT_LOG_SIZE -1, "Could not write to GPIO LED direction\n");
    printf("%s\n", log_buffer);

    return;
  }
  fs << "out";
  fs.close();

  fs.open(GPIO_PATH "/gpio"+gpioNr+"/value", std::fstream::out);
  log_formatter(DEBUG, log_buffer, DEFAULT_LOG_SIZE -1, "Value path was %sgpio%s/value\n", GPIO_PATH, gpioNr);
  printf("%s\n", log_buffer);
  
  do{
      fs << "1";
      fs.close();
      sleep_for(100ms);
      fs.open(GPIO_PATH "/gpio"+gpioNr+"/value", std::fstream::out);
      fs << "0";
      fs.close();
      sleep_for(100ms);
      fs.open(GPIO_PATH "/gpio"+gpioNr+"/value", std::fstream::out);
  }while(fs.is_open());

  log_formatter(ERROR, log_buffer, DEFAULT_LOG_SIZE -1, "Could not write to GPIO LED value\n");
  printf("%s\n", log_buffer);
}
