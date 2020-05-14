#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>

using namespace std;

struct Currency {
    int ID;
    string name;
    double course;
};

void print(vector <Currency> cur) {
    system("cls");
    for (int i = 0; i < cur.size(); i++) {
        cout << cur.at(i).ID << '\t' << cur.at(i).name << "\t\t" << cur.at(i).course << endl;
    }

    cout << endl << "Любая клавиша. Выход" << endl;
    getch();
}

void add(vector <Currency>& cur) {
    system("cls");

    Currency buff;

    buff.ID = cur.back().ID + 1;

    cout << "Введите название валюты: ";
    cin >> buff.name;

    cout << "Введите курс к рублю: ";
    cin >> buff.course;

    cur.push_back(buff);

    ofstream out("currency.txt"); // окрываем файл для записи

    if (out.is_open())
    {
        for (int i = 0; i < cur.size(); i++) {
            out << cur.at(i).ID << '\t' << cur.at(i).name << "\t\t" << cur.at(i).course << endl;
        }

        cout << endl << "Добавлено.\nЛюбая клавиша. Выход" << endl;
        getch();
    } else {
        cout << endl << "Ошибка.\nЛюбая клавиша. Выход" << endl;
        getch();
    }

    out.close();     // закрываем файл
}

void deleteRow(vector <Currency>& cur) {
    system("cls");
    int id;
    cout << "Введите ID удаляемого элемента: ";
    cin >> id;

    for (int i = 0; i < cur.size(); i++) {
        if (cur.at(i).ID == id) {
            cur.erase(cur.begin() + i);
            break;
        }
    }

    ofstream out("currency.txt"); // окрываем файл для записи

    if (out.is_open())
    {
        for (int i = 0; i < cur.size(); i++) {
            out << cur.at(i).ID << '\t' << cur.at(i).name << "\t\t" << cur.at(i).course << endl;
        }

        cout << endl << "Удалено.\nЛюбая клавиша. Выход" << endl;
        getch();
    } else {
        cout << endl << "Ошибка.\nЛюбая клавиша. Выход" << endl;
        getch();
    }

    out.close();     // закрываем файл
}

void edit(vector <Currency>& cur) {
    system("cls");
    int id;
    bool edit = false;
    string newName;
    double newCourse;
    cout << "Введите ID редактируемого элемента: ";
    cin >> id;

    for (int i = 0; i < cur.size(); i++) {
        if (cur.at(i).ID == id) {
            cout << endl << "Название валюты (" << cur.at(i).name << ". Без изменений - 0): ";
            cin >> newName;
            cur.at(i).name = (newName != "0") ? newName : cur.at(i).name;
            if (newName != "0") edit = true;

            cout << endl << "Курс валюты (" << cur.at(i).course << ". Без изменений - 0): ";
            cin >> newCourse;
            cur.at(i).course = (newCourse != 0) ? newCourse : cur.at(i).course;
            if (newCourse != 0) edit = true;
        }
    }

    ofstream out("currency.txt"); // окрываем файл для записи

    if (out.is_open())
    {
        if (edit){
            for (int i = 0; i < cur.size(); i++) {
                out << cur.at(i).ID << '\t' << cur.at(i).name << "\t\t" << cur.at(i).course << endl;
            }

            cout << endl << "Изменено.\nЛюбая клавиша. Выход" << endl;
            getch();
        } else {
            cout << endl << "Изменений нет.\nЛюбая клавиша. Выход" << endl;
            getch();
        }
    } else {
        cout << endl << "Ошибка.\nЛюбая клавиша. Выход" << endl;
        getch();
    }

    out.close();     // закрываем файл
}
