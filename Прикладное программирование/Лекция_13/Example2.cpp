#include <iostream>
#include <math.h>

using namespace std;

class CPoint
{
    protected:
        int x, y;
    public:
        CPoint(int _x = 0, int _y = 0)
    {
        x = _x; y = _y;
    }
};

class CCircle: public CPoint
{
    protected:
        int R;
    public:
        CCircle(int _x, int _y, int _r): CPoint(_x, _y)
        {
            R = _r;
        }
    void print()
    {
        cout << "Centr: (" << x << "," <<  y << ") R = " << R << endl;
    }
};
   
int main()
{
    CCircle c1(4, 7, 8);
    c1.print();
    return 0;
}
