/**Напишите программу для вычисления целочисленного логарифма по основанию 2.

Выполнила: Попкова Алена П1-17
Источник: Stepik.org Программирование в C++**/

#include <iostream>

int logf(int b)
{
    int a = 2;
    int i = 0;
    while (b >= a)
    {
        b /= a;
        i++;
    }

    return i;

}

using namespace std;

int main()
{
    int t;
    int num;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> num;
        cout << logf(num)<< endl;
    }

    return 0;
}
