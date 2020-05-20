#include "data.h"
vector<Category> categories;
vector<Room> rooms;
vector<Person> persons;
vector<LockedRoom> lockedRooms;

//Считывание из файлов 
void Initialization() {
	string poof;

	ifstream f1("Category.txt");
	Category category;
	if (f1.is_open()) {
		while (!f1.eof()) {
			f1 >> category.categoryiD;
			getline(f1, poof, ' ');
			getline(f1, category.category_name);
			categories.push_back(category);
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
			getline(f3, poof, ' ');
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
			f4 >> lockedRoom.lockedRoomiD >> lockedRoom.personiD >> lockedRoom.roomiD;
			getline(f4, poof, ' '); 
			getline(f4, lockedRoom.star,' ' );
			getline(f4, lockedRoom.finis);
			lockedRooms.push_back(lockedRoom);
		}

		f4.close();
	}
}

//запись в файлы	
void Save() {

	ofstream f1("Category.txt");
	
	if (f1.is_open()) {
		for (int i = 0; i != categories.size(); i++) {
			f1 << categories[i].categoryiD << " " << categories[i].category_name;
			if (i != categories.size() - 1)
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
		case '1'://1: Вывод таблицы 
			StructMenu(&exit);
			break;
		case '2'://2: Сортировка таблицы
			SortMenu(&exit);
			break;
		case '3'://3: Редактирование таблицы
			EditMenu(&exit);
			break;
		case '0'://О программе+
			About(&exit);
			break;
		case 27:// Выход
			exit = false;
			break;
		default:
			break;
		}

	}
	Save();
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

void SortMenu(bool *exit) {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ________________________________________ " << endl;
		cout << "|        Сортировать записи              |" << endl;
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
		case '1'://1:  Список номеров 
			sortRoom();
			break;
		case '2'://2: Занятые номера 
			sortLockedRoom();
			break;
		case '3'://3: Категории номеров
			sortCategory();
			break;
		case '4'://4: Информация о постояльцах
			sortPerson();
			break;
		case 27:
			*exit = false;
			key = '0';
			break;
		}
	}
}

