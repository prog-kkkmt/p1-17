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

    Currency& operator= (const Currency &c) {
        if (ID == 0) ID = c.ID;
        if (name != c.name) name = c.name;
        if (course != c.course) course = c.course;

        return *this;
    }
};

istream& operator >> (istream& in, Currency& c)
{
    in >> c.ID >> c.name >> c.course;
    return in;
}

ostream& operator << (ostream &os, const Currency &c)
{
    return os << c.ID << '\t' << c.name << "\t\t" << c.course;
}

struct Customer {
    int ID;
    string name;
    int passport;

    Customer& operator= (const Customer &c) {
        if (ID == 0) ID = c.ID;
        if (name != c.name) name = c.name;
        if (passport != c.passport) passport = c.passport;

        return *this;
    }
};

istream& operator >> (istream& in, Customer& c)
{
    in >> c.ID >> c.name >> c.passport;
    return in;
}

ostream& operator << (ostream &os, const Customer &c)
{
    return os << c.ID << '\t' << c.name << '\t' << c.passport;
}

struct Deal {
    int ID;
    int IDCustomer;
    int IDCurrency;
    int amount;

    Deal& operator= (const Deal &d) {
        if (ID == 0) ID = d.ID;
        if (IDCustomer != d.IDCustomer) IDCustomer = d.IDCustomer;
        if (IDCurrency != d.IDCurrency) IDCurrency = d.IDCurrency;
        if (amount != d.amount) amount = d.amount;

        return *this;
    }
};

istream& operator >> (istream& in, Deal& d)
{
    in >> d.ID >> d.IDCustomer >> d.IDCurrency >> d.amount;
    return in;
}

ostream& operator << (ostream &os, const Deal &d)
{
    return os << d.ID << '\t' << d.IDCustomer << "\t" << d.IDCurrency << '\t' << d.amount;
}

template <typename T>
void get(vector <T>& cur, string filename) {
    T buff;

    ifstream in(filename);

    if (in.is_open())
    {
        while (in >> buff)
        {
            cur.push_back(buff);
        }
    }

    in.close();
}

template <typename T>
void print(vector <T> cur) {
    system("cls");
    if (cur.size() > 0) {
        for (int i = 0; i < cur.size(); i++) {
            cout << cur.at(i) << endl;
        }
    } else {
        cout << "DB is empty.";
    }

    cout << endl << "Any keys. Quit" << endl;
    getch();
}

template <typename T>
void add(vector <T>& cur, string filename) {
    system("cls");

    T buff;

    cout << "Enter data with a space(ID - 0) ";
    cin >> buff;

    if (cur.size() > 0)
        buff.ID = cur.back().ID + 1;
    else
        buff.ID = 1;

    

    cur.push_back(buff);

    ofstream out(filename);

    if (out.is_open())
    {
        for (int i = 0; i < cur.size(); i++) {
            out << cur.at(i) << endl;
        }

        cout << endl << "Added.\nAny keys. Quit" << endl;
        getch();
    } else {
        cout << endl << "Error.\nAny keys. Quit" << endl;
        getch();
    }

    out.close();
}

template <typename T>
void deleteRow(vector <T>& cur, string filename) {
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

    ofstream out(filename);

    if (out.is_open())
    {
        for (int i = 0; i < cur.size(); i++) {
            out << cur.at(i) << endl;
        }

        cout << endl << "Delete.\nAny keys. Quit" << endl;
        getch();
    } else {
        cout << endl << "Error.\nAny keys. Quit" << endl;
        getch();
    }

    out.close();
}

template <typename T>
void edit(vector <T>& cur, string filename) {
    system("cls");
    int id;
    bool edit = false;

    T buff;

    cout << "Enter the ID of the item to edit: ";
    cin >> id;

    for (int i = 0; i < cur.size(); i++) {
        if (cur.at(i).ID == id) {
            cout << cur.at(i) << endl;

            cout << "Enter new data with a space(ID - 0) ";
            cin >> buff;

            cur.at(i) = buff;
        }
    }

    ofstream out(filename);

    if (out.is_open())
    {
        for (int i = 0; i < cur.size(); i++) {
            out << cur.at(i) << endl;
        }

        cout << endl << "Edited.\nAny keys. Quit" << endl;
        getch();
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