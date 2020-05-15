/**
Напишите программу, читающую со стандартного устройства ввода целые строки.
Измените программу так, чтобы она читала отдельные слова.
**/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    string str;
    while (getline(cin, str))
        cout << str << endl;
}

///Выполнила: Фролова Л.А.
///Дата выполнения: 14.05.2020
