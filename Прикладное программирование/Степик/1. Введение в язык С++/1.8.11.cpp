/*
30.04.2020
Выполнил Бобнев Алексей П1-17
Напишите программу для решения квадратных уравнений.
Ссылка на задание https://stepik.org/lesson/13377/step/11?unit=3571
Степик 1.8.11
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c, Di;
    cin >> a >> b >> c;
    Di = b * b - 4 * a * c;
    if (Di < 0)
    cout << " No real roots";
    else
        cout << (double)((-b + sqrt(Di)) / (2 * a)) << " " << (double)((-b - sqrt(Di)) / (2 * a));
    return 0;
}
