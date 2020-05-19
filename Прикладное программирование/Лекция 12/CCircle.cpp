# include <stdio.h>
class CCircle                             //класс «окружность»
{
private:
    int x;
    int y;
    const int R;
public:
    CCircle(int _x = 0, int _y = 0, int _r = 1);
    //прототип конструктора
    void prn();
};
CCircle::CCircle(int _x, int _y, int _r) : R(_r)
    //реализация конструктора
{
    x = _x;
    y = _y;
}

void CCircle::prn()
{
    printf("Centr (%d, %d), R = %d.\n", x, y, R);
}

int main()
{
    CCircle c1(7, 8, 4), c2;
    c1.prn();
    c2.prn();
}
