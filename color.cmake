# Defining variables for configure cmake_print_colors
option(USING_COLOR OFF)

set(COLOR_DEBUG "\\e[90m")
set(COLOR_INFO "\\e[92m")
set(COLOR_WARNING "\\e[95m")
set(COLOR_ERROR "\\e[91m")
set(COLOR_CLEAR "\\e[0m")

configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake_print_colors.hpp.in"
  "${CMAKE_BINARY_DIR}/inc/cmake_print_colors.hpp"
  )
