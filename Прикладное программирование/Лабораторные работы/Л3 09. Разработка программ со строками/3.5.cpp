/*Выполнила: Феоктистова А.С., П1-17, 15.05.2020
Задача: Напишите программу, читающую со стандартного устройства ввода целые строки.
Измените программу так, чтобы она читала отдельные слова.*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str, word;
    getline(cin, str);
    cout << str << endl;
    while (cin >> word)
        cout << word << endl;
    return 0;



}
