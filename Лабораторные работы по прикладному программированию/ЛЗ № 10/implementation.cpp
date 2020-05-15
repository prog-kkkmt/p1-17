#include "Hotel.h"

vector<Person> persons;

void Start() {
    ifstream f("test.txt");
    Person person;
    if (f.is_open()) {
        while (!f.eof()) {
            f >> person.personID;
            getline(f, person.FIO, '"');
            getline(f, person.passport);
            persons.push_back(person);
        }
        f.close();
    }
}

void Menu() {
    bool menu = true;
    int operation;
    while (menu) {
        cout << "Введите" << endl;
        cout << "1: Добавление информации в таблицу" << endl;
        cout << "2: Удаление информации из таблицы" << endl;
        cout << "3: Редактирование таблицы" << endl;
        cout << "4: Вывод таблицы" << endl;
        cout << "5: Выход" << endl;
        cin >> operation;
        switch (operation) {
            case 1: system("cls"); Add(); break;
            case 2: system("cls"); Delete(); break;
            case 3: system("cls"); Edit(); break;
            case 4: system("cls"); Out(); break;
            case 5: menu = false; break;
            default: system("cls"); cout << "Вы ввели не правильное число." << endl; break;
        }
    }
}

void Out() {
    cout << setw(11) << left << "PersonID" << setw(39) << left << "FIO" << setw(14) << left << "Passport" << endl;
    for (size_t i = 0; i < persons.size(); ++i)
        cout << setw(10) << left << persons[i].personID << setw(40) << left << persons[i].FIO << setw(14) << left << persons[i].passport << endl;
}

void Add() {
    Person person;
    person.personID = persons[persons.size() - 1].personID + 1;
    getchar();
    cout << "Введите ФИО: ";
    getline(cin, person.FIO);
    cout << "Введите паспорт: ";
    getline(cin, person.passport);
    person.FIO.insert(0, " ");
    persons.push_back(person);
    Save();
}

void Save() {
    ofstream f("test.txt");
    for (size_t i = 0; i != persons.size() - 1; ++i)
        f << persons[i].personID << persons[i].FIO << '"' << persons[i].passport << endl;
    f << persons[persons.size() - 1].personID << persons[persons.size() - 1].FIO << '"' << persons[persons.size() - 1].passport;
    f.close();
}

void Delete() {
    Out();
    int operation;
    cout << "Введите ID гражданина которого хотите удалить: ";
    cin >> operation;
    for (size_t i = 0; i != persons.size() - 1; ++i)
        if (persons[i].personID == operation)
            persons.erase(persons.begin() + i);
    if (persons[persons.size() - 1].personID == operation)
        persons.pop_back();
    Save();
}

void Edit() {
    Out();
    int operation;
    cout << "Введите ID гражданина которого хотите редактировать: ";
    cin >> operation;
    for (size_t i = 0; i != persons.size(); ++i)
        if (persons[i].personID == operation) {
            getchar();
            cout << "Введите ФИО: ";
            getline(cin, persons[i].FIO);
            cout << "Введите паспорт: ";
            getline(cin, persons[i].passport);
            persons[i].FIO.insert(0, " ");
        }
    Save();
}
