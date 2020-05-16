#include <iostream>

using namespace std;


struct Point
{
    Point () : x(0), y(0)
    {}

    Point(double x, double y) : x(x), y(y)
    {}
    double x;
    double y;
};

int main()
{
    Point p1;
    Point p2(3,7);
}
