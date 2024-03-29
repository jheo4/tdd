#include <iostream>
//#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

unsigned int
factorial(unsigned int number){
  return number <= 1 ? 1 : factorial(number-1)*number;
}

// TEST_CASE("TEST_NAME" [, TAGS])
// SECTION("SECTION_NAME")
TEST_CASE("factorial", "[factorial]"){
  REQUIRE( factorial(0) == 1 );
  REQUIRE( factorial(1) == 1 );
  REQUIRE( factorial(2) == 2 );
  REQUIRE( factorial(3) == 6 );
  REQUIRE( factorial(10) == 3628800 );
}

