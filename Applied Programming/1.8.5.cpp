#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c; 
    int x1 = 0;
    int x2 = 0;
    cin >> a >> b >> c;
    
    int d = b * b - 4 * a * c;
    
    if(d < 0) 
    {
      cout << "No real roots";
    }  
    if(d == 0) 
    {
      x1 = (-b + sqrt(d)) / (2 * a);
      cout << x1 << " " << x1;
    }
    if(d > 0)
    { 
      x1 = (-b + sqrt(d)) / (2 * a);
      x2 = (-b - sqrt(d)) / (2 * a);
      cout << x1 << " " << x2;
    }
    return 0;
}
