/*Напишите программу, читающую со стандартного устройства ввода целые строки. 
Измените программу так, чтобы она читала отдельные слова.
*/
//Фатеев Д.И.

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;
    getline(cin, line);
    cout << line;
}
