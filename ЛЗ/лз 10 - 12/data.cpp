#include "data.h"
vector<Category> сategories;
vector<Room> rooms;
vector<Person> persons;
vector<LockedRoom> lockedRooms;

//Считывание из файлов 
void Initialization() {

	ifstream f1("Category.txt");
	Category category;

	if (f1.is_open()) {
		while (!f1.eof()) {
			f1 >> category.categoryiD;
			getline(f1, category.category_name);
			сategories.push_back(category);
		}

		f1.close();
	}

	ifstream f2("Room.txt");
	Room room;
	if (f2.is_open()) {
		while (!f2.eof()) {
			f2 >> room.roomiD >> room.categoryiD >> room.num >> room.beds;
			rooms.push_back(room);
		}

		f2.close();
	}

	ifstream f3("Person.txt");
	Person person;
	if (f3.is_open()) {
		while (!f3.eof()) {
			f3 >> person.personiD;
			getline(f3, person.Fio, ':');
			getline(f3, person.passport);
			persons.push_back(person);

		}		
		
		f3.close();
	}
	
	ifstream f4("LockedRoom.txt");
	LockedRoom lockedRoom;
	if (f4.is_open()) {
		while (!f4.eof()) {
			f4 >> lockedRoom.lockedRoomiD >> lockedRoom.personiD >> lockedRoom.roomiD >> lockedRoom.star >> lockedRoom.finis;
			lockedRooms.push_back(lockedRoom);
		}

		f4.close();
	}
}

//запись в файлы
void Save() {

	ofstream f1("Category.txt");
	
	if (f1.is_open()) {
		for (int i = 0; i != сategories.size(); i++) {
			f1 << сategories[i].categoryiD << " " << сategories[i].category_name;
			if (i != сategories.size() - 1)
				f1 << endl;
		}
		f1.close();
	}

	ofstream f2("Room.txt");

	if (f2.is_open()) {
		for (int i = 0; i != rooms.size(); i++) {
			f2 << rooms[i].roomiD << " " << rooms[i].categoryiD << " " << rooms[i].num << " " << rooms[i].beds;
			if (i != rooms.size() - 1)
				f2 << endl;
		}
		f2.close();
	}

	ofstream f3("Person.txt");

	if (f3.is_open()) {
		
		for (int i = 0; i != persons.size(); i++) {
			f3 << persons[i].personiD << " " << persons[i].Fio << ':' << persons[i].passport;
			if (i != persons.size() - 1)
				f3 << endl;
		}
		
		f3.close();
	}
	
	ofstream f4("LockedRoom.txt");

	if (f4.is_open()) {
		for (int i = 0; i != lockedRooms.size(); i++) {
			f4 << lockedRooms[i].lockedRoomiD << " " << lockedRooms[i].personiD << " " << lockedRooms[i].roomiD << " " << lockedRooms[i].star << " " << lockedRooms[i].finis;
			if (i != lockedRooms.size() - 1)
				f4 << endl;
		}
		f4.close();
	}
}

void printDefaultMenu() {
	system("cls");
	cout << " ________________________________________ " << endl;
	cout << "|        Гостевая книга отеля            |" << endl;
	cout << "|________________________________________|" << endl;
	cout << "|                                        |" << endl;
	cout << "|   1: Вывод таблицы                     |" << endl;
	cout << "|   2: Сортировка таблицы                |" << endl;
	cout << "|   3: Редактирование таблицы            |" << endl;
	cout << "|________________________________________|" << endl;
	cout << "|                                        |" << endl;
	cout << "|   0: О программе                       |" << endl;
	cout << "| Esc: Выход                             |" << endl;
	cout << "|________________________________________|" << endl;

}

//Меню программы
void Menu() {
	Initialization();
	int key;
	bool exit = true;
	
	while (exit)
	{
		
		printDefaultMenu();
		switch ((key = _getch()))
		{
		case '1'://1: Вывод таблицы +
			StructMenu(&exit);
			break;
		case '2'://2: Сортировка таблицы ?
			;
			break;
		case '3'://3: Редактирование таблицы
			Edit();
			break;
		case '0'://О программе+
			About(&exit);
			break;
		case 27://выход+
			exit = false;
			break;
		default:
			break;
		}

	}
}

