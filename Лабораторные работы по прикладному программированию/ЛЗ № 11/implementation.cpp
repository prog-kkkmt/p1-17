#include "Hotel.h"

vector<Category> categories;
vector<Room> rooms;
vector<Person> persons;
vector<Check_in> check_ins;

///Ôóíêöèÿ ñ÷èòûâàþùàÿ èíôîðìàöèþ èç ôàéëîâ ïðè ñòàðòå ïðîãðàììû.
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

///Ôóíêöèÿ ìåíþ êîíòðîëèðóåò âñþ ðàáîòó ïðîãðàììû.
void Menu() {
    bool menu = true;
    int operation;
    while (menu) {
        cout << "Введите" << endl;
        cout << "1: Добавление информации в таблицу" << endl;
        cout << "2: Удаление информации из таблицы" << endl;
        cout << "3: Редактирование таблицы" << endl;
        cout << "4: Вывод таблицы" << endl;
        cout << "5: О программе" << endl;
        cout << "6: Выход" << endl;
        cin >> operation;
        switch (operation) {
            case 1: system("cls"); Add(Table_menu()); break;
            case 2: system("cls"); Delete(Table_menu()); break;
            case 3: system("cls"); Edit(Table_menu()); break;
            case 4: system("cls"); Out(Table_menu()); break;
            case 5: system("cls"); About(); break;
            case 6: menu = false; break;
            default: system("cls"); cout << "Вы ввели не правильное число." << endl; break;
        }
    }
}

///Óíèâðñàëüíàÿ ôóíêöèÿ äëÿ âûáîðà ìåíÿ íàä êîòîðîé íóæíî ïðîâåñòè äåéñòâèå.
int Table_menu() {
    int operation;
    cout << "Ââåäèòå íîìåð òàáëèöû íàä êîòîðîé íóæíî ïðîâåñòè äåéñòâèå: " << endl;
    cout << "1: Êàòåãîðèè" << endl;
    cout << "2: Íîìåðà" << endl;
    cout << "3: Ãðàæäàíå" << endl;
    cout << "4: Ðàçìåùåíèå" << endl;
    cout << "5: Âûõîä â ãëàâíîå ìåíþ" << endl;
    cin >> operation;
    return operation;
}

///Ôóíêöèÿ âûâîäà ñîäåðæèìîãî òàáëèöû â çàâèñèìîñòè îò âûáîðà.
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
        default: system("cls"); cout << "Âû ââåëè íå ïðàâèëüíîå ÷èñëî." << endl; Out(Table_menu()); break;
    }
}

///Ôóíêöèÿ äîáàâëåíèÿ ñîäåðæèìîãî â âûáðàííóþ òàáëèöó.
void Add(int k) {
    switch(k) {
        case 1: {
            Category category;
            category.categoryID = categories[categories.size() - 1].categoryID + 1;
            cout << "Ââåäèòå íàçâàíèå êàòåãîðèè: ";
            cin >> category.category_name;
            category.category_name.insert(0, " ");
            categories.push_back(category);
            Save(k);
            system("cls");
            cout << "Êàòåãîðèÿ óñïåøíî äîáàâëåíà" << endl;
            break;
        }
        case 2: {
            Room room;
            room.roomID = rooms[rooms.size() - 1].roomID + 1;
            cout << "Ââåäèòå ID êàòåãîðèè: ";
            cin >> room.categoryID;
            cout << "Ââåäèòå íîìåð íîìåðà: ";
            cin >> room.number;
            cout << "Ââåäèòå êîëè÷åñòâî ñïàëüíûõ ìåñò: ";
            cin >> room.beds;
            rooms.push_back(room);
            Save(k);
            system("cls");
            cout << "Íîìåð óñïåøíî äîáàâëåí" << endl;
            break;
        }
        case 3: {
            Person person;
            person.personID = persons[persons.size() - 1].personID + 1;
            getchar();
            cout << "Ââåäèòå ÔÈÎ: ";
            getline(cin, person.FIO);
            cout << "Ââåäèòå ïàñïîðò: ";
            getline(cin, person.passport);
            person.FIO.insert(0, " ");
            persons.push_back(person);
            Save(k);
            system("cls");
            cout << "Ãðàæäàíèí óñïåøíî äîáàâëåí" << endl;
            break;
        }
        case 4: {
            Check_in check_in;
            check_in.check_inID = check_ins[check_ins.size() - 1].check_inID + 1;
            cout << "Ââåäèòå ID ãðàæäàíèíà: ";
            cin >> check_in.personID;
            cout << "Ââåäèòå ID íîìåðà: ";
            cin >> check_in.roomID;
            cout << "Ââåäèòå äàòó âúåçäà â ôîðìàòå ÄÄ.ÌÌ.ÃÃÃÃ: ";
            cin >> check_in.start;
            cout << "Ââåäèòå äàòó âûåçäà â ôîðìàòå ÄÄ.ÌÌ.ÃÃÃÃ: ";
            cin >> check_in.finish;
            check_ins.push_back(check_in);
            Save(k);
            system("cls");
            cout << "Çàñåëåíèå óñïåøíî äîáàâëåíî" << endl;
            break;
        }
        case 5: system("cls"); break;
        default: system("cls"); cout << "Âû ââåëè íå ïðàâèëüíîå ÷èñëî." << endl; Add(Table_menu()); break;
    }
}

