// Напишите программу для решения квадратных уравнений
//Выполнил: Богомолов Максим П1-17
//Источник: Stepik Computer Science Center (CS центр)
//Программирование на языке C++
//1.8.11 https://stepik.org/lesson/13377/step/11
//25.04.2020
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, c;

    cin >> a >> b >> c;
    
    double d = pow(b, 2) - (4 * a * c);
    if (d >= 0) {
        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);
        cout << x1 << " " << x2;
    } else {
        cout << "No real roots";
    }
    
    

    return 0;
}
