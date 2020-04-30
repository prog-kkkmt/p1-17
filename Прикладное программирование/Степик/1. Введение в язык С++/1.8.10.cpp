/*
25.04.2020
Выполнил Бобнев Алексей П1-17
Источник: 1.8.10. https://stepik.org/lesson/13377/step/10?unit=3571
Простая задача на закрепления материала по работе с  вводом/выводом. Напишите программу, которая суммирует целые числа./*
*/

#include <iostream>

using namespace std;

int main()
{
    int Kol;
    int a, b, i;
    cin >> Kol;
    for(i = 0; i < Kol; i++)
    {
        cin >> a >> b;
        cout << a + b << endl;
    }
    return 0;
}
