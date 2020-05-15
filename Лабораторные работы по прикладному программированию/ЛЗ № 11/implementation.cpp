#include "Hotel.h"

vector<Category> categories;
vector<Room> rooms;
vector<Person> persons;
vector<Check_in> check_ins;

///Функция считывающая информацию из файлов при старте программы.
void Start() {
    ifstream f("Person.txt");
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
    ifstream f1("Category.txt");
    Category category;
    if (f1.is_open()) {
        while (!f1.eof()) {
            f1 >> category.categoryID;
            getline(f1, category.category_name);
            categories.push_back(category);
        }
        f1.close();
    }
    ifstream f2("Room.txt");
    Room room;
    if (f2.is_open()) {
        while (!f2.eof()) {
            f2 >> room.roomID >> room.categoryID >> room.number >> room.beds;
            rooms.push_back(room);
        }
        f2.close();
    }
    ifstream f3("Check_in.txt");
    Check_in check_in;
    if (f3.is_open()) {
        while (!f3.eof()) {
            f3 >> check_in.check_inID >> check_in.personID >> check_in.roomID >> check_in.start >> check_in.finish;
            check_ins.push_back(check_in);
        }
        f3.close();
    }
}

///Функция меню контролирует всю работу программы.
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
            case 1: system("cls"); Add(Table_menu()); break;
            case 2: system("cls"); Delete(Table_menu()); break;
            case 3: system("cls"); Edit(Table_menu()); break;
            case 4: system("cls"); Out(Table_menu()); break;
            case 5: menu = false; break;
            default: system("cls"); cout << "Вы ввели не правильное число." << endl; break;
        }
    }
}

///Униврсальная функция для выбора меня над которой нужно провести действие.
int Table_menu() {
    int operation;
    cout << "Введите номер таблицы над которой нужно провести действие: " << endl;
    cout << "1: Категории" << endl;
    cout << "2: Номера" << endl;
    cout << "3: Граждане" << endl;
    cout << "4: Размещение" << endl;
    cout << "5: Выход в главное меню" << endl;
    cin >> operation;
    return operation;
}

///Функция вывода содержимого таблицы в зависимости от выбора.
void Out(int k) {
    system("cls");
    switch(k) {
        case 1: {
            cout << setw(13) << left << "Category ID" << setw(14) << left << "Category name" << endl;
            for (size_t i = 0; i != categories.size(); ++i)
                cout << setw(12) << left << categories[i].categoryID << setw(14) << left << categories[i].category_name << endl;
            cout << endl; break;
        }
        case 2: {
            cout << setw(8) << left << "Room ID" << setw(12) << left << "Category ID" << setw(7) << left << "Number" << setw(5) << left << "Beds" << endl;
            for (size_t i = 0; i != rooms.size(); ++i)
                cout << setw(8) << left << rooms[i].roomID << setw(12) << left << rooms[i].categoryID << setw(7) << left << rooms[i].number << setw(5) << left << rooms[i].beds << endl;
            cout << endl; break;
        }
        case 3: {
            cout << setw(12) << left << "Person ID" << setw(39) << left << "FIO" << setw(14) << left << "Passport" << endl;
            for (size_t i = 0; i != persons.size(); ++i)
                cout << setw(11) << left << persons[i].personID << setw(40) << left << persons[i].FIO << setw(14) << left << persons[i].passport << endl;
            cout << endl; break;
        }
        case 4: {
            cout << setw(12) << left << "Check in ID" << setw(10) << left << "Person ID" << setw(8) << left << "Room ID" << setw(12) << left << "Start" << setw(11) << left << "Finish" << endl;
            for (size_t i = 0; i != check_ins.size(); ++i)
                cout << setw(12) << left << check_ins[i].check_inID << setw(10) << left << check_ins[i].personID << setw(8) << left << check_ins[i].roomID << setw(12) << left << check_ins[i].start << setw(11) << left << check_ins[i].finish << endl;
            cout << endl; break;
        }
        case 5: system("cls"); break;
        default: system("cls"); cout << "Вы ввели не правильное число." << endl; Out(Table_menu()); break;
    }
}

