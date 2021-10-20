/** \file log_formatter.hpp
 * Contains logging related definitions and helper functions
 */
#include <cstdio>
#define DEFAULT_LOG_SIZE 100

#ifdef __has_include
# if __has_include("cmake_configuration.hpp")
#  include "cmake_configuration.hpp"
# endif
# if __has_include("cmake_print_colors.hpp")
#  include "cmake_print_colors.hpp"
# endif
#else
# pragma message("Your compiler does not support __has_include, source shuld be manually updated to support cmake_configuration.h when relevant")
#endif

#ifndef LOG_LEVEL
/// Default Minimum required significanse for a message to be printed. might be overwritten in cmake_configuration.h
#define LOG_LEVEL WARNING
#endif

#ifndef USING_COLOR
# define COLOR_DEBUG ""
# define COLOR_INFO ""
# define COLOR_WARNING ""
# define COLOR_ERROR ""
# define COLOR_CLEAR ""
#endif

/**
 * Represents the significanse of a logging message
 */
enum Log_level{
  DEBUG = 0,
  INFO,
  WARNING,
  ERROR
};

/**
 * Formats text for logging
 * @param level indicate the significanse of the message
 * @param buffer location for the formated text
 * @param buf_size the maximum nr of bytes to write
 * @param fmt format used with printf and similar functions
 * @return nr of bytes written -1 if error occured
 */
int log_formatter(Log_level level, char* buffer, std::size_t buf_size, const char* fmt, ...);
