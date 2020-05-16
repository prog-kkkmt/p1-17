////Напишите программу, способную читать строки со стандартного устройства ввода  и соединять их в одну большую строку. Отобразите полученную строку. Измените программу так, чтобы  отделить соседние введенные строки пробелами.
////Сделал Величко В.А.
////Дата: 13.05.2020

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    string temp;
    while (getline(cin, temp))
        if (s.empty())
            s += temp;
        else
            s = s + " " + temp;
    cout << s;
    return 0;
}
