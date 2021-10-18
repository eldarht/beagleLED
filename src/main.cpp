#include <iostream>
#include "Beaglebone.hpp"
#include "log_formatter.hpp"

#define LOG_SIZE 50

int main(int argc, char* argv[]){
  char log_buffer[LOG_SIZE];
  log_formatter(DEBUG, log_buffer, LOG_SIZE -1, "Application started");
  printf(log_buffer);
}