///Ôóíêöèÿ ñîõðàíåíèÿ èçìåíåííûõ òàáëèö.
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

///ôóíêöèÿ óäàëåíèÿ âûáðàííîé ïîçèöèè èç âûáðàííîå òàáëèöû ïî ID.
void Delete(int k) {
    switch(k) {
        case 1: {
            Out(k);
            int operation;
            cout << "Ââåäèòå ID êàòåãîðèè êîòîðóþ õîòèòå óäàëèòü: ";
            cin >> operation;
            for (size_t i = 0; i != categories.size() - 1; ++i)
                if (categories[i].categoryID == operation)
                    categories.erase(categories.begin() + i);
            if (categories[categories.size() - 1].categoryID == operation)
                categories.pop_back();
            Save(k);
            system("cls");
            cout << "Êàòåãîðèÿ óñïåøíî óäàëåíà" << endl;
            break;
        }
        case 2: {
            Out(k);
            int operation;
            cout << "Ââåäèòå ID íîìåðà êîòîðîãî õîòèòå óäàëèòü: ";
            cin >> operation;
            for (size_t i = 0; i != rooms.size() - 1; ++i)
                if (rooms[i].roomID == operation)
                    rooms.erase(rooms.begin() + i);
            if (rooms[rooms.size() - 1].roomID == operation)
                rooms.pop_back();
            Save(k);
            system("cls");
            cout << "Íîìåð óñïåøíî óäàëåí" << endl;
            break;
        }
        case 3: {
            Out(k);
            int operation;
            cout << "Ââåäèòå ID ãðàæäàíèíà êîòîðîãî õîòèòå óäàëèòü: ";
            cin >> operation;
            for (size_t i = 0; i != persons.size() - 1; ++i)
                if (persons[i].personID == operation)
                    persons.erase(persons.begin() + i);
            if (persons[persons.size() - 1].personID == operation)
                persons.pop_back();
            Save(k);
            system("cls");
            cout << "Ãðàæäàíèí óñïåøíî óäàëåí" << endl;
            break;
        }
        case 4: {
            Out(k);
            int operation;
            cout << "Ââåäèòå ID çàñåëåíèÿ êîòîðîå õîòèòå óäàëèòü: ";
            cin >> operation;
            for (size_t i = 0; i != check_ins.size() - 1; ++i)
                if (check_ins[i].check_inID == operation)
                    check_ins.erase(check_ins.begin() + i);
            if (check_ins[check_ins.size() - 1].check_inID == operation)
                check_ins.pop_back();
            Save(k);
            system("cls");
            cout << "Çàñåëåíèå óñïåøíî óäàëåíî" << endl;
            break;
        }
        case 5: system("cls"); break;
        default: system("cls"); cout << "Âû ââåëè íå ïðàâèëüíîå ÷èñëî." << endl; Delete(Table_menu()); break;
    }
}

