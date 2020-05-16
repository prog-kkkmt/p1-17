#include <iostream>

using namespace std;


struct Point
{
    Point(double x = 0, double y = 0) : x(x), y(y)
    {}
    double x;
    double y;
};

int main()
{
    Point p1;
    Point p2(2);
    Point p3(3,7);
}
