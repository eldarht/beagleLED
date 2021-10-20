add_library(beagleboneLib "${CMAKE_CURRENT_SOURCE_DIR}/src/Beaglebone.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/Led.cpp"
  )
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

target_include_directories(beagleboneLib
  INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
  $<INSTALL_INTERFACE:include>
  )

find_package(Doxygen
  OPTIONAL_COMPONENTS dot mscgen dia
  )
if(DOXYGEN_FOUND)
  set(DOXYGEN_OUTPUT_DIRECTORY docs)

  doxygen_add_docs(beagleboneLib-docs
    "${CMAKE_CURRENT_SOURCE_DIR}/inc/"
    COMMENT "Adding documentation for beagleboneLib"
    )
endif()
