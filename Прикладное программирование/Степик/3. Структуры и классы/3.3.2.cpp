#include <iostream>

using namespace std;


struct Point
{
    Point ()
    {
        x = y = 0;
    }

    Point(double x, double y)
    {
        this -> x = x;
        this -> y = y;
    }
    double x;
    double y;
};

int main()
{
    Point p1;
    Point p2(3,7);
}
