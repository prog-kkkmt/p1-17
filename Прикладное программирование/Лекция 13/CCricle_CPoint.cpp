/*Создать класс CCircle на основе класса CPoint.*/
#include <stdio.h>
#include <math.h>
class CPoint
{
protected:
    int x, y;
public:
    CPoint(int _x = 0, int _y = 0)
    {
        x = _x;
        y = _y;
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
        printf("Centr: (%d, %d). R = %d.\n", x, y, R);
    }
};
int main()
{
    CCircle c1(4, 7, 8);
    c1.print();
    return 0;
}
