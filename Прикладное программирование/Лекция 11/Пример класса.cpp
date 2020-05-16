/*Приведем пример класса CPoint с конструктором.*/
# include <stdio.h>

class CPoint                     //начало описания класса CPoint
{
private:                      //определение закрытых полей класса
    int x;                                                  //поле х
    int y;                                                  //поле y
public:                      //определение открытых полей класса
    CPoint(int, int); //прототип конструктора с двумя параметрами
    void Prn();                      //прототип метода класса Prn
};                                //конец описания класса CPoint
CPoint::CPoint(int _x, int _y)
//реализация конструктора класса CPoint
{
    x = _x;
    y = _y;
}
void CPoint::Prn()        //реализация метода Prn класса CPoint
{
    printf("Tochka (%d, %d);\n", x, y);
}
int main()
{
    CPoint A(3,9);
    A.Prn();
    return 0;
}