// Редактирование таблицы
void Edit() {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ________________________________________ " << endl;
		cout << "|        Редактировать записи            |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   1: Список номеров                    |" << endl;
		cout << "|   2: Занятые номера                    |" << endl;
		cout << "|   3: Категории номеров                 |" << endl;
		cout << "|   4: Информация о постояльцах          |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   0: Назад                             |" << endl;
		cout << "|                                        |" << endl;
		cout << "|________________________________________|" << endl;

		switch ((key = _getch()))
		{
		case '1'://1: Список номеров 
			editRoom();
			break;
		case '2'://2: Занятые номера 
			editLockedRoom();
			break;
		case '3'://3: Категории номеров
			editCategory();
			break;
		case '4'://4: Информация о постояльцах
			editPerson();
			break;
		}
	}

}

//Просмотр записей
void StructMenu(bool *exit) {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ________________________________________ " << endl;
		cout << "|        Просмотреть записи              |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   1: Список номеров                    |" << endl;
		cout << "|   2: Занятые номера                    |" << endl;
		cout << "|   3: Категории номеров                 |" << endl;
		cout << "|   4: Информация о постояльцах          |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   0: Назад                             |" << endl;
		cout << "| Esc: Выход                             |" << endl;
		cout << "|________________________________________|" << endl;

		switch ((key = _getch()))
		{
		case '1'://1: Список номеров 
			printRoom();
			break;
		case '2'://2: Занятые номера 
			printLockedRoom();
			;
			break;
		case '3'://3: Категории номеров
			printCategory();
			break;
		case '4'://4: Информация о постояльцах
			printPerson();
			break;
		case 27:
			*exit = false;
			key = '0';
			break;
		}
		}

	}

//О программе
void About(bool *exit) {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ________________________________________ " << endl;
		cout << "|        О программе                     |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|     Консольное приложение              |" << endl;
		cout << "|     учета  посетителей гостиницы       |" << endl;
		cout << "|                                        |" << endl;
		cout << "|                                        |" << endl;
		cout << "|     Версия 0.8.6с                      |" << endl;
		cout << "|     Автор             Звонарёв Д.А.    |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   0: Назад                             |" << endl;
		cout << "| Esc: Выход                             |" << endl;
		cout << "|________________________________________|" << endl;
		if ((key = _getch()) == 27) {
			*exit = false;
			break;
		}
	}
	
}

//Список номеров 
void printRoom() {
	int key = 1;
	while (key != '0') {
		system("cls");//Номера (Код	номера, Код категории, номер, мест);
		cout << " ________________________________________ " << endl;
		cout << "|        Список номеров                  |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|  Код   |   Код     |  Номер   | Всего  |" << endl;
		cout << "| номера | категории |          |  мест  |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		for (int i = 0; i != rooms.size(); i++)
			printf("| %4d   | %4d      | %5d    |  %2d    |\n", rooms[i].roomiD, rooms[i].categoryiD, rooms[i].num, rooms[i].beds);
		cout << "|        |           |          |        |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   0: Назад                             |" << endl;
		cout << "|________________________________________|" << endl;
		key = _getch();
	}
}

//Занятые номера
void printLockedRoom(){
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ______________________________________________________________________ " << endl;
		cout << "|                            Занятые номера                            |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		cout << "|    Код     |    Код     |  Код   |     Дата       |       Срок       |" << endl;
		cout << "| размещения | гражданина | номера |    въезда      |    проживания    |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		cout << "|                                                                      |" << endl;
		for (int i = 0; i != lockedRooms.size(); i++)
			printf("|  %5d     | %5d      | %4d   |  %10s    |    %10s    |\n", lockedRooms[i].lockedRoomiD, lockedRooms[i].personiD, lockedRooms[i].roomiD, lockedRooms[i].star.c_str(), lockedRooms[i].finis.c_str());
		cout << "|            |            |        |                |                  |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		cout << "|                                                                      |" << endl;
		cout << "|   0: Назад                                                           |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		key = _getch();
	}
}
//Категории номеров
void printCategory(){
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ___________________________" << endl;
		cout << "|     Категории номеров     |" << endl;
		cout << "|___________________________|" << endl;
		cout << "|   Код     |    Название   |" << endl;
		cout << "| категории |   категории   |" << endl;
		cout << "|___________________________|" << endl;
		cout << "|                           |" << endl;
		for (int i = 0; i != сategories.size(); i++)		     
			printf("| %4d      | %12s  |\n", сategories[i].categoryiD, сategories[i].category_name.c_str());
		cout << "|                           |" << endl;
		cout << "|___________________________|" << endl;
		cout << "|                           |" << endl;
		cout << "|   0: Назад                |" << endl;
		cout << "|___________________________|" << endl;
		key = _getch();
	}
}

