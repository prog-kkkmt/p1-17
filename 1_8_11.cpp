#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c;
    double D, x;
    cin >> a >> b >> c;
    D = b * b - 4 * a * c;
    if (D < 0)
        cout << "No real roots";
    else if (D == 0)
        cout << (-b / (2 * a)) << " " << (-b / (2 * a));
    else
    {
        x = (-b - sqrt(D)) / (2 * a);
        cout << x << " ";
        x =(-b + sqrt(D)) / (2 * a);
        cout << x;
    }
    return 0;
}
