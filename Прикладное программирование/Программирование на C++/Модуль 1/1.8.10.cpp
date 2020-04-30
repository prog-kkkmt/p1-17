// """Простая задача на закрепления материала по работе с  
// вводом/выводом. Напишите программу, которая суммирует целые числа."""
//Выполнил: Пищулин Игорь
//Источник: Stepik Computer Science Center (CS центр)
//Программирование на языке C++
//1.8.10 https://stepik.org/lesson/13377/step/10
//25.04.2020
#include <iostream>
using namespace std;

int main()
{
    int n;
    int a, b;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        cout << a + b << '\n';
    }

    return 0;
}
