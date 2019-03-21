#include <iostream>
#include <vector.h>

int main(int argc, char *argv[])
{
  Vector<char> test_vector;
  test_vector.push_back('t');
  test_vector.push_back('e');
  test_vector.push_back('s');
  test_vector.push_back('t');
  test_vector.print_elements();
  return 0;
}
