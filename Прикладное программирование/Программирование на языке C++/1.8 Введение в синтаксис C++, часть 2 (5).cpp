#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    double d = b * b - 4 * a * c;
    if (d < 0)
        cout << "No real roots";
    else
        cout << ((-1.0 * b) + sqrt(d)) / (2 * a) << " " << ((-1.0 * b) - sqrt(d)) / (2 * a);
    return 0;
}