///Функция добавления содержимого в выбранную таблицу.
void Add(int k) {
    switch(k) {
        case 1: {
            Category category;
            category.categoryID = categories[categories.size() - 1].categoryID + 1;
            cout << "Введите название категории: ";
            cin >> category.category_name;
            category.category_name.insert(0, " ");
            categories.push_back(category);
            Save(k);
            system("cls");
            cout << "Категория успешно добавлена" << endl;
            break;
        }
        case 2: {
            Room room;
            room.roomID = rooms[rooms.size() - 1].roomID + 1;
            cout << "Введите ID категории: ";
            cin >> room.categoryID;
            cout << "Введите номер номера: ";
            cin >> room.number;
            cout << "Введите количество спальных мест: ";
            cin >> room.beds;
            rooms.push_back(room);
            Save(k);
            system("cls");
            cout << "Номер успешно добавлен" << endl;
            break;
        }
        case 3: {
            Person person;
            person.personID = persons[persons.size() - 1].personID + 1;
            getchar();
            cout << "Введите ФИО: ";
            getline(cin, person.FIO);
            cout << "Введите паспорт: ";
            getline(cin, person.passport);
            person.FIO.insert(0, " ");
            persons.push_back(person);
            Save(k);
            system("cls");
            cout << "Гражданин успешно добавлен" << endl;
            break;
        }
        case 4: {
            Check_in check_in;
            check_in.check_inID = check_ins[check_ins.size() - 1].check_inID + 1;
            cout << "Введите ID гражданина: ";
            cin >> check_in.personID;
            cout << "Введите ID номера: ";
            cin >> check_in.roomID;
            cout << "Введите дату въезда в формате ДД.ММ.ГГГГ: ";
            cin >> check_in.start;
            cout << "Введите дату выезда в формате ДД.ММ.ГГГГ: ";
            cin >> check_in.finish;
            check_ins.push_back(check_in);
            Save(k);
            system("cls");
            cout << "Заселение успешно добавлено" << endl;
            break;
        }
        case 5: system("cls"); break;
        default: system("cls"); cout << "Вы ввели не правильное число." << endl; Add(Table_menu()); break;
    }
}

///Функция сохранения измененных таблиц.
void Save(int k) {
    switch(k) {
        case 1: {
            ofstream f1("Category.txt");
            for (size_t i = 0; i != categories.size() - 1; ++i)
                f1 << categories[i].categoryID << categories[i].category_name << endl;
            f1 << categories[categories.size() - 1].categoryID << categories[categories.size() - 1].category_name;
            f1.close();
            break;
        }
        case 2: {
            ofstream f2("Room.txt");
            for (size_t i = 0; i != rooms.size() - 1; ++i)
                f2 << rooms[i].roomID << " " << rooms[i].categoryID << " " << rooms[i].number << " " << rooms[i].beds << endl;
            f2 << rooms[rooms.size() - 1].roomID << " " << rooms[rooms.size() - 1].categoryID << " " << rooms[rooms.size() - 1].number << " " << rooms[rooms.size() - 1].beds;
            f2.close();
            break;
        }
        case 3: {
            ofstream f("Person.txt");
            for (size_t i = 0; i != persons.size() - 1; ++i)
                f << persons[i].personID << persons[i].FIO << '"' << persons[i].passport << endl;
            f << persons[persons.size() - 1].personID << persons[persons.size() - 1].FIO << '"' << persons[persons.size() - 1].passport;
            f.close();
            break;
        }
        case 4: {
            ofstream f3("Check_in.txt");
            for (size_t i = 0; i != check_ins.size() - 1; ++i)
                f3 << check_ins[i].check_inID << " " << check_ins[i].personID << " " << check_ins[i].roomID << " " << check_ins[i].start << " " << check_ins[i].finish << endl;
            f3 << check_ins[check_ins.size() - 1].check_inID << " " << check_ins[check_ins.size() - 1].personID << " " << check_ins[check_ins.size() - 1].roomID << " " << check_ins[check_ins.size() - 1].start << " " << check_ins[check_ins.size() - 1].finish;
            f3.close();
            break;
        }
    }
}

