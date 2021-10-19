#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <chrono>
#include <thread>
#include "heartbeat.hpp"
#include "Beaglebone.hpp"
#include "log_formatter.hpp"

#define GPIO_PATH "/sys/class/gpio/"

Beaglebone beaglebone;

void heartbeat()
{
  using namespace std::this_thread;     // sleep_for, sleep_until
  using namespace std::chrono_literals; // ns, us, ms, s, h, etc.

  std::fstream fs;
  char log_buffer[DEFAULT_LOG_SIZE];
  log_formatter(INFO, log_buffer, DEFAULT_LOG_SIZE -1, "Starting LED flash\n");
  printf("%s\n", log_buffer);

  fs.open(GPIO_PATH "export", std::fstream::out);
  if(!fs.is_open()){
    log_formatter(ERROR, log_buffer, DEFAULT_LOG_SIZE -1, "Could not write to GPIO \"export\"\n");
    printf("%s\n", log_buffer);
    return;
  }

  std::string gpioNr = std::to_string(beaglebone.convertGpioPositionToAbsolute(beaglebone.getLed(1).getGpioPosition()));
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

  fs.open(GPIO_PATH "/gpio53/value", std::fstream::out);
  log_formatter(DEBUG, log_buffer, DEFAULT_LOG_SIZE -1, "Value path was %sgpio53/value\n", GPIO_PATH);
  printf("%s\n", log_buffer);
  
  while(fs.is_open()){
      fs << "1";
      fs.close();
      sleep_for(100ms);
      fs.open(GPIO_PATH "/gpio53/value", std::fstream::out);
      fs << "0";
      fs.close();
      sleep_for(100ms);
  }

  log_formatter(ERROR, log_buffer, DEFAULT_LOG_SIZE -1, "Could not write to GPIO LED value\n");
  printf("%s\n", log_buffer);
}
