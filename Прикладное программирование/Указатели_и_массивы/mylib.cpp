#include "mylib.hpp"
#include <iostream>

using namespace std;

void input(int *m, int n) /*Заполнение массива*/
{
    for (int *p = m; p < m + n; p++)
        cin >> *p;
    cout << "Done" << endl;
}

int *Max(int * p, int *q)/*Поиск максимального элемента*/
{
    int *pmax = p; /*Указатель на максимальный элемент*/

    for (; p != q; p++)
        if (*p > *pmax)
            pmax = p;

    return pmax;
}

int sumArray(int *p, int *q) /*Сумма массива*/
{
    int sum = 0;
    for (; p != q; p++)
        sum += *p;

    return sum;
}

void output(int *m, int n) /*Печать массива*/
{
    for (int *p = m; p < m + n; p++)
        cout << *p << " ";

    cout << endl;
}
