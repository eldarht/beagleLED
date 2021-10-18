add_library(beagleboneLib "${CMAKE_CURRENT_SOURCE_DIR}/src/Beaglebone.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/Led.cpp"
  )
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

target_include_directories(beagleboneLib
  INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
  $<INSTALL_INTERFACE:include>
  )

