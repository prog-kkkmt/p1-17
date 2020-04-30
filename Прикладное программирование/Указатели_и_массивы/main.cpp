/**Разработать программу с меню для работы с массивом целых чисел из 10 элементов.
Пункты меню: Заполнение, Нахождение максимального, Нахождение суммы, Печать, Выход.
Для каждого действия (кроме выхода) разработать функцию, принимающую в качестве параметров
адрес первого элемента массива и количество элементов.**/

#include <iostream>
#include "mylib.hpp"
#define SIZE 10

using namespace std;

int main()
{
    int arr[SIZE];
    int n, f;

    setlocale(LC_ALL, "Russian");

    cout << "Size of array: ";
    cin >> n;

    cout << "0: Заполнение"<< endl;
    cout << "1: Нахождение максимального элемента"<< endl;
    cout << "2: Нахождение суммы"<< endl;
    cout << "3: Печать"<< endl;
    cout << "4: Выход"<< endl;

    do{
        cout << "Выберите номер действия: ";
        cin >> f;
        switch(f){
        case 0:
            input(arr, n);
            break;
        case 1:
            {
                 int *pmax =Max(arr, arr + n);
                cout <<"Max = " << *pmax << endl;
                break;
            }

        case 2:
            cout << "Sum = " << sumArray(arr, arr + n) << endl;
            break;

        case 3:
            output(arr, n);
            break;

        case 4:
            cout << "Goodbye!" << endl;
            break;

        default:
            cout << "Error" << endl;
        }

    }while (f != 4);


    return 0;
}
