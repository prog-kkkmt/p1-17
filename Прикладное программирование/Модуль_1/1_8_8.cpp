/**Реализуйте макрос MAX от трёх параметров, который присваивает целочисленной (int) переменной, переданной в качестве третьего аргумента,
наибольшее из значений, переданных в первых двух аргументах.

Выполнила: Попкова Алена П1-17
Источник: Stepik.org "Программирование на языке C++" Computer Science Center (CS центр) 1.8.8. https://stepik.org/lesson/13377/step/8
23.04.2020 **/


#include <iostream>
#define MAX(x, y, r) { \
    int num1 = (x);\
    int num2 = (y);\
    r = (num1 > num2)? num1: num2;}

using namespace std;


int main()
{
    int a;
    int b;
    int res = 0;

    cin >> a >> b;
    MAX(a, b, res);
    cout << res << endl;
    MAX(a+=b, b, res);
    cout << res << endl;

  return 0;
}


