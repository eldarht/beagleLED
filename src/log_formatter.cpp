#include <string>
#include <vector>
#include <ctime>
#include "log_formatter.hpp"
#include <cstdio>
#include <cstdarg>

std::string log_level_to_string(Log_level level){
  
  switch(level){
  case DEBUG:
    return "DEBUG";
    break;
  case INFO:
    return "INFO";
    break;
  case WARNING:
    return "WARNING";
    break;
  case ERROR:
    return "ERROR";
    break;
  default:
    return "?";
    break;
  }
}
  
int log_formatter(Log_level level, char* buffer, std::size_t buf_size, const char* fmt, ...)
{
  // Get log level text
  std::string log_level_buf = log_level_to_string(level);

  // Get timing text
  std::time_t t = std::time(nullptr);
  char time_buf[100];
  std::strftime(time_buf, sizeof time_buf, "%D %T", std::gmtime(&t));

  // Create argument list and copy
  va_list args1;
  va_start(args1, fmt);
  va_list args2;
  va_copy(args2, args1);

  // Use one argument list to create buffer
  std::vector<char> buf(1+std::vsnprintf(nullptr, 0, fmt, args1));
  va_end(args1);

  // Use buffer to create log text
  std::vsnprintf(buf.data(), buf.size(), fmt, args2);
  va_end(args2);

  int written_length;
  // Combine text segments in result buffer and return length
  if(log_level_buf.c_str() != nullptr && time_buf != nullptr && buf.data() != nullptr){ 
    written_length = std::snprintf(buffer, buf_size, "[%-7s] %s:\t%s", log_level_buf.c_str(), time_buf, buf.data());
  }
  return written_length;//written_length;
}
