#include <iostream>
#include <thread>
#include "heartbeat.hpp"
#include "log_formatter.hpp"
#include "Beaglebone.hpp"

int main(int argc, char* argv[]){
  char log_buffer[DEFAULT_LOG_SIZE];
  log_formatter(DEBUG, log_buffer, DEFAULT_LOG_SIZE -1, "Application started");
  printf("%s\n",log_buffer);

  std::thread thread_heartbeat(heartbeat);

  thread_heartbeat.join();

  return 0;
}

