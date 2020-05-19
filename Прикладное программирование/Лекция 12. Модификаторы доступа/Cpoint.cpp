# include <stdio.h>
class CPoint                        //начало определения класса CPoint
{
private:
    int x;                //определение целой закрытой члена(переменной х
    int y;               //определение целой закрытой члена(переменной y
public:
    CPoint(int, int);
             //прототип конструктора класса CPoint с двумя параметрами
    void prn();            //прототип члена(функции prn класса CPoint
};                                       //конец описания класса CPoint
CPoint::CPoint(int x = 0, int _y = 0)
           //определение конструктора класса CPoint с двумя параметрами
{
    this >x = _x;                               //получаем доступ к полям
    this >y = _y;                                   //с помощью указателя
}
void CPoint::prn() //определение члена(функции prn класса CPoint
{
    printf("Tochka (%d, %d);\n", this >x, this >y);
                                  //вывод информации о координатах точки
}
void main()
{
    CPoint p1(7, 8), p2;
    p1.prn();
    p2.prn();
}