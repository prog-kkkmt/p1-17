///Упражнение 3.5. Напишите программу, читающую со стандартного устройства ввода целые строки. Измените программу так, чтобы она читала отдельные слова.
///Выполнил: Юшаков Н. Р.
///Дата: 13.05.2020
#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main() {
    setlocale(0, "");
    string line;
    string word;
    cout << "Сейчас считывается строка: ";
    getline(cin, line);
    cout << line << endl;
    cout << "Сейчас считываются слова: ";
    while (cin >> word)
        cout << word << endl;
    return 0;
}
