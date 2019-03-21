#include <catch2/catch.hpp>

SCENARIO("vector operation", "[vector]"){
  GIVEN("vector items"){
    std::vector<int> vec(5);

    REQUIRE(vec.size() == 5);
    REQUIRE(vec.capacity() >= 5);

    WHEN("resize the vector"){
      vec.resize(10);
      THEN("check the increased size and capacity"){
        REQUIRE(vec.size() == 10);
        REQUIRE(vec.capacity() >= 10);
      }

      vec.resize(0);
      THEN("check the reduced size and capacity"){
        REQUIRE(vec.size() == 0);
        REQUIRE(vec.capacity() >= 5);
      }
    }

    WHEN("change the capacity"){
      vec.reserve(10);
      THEN("check the increased capacity"){
        REQUIRE(vec.size() == 5);
        REQUIRE(vec.capacity() >= 10);
      }

      vec.reserve(0);
      THEN("check the reduced capacity"){
        REQUIRE(vec.size() == 5);
        REQUIRE(vec.capacity() >= 5);
      }
    }
  }
}
