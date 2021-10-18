#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>
#include "log_formatter.hpp"

TEST_CASE( "log_formatter contains input string", "[logging]" ) {
  char log_buffer[50];

  log_formatter(DEBUG, log_buffer, 50, "TEST STRING");

  REQUIRE_THAT(log_buffer,  Catch::Matchers::Contains("TEST STRING"));
}
