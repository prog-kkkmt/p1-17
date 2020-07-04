#include <iostream>
#include "cmdmenu.hpp"
#include "classes.hpp"
#include "structors.hpp"

using namespace std;

int main()
{
    //Инициализируем два обьекта двух классов
    Menu cmd;
    Vac v;
    setlocale(LC_ALL, "Russian");
    cmd.menu();
    int input;
    //Создаем консольное меню при помощи case
    do
    {
        input = cmd.select_num(4);

        switch (input)
        {
        case 1:
            break;
        case 2:
            break;
        }
        if (input != 4)
            cout << endl;
    } while (input != 4);
    cout << "Работа приложения окончена";
    return 0;
}