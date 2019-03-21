#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  std::vector<char> test;

  test.reserve(5);


  test.insert(test.begin(), 't');
  test.insert(test.begin()+1, 't');
  test.insert(test.begin()+2, 't');
  test.insert(test.begin()+2, 't');
  test.insert(test.begin()+2, 't');
  test.insert(test.begin()+2, 't');
  test.insert(test.begin()+2, 't');
  cout << "size/capacity : " << test.size() << "/" << test.capacity() << endl;

  for(int i = 0; i < test.capacity(); i++){
    cout << i << "-th element: " << test[i] << endl;
  }
  return 0;
}
