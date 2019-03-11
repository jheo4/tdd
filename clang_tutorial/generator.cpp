#include "catch2/catch.hpp"

#include <random>

class RandomIntGenerator : public Catch::Generators::IGenerator<int>{
  std::minstd_rand rand;
  std::uniform_int_distribution<> dist;
  int current_nuber;

public:
  RandomIntGenerator(int low, int high):rand(std::random_device{}()),
    dist(low, high){
      static_cast<void>(next());
    }

  int const& get() const override;

  bool next() override{
    current_nuber = dist(rand);
    return true;
  }
};

int const& RandomIntGenerator::get() const{
  return current_nuber;
}

Catch::Generators::GeneratorWrapper<int> random(int low, int high){
  return Catch::Generators::GeneratorWrapper<int>(
      std::unique_ptr<Catch::Generators::IGenerator<int>>(
      new RandomIntGenerator(low, high)));
}

TEST_CASE("Generating random ints", "[example][generator]") {
  SECTION("Nice UX") {
    auto i = GENERATE(take(100, random(-100, 100)));
    REQUIRE(i >= -100);
    REQUIRE(i <= 100);
  }
  SECTION("Creating the random generator directly") {
    auto i = GENERATE(take(100,
                GeneratorWrapper<int>(std::unique_ptr<IGenerator<int>>(
                new RandomIntGenerator(-100, 100)))));
    REQUIRE(i >= -100);
    REQUIRE(i <= 100);
  }
}
