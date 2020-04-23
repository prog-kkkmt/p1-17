/**Напишите рекурсивную функцию вычисления наибольшего общего делителя двух положительных целых чисел

Выполнила: Попкова Алена П1-17
Источник: Stepik.org Программирование в C++**/

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
