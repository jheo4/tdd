#include "catch2/catch.hpp"

#ifdef _MSC_VER
# pragma warning (disable : 4702) // Disable warning: unreachable code
#endif

TEST_CASE( "TeamCity passes unconditionally succeeding assertion",
    "[teamcity]" ) {
  SUCCEED();
}

TEST_CASE( "TeamCity reports unconditionally failing assertion",
    "[teamcity]" ) {

  FAIL();
}

TEST_CASE( "TeamCity reports failing check", "[teamcity]" ) {
  REQUIRE( 3 == 7 );
}

TEST_CASE( "TeamCity reports failing check-false", "[teamcity]" ) {
  REQUIRE_FALSE( 3 == 3 );
}

TEST_CASE( "TeamCity reports failing check-that", "[teamcity]" ) {
  using namespace Catch;

  REQUIRE_THAT( "hello", Contains( "world" ) );
}

TEST_CASE( "TeamCity reports unexpected exception", "[teamcity]" ) {
  REQUIRE( (throw std::runtime_error("surprise!"), true) );
}

TEST_CASE( "TeamCity reports undesired exception", "[teamcity]" ) {
  REQUIRE_NOTHROW( (throw std::runtime_error("surprise!"), true) );
}

TEST_CASE( "TeamCity reports missing expected exception", "[teamcity]" ) {
  REQUIRE_THROWS( true );
}

TEST_CASE( "TeamCity reports missing specific expected exception",
    "[teamcity]" ) {
  REQUIRE_THROWS_AS( throw std::bad_alloc(), std::runtime_error );
}

TEST_CASE( "TeamCity reports unexpected message in expected exception",
    "[teamcity]" ) {
  using namespace Catch;

  CHECK_THROWS_WITH( throw std::runtime_error("hello"), "world" );
  CHECK_THROWS_WITH( throw std::runtime_error("hello"), Contains("world") );
}

struct MyException: public std::runtime_error
{
  MyException( char const * text )
    : std::runtime_error( text ) {}

  ~MyException() override;
};
MyException::~MyException() = default;

struct MyExceptionMatcher : Catch::MatcherBase< std::runtime_error >
{
  std::string m_text;

  MyExceptionMatcher( char const * text )
    : m_text( text )
  {}

  ~MyExceptionMatcher() override;
  bool match( std::runtime_error const & arg ) const override
  {
    return m_text == arg.what();
  }

  std::string describe() const override
  {
    return "it's me";
  }
};
MyExceptionMatcher::~MyExceptionMatcher() = default;

TEST_CASE( "TeamCity failing check-throws-matches", "[teamcity]" ) {
  CHECK_THROWS_MATCHES( throw MyException("hello"), MyException,
      MyExceptionMatcher("world") );
}

TEST_CASE( "TeamCity throwing exception with tag [!throws]",
    "[teamcity][!throws]" ) {
  REQUIRE_THROWS( throw std::runtime_error("unsurprisingly") );
}

TEST_CASE( "TeamCity failing assertion with tag [!mayfail]",
    "[teamcity][!mayfail] " ) {

  REQUIRE( 3 == 7 );
  REQUIRE( 3 == 3 );
}

TEST_CASE( "TeamCity succeeding assertion with tag [!shouldfail]",
    "[teamcity][!shouldfail]" ) {
  SUCCEED( "Marked [!shouldfail]" );
}