//Информация о постояльцах
void printPerson() {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " _______________________________________________________________ " << endl;
		cout << "|                    Информация о постояльцах                   |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|    Код     |              Ф.И.О.              |   Паспорт     |" << endl;
		cout << "| гражданина |            гражданина            |  гражданина   |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|                                                               |" << endl;
		for (int i = 0; i != persons.size(); i++)
			printf("| %4d       | %30s   | %13s |\n", persons[i].personiD,persons[i].Fio.c_str(),persons[i].passport.c_str());
		cout << "|                                                               |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|                                                               |" << endl;
		cout << "|   0: Назад                                                    |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		key = _getch();
	}
}

void editRoom() {//+
	int key = 1;
	while (key != '0') {
		system("cls");//Номера (Код	номера, Код категории, номер, мест);
		cout << " ________________________________________ " << endl;
		cout << "|        Список номеров                  |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|  Код   |   Код     |  Номер   | Всего  |" << endl;
		cout << "| номера | категории |          |  мест  |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		for (int i = 0; i != rooms.size(); i++)
			printf("| %4d   | %4d      | %5d    |  %2d    |\n", rooms[i].roomiD, rooms[i].categoryiD, rooms[i].num, rooms[i].beds);
		cout << "|        |           |          |        |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   a: Добавить         e: Редактировать |" << endl;
		cout << "|   d: Удалить                           |" << endl;
		cout << "|   0: Назад                             |" << endl;
		cout << "|________________________________________|" << endl;
		key = _getch();
		if (key == 'a') {
			cout << "|   Введите новую запись   :             |" << endl;
			cout << "|________________________________________|" << endl;
			Room room;
			cin >> room.roomiD >> room.categoryiD >> room.num >> room.beds;//
			rooms.push_back(room);
		}
		if (key == 'e') {
			cout << "|   Введите код номера:                  |" << endl;
			cout << "|________________________________________|" << endl;
			int searchiD;
			cout << ": ";
			searchiD = getInt();
			for (int i = 0; i != rooms.size(); i++) {
				if (rooms[i].roomiD == searchiD) {
					cout << "|________________________________________|" << endl;
					printf("| %4d   | %4d      | %5d    |  %2d    |\n", rooms[i].roomiD, rooms[i].categoryiD, rooms[i].num, rooms[i].beds);
					/*
					cout << "|________________________________________|" << endl;
					cout << "|   Введите код номера:              |" << endl;
					cout << "|________________________________________|" << endl;
					cout << ": ";
					int newRoomiD;
					newRoomiD = getInt();
					rooms[i].roomiD = newRoomiD;
					*/
					cout << "|________________________________________|" << endl;
					cout << "|   Введите  код категории:              |" << endl;
					cout << "|________________________________________|" << endl;
					cout << ": ";
					int newcategoryiD;
					newcategoryiD = getInt();
					rooms[i].categoryiD = newcategoryiD;
					cout << "|________________________________________|" << endl;
					cout << "|   Введите  номер:                      |" << endl;
					cout << "|________________________________________|" << endl;
					cout << ": ";
					int newnum;
					newnum = getInt();
					rooms[i].num = newnum;
					cout << "|________________________________________|" << endl;
					cout << "|   Введите количество мест:             |" << endl;
					cout << "|________________________________________|" << endl;
					cout << ": ";
					int newbeds;
					newbeds = getInt();
					rooms[i].beds = newbeds;
				}
			}
		}
		if (key == 'd') {
			cout << "|   Введите код номера удаляемой записи: |" << endl;
			cout << "|________________________________________|" << endl;
			int searchiD;
			cout << ": ";
			searchiD = getInt();
			for (int i = 0; i != rooms.size(); i++) {
				if (rooms[i].roomiD == searchiD) {
					rooms.erase(rooms.begin() + i);
					break;
				}
			}
		}
	}
	Save();
}

