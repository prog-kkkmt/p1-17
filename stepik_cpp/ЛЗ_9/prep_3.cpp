/*Напишите программу, способную читать строки со стандартного устройства ввода 
и соединять их в одну большую строку. Отобразите полученную строку. Измените программу так, чтобы 
отделить соседние введенные строки пробелами.
*/
//Фатеев Д.И.

#include <iostream>
#include <string>

#define MAX 100

using namespace std;

int main()
{
    char CHOICE;
    string mas_str[MAX];
    int size;

    cout << "Enter the number of lines: ";
    cin >> size;
    for(int i = 0; i < size; ++i)
    {
            cout << "[" << i + 1 << "]" << ": ";
            cin >> mas_str[i];
    }

    cout << "Combine strings?   y/n" << endl;
    cin >> CHOICE;
    if(CHOICE == 'y')
    {
        cout << "Combine string: ";
        for (int i = 0; i < 10; ++i) 
            cout << mas_str[i];
    }
    else
    {
        cout << "Space separated string: ";
        for (int i = 0; i < 10; ++i) 
            cout << mas_str[i] << " ";
    }
    
}