/**
Напишите программу, которая читает две строки и уведомляет, равны ли они,
а если нет, какая из них больше. Измените программу так, чтобы она указывала, имеют ли строки
одинаковую длину, и если нет, то какая из них длинней.
**/

#include <iostream>
#include <string>

using namespace std;

int sravnenie_strok(string s1, string s2)
{
    if (s1 == s2)
        return 0;
    else if (s1 > s2)
        return 1;
    else if (s2 > s1)
        return 2;
}

int sravnenie_dlin(string s1, string s2)
{
    if (s1.size() == s2.size())
        return 0;
    else if (s1.size() > s2.size())
        return 1;
    else if (s2.size() > s1.size())
        return 2;
}

int main()
{
    setlocale (LC_ALL, "Rus");
    string str1 = "Zravstvuyte,", str2 = "Leonid Borisovich!";

    switch (sravnenie_strok(str1, str2))
        {
            case 0:
            cout << "Строки равны" << endl;
            break;

            case 1:
            cout << "Первая строка больше второй" << endl;
            break;

            case 2:
            cout << "Вторая строка больше первой" << endl;
            break;
        }

    switch (sravnenie_dlin(str1, str2))
        {
            case 0:
            cout << "Длины строк равны" << endl;
            break;

            case 1:
            cout << "Длина первой строки больше второй" << endl;
            break;

            case 2:
            cout << "Длина второй строки больше первой" << endl;
            break;
        }

    return 0;
}

///Выполнила: Фролова Л.А.
///Дата выполнения: 14.05.2020