///Ôóíêöèÿ ðåäàêòèðîâàíèÿ âûáðàííîé ïîçèöèè èç âûáðàííîé òàáëèöû ïî ID.
void Edit(int k) {
    switch(k) {
        case 1: {
            Out(k);
            int operation;
            cout << "Ââåäèòå ID êàòåãîðèè êîòîðóþ õîòèòå ðåäàêòèðîâàòü: ";
            cin >> operation;
            for (size_t i = 0; i != categories.size(); ++i)
                if (categories[i].categoryID == operation) {
                    cout << "Ââåäèòå íàçâàíèå êàòåãîðèè: ";
                    cin >> categories[i].category_name;
                    categories[i].category_name.insert(0, " ");
                }
            Save(k);
            system("cls");
            cout << "Èíôîðìàöèÿ î êàòåãîðèè óñïåøíî ðåäàêòèðîâàíà" << endl;
            break;
        }
        case 2: {
            Out(k);
            int operation;
            cout << "Ââåäèòå ID íîìåðà êîòîðîãî õîòèòå ðåäàêòèðîâàòü: ";
            cin >> operation;
            for (size_t i = 0; i != rooms.size(); ++i)
                if (rooms[i].roomID == operation) {
                    cout << "Ââåäèòå ID êàòåãîðèè: ";
                    cin >> rooms[i].categoryID;
                    cout << "Ââåäèòå íîìåð íîìåðà: ";
                    cin >> rooms[i].number;
                    cout << "Ââåäèòå êîëè÷åñòâî ñïàëüíûõ ìåñò: ";
                    cin >> rooms[i].beds;
                }
            Save(k);
            system("cls");
            cout << "Èíôîðìàöèÿ î íîìåðå óñïåøíî ðåäàêòèðîâàíà" << endl;
            break;
        }
        case 3: {
            Out(k);
            int operation;
            cout << "Ââåäèòå ID ãðàæäàíèíà êîòîðîãî õîòèòå ðåäàêòèðîâàòü: ";
            cin >> operation;
            for (size_t i = 0; i != persons.size(); ++i)
                if (persons[i].personID == operation) {
                    getchar();
                    cout << "Ââåäèòå ÔÈÎ: ";
                    getline(cin, persons[i].FIO);
                    cout << "Ââåäèòå ïàñïîðò: ";
                    getline(cin, persons[i].passport);
                    persons[i].FIO.insert(0, " ");
                }
            Save(k);
            system("cls");
            cout << "Èíôîðìàöèÿ î ãðàæäàíèíå óñïåøíî ðåäàêòèðîâàíà" << endl;
            break;
        }
        case 4: {
            Out(k);
            int operation;
            cout << "Ââåäèòå ID çàñåëåíèÿ êîòîðîðîãî õîòèòå ðåäàêòèðîâàòü: ";
            cin >> operation;
            for (size_t i = 0; i != check_ins.size(); ++i)
                if (check_ins[i].check_inID == operation) {
                    cout << "Ââåäèòå ID ãðàæäàíèíà: ";
                    cin >> check_ins[i].personID;
                    cout << "Ââåäèòå ID íîìåðà: ";
                    cin >> check_ins[i].roomID;
                    cout << "Ââåäèòå äàòó âúåçäà â ôîðìàòå ÄÄ.ÌÌ.ÃÃÃÃ: ";
                    cin >> check_ins[i].start;
                    cout << "Ââåäèòå äàòó âûåçäà â ôîðìàòå ÄÄ.ÌÌ.ÃÃÃÃ: ";
                    cin >> check_ins[i].finish;
                }
            Save(k);
            system("cls");
            cout << "Èíôîðìàöèÿ î çàñåëåíèè óñïåøíî ðåäàêòèðîâàíà" << endl;
            break;
        }
        case 5: system("cls"); break;
        default: system("cls"); cout << "Âû ââåëè íå ïðàâèëüíîå ÷èñëî." << endl; Edit(Table_menu()); break;
    }
}

void About() {
    cout << "Программа позволяет производить действия над 4 таблицами: " << endl;
    cout << "1: Категории номеров\n" << "2: Номера\n" << "3: Граждане\n" << "4: Список заселения\n" << endl;
    cout << "Made by Yushakov N. R.\n" <<endl;
}
