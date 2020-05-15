/**
Изменить программу упражнения 3.10. так, чтобы входные данные поступали из файла input.txt,
а результат записывался в файл output.txt
**/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream input;
    ofstream output;
    string str;
    input.open("input.txt");
    getline(input, str);
    input.close();
    int i = 0;
    output.open("output.txt");
    while (str[i] != '\0')
    {
        if (ispunct(str[i]) && str[i] != ' ');
        else
            output << str[i];
        i++;
    }
    output.close();
    return 0;
}

///Выполнила: Фролова Л.А.
///Дата выполнения: 14.05.2020
