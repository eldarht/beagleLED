cmake_minimum_required(VERSION 3.10)

project(beagleLED)

add_executable(beagleLED "${PROJECT_SOURCE_DIR}/src/main.cpp")

find_package(Catch2 REQUIRED)