//Занятые номера
void editLockedRoom() {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ______________________________________________________________________ " << endl;
		cout << "|                            Занятые номера                            |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		cout << "|    Код     |    Код     |  Код   |     Дата       |       Срок       |" << endl;
		cout << "| размещения | гражданина | номера |    въезда      |    проживания    |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		cout << "|                                                                      |" << endl;
		for (int i = 0; i != lockedRooms.size(); i++)
			printf("|  %5d     | %5d      | %4d   |  %10s    |    %10s    |\n", lockedRooms[i].lockedRoomiD, lockedRooms[i].personiD, lockedRooms[i].roomiD, lockedRooms[i].star.c_str(), lockedRooms[i].finis.c_str());
		cout << "|            |            |        |                |                  |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		cout << "|                                                                      |" << endl;
		cout << "|   d: Удалить           e: Редактировать               a: Добавить    |" << endl;
		cout << "|   0: Назад                                                           |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		key = _getch();
		if (key == 'e') {
			cout << "|   Введите код размещения :                                           |" << endl;
			cout << "|______________________________________________________________________|" << endl;
			int searchiD;
			cout << ": ";
			searchiD = getInt();
			for (int i = 0; i != lockedRooms.size(); i++) {
				if (lockedRooms[i].lockedRoomiD == searchiD) {
					cout << " ______________________________________________________________________ " << endl;
					printf("|  %5d     | %5d      | %4d   |  %10s    |    %10s    |\n", lockedRooms[i].lockedRoomiD, lockedRooms[i].personiD, lockedRooms[i].roomiD, lockedRooms[i].star.c_str(), lockedRooms[i].finis.c_str());
					/*
					cout << "|______________________________________________________________________|" << endl;
					cout << "|   Введите новый код размещения:                                      |" << endl;
					cout << "|______________________________________________________________________|" << endl;
					cout << ": ";
					int newlockedRoomiD;
					cin >> newlockedRoomiD;
					lockedRooms[i].lockedRoomiD = newlockedRoomiD;
					*/
					cout << "|______________________________________________________________________|" << endl;
					cout << "|   Введите новый код гражданина:                                      |" << endl;
					cout << "|______________________________________________________________________|" << endl;
					cout << ": ";
					int newpersoniD;
					cin >> newpersoniD;

					lockedRooms[i].personiD = newpersoniD;
					cout << "|______________________________________________________________________|" << endl;
					cout << "|   Введите новый код номера:                                          |" << endl;
					cout << "|______________________________________________________________________|" << endl;
					cout << ": ";
					int newroomiD;
					cin >> newroomiD;
					lockedRooms[i].roomiD = newroomiD;
					cout << "|______________________________________________________________________|" << endl;
					cout << "|   Введите новую дату въезда:                                         |" << endl;
					cout << "|______________________________________________________________________|" << endl;
					cout << ": ";
					string  newstart;
					cin >> newstart;
					lockedRooms[i].star = newstart;
					cout << "|   Введите новый срок проживания:                                     |" << endl;
					cout << "|______________________________________________________________________|" << endl;
					cout << ": ";
					string newfinish;
					cin >> newfinish;
					lockedRooms[i].finis = newfinish;
				}
			}
			
		}
		if (key == 'a') {
			cout << "|   Введите новую запись   :                                           |" << endl;
			cout << "|______________________________________________________________________|" << endl;
			Room room;
			cin >> room.roomiD >> room.categoryiD >> room.num >> room.beds;// ? тоже проверку на числа?
			rooms.push_back(room);
		}
		if (key == 'd') {
			cout << "|   Введите код размещения удаляемой записи :                          |" << endl;
			cout << "|______________________________________________________________________|" << endl;
			int searchiD;
			cout << ": ";
			searchiD = getInt();
			for (int i = 0; i != lockedRooms.size(); i++) {
				if (lockedRooms[i].lockedRoomiD == searchiD) {
					lockedRooms.erase(lockedRooms.begin() + i);
					break;
				}
			}
		}
	}
	Save();
}

//Категории номеров
void editCategory() {
	int key = 1;
	 while (key != '0') {
		system("cls");
		cout << " ___________________________" << endl;
		cout << "|     Категории номеров     |" << endl;
		cout << "|___________________________|" << endl;
		cout << "|   Код     |    Название   |" << endl;
		cout << "| категории |   категории   |" << endl;
		cout << "|___________________________|" << endl;
		cout << "|                           |" << endl;
		for (int i = 0; i != сategories.size(); i++)
			printf("| %4d      | %12s  |\n", сategories[i].categoryiD, сategories[i].category_name.c_str());
		cout << "|                           |" << endl;
		cout << "|___________________________|" << endl;
		cout << "|                           |" << endl;
		cout << "|   e: Редактировать        |" << endl;
		cout << "|   a: Добавить             |" << endl;
		cout << "|   d: Удалить              |" << endl;
		cout << "|   0: Назад                |" << endl;
		cout << "|___________________________|" << endl;
		key = _getch();
		if (key == 'e') {
			cout << "|   Введите код категории  :|" << endl;
			cout << "|___________________________|" << endl;
			int searchiD;
			cout << ": ";
			searchiD = getInt();
			for (int i = 0; i != сategories.size(); i++) {
				if (сategories[i].categoryiD == searchiD) {
					printf("| %4d      | %12s  |\n", сategories[i].categoryiD, сategories[i].category_name.c_str());

					cout << "|___________________________|" << endl;
					cout << "|      Введите новое        |" << endl;
					cout << "|    название категории:    |" << endl;
					cout << "|___________________________|" << endl;
					cout << ": ";
					string newcategory_name;
					cin >> newcategory_name;
					сategories[i].category_name = newcategory_name;
				}
			}

		}
		if (key == 'a') {
			cout << "|   Введите новую запись:   |" << endl;
			cout << "|___________________________|" << endl;
			Category category;
			cin >> category.categoryiD >> category.category_name;
			сategories.push_back(category);
		}
		if (key == 'd') {
			cout << "|   Введите код категории   |" << endl;
			cout << "|     удаляемой записи:     |" << endl;
			cout << "|___________________________|" << endl;
			int searchiD;
			cout << ": ";
			searchiD = getInt();
			for (int i = 0; i != сategories.size(); i++) {
				if (сategories[i].categoryiD == searchiD) {
					сategories.erase(сategories.begin() + i);
					break;
				}
			}
		}
	}
	Save();
}

