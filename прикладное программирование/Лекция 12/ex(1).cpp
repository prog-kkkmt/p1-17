#include <iostream>
using namespace std;
 
class Point
{
private:
	int x;
	int y;
public:
	Point(int = 0,int = 0);//прототип конструктора
	void prn(); //прототип функции prn()
};
Point :: Point(int x, int y)
{
	this -> x = x; //доступ к полям с помощью указателя
	this -> y = y;
}
void Point :: prn() //вывод информации о точке
{
	cout << "Tochka : (" << this -> x << "," << this -> y << ")\n"; 
}
int main()
{
    Point p1(7, 8), p2;
    p1.prn();
    p2.prn();
    return 0;
}
