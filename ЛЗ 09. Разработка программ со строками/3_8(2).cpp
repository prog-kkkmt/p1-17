// Напишите программу, способную читать строки со стандартного устройства ввода 
// и соединять их в одну большую строку. Отобразите полученную строку. Измените программу так, чтобы 
// отделить соседние введенные строки пробелами.

//Выполнил: Богомолов Максим П1-17
//14.05.2020

#include <iostream>

using namespace std;

int main() {
    string s1;
    string s2 = "";

    while (getline(cin, s1)) {
        s2 = s2 + s1 + ' ';
    }

    cout << s2 << endl;

    return 0;
}
