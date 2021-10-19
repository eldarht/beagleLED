#include <cstdio>
#define DEFAULT_LOG_SIZE 100

#ifdef __has_include
# if __has_include("cmake_configuration.h")
#  include "cmake_configuration.h"
# endif
#else
# pragma message("Your compiler does not support __has_include, source shuld be manually updated to support cmake_configuration.h when relevant")
#endif

//#endif

#ifndef LOG_LEVEL
#define LOG_LEVEL WARNING
#endif

enum Log_level{
  DEBUG = 0,
  INFO,
  WARNING,
  ERROR
};

int log_formatter(Log_level level, char* buffer, std::size_t buf_size, const char* fmt, ...);