// Редактирование таблицы
void EditMenu(bool *exit) {
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
		cout << "| Esc: Выход                             |" << endl;
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
		cout << "|     Версия 1.0.3с                      |" << endl;
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
		system("cls");
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
		cout << " ____________________________" << endl;
		cout << "|     Категории номеров      |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|   Код     |    Название    |" << endl;
		cout << "| категории |   категории    |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|                            |" << endl;
		for (int i = 0; i != categories.size(); i++)		     
			printf("| %4d      | %14s |\n", categories[i].categoryiD, categories[i].category_name.c_str());
		cout << "|                            |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|                            |" << endl;
		cout << "|   0: Назад                 |" << endl;
		cout << "|____________________________|" << endl;
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

//редактировать список номеров
void editRoom() {
	int key = 1;
	while (key != '0') {
		system("cls");
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
			cout << "|________________________________________|" << endl;
			cout << "|   Добавление новой записи              |" << endl;
			cout << "|________________________________________|" << endl;
			cout << "|   Введите  код категории:              |" << endl;
			cout << "|________________________________________|" << endl;
			cout << ": ";
			Room room;
			int newcategoryiD;
			newcategoryiD = getInt();
			room.categoryiD = newcategoryiD;
			cout << "|________________________________________|" << endl;
			cout << "|   Введите  номер:                      |" << endl;
			cout << "|________________________________________|" << endl;
			cout << ": ";
			int newnum;
			newnum = getInt();
			room.num = newnum;
			cout << "|________________________________________|" << endl;
			cout << "|   Введите количество мест:             |" << endl;
			cout << "|________________________________________|" << endl;
			cout << ": ";
			int newbeds;
			newbeds = getInt();
			room.beds = newbeds;
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
					cout << "|   Введите код номера:                  |" << endl;
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
			cout << "|   Введите код размещения:                                            |" << endl;
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
					cout << "|    Введите новый код размещения:                                     |" << endl;
					cout << "|______________________________________________________________________|" << endl;
					cout << ": ";
					int newlockedRoomiD;
					newlockedRoomiD = getInt();
					lockedRooms[i].lockedRoomiD = newlockedRoomiD;
					*/
					cout << "|______________________________________________________________________|" << endl;
					cout << "|   Введите новый код гражданина:                                      |" << endl;
					cout << "|______________________________________________________________________|" << endl;
					cout << ": ";
					int newpersoniD;
					newpersoniD = getInt();
					lockedRooms[i].personiD = newpersoniD;
					cout << "|______________________________________________________________________|" << endl;
					cout << "|   Введите новый код номера:                                          |" << endl;
					cout << "|______________________________________________________________________|" << endl;
					cout << ": ";
					int newroomiD;
					newroomiD = getInt();
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
			cout << "|    Введите новую запись:                                             |" << endl;
			cout << "|______________________________________________________________________|" << endl;
			LockedRoom lockedRoom; 
			lockedRoom.personiD = getInt();
			lockedRoom.roomiD = getInt();
			cin >> lockedRoom.star >> lockedRoom.finis;
			lockedRooms.push_back(lockedRoom);
		}
		if (key == 'd') {
			cout << "|   Введите код размещения удаляемой записи:                           |" << endl;
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
}

//Категории номеров
void editCategory() {
	int key = 1;
	 while (key != '0') {
		system("cls");
		cout << " ____________________________" << endl;
		cout << "|     Категории номеров      |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|   Код     |    Название    |" << endl;
		cout << "| категории |   категории    |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|                            |" << endl;
		for (int i = 0; i != categories.size(); i++)
			printf("| %4d      | %14s |\n", categories[i].categoryiD, categories[i].category_name.c_str());
		cout << "|                            |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|                            |" << endl;
		cout << "|   e: Редактировать         |" << endl;
		cout << "|   a: Добавить              |" << endl;
		cout << "|   d: Удалить               |" << endl;
		cout << "|   0: Назад                 |" << endl;
		cout << "|____________________________|" << endl;
		key = _getch();
		if (key == 'e') {
			cout << "|   Введите код категории:   |" << endl;
			cout << "|____________________________|" << endl;
			int searchiD;
			cout << ": ";
			searchiD = getInt();
			for (int i = 0; i != categories.size(); i++) {
				if (categories[i].categoryiD == searchiD) {
					printf("| %4d      | %14s |\n", categories[i].categoryiD, categories[i].category_name.c_str());

					cout << "|____________________________|" << endl;
					cout << "|      Введите новое         |" << endl;
					cout << "|    название категории:     |" << endl;
					cout << "|____________________________|" << endl;
					cout << ": ";
					string newcategory_name;
					cin >> newcategory_name;
					categories[i].category_name = newcategory_name;
				}
			}

		}
		if (key == 'a') {
			cout << "|   Введите новую запись:    |" << endl;
			cout << "|____________________________|" << endl;
			Category category;
			category.categoryiD = getInt();
			cin >> category.category_name;
			categories.push_back(category);
		}
		if (key == 'd') {
			cout << "|   Введите код категории    |" << endl;
			cout << "|     удаляемой записи:      |" << endl;
			cout << "|____________________________|" << endl;
			int searchiD;
			cout << ": ";
			searchiD = getInt();
			for (int i = 0; i != categories.size(); i++) {
				if (categories[i].categoryiD == searchiD) {
					categories.erase(categories.begin() + i);
					break;
				}
			}
		}
	}
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
			cout << "|   Введите код гражданина:                                     |" << endl;
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
			cout << "|   Введите код гражданина:                                     |" << endl;
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
}

//сортировка списка номеров
void sortRoom() {
	int key = 1;
	bool down = true; 
	while (key != '0') {
		system("cls"); 
		cout << " ________________________________________ " << endl;
		cout << "|        Сортировка списка номеров       |" << endl;
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
		cout << "|   Сортировать по:                      |" << endl;
		cout << "|   1: По коду номера                    |" << endl;
		cout << "|   2: По коду категории                 |" << endl;
		cout << "|   3: По номеру                         |" << endl;
		cout << "|   4: По количеству мест                |" << endl;
		cout << "|   0: Назад                             |" << endl;
		cout << "|________________________________________|" << endl;
		key = _getch();
		switch (key) {
		case '1':
			if (down)
				sort(rooms.begin(), rooms.end(), [](const Room &p1, const Room &p2)
			{
				return p1.roomiD > p2.roomiD;
			});

			else
				sort(rooms.begin(), rooms.end(), [](const Room &p1, const Room &p2)
			{
				return p1.roomiD < p2.roomiD;
			});
			down = !down;
			break;
		case '2':
			if (down)
				sort(rooms.begin(), rooms.end(), [](const Room &p1, const Room &p2)
			{
				return p1.categoryiD > p2.categoryiD;
			});

			else
				sort(rooms.begin(), rooms.end(), [](const Room &p1, const Room &p2)
			{
				return p1.categoryiD < p2.categoryiD;
			});
			down = !down;
			break;
		case '3':
			if (down)
				sort(rooms.begin(), rooms.end(), [](const Room &p1, const Room &p2)
			{
				return p1.num > p2.num;
			});

			else
				sort(rooms.begin(), rooms.end(), [](const Room &p1, const Room &p2)
			{
				return p1.num < p2.num;
			});
			down = !down;
			break;
		case '4':
			if (down)
				sort(rooms.begin(), rooms.end(), [](const Room &p1, const Room &p2)
			{
				return p1.beds > p2.beds;
			});

			else
				sort(rooms.begin(), rooms.end(), [](const Room &p1, const Room &p2)
			{
				return p1.beds < p2.beds;
			});
			down = !down;
			break;
		}
	}
}

//сортировка списка занятых номеров
void sortLockedRoom(){
	int key = 1;
	bool down = true;//сортировку сверху-вниз,иначе снизу-вверх
	while (key != '0') {
		system("cls");	
		cout << " ______________________________________________________________________ " << endl;
		cout << "|                    Сортировка списка занятых номеров                 |" << endl;
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
		cout << "|   Сортировать по:                                                    |" << endl;
		cout << "|   1: Коду размещения                                                 |" << endl;
		cout << "|   2: Коду гражданина                                                 |" << endl;
		cout << "|   3: Коду номера                                                     |" << endl;
		cout << "|   4: Дате въезда                                                     |" << endl;
		cout << "|   5: Сроку проживания                                                |" << endl;
		cout << "|   0: Назад                                                           |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		key = _getch();
		switch (key) {
		case '1':
			if (down)
				sort(lockedRooms.begin(), lockedRooms.end(), [](const LockedRoom &p1, const LockedRoom &p2)
			{
				return p1.lockedRoomiD > p2.lockedRoomiD;
			});

			else
				sort(lockedRooms.begin(), lockedRooms.end(), [](const LockedRoom &p1, const LockedRoom &p2)
			{
				return p1.lockedRoomiD < p2.lockedRoomiD;
			});
			down = !down;
			break;
		case '2':
			if (down)
				sort(lockedRooms.begin(), lockedRooms.end(), [](const LockedRoom &p1, const LockedRoom &p2)
			{
				return p1.personiD > p2.personiD;
			});

			else
				sort(lockedRooms.begin(), lockedRooms.end(), [](const LockedRoom &p1, const LockedRoom &p2)
			{
				return p1.personiD < p2.personiD;
			});
			down = !down;
			break;
		case '3':
			if (down)
				sort(lockedRooms.begin(), lockedRooms.end(), [](const LockedRoom &p1, const LockedRoom &p2)
			{
				return p1.roomiD > p2.roomiD;
			});

			else
				sort(lockedRooms.begin(), lockedRooms.end(), [](const LockedRoom &p1, const LockedRoom &p2)
			{
				return p1.roomiD < p2.roomiD;
			});
			down = !down;
			break;
		case '4':
			if (down)
				sort(lockedRooms.begin(), lockedRooms.end(), [](const LockedRoom &p1, const LockedRoom &p2)
			{
				return p1.star > p2.star;
			});

			else
				sort(lockedRooms.begin(), lockedRooms.end(), [](const LockedRoom &p1, const LockedRoom &p2)
			{
				return p1.star < p2.star;
			});
			down = !down;
			break;
		case '5':
			if (down)
				sort(lockedRooms.begin(), lockedRooms.end(), [](const LockedRoom &p1, const LockedRoom &p2)
			{
				return p1.finis > p2.finis;
			});

			else
				sort(lockedRooms.begin(), lockedRooms.end(), [](const LockedRoom &p1, const LockedRoom &p2)
			{
				return p1.finis < p2.finis;
			});
			down = !down;
			break;
		}
	}
}

void sortCategory(){
	int key = 1;
	bool down = true;
	while (key != '0') {
		system("cls");
		cout << " ____________________________" << endl;
		cout << "|     Сортировать список     |" << endl;
		cout << "|     категорий номеров      |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|   Код     |    Название    |" << endl;
		cout << "| категории |   категории    |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|                            |" << endl;
		for (int i = 0; i != categories.size(); i++)
			printf("| %4d      | %14s |\n", categories[i].categoryiD, categories[i].category_name.c_str());
		cout << "|                            |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|                            |" << endl;
		cout << "|   Сортировать по:          |" << endl;
		cout << "|   1: Коду                  |" << endl;
		cout << "|   2: Названию              |" << endl;
		cout << "|   0: Назад                 |" << endl;
		cout << "|____________________________|" << endl;
		key = _getch();
		switch (key) {
		case '1':
			if (down)
				sort(categories.begin(), categories.end(), [](const Category &p1, const Category &p2)
			{
				return p1.categoryiD > p2.categoryiD;
			});

			else
				sort(categories.begin(), categories.end(), [](const Category &p1, const Category &p2) {
				return p1.categoryiD < p2.categoryiD;
			});
			down = !down;
			break;
		case '2':
			if (down)
				sort(categories.begin(), categories.end(), [](const Category &p1, const Category &p2) {
				return p1.category_name > p2.category_name;
			});

			else
				sort(categories.begin(), categories.end(), [](const Category &p1, const Category &p2) {
				return p1.category_name < p2.category_name;
			});
			down = !down;
			break;
		}
	}
	
}

//Сортировка информации о постояльцах 
void sortPerson() {
	int key = 1;
	bool down = true;
	while (key != '0') {
		system("cls");
		cout << " _______________________________________________________________ " << endl;
		cout << "|                   Сортировка информации о постояльцах         |" << endl;
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
		cout << "|   Сортировать по:                                             |" << endl;
		cout << "|   1: Коду гражданина                                          |" << endl;
		cout << "|   2: Ф.И.О.                                                   |" << endl;
		cout << "|   3: Паспорту                                                 |" << endl;
		cout << "|   0: Назад                                                    |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		key = _getch();
		switch (key) {
		case '1':
			if (down)
				sort(persons.begin(), persons.end(), [](const Person &p1, const Person &p2)
			{
				return p1.personiD > p2.personiD;
			});

			else
				sort(persons.begin(), persons.end(), [](const Person &p1, const Person &p2)
			{
				return p1.personiD < p2.personiD;
			});
			down = !down;
			break;
		case '2':
			if (down)
				sort(persons.begin(), persons.end(), [](const Person &p1, const Person &p2)
			{
				return p1.Fio > p2.Fio;
			});

			else
				sort(persons.begin(), persons.end(), [](const Person &p1, const Person &p2)
			{
				return p1.Fio < p2.Fio;
			});
			down = !down;
			break;
		case '3':
			if (down)
				sort(persons.begin(), persons.end(), [](const Person &p1, const Person &p2)
			{
				return p1.passport > p2.passport;
			});

			else
				sort(persons.begin(), persons.end(), [](const Person &p1, const Person &p2)
			{
				return p1.passport < p2.passport;
			});
			down = !down;
			break;
		}


	}
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
		{
			cin.clear();
			cin.ignore(32767, '\n');
			return value;
		}
	}
}
