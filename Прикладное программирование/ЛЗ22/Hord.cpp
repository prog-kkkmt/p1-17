//сделал Богомолов Максим П1-17
#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
    return pow(x, 3) - 18 * x - 83;
}

double hordMethod(double xPrev, double xCurr, double e)
{
    double xNext = 0;
    double tmp;

    do
    {
        tmp = xNext;
        xNext = xCurr - f(xCurr) * (xPrev - xCurr) / (f(xPrev) - f(xCurr));
        xPrev = xCurr;
        xCurr = tmp;
    } while (fabs(xNext - xCurr) > e);

    return xNext;
}

int main()
{
    double e = 0.001;

    double x0;
    double x1;

    cout << "enter x0\n";
    cin >> x0;

    cout << "enter x1\n";
    cin >> x1;

    double x = hordMethod(x0, x1, e);
    cout << "root: ";
    cout << x;
    return 0;
}
