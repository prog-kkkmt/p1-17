#include <iostream>
using namespace std;

int main()
{
  int i = 42;
  double d = 3.14;
  const char *s = "C-style string";
  bool l = i < d;

  cout << "This is an integer " << i << "\n";
  cout << "This is a bool "<< l << "\n";
  cout << "This is a double " << d << "\n";
  cout << "This is a \"" << s << "\"\n";

  return 0;
}
