// Напишите программу, читающую со стандартного устройства ввода целые строки. 
// Измените программу так, чтобы она читала отдельные слова.

//Выполнил: Пищулин Игорь
//14.05.2020

#include <iostream>

using namespace std;

string s2;

int main() {
    string word;

    while (cin >> word)
        cout << word << endl;

    return 0;
}