//Информация о постояльцах
void editPerson() {
	int key = 1;

	while (key != '0') {
		system("cls");
		cout << " _______________________________________________________________ " << endl;
		cout << "|                    Информация о постояльцах                   |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|    Код     |              Ф.И.О.              |   Паспорт     |" << endl;
		cout << "| гражданина |            гражданина            |  гражданина   |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|                                                               |" << endl;
		for (int i = 0; i != persons.size(); i++)
			printf("| %4d       | %30s   | %13s |\n", persons[i].personiD, persons[i].Fio.c_str(), persons[i].passport.c_str());
		cout << "|                                                               |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|                                                               |" << endl;
		cout << "|   d: Удалить          e: Редактировать          a: Добавить   |" << endl;
		cout << "|   0: Назад                                                    |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		key = _getch();
		if (key == 'e') {
			cout << "|   Введите код гражданина :                                    |" << endl;
			cout << "|_______________________________________________________________|" << endl;
			int searchiD;
			cout << ": ";
			searchiD = getInt();
			for (int i = 0; i != persons.size(); i++) {
				if (persons[i].personiD == searchiD) {
					cout << " _______________________________________________________________ " << endl;
					printf("| %4d       | %30s   | %12s |\n", persons[i].personiD, persons[i].Fio.c_str(), persons[i].passport.c_str());
					cout << "|_______________________________________________________________|" << endl;
					cout << "|   Введите новое Ф.И.О гражданина:                             |" << endl;
					cout << "|_______________________________________________________________|" << endl;
					cout << ": ";
					string newfio;
					cin.clear();
					cin.ignore(10000, '\n');
					getline(cin, newfio);
					persons[i].Fio = newfio;
					cout << "|_______________________________________________________________|" << endl;
					cout << "|   Введите паспорт гражданина:                                 |" << endl;
					cout << "|_______________________________________________________________|" << endl;
					cout << ": ";
					string newpassport;					
					getline(cin, newpassport);
					persons[i].passport = newpassport.insert(0, " ");
				}
			}
		}
		if (key == 'a') {
			Person person;
			cout << "|   Введите код гражданина :                                    |" << endl;
			cout << "|_______________________________________________________________|" << endl;
			cout << ": ";
			person.personiD = getInt();
			cout << " _______________________________________________________________ " << endl;
			cout << "|   Введите новое Ф.И.О гражданина:                             |" << endl;
			cout << "|_______________________________________________________________|" << endl;
			cout << ": ";
			cin.clear();
			cin.ignore(10000, '\n');
			getline(cin, person.Fio);
			cout << " _______________________________________________________________ " << endl;
			cout << "|   Введите паспорт гражданина:                                 |" << endl;
			cout << "|_______________________________________________________________|" << endl;
			cout << ": ";
			string passport;
			getline(cin, passport);
			person.passport = passport.insert(0, " ");//fgets(nazv_sh, sizeof(nazv_sh), stdin); nazv_sh[strlen[nazv_sh] - 1] = 0;
			persons.push_back(person);
		}
		if (key == 'd') {
			cout << "|   Введите код гражданина                                      |" << endl;
			cout << "|     удаляемой записи:                                         |" << endl;
			cout << "|_______________________________________________________________|" << endl;
			int searchiD;
			cout << ": ";
			searchiD = getInt();
			for (int i = 0; i != persons.size(); i++) {
				if (persons[i].personiD == searchiD) {
					persons.erase(persons.begin() + i);
					break;
				}
			}
		}
	}
	Save();
}
//защита от дурака
int getInt() {//проверка на корректный ввод чисел
	int value;
	while (true) {
		cin >> value;
		if (cin.fail()) // если предыдущее извлечение было неудачным,
		{
			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cout << "Введите целочисленное число повторно : ";
			cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
		}
		else
			return value;
	}
}
