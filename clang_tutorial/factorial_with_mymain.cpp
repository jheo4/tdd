#include <iostream>
#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp>

unsigned int
factorial(unsigned int number){
  return number <= 1 ? 1 : factorial(number-1)*number;
}

TEST_CASE("factorial", "[factorial]"){
  REQUIRE( factorial(0) == 1 );
  REQUIRE( factorial(1) == 1 );
  REQUIRE( factorial(2) == 2 );
  REQUIRE( factorial(3) == 6 );
  REQUIRE( factorial(10) == 3628800 );
}

int main(int argc, char *argv[])
{
  Catch::Session session;
  // session.configData();

  // using namespace Catch::clara;
  // auto cli =
  //  session.cli() | Opt(<VAR>, "VAR") ["FLAG"]["--VAR"] ("DESCRIPTION");
  // session.cli(cli);

  int returnCode = session.applyCommandLine(argc, argv);
  if(returnCode != 0)
    return returnCode;

  int numFailed = session.run();
  return numFailed;
}
