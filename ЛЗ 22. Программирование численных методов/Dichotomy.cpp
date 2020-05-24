#include <iostream>
#include <cmath>
using namespace std;
const double epsilon = 1e-2;

double f(double x)
{
    return 4- exp(x) - 2*x^2;
}

int main()
{
    double a, b, c;
    a = 0;
    b = 2;
    while (b - a > epsilon){
        c = (a + b) / 2;
        if(f(b) * f(c) < 0)
            a = c;
        else
            b = c;
    }
    cout << (a + b) / 2 << endl;
    return 0;
}
