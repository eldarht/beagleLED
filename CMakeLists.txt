cmake_minimum_required(VERSION 3.10)

project(beagleLED)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  add_compile_options(-Wall -Werror -O2 -fstack-protector-strong -Wformat-security)
endif()

include(FindThreads)
add_subdirectory("${PROJECT_SOURCE_DIR}/beagleboneLib")
add_executable(beagleLED
  "${PROJECT_SOURCE_DIR}/src/main.cpp"
  "${PROJECT_SOURCE_DIR}/src/log_formatter.cpp"
  "${PROJECT_SOURCE_DIR}/src/heartbeat.cpp"
  )

set(LOG_LEVEL_OPTIONS DEBUG INFO WARNING ERROR)
set(LOG_LEVEL INFO CACHE STRING "Application's level of logging")
set_property(CACHE LOG_LEVEL PROPERTY STRINGS ${LOG_LEVEL_OPTIONS})
configure_file(
  "${PROJECT_SOURCE_DIR}/cmake_configuration.hpp.in"
  "${PROJECT_SOURCE_DIR}/inc/cmake_configuration.hpp"
  )

target_link_libraries(beagleLED PUBLIC
  beagleboneLib
  Threads::Threads
  )

target_include_directories(beagleLED PUBLIC
  "${PROJECT_SOURCE_DIR}/inc"
  )

find_package(Catch2)

if(Catch2_FOUND)
  message("Testing: ENABLED")
  add_executable(unittesting
    "${PROJECT_SOURCE_DIR}/test/main.cpp"
    "${PROJECT_SOURCE_DIR}/src/log_formatter.cpp"
    )
  target_link_libraries(unittesting Catch2::Catch2)
  target_include_directories(unittesting PUBLIC
    "${CMAKE_SOURCE_DIR}/inc"
    )
  
  include(CTest)
  include(Catch)

  catch_discover_tests(unittesting OUT_DIR {CMAKE_BINARY_DIR}/test)
else()
  message("Testing: DISABLED")
endif()

find_package(Doxygen  
  OPTIONAL_COMPONENTS dot mscgen dia
  )

if(DOXYGEN_FOUND)
  message("Documentation: ENABLED")

  set(DOXYGEN_OUTPUT_DIRECTORY docs)
  set(DOXYGEN_GENERATE_LATEX YES)
  
  doxygen_add_docs(docs
    "${CMAKE_SOURCE_DIR}/inc/"
    COMMENT "Adding documentation with Doxygen"
    )
else()
  message("Documentation: DISABLED")
endif()

#Install rules
install(TARGETS beagleLED DESTINATION bin)
