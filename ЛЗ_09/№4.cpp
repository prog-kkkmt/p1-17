#include <iostream>
#include <string>
#include <locale>

///Упражнение 3.5. Напишите программу, читающую со стандартного устройства ввода целые строки. Измените программу так, чтобы она читала отдельные слова.
/**
Программа выполнена студентом грцппы П1-17
Карандашев Н.К.
Дата выполненгия 12.05.20
**/
using namespace std;

int main() {
    setlocale(0, "");
    string str;
    string word;
    cout <<"Чтение всей строки"<<endl;
    getline(cin, str);
    cout << str << endl;
    cout << "Чтение одного слова"<<endl;
    while (cin >> word)
        cout << word << endl;

	return 0;
}
