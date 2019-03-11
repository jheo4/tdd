# Clang TDD with catch2
## How to compile & test
catch_main.cpp is used as the test main of other files

```
g++ -std=c++11 -Wall -c catch_main.cpp
g++ -std=c++11 -Wall -o <OUT_NAME> catch_main.o <OTHER_TEST_FILES>
```

## Breif Description of Catch2
### Use my main instead of CATCH_CONFIG_MAIN
factorial_widt_mymain.cpp

### Class fixtures
There are two kinds of fixtures.
  - Section fixture: test_section_fixture.cpp, section.cpp
  - Class fixture: test_class_fixture.cpp

### Assertion and Check
REQEST must be passed in the test, and CHECK can be failed while testing.

factorial.cpp, req_check.cpp

### Report
Catch2 supports various kinds of report options

rpt_catch_main.cpp, rpt_teamcity_reporter.cpp, reporters/catc_reporter_teamcity.hpp

### Generator
There is a generator template of catch2

generator.cpp
