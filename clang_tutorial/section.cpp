#include <catch2/catch.hpp>

TEST_CASE("vector operations", "[vector]"){
  std::vector<int> vec(5);

  REQUIRE(vec.size() == 5);
  REQUIRE(vec.capacity() >= 5);

  SECTION("vector size-resizing"){
    vec.resize(10);
    REQUIRE(vec.size() == 10);
    REQUIRE(vec.capacity() >= 10);

    vec.resize(0);
    REQUIRE(vec.size() == 0);
    REQUIRE(vec.capacity() >= 5);
  }

  SECTION("vector capacity-resizing"){
    vec.reserve(10);
    REQUIRE(vec.size() == 5);
    REQUIRE(vec.capacity() >= 10);

    vec.reserve(0);
    REQUIRE(vec.size() == 5);
    REQUIRE(vec.capacity() >= 5);
  }
}
