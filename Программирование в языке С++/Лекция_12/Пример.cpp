///Âûïîëíèëà:Ñóðêîâà Âàëåðèÿ

#include <stdio.h>

class CCircle
{
private:
    int x, y;
    const int R;
public:
    CCircle(int _x = 0, int _y = 0, int _r = 1);
    void prn();
};
CCircle::CCircle(int _x, int _y, int _r) : R(_r)
{
    x = _x;
    y = _y;
}
void CCircle::prn()
{
    printf("Center (%d, %d), R = %d.\n", x, y, R);
}
int main()
{
    CCircle x(7, 8, 9), y;
    x.prn();
    y.prn();
    return 0;
}
