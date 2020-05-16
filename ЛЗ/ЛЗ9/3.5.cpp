#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main() {
    setlocale(0, "");
    string line;
    string word;
    cout << "Считывается строчкой: ";
    getline(cin, line);
    cout << line << endl;
    cout << "Считывается словами ";
    while (cin >> word)
        cout << word << endl;
    return 0;
}
////3.5Напишите программу, читающую со стандартного устройства ввода целые строки. 
////Измените программу так, чтобы она читала отдельные слова.
////Сделал Величко В.А.
////Дата : 13.05.2020
