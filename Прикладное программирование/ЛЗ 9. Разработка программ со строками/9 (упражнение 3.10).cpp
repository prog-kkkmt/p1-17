/**
Напишите программу поиска в строке знаков пунктуации.
Программа должна позволить ввести символьную строку, содержащую знаки пунктуации,
и вывести ту же строку, но уже без знаков пунктуации.
**/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    getline (cin, str);
    int i = 0;
    while (str[i] != '\0')
    {
        if (ispunct(str[i]) && str[i] != ' ');
        else
           cout << str[i];
        i++;
    }
    return 0;
}

///Выполнила: Фролова Л.А.
///Дата выполнения: 14.05.2020
