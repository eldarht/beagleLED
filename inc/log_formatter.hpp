#include <cstdio>

#define DEFAULT_LOG_SIZE 50

enum Log_level{
  DEBUG = 0,
  INFO,
  WARNING,
  ERROR
};

int log_formatter(Log_level level, char* buffer, std::size_t buf_size, const char* fmt, ...);
