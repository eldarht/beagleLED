cmake_minimum_required(VERSION 3.10)

project(beagleLED)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  add_compile_options(-Wall -Werror -fstack-protector-strong -Wformat-security)
endif()

include(FindThreads)
add_subdirectory("${PROJECT_SOURCE_DIR}/beagleboneLib")
add_executable(beagleLED
  "${PROJECT_SOURCE_DIR}/src/main.cpp"
  "${PROJECT_SOURCE_DIR}/src/log_formatter.cpp"
  "${PROJECT_SOURCE_DIR}/src/heartbeat.cpp"
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

#Install rules
install(TARGETS beagleLED DESTINATION bin)
