/******************************************************************************
Вычислить а в степени b

*******************************************************************************/

#include <iostream>
using namespace std;
 
long pow(long a, long b) {
  if(b == 0){
    return 1;
  }
  if(b % 2 == 0){
    return pow(a * a, b / 2);
  }
  return a * pow(a, b - 1);
}
 
int main() {
  long a, b;
  cin >> a >> b;
  cout << pow(a,b);
  return 0;
}