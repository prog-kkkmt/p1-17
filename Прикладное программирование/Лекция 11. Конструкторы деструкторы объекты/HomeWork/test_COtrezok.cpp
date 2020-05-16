#include <stdio.h>
#include <math.h>
   
class CPoint                           //определение класса «точка»
{
private:
    int x, y;
public:
    CPoint(int _x, int _y)
    {x = _x; y = _y;}
     
    CPoint()
    {x = 0; y = 0;}
     
    void SetX(int _x)
    {x = _x;}
     
    void SetY(int _y)
    {y = _y;}
    
    int GetX()
    { return x; }
    
    int GetY()
    { return y; }
};
   
class COtrezok                       //определение класса «отрезок»
{
private:
    CPoint P1, P2;
                //начало отрезка — точка P1, конец отрезка — точка P2
public:
    COtrezok()                           //конструктор по умолчанию
    {
        P1.SetX(3);          //задаем координаты начала и конца отрезка,
        P1.SetY(3);                       //вызывая методы SetX и SetY
        P2.SetX(8);                         //для объекта класса CPoint
        P2.SetY(8);
    }
    COtrezok(int x1, int y1, int x2, int y2)
                                         //конструктор с параметрами
    {
        P1.SetX(x1);
        P1.SetY(y1);
        P2.SetX(x2);
        P2.SetY(y2);
    }
    
    COtrezok(CPoint p1, CPoint p2) //конструктор с параметрами
    {
        P1 = p1;                   //задаем значения начала отрезка
        P2 = p2;                    //задаем значения конца отрезка
    }
    
    void info()
    {
        printf("Begin: (%d, %d).\n", P1.GetX(),
            P1.GetY());
        printf("End: (%d, %d).\n", P2.GetX(),
            P2.GetY());
    }
};

int main()
{
    COtrezok otr1(5, 4, 10, 3); //создаем объект класса «отрезок»
    otr1.info();                   //выводим координаты отрезка на экран
    CPoint p1(1, 1), p2(7, 7);
       //создаем объект класса «отрезок» с помощью второго конструктора
    COtrezok otr2(p1, p2);
      //создаем объект класса «отрезок» с помощью третьего конструктора
    otr2.info();
    return 0;
}