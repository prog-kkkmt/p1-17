#include <stdio.h>

class CPoint

{
private:
    int x, y;
public:
    CPoint(int x = 0, int y = 0);
    void Prn();
};
CPoint::CPoint(int _x, int _y)
{
   x = _x;
   y = _y;
}
void CPoint::Prn()
{
    printf("Tochka (%d, %d); \n", x, y);
}
int main()
{
    CPoint A(3, 9), B(5);
    A.Prn();
    B.Prn();
    return 0;
}
