#include "catch2/catch.hpp"


std::string
getOne(){
  return "one";
}


TEST_CASE("getOne req_pass", "[require]"){
  REQUIRE(getOne() == "one");
}


TEST_CASE("getOne req_fail", "[require]"){
  REQUIRE(getOne() == "1");
}


TEST_CASE("getOne req_fail_pass", "[require]"){
  WARN("REQUIRE stops at first failure");

  REQUIRE(getOne() == "x");
  REQUIRE(getOne() == "one");
}


TEST_CASE("getOne check_fail_req_pass", "[check]"){
  WARN("CHECK continues after failure");

  CHECK(getOne() == "x");
  REQUIRE(getOne() == "one");
}


TEST_CASE("getOne reqf_fail_pass", "[require-false]"){
  WARN("REQUIRE_FALSE stops at first failure");

  REQUIRE_FALSE(getOne() == "one");
  REQUIRE_FALSE(getOne() != "one");
}


TEST_CASE("getOne checkf_fail_reqf_pass", "[check-false]"){
  WARN("CHECK_FALSE continues after failure");

  CHECK_FALSE(getOne() == "one");
  REQUIRE_FALSE(getOne() != "one");
}

// TEST_CASE (6): 1 passed, 5 failed
// assertions;REQUIRE,REQUIRE_FALSE (8): 3 passed, 5 failed
