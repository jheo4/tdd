#include <catch2/catch.hpp>
#include "vector.h"
#include <string.h>

TEST_CASE("Test Vector Class", "[vector]"){
  Vector<char> test_vector;
  REQUIRE(test_vector.get_size() == MIN_VEC_SIZE);
  REQUIRE(test_vector.get_capacity() >= MIN_VEC_SIZE);

  SECTION("resize & reserve vector"){
    REQUIRE_THROWS(test_vector.resize(MAX_VEC_SIZE+1));
    REQUIRE_THROWS(test_vector.reserve(MAX_VEC_SIZE+1));

    REQUIRE_THROWS(test_vector.resize(MIN_VEC_SIZE-1));
    REQUIRE_THROWS(test_vector.reserve(MIN_VEC_SIZE-1));

    test_vector.resize(40);
    REQUIRE(test_vector.get_size() == 40);
    REQUIRE(test_vector.get_capacity() >= 40);

    test_vector.reserve(60);
    REQUIRE(test_vector.get_size() == 40);
    REQUIRE(test_vector.get_capacity() >= 60);

    test_vector.resize(20);
    REQUIRE(test_vector.get_size() == 20);
    REQUIRE(test_vector.get_capacity() >= 20);

    test_vector.reserve(MIN_VEC_SIZE);
    REQUIRE(test_vector.get_size() == 20);
    REQUIRE(test_vector.get_capacity() >= 20);
  }

  SECTION("push & pop back"){
    REQUIRE(test_vector.reserve(4) == true);
    test_vector.push_back('a');
    test_vector.push_back('b');
    test_vector.push_back('c');
    test_vector.push_back('d');
    REQUIRE(strncmp(test_vector.get_elements(), "abcd", 4) == 0);
    char pop_result = test_vector.pop_back();
    REQUIRE(strncmp(test_vector.get_elements(), "abc", 3) == 0);
    REQUIRE(pop_result == 'd');
  }

  SECTION("allocate new array and copy all the elements into it"){
    char test_string[5] = "test";
    char *test_result = Vector<char>::get_copied_elements(test_string, 4, 2);

    char cmp_ans[5] = "te";
    REQUIRE(strncmp(test_result, cmp_ans, 2) == 0);
    delete []test_result;

    test_result = Vector<char>::get_copied_elements(test_string, 4, 6);
    REQUIRE(strncmp(test_result, test_string, 4) == 0);
    delete []test_result;
  }

  SECTION("insert / erase / clear element(s)"){
    REQUIRE(test_vector.reserve(2) == true);

    REQUIRE(test_vector.insert('a', 0) == true);
    REQUIRE(test_vector.insert('b', 1) == true);
    REQUIRE(test_vector.erase(1) == 'b');
    REQUIRE(test_vector.erase(0) == 'a');
    REQUIRE(test_vector.insert('c', 2) == false);


    REQUIRE(test_vector.insert('a', 0) == true);
    REQUIRE(test_vector.insert('b', 1) == true);
    REQUIRE(test_vector.insert('c', 1) == true);
    REQUIRE(test_vector.insert('d', 1) == true);
    REQUIRE(test_vector.insert('d', 4) == true);
    REQUIRE(test_vector.insert('d', 5) == true);
    REQUIRE(test_vector.erase(1) == 'd');
    REQUIRE(test_vector.erase(1) == 'c');
    REQUIRE_THROWS(test_vector.insert('f', MAX_VEC_SIZE)); // out of the range

    REQUIRE(test_vector.clear() == true);
  }

  SECTION("reverse all the elements / swap two elements"){
    REQUIRE(test_vector.push_back('a') == true);
    REQUIRE(test_vector.push_back('b') == true);
    REQUIRE(test_vector.push_back('c') == true);
    REQUIRE(test_vector.push_back('d') == true);
    REQUIRE(test_vector.push_back('e') == true);

    REQUIRE_THROWS(test_vector.swap_elements(-1, 2));
    REQUIRE_THROWS(test_vector.swap_elements(0, MAX_VEC_SIZE));
    REQUIRE(test_vector.swap_elements(0, 4) == true);
    REQUIRE(test_vector.get_element(4) == 'a');
    REQUIRE(test_vector.get_element(0) == 'e');
    REQUIRE(test_vector.swap_elements(1, 3) == true);
    REQUIRE(test_vector.swap_elements(2, 2) == true);
    REQUIRE(test_vector.get_element(2) == 'c');

    REQUIRE(test_vector.clear() == true);
    REQUIRE(test_vector.push_back('a') == true);
    REQUIRE(test_vector.push_back('b') == true);
    REQUIRE(test_vector.push_back('c') == true);
    REQUIRE(test_vector.push_back('d') == true);
    REQUIRE(test_vector.push_back('e') == true);

    REQUIRE(test_vector.reverse() == true);
    REQUIRE(test_vector.get_element(0) == 'e');
    REQUIRE(test_vector.get_element(1) == 'd');
    REQUIRE(test_vector.get_element(2) == 'c');
    REQUIRE(test_vector.get_element(3) == 'b');
    REQUIRE(test_vector.get_element(4) == 'a');

    test_vector.erase(0);
    REQUIRE(test_vector.reverse() == true);
    REQUIRE(test_vector.get_element(0) == 'a');
    REQUIRE(test_vector.get_element(3) == 'd');
  }

  SECTION("search/get an element by index/value"){
    test_vector.push_back('a');
    test_vector.push_back('b');
    test_vector.push_back('c');
    char result_element = test_vector.get_element(2);
    REQUIRE(result_element == 'c');
  }
}

