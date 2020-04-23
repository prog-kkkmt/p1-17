/**Напишите функцию power, реализующую возведение целого числа в неотрицательную целую степень.

Выполнила: Попкова Алена П1-17
Источник: Stepik.org Программирование в C++**/

#include <iostream>
using namespace std;

int power(int x, unsigned p) {
    return (p == 0)? 1: x * power(x, p - 1);
}

int main()
{
    int a;
    unsigned b;

    cin >> a >> b;
    cout << power(a, b);

  return 0;
}

