#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Currency {
    int ID;
    string name;
    double course;
};

void print(vector <Currency> cur) {
    system("cls");
    if (cur.size() > 0) {
        for (int i = 0; i < cur.size(); i++) {
            cout << cur.at(i).ID << '\t' << cur.at(i).name << "\t\t" << cur.at(i).course << endl;
        }
    } else {
        cout << "DB is empty.";
    }

    cout << endl << "Any keys. Quit" << endl;
    getch();
}

void add(vector <Currency>& cur) {
    system("cls");

    Currency buff;

    if (cur.size() > 0)
        buff.ID = cur.back().ID + 1;
    else
        buff.ID = 1;

    cout << "Enter of currency name: ";
    cin >> buff.name;

    cout << "Enter the course to the ruble: ";
    cin >> buff.course;

    cur.push_back(buff);

    ofstream out("currency.txt");

    if (out.is_open())
    {
        for (int i = 0; i < cur.size(); i++) {
            out << cur.at(i).ID << '\t' << cur.at(i).name << "\t\t" << cur.at(i).course << endl;
        }

        cout << endl << "Added.\nAny keys. Quit" << endl;
        getch();
    } else {
        cout << endl << "Error.\nAny keys. Quit" << endl;
        getch();
    }

    out.close();
}

void deleteRow(vector <Currency>& cur) {
    system("cls");
    int id;
    cout << "Enter the ID of the item to delete: ";
    cin >> id;

    for (int i = 0; i < cur.size(); i++) {
        if (cur.at(i).ID == id) {
            cur.erase(cur.begin() + i);
            break;
        }
    }

    ofstream out("currency.txt");

    if (out.is_open())
    {
        for (int i = 0; i < cur.size(); i++) {
            out << cur.at(i).ID << '\t' << cur.at(i).name << "\t\t" << cur.at(i).course << endl;
        }

        cout << endl << "Delete.\nAny keys. Quit" << endl;
        getch();
    } else {
        cout << endl << "Error.\nAny keys. Quit" << endl;
        getch();
    }

    out.close();
}

void edit(vector <Currency>& cur) {
    system("cls");
    int id;
    bool edit = false;
    string newName;
    double newCourse;
    cout << "Enter the ID of the item to edit: ";
    cin >> id;

    for (int i = 0; i < cur.size(); i++) {
        if (cur.at(i).ID == id) {
            cout << endl << "Currency name (" << cur.at(i).name << ". Unchanged - 0): ";
            cin >> newName;
            cur.at(i).name = (newName != "0") ? newName : cur.at(i).name;
            if (newName != "0") edit = true;

            cout << endl << "Currency course(" << cur.at(i).course << ". Unchanged - 0): ";
            cin >> newCourse;
            cur.at(i).course = (newCourse != 0) ? newCourse : cur.at(i).course;
            if (newCourse != 0) edit = true;
        }
    }

    ofstream out("currency.txt");

    if (out.is_open())
    {
        if (edit){
            for (int i = 0; i < cur.size(); i++) {
                out << cur.at(i).ID << '\t' << cur.at(i).name << "\t\t" << cur.at(i).course << endl;
            }

            cout << endl << "Edited.\nAny keys. Quit" << endl;
            getch();
        } else {
            cout << endl << "No changes.\nAny keys. Quit" << endl;
            getch();
        }
    } else {
        cout << endl << "Error.\nAny keys. Quit" << endl;
        getch();
    }

    out.close();
}

bool sortByName(Currency v1, Currency v2) {
    return v1.name < v2.name;
}

bool sortByCourse(Currency v1, Currency v2) {
    return v1.course < v2.course;
}

void sortBy(vector <Currency> cur) {
    system("cls");
    int choise;

    cout << "1. by name" << endl;
    cout << "2. by course" << endl;

    choise = getch() - 48;

    switch (choise) {
        case 1: sort(cur.begin(), cur.end(), sortByName); break;
        case 2: sort(cur.begin(), cur.end(), sortByCourse); break;
        default: break;
    }

    print(cur);
}

void about() {
    system("cls");
    cout << "DATABASE OF CURRENCY AND ITS EXCHANGE RATE IN RUBLES" << endl;
    cout << endl << "DEVELOPER: OVOSKOP. All right reserved." << endl;
    cout << "16.05.2020" << endl;

    cout << endl << "Any keys. Quit" << endl;
    getch();    
}