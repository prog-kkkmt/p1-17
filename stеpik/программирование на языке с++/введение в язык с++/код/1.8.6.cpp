#include <iostream>
using namespace std;

int log(int a)
{int b = 2, c = 0;
 while (a >= b)
  {a /= b;
   c++;}
return c;}

int main()
{int t, n;
 cin>>t;
 for(int i = 0; i<t; i++)
  {cin>>n;
   cout<<log(n)<<endl;}
  return 0;}


