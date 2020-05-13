/**
Разработать программу с меню для работы с массивом целых чисел из 10 элементов.
Пункты меню: Заполнение, Нахождение максимального, Нахождение суммы, Печать, Выход.
Для каждого действия (кроме выхода) разработать функцию, принимающую в качестве параметров
адрес первого элемента массива и количество элементов.
**/

#include <iostream>
#include <locale>
#define SIZE 10

using namespace std;

void zapolnenie(int *a, int n)
{
    int k;
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> *(a + i);
    }
}

void vivod(int *a, int n)
{
    for (int i = 0; i < n; i++)
        cout << *(a + i) << " ";
    cout << endl;
}

int max_elem(int *a, int n)
{
    int max_el = *a;
    for (int i = 1; i < n; i++)
        if (*(a + i) > max_el)
            max_el = *(a + i);
    return max_el;
}

int summa(int *a, int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
        sum += *(a + i);
    return sum;
}

int main()
{
    setlocale (LC_ALL, "Rus");
    cout << "Выберите действие:\n1 - Заполнение\n2 - Нахождение максимального\n3 - Нахождение суммы\n4 - Печать\n0 - Выход\n" << endl;
    int vibor, *m = new int[SIZE];
    cin >> vibor;
    while (vibor != 0)
    {
        switch (vibor)
        {
            case 1:
                zapolnenie(m, SIZE);
                break;

            case 2:
                cout << max_elem(m, SIZE) << endl;
                break;

            case 3:
                cout << summa(m, SIZE) << endl;
                break;

            case 4:
                vivod(m, SIZE);
                break;
        }
        cout << "Выберите действие:\n1 - Заполнение\n2 - Нахождение максимального\n3 - Нахождение суммы\n4 - Печать\n0 - Выход\n" << endl;
        cin >> vibor;
    }
    return 0;
}

///Выполнила: Фролова Л.А.
///Дата выполнения: 25.04.2020
