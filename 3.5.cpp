//Напишите программу, читающую со стандартного устройства ввода целые строки.
//Измените программу так, чтобы она читала отдельные слова.
//Выполнила: Суркова Валерия П1-17
//Дата:14.05.2020


#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main()
{
    setlocale(0, " ");
    string stroka, slovo;
    cout << "Считывает целые строки:";
        getline(cin, stroka);
            cout << stroka << endl;
    cout << "Считывает отдельные слова:";
        while (cin >> slovo)
            cout << slovo << endl;
    return 0;



}
