#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#ifdef CATCH_EXAMPLE_RPT_1
#include CATCH_EXAMPLE_RPT_1
#endif

#ifdef CATCH_EXAMPLE_RPT_2
#include CATCH_EXAMPLE_RPT_2
#endif

#ifdef CATCH_EXAMPLE_RPT_3
#include CATCH_EXAMPLE_RPT_3
#endif

// g++ -std=c++11 -Wall -DCATCH_EXAMPLE_RPT_1=\"reporters/catch_reporter_teamcity.hpp\" rpt_catch_main.cpp
