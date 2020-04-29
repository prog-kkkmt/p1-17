/**Напишите рекурсивную функцию вычисления наибольшего общего делителя двух положительных целых чисел

Выполнила: Попкова Алена П1-17
Источник: Stepik.org "Программирование на языке C++" Computer Science Center (CS центр) 2.2.8 https://stepik.org/lesson/538/step/8
23.04.2020 **/

#include <iostream>

using namespace std;

unsigned gcd(unsigned a, unsigned b)
{
   if (b == 0)
        return a;
    else
        return gcd(b, a%b);

}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a,b);
    return 0;
}
