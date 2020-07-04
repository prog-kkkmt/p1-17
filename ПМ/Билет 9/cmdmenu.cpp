#include "cmdmenu.hpp"
#include <iostream>
#include <string>

using namespace std;

void Menu::menu()
{
    cout << "1)Актуальные вакансии\n";
    cout << "2)Сравнительная таблица средних окладов по уровню владения ПК\n";
    cout << "3)Выход\n";
    cout << "\n";
    cout << "Выберете пункт: ";
}

//Проверка ввода номера элемента меню

int Menu::select_num(int n)
{
    int input;
    string s;
    getline(cin, s);
    while (sscanf(s.c_str(), "%d", &input) != 1 || input < 1 || input > n)
    {
        cout << "Некорректный ввод, повторите...\nВыберете пункт: ";
        getline(cin, s);
    }
    return input;
}

//Очистка консоли

void Menu::clear()
{
    static const int LINE_COUNT = 200;
    for (int i = 0; i < LINE_COUNT; i++)
        cout << "\n";
}