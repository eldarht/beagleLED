
cmake_minimum_required(VERSION 3.10)

project(beagleLED)

add_executable(beagleLED "${PROJECT_SOURCE_DIR}/src/main.cpp")

find_package(Catch2)

if(Catch2::Catch2)
  message("Testing: ENABLED")
else()
  message("Testing: DISABLED")
endif()

#Install rules
install(TARGETS beagleLED DESTINATION bin)