///функция удаления выбранной позиции из выбранное таблицы по ID.
void Delete(int k) {
    switch(k) {
        case 1: {
            Out(k);
            int operation;
            cout << "Введите ID категории которую хотите удалить: ";
            cin >> operation;
            for (size_t i = 0; i != categories.size() - 1; ++i)
                if (categories[i].categoryID == operation)
                    categories.erase(categories.begin() + i);
            if (categories[categories.size() - 1].categoryID == operation)
                categories.pop_back();
            Save(k);
            system("cls");
            cout << "Категория успешно удалена" << endl;
            break;
        }
        case 2: {
            Out(k);
            int operation;
            cout << "Введите ID номера которого хотите удалить: ";
            cin >> operation;
            for (size_t i = 0; i != rooms.size() - 1; ++i)
                if (rooms[i].roomID == operation)
                    rooms.erase(rooms.begin() + i);
            if (rooms[rooms.size() - 1].roomID == operation)
                rooms.pop_back();
            Save(k);
            system("cls");
            cout << "Номер успешно удален" << endl;
            break;
        }
        case 3: {
            Out(k);
            int operation;
            cout << "Введите ID гражданина которого хотите удалить: ";
            cin >> operation;
            for (size_t i = 0; i != persons.size() - 1; ++i)
                if (persons[i].personID == operation)
                    persons.erase(persons.begin() + i);
            if (persons[persons.size() - 1].personID == operation)
                persons.pop_back();
            Save(k);
            system("cls");
            cout << "Гражданин успешно удален" << endl;
            break;
        }
        case 4: {
            Out(k);
            int operation;
            cout << "Введите ID заселения которое хотите удалить: ";
            cin >> operation;
            for (size_t i = 0; i != check_ins.size() - 1; ++i)
                if (check_ins[i].check_inID == operation)
                    check_ins.erase(check_ins.begin() + i);
            if (check_ins[check_ins.size() - 1].check_inID == operation)
                check_ins.pop_back();
            Save(k);
            system("cls");
            cout << "Заселение успешно удалено" << endl;
            break;
        }
        case 5: system("cls"); break;
        default: system("cls"); cout << "Вы ввели не правильное число." << endl; Delete(Table_menu()); break;
    }
}

///Функция редактирования выбранной позиции из выбранной таблицы по ID.
void Edit(int k) {
    switch(k) {
        case 1: {
            Out(k);
            int operation;
            cout << "Введите ID категории которую хотите редактировать: ";
            cin >> operation;
            for (size_t i = 0; i != categories.size(); ++i)
                if (categories[i].categoryID == operation) {
                    cout << "Введите название категории: ";
                    cin >> categories[i].category_name;
                    categories[i].category_name.insert(0, " ");
                }
            Save(k);
            system("cls");
            cout << "Информация о категории успешно редактирована" << endl;
            break;
        }
        case 2: {
            Out(k);
            int operation;
            cout << "Введите ID номера которого хотите редактировать: ";
            cin >> operation;
            for (size_t i = 0; i != rooms.size(); ++i)
                if (rooms[i].roomID == operation) {
                    cout << "Введите ID категории: ";
                    cin >> rooms[i].categoryID;
                    cout << "Введите номер номера: ";
                    cin >> rooms[i].number;
                    cout << "Введите количество спальных мест: ";
                    cin >> rooms[i].beds;
                }
            Save(k);
            system("cls");
            cout << "Информация о номере успешно редактирована" << endl;
            break;
        }
        case 3: {
            Out(k);
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
            Save(k);
            system("cls");
            cout << "Информация о гражданине успешно редактирована" << endl;
            break;
        }
        case 4: {
            Out(k);
            int operation;
            cout << "Введите ID заселения которорого хотите редактировать: ";
            cin >> operation;
            for (size_t i = 0; i != check_ins.size(); ++i)
                if (check_ins[i].check_inID == operation) {
                    cout << "Введите ID гражданина: ";
                    cin >> check_ins[i].personID;
                    cout << "Введите ID номера: ";
                    cin >> check_ins[i].roomID;
                    cout << "Введите дату въезда в формате ДД.ММ.ГГГГ: ";
                    cin >> check_ins[i].start;
                    cout << "Введите дату выезда в формате ДД.ММ.ГГГГ: ";
                    cin >> check_ins[i].finish;
                }
            Save(k);
            system("cls");
            cout << "Информация о заселении успешно редактирована" << endl;
            break;
        }
        case 5: system("cls"); break;
        default: system("cls"); cout << "Вы ввели не правильное число." << endl; Edit(Table_menu()); break;
    }
}
