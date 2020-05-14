#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include <windows.h>

#include "currency.hpp"

using namespace std;

void print(vector <Currency> cur);
void add(vector <Currency>& cur);

int main() {
    setlocale(0,"");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector <Currency> cur;

    Currency buff;

    bool mainLoop = true;

    ifstream in("currency.txt"); // окрываем файл для чтения

    if (in.is_open())
    {
        while (in >> buff.ID >> buff.name >> buff.course)
        {
            cur.push_back(buff);
        }
    }

    in.close();     // закрываем файл

    int choise;

    while (mainLoop) {
        system("cls");
        cout << "МЕНЮ (БАЗА ДАННЫХ ВАЛЮТЫ И ЕЕ КУРСА В РУБЛЯХ)" << endl;
        cout << "1. Печать строк базы данных" << endl;
        cout << "2. Добавление строки в базу" << endl;
        cout << "3. Удаление строки в базе" << endl;
        cout << "4. Редактирование строки в базе" << endl;
        cout << endl << "Любая клавиша. Выход" << endl;


        choise = getch() - 48;

        switch(choise){
            case 1: print(cur); break;
            case 2: add(cur); break;
            case 3: deleteRow(cur); break;
            case 4: edit(cur); break;
            default: mainLoop = false; break;
        }

    }

    return 0;
}
