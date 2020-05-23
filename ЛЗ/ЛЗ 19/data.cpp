#include "data.h"

vector<Category> categories;
vector<Room> rooms;
vector<Person> persons;
vector<LockedRoom> lockedRooms;

//Считывание из файлов 
void Initialization() {
	string poof;
	string str;
	string fio;
	system("MD data");
	ifstream f1("data//Category.txt");
	
	if (f1.is_open()) {
		while (!f1.eof()) {
			Category category;
			f1 >> category.categoryiD;
			getline(f1, poof, ' ');
			getline(f1, str);
			category.lencategory_name = str.copy(category.category_name, str.size());
			category.category_name[category.lencategory_name] = '\0';
			categories.push_back(category);
		}

		f1.close();
	}

	ifstream f2("data//Room.txt");
	
	if (f2.is_open()) {
		while (!f2.eof()) {
			Room room;
			f2 >> room.roomiD >> room.categoryiD >> room.num >> room.beds;
			rooms.push_back(room);
		}

		f2.close();
	}

	ifstream f3("data//Person.txt");
	
	if (f3.is_open()) {
		while (!f3.eof()) {
			Person person;
			f3 >> person.personiD;
			getline(f3, poof, ' ');
			getline(f3, fio, ':');
			getline(f3, str);
			person.lenFio = fio.copy(person.Fio, fio.size());
			person.Fio[person.lenFio] = '\0';
			person.lenpassport = str.copy(person.passport, str.size());
			person.passport[person.lenpassport] = '\0';
			persons.push_back(person);


		}

		f3.close();
	}

	ifstream f4("data//LockedRoom.txt");
	
	if (f4.is_open()) {
		while (!f4.eof()) {
			LockedRoom lockedRoom;
			f4 >> lockedRoom.lockedRoomiD >> lockedRoom.personiD >> lockedRoom.roomiD;
			getline(f4, poof, ' ');
			getline(f4, str, ' ');
			lockedRoom.lenstar = str.copy(lockedRoom.star, str.size());
			lockedRoom.star[lockedRoom.lenstar] = '\0';
			getline(f4, str);
			lockedRoom.lenfinis = str.copy(lockedRoom.finis, str.size());
			lockedRoom.finis[lockedRoom.lenfinis] = '\0';
			lockedRooms.push_back(lockedRoom);
		}

		f4.close();
	}
}

//запись в файлы	
void Save() {

	ofstream f1("data//Category.txt");

	if (f1.is_open()) {
		for (int i = 0; i != categories.size(); i++) {
			f1 << categories[i].categoryiD << " " << categories[i].category_name;
			if (i != categories.size() - 1)
				f1 << endl;
		}
		f1.close();
	}

	ofstream f2("data//Room.txt");

	if (f2.is_open()) {
		for (int i = 0; i != rooms.size(); i++) {
			f2 << rooms[i].roomiD << " " << rooms[i].categoryiD << " " << rooms[i].num << " " << rooms[i].beds;
			if (i != rooms.size() - 1)
				f2 << endl;
		}
		f2.close();
	}

	ofstream f3("data//Person.txt");

	if (f3.is_open()) {

		for (int i = 0; i != persons.size(); i++) {
			f3 << persons[i].personiD << " " << persons[i].Fio << ':' << persons[i].passport;
			if (i != persons.size() - 1)
				f3 << endl;
		}

		f3.close();
	}

	ofstream f4("data//LockedRoom.txt");

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
	cout << "|   4: Печать в html таблицы             |" << endl;
	cout << "|________________________________________|" << endl;
	cout << "|                                        |" << endl;
	cout << "|   0: О программе                       |" << endl;
	cout << "| Esc: Выход                             |" << endl;
	cout << "|________________________________________|" << endl;

}
//----------------------------------------------------------------------------------------------------------
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
		case '3'://4: Редактирование таблицы
			EditMenu(&exit);
			break;
		case '4'://4: Печать в html
			htmlMenu(&exit);
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
//Просмотр сортировок
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
// Печать в html таблицы
void htmlMenu(bool *exit) {
	int key = 1;
	system("MD html");
	
	while (key != '0') {
		system("cls");
		cout << " ________________________________________ " << endl;
		cout << "|        Печать записей в html           |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   1: Список номеров                    |" << endl;
		cout << "|   2: Занятые номера                    |" << endl;
		cout << "|   3: Категории номеров                 |" << endl;
		cout << "|   4: Информация о постояльцах          |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   a: Печатать все                      |" << endl;
		cout << "|   0: Назад                             |" << endl;
		cout << "| Esc: Выход                             |" << endl;
		cout << "|________________________________________|" << endl;

		switch ((key = _getch()))
		{
		case '1'://1: Список номеров 
			htmlprintRoom();
			system("html\\Room.html");
			break;
		case '2'://2: Занятые номера
			htmlprintLockedRoom();
			system("html\\LockedRoom.html");
			break;
		case '3'://3: Категории номеров
			htmlprintCategory();
			system("html\\Category.html");
			break;
		case '4'://4: Информация о постояльцах
			htmlprintPerson();
			system("html\\Person.html");
			break;
		case 'a'://4: Печатать всё
			htmlprintAll();	
			system("html\\All.html");
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
		cout << "|     Версия 1.7.6с                      |" << endl;
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


//--------------------------------------------------------------------------------------------------------
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
void printLockedRoom() {
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
			printf("|  %5d     | %5d      | %4d   |  %10s    |    %10s    |\n", lockedRooms[i].lockedRoomiD, lockedRooms[i].personiD, lockedRooms[i].roomiD, lockedRooms[i].star, lockedRooms[i].finis);
		cout << "|            |            |        |                |                  |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		cout << "|                                                                      |" << endl;
		cout << "|   0: Назад                                                           |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		key = _getch();
	}
}

//Категории номеров
void printCategory() {
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
			printf("| %4d      | %14s |\n", categories[i].categoryiD, categories[i].category_name);
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
			printf("| %4d       | %30s   | %13s |\n", persons[i].personiD, persons[i].Fio, persons[i].passport);
		cout << "|                                                               |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|                                                               |" << endl;
		cout << "|   0: Назад                                                    |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		key = _getch();
	}
}

//----------------------------------------------------------------------------------------------------------

//htmlСписок номеров 
void htmlprintRoom() {
	ofstream html("html//Room.html");
		system("cls");
		cout << " ________________________________________ " << endl;
		cout << "|            Список номеров              |" << endl;
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
		cout << "|                                        |" << endl;
		cout << "|________________________________________|" << endl;
		if (html.is_open()) {
			html << "<!DOCTYPE HTML>\n<html>\n<head>\n<! --   http-equiv=\"Content-Type\" content=\"text/html; charset=Windows-1251\"-->\n<title>Список номеров</title>\n</head>\n";
			html << "<body>\n<table border=\"1\">\n <caption>Список номеров</caption>\n";
			html << "<thead>\n <tr>\n";
			html << "<th>Код номера</th>\n" << "<th>Код категории</th>\n" << "<th>Номер</th>\n" << "<th>Всего мест</th>\n";
			html << "</tr>\n</thead>\n";
			html << "<tbody>";
			for (int i = 0; i != rooms.size(); i++) { //<tr>  </tr>
				html << "<tr>";
				html <<"<td>"<< rooms[i].roomiD <<"</td>" << "<td>" << rooms[i].categoryiD << "</td>" << "<td>" << rooms[i].num << "</td>" << "<td>" << rooms[i].beds << "</td>";
				html << "</tr>\n";
			}
			html << "</tbody>\n";
			html << "</html>";
		} 
}

//htmlЗанятые номера
void htmlprintLockedRoom() {
	ofstream html("html//LockedRoom.html"); 
	system("cls");
	cout << " ______________________________________________________________________ " << endl;
	cout << "|                            Занятые номера                            |" << endl;
	cout << "|______________________________________________________________________|" << endl;
	cout << "|    Код     |    Код     |  Код   |     Дата       |       Срок       |" << endl;
	cout << "| размещения | гражданина | номера |    въезда      |    проживания    |" << endl;
	cout << "|______________________________________________________________________|" << endl;
	cout << "|                                                                      |" << endl;
	for (int i = 0; i != lockedRooms.size(); i++)
		printf("|  %5d     | %5d      | %4d   |  %10s    |    %10s    |\n", lockedRooms[i].lockedRoomiD, lockedRooms[i].personiD, lockedRooms[i].roomiD, lockedRooms[i].star, lockedRooms[i].finis);
	cout << "|            |            |        |                |                  |" << endl;
	cout << "|______________________________________________________________________|" << endl;
	cout << "|                                                                      |" << endl;
	cout << "|                                                                      |" << endl;
	cout << "|______________________________________________________________________|" << endl;
	 
	if (html.is_open()) {
		html << "<!DOCTYPE HTML>\n<html>\n<head>\n<! --  http-equiv=\"Content-Type\" content=\"text/html; charset=Windows-1251\"-->\n<title>Занятые номера</title>\n</head>\n";
		html << "<body>\n<table border=\"1\">\n <caption>Занятые номера</caption>\n";
		html << "<thead>\n <tr>\n";
		html << "<th>Код размещения</th>\n" << "<th>Код гражданина</th>\n" << "<th>Код номера</th>\n" << "<th>Дата въезда</th>\n" << "<th>Срок проживания</th>\n";
		html << "</tr>\n</thead>\n";
		html << "<tbody>";
		for (int i = 0; i != lockedRooms.size(); i++) {
			html << "<tr>";
			html << "<td>" << lockedRooms[i].lockedRoomiD << "</td>" << "<td>" << lockedRooms[i].personiD << "</td>" << "<td>" << lockedRooms[i].roomiD << "</td>" << "<td>" << lockedRooms[i].star << "</td>" << "<td>" << lockedRooms[i].finis << "</td>";
			html << "</tr>\n";
		}
		html << "</tbody>\n";
		html << "</html>";
	}
}

//htmlКатегории номеров
void htmlprintCategory() {
	ofstream html("html//Category.html");
	
		system("cls");
		cout << " ____________________________" << endl;
		cout << "|     Категории номеров      |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|   Код     |    Название    |" << endl;
		cout << "| категории |   категории    |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|                            |" << endl;
		for (int i = 0; i != categories.size(); i++)
			printf("| %4d      | %14s |\n", categories[i].categoryiD, categories[i].category_name);
		cout << "|                            |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|                            |" << endl;
		cout << "|   0: Назад                 |" << endl;
		cout << "|____________________________|" << endl;
		if (html.is_open()) {
			html << "<!DOCTYPE HTML>\n<html>\n<head>\n<! --  http-equiv=\"Content-Type\" content=\"text/html; charset=Windows-1251\"-->\n<title>Категории номеров</title>\n</head>\n";
			html << "<body>\n<table border=\"1\">\n <caption>Категории номеров</caption>\n";
			html << "<thead>\n <tr>\n";
			html << "<th>Код категории</th>\n" << "<th>Название категории</th>\n";
			html << "</tr>\n</thead>\n";
			html << "<tbody>";
			for (int i = 0; i != categories.size(); i++) { //<tr>  </tr>
				html << "<tr>";
				html << "<td>" << categories[i].categoryiD << "</td>" << "<td>" << categories[i].category_name << "</td>";
				html << "</tr>\n";
			}
			html << "</tbody>\n";
			html << "</html>";
		}

}

//htmlИнформация о постояльцах
void htmlprintPerson() {
	ofstream html("html//Person.html");

		system("cls");
		cout << " _______________________________________________________________ " << endl;
		cout << "|                    Информация о постояльцах                   |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|    Код     |              Ф.И.О.              |   Паспорт     |" << endl;
		cout << "| гражданина |            гражданина            |  гражданина   |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|                                                               |" << endl;
		for (int i = 0; i != persons.size(); i++)
			printf("| %4d       | %30s   | %13s |\n", persons[i].personiD, persons[i].Fio, persons[i].passport);
		cout << "|                                                               |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|                                                               |" << endl;
		cout << "|   0: Назад                                                    |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		if (html.is_open()) {
			html << "<!DOCTYPE HTML>\n<html>\n<head>\n<! --   http-equiv=\"Content-Type\" content=\"text/html; charset=Windows-1251\"-->\n<title>Информация о постояльцах</title>\n</head>\n";
			html << "<body>\n<table border=\"1\">\n <caption>Информация о постояльцах</caption>\n";
			html << "<thead>\n <tr>\n";
			html << "<th>Код категории</th>\n" << "<th> Ф.И.О. гражданина</th>\n" << "<th> Паспорт гражданина</th>\n";
			html << "</tr>\n</thead>\n";
			html << "<tbody>";
			for (int i = 0; i != persons.size(); i++) {
				html << "<tr>";
				html << "<td>" << persons[i].personiD << "</td>" << "<td>" << persons[i].Fio << "</td>" << "<td>" << persons[i].passport << "</td>";
				html << "</tr>\n";
			}
			html << "</tbody>\n";
			html << "</html>";
		}
}
//htmlВсехтаблиц на 1 странице
void htmlprintAll() {
	ofstream html("html//All.html");
	if (html.is_open()) {
		html << "<!DOCTYPE HTML>\n<html>\n<head>\n<! --  http-equiv=\"Content-Type\" content=\"text/html; charset=Windows-1251\"-->\n<title>Список номеров</title>\n</head>\n";

		html << "<body>\n<table border=\"1\">\n <caption>Категории номеров</caption>\n";
		html << "<thead>\n <tr>\n";
		html << "<th>Код категории</th>\n" << "<th>Название категории</th>\n";
		html << "</tr>\n</thead>\n";
		html << "<tbody>";
		for (int i = 0; i != categories.size(); i++) { //<tr>  </tr>
			html << "<tr>";
			html << "<td>" << categories[i].categoryiD << "</td>" << "<td>" << categories[i].category_name << "</td>";
			html << "</tr>\n";
		}
		html << "</tbody>\n";

		html << "<body>\n<table border=\"1\">\n <caption>Список номеров</caption>\n";
		html << "<thead>\n <tr>\n";
		html << "<th>Код номера</th>\n" << "<th>Код категории</th>\n" << "<th>Номер</th>\n" << "<th>Всего мест</th>\n";
		html << "</tr>\n</thead>\n";
		html << "<tbody>";
		for (int i = 0; i != rooms.size(); i++) { //<tr>  </tr>
			html << "<tr>";
			html << "<td>" << rooms[i].roomiD << "</td>" << "<td>" << rooms[i].categoryiD << "</td>" << "<td>" << rooms[i].num << "</td>" << "<td>" << rooms[i].beds << "</td>";
			html << "</tr>\n";
		}
		html << "</tbody>\n";

		html << "<body>\n<table border=\"1\">\n <caption>Занятые номера</caption>\n";
		html << "<thead>\n <tr>\n";
		html << "<th>Код размещения</th>\n" << "<th>Код гражданина</th>\n" << "<th>Код номера</th>\n" << "<th>Дата въезда</th>\n" << "<th>Срок проживания</th>\n";
		html << "</tr>\n</thead>\n";
		html << "<tbody>";
		for (int i = 0; i != lockedRooms.size(); i++) {
			html << "<tr>";
			html << "<td>" << lockedRooms[i].lockedRoomiD << "</td>" << "<td>" << lockedRooms[i].personiD << "</td>" << "<td>" << lockedRooms[i].roomiD << "</td>" << "<td>" << lockedRooms[i].star << "</td>" << "<td>" << lockedRooms[i].finis << "</td>";
			html << "</tr>\n";
		}
		html << "</tbody>\n";

		html << "<body>\n<table border=\"1\">\n <caption>Информация о постояльцах</caption>\n";
		html << "<thead>\n <tr>\n";
		html << "<th>Код категории</th>\n" << "<th> Ф.И.О. гражданина</th>\n" << "<th> Паспорт гражданина</th>\n";
		html << "</tr>\n</thead>\n";
		html << "<tbody>";
		for (int i = 0; i != persons.size(); i++) {
			html << "<tr>";
			html << "<td>" << persons[i].personiD << "</td>" << "<td>" << persons[i].Fio << "</td>" << "<td>" << persons[i].passport << "</td>";
			html << "</tr>\n";
		}
		html << "</tbody>\n";
		html << "</html>";

	}
}
//---------------------------------------------------------------------------------------------

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
			cout << " ________________________________________ " << endl;
			cout << "|   Добавление новой записи              |" << endl;
			cout << "|________________________________________|" << endl;
			cout << "|   Введите код номера:                  |" << endl;
			cout << "|________________________________________|" << endl;
			cout << ": ";
			Room room;
			int newRoomiD;
			newRoomiD = getInt();
			room.roomiD = newRoomiD;
			cout << "|   Введите  код категории:              |" << endl;
			cout << "|________________________________________|" << endl;
			cout << ": ";
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
					cout << " ________________________________________ " << endl;
					cout << "|  Код   |   Код     |  Номер   | Всего  |" << endl;
					cout << "| номера | категории |          |  мест  |" << endl;
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
					break;
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
			printf("|  %5d     | %5d      | %4d   |  %10s    |    %10s    |\n", lockedRooms[i].lockedRoomiD, lockedRooms[i].personiD, lockedRooms[i].roomiD, lockedRooms[i].star, lockedRooms[i].finis);
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
					printf("|  %5d     | %5d      | %4d   |  %10s    |    %10s    |\n", lockedRooms[i].lockedRoomiD, lockedRooms[i].personiD, lockedRooms[i].roomiD, lockedRooms[i].star, lockedRooms[i].finis);
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
					lockedRooms[i].lenstar = newstart.copy(lockedRooms[i].star, newstart.size());
					lockedRooms[i].star[lockedRooms[i].lenstar] = '\0';
					cout << "|   Введите новый срок проживания:                                     |" << endl;
					cout << "|______________________________________________________________________|" << endl;
					cout << ": ";
					string newfinish;
					cin >> newfinish;
					lockedRooms[i].lenfinis = newfinish.copy(lockedRooms[i].finis, newfinish.size());
					lockedRooms[i].finis[lockedRooms[i].lenfinis] = '\0';
					break;
				}
			}
		}
		if (key == 'a') {
			cout << "|    Ввод новой записи                                                 |" << endl;
			cout << "|______________________________________________________________________|" << endl;
			cout << "|______________________________________________________________________|" << endl;
			cout << "|    Введите новый код размещения:                                     |" << endl;
			cout << "|______________________________________________________________________|" << endl;
			cout << ": ";
			LockedRoom lockedRoom;
			int newlockedRoomiD;
			newlockedRoomiD = getInt();
			lockedRoom.lockedRoomiD = newlockedRoomiD; 
			cout << "|   Введите новый код гражданина:                                      |" << endl;
			cout << "|______________________________________________________________________|" << endl;
			cout << ": ";
			
			lockedRoom.personiD = getInt();  
			cout << "|______________________________________________________________________|" << endl;
			cout << "|   Введите новый код номера:                                          |" << endl;
			cout << "|______________________________________________________________________|" << endl;
			cout << ": "; 
			lockedRoom.roomiD =  getInt();
			cout << "|______________________________________________________________________|" << endl;
			cout << "|   Введите новую дату въезда:                                         |" << endl;
			cout << "|______________________________________________________________________|" << endl;
			cout << ": ";
			string  newstart;
			cin >> newstart; 
			lockedRoom.lenstar = newstart.copy(lockedRoom.star, newstart.size());
			lockedRoom.star[lockedRoom.lenstar] = '\0';
			cout << "|   Введите новый срок проживания:                                     |" << endl;
			cout << "|______________________________________________________________________|" << endl;
			cout << ": ";
			string newfinish;
			cin >> newfinish;
			lockedRoom.lenfinis = newfinish.copy(lockedRoom.finis, newfinish.size());
			lockedRoom.finis[lockedRoom.lenfinis] = '\0';
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
			printf("| %4d      | %14s |\n", categories[i].categoryiD, categories[i].category_name);
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
					printf("| %4d      | %14s |\n", categories[i].categoryiD, categories[i].category_name);

					cout << "|____________________________|" << endl;
					cout << "|      Введите новое         |" << endl;
					cout << "|    название категории:     |" << endl;
					cout << "|____________________________|" << endl;
					cout << ": ";
					string newcategory_name;
					cin >> newcategory_name;
					categories[i].lencategory_name = newcategory_name.copy(categories[i].category_name, newcategory_name.size());
					categories[i].category_name[categories[i].lencategory_name] = '\0';
					break;
				}
			}

		}
		if (key == 'a') {
			cout << "|   Введите код категории:   |" << endl;
			cout << "|____________________________|" << endl;
			Category category;
			category.categoryiD = getInt();
			cout << "|____________________________|" << endl;
			cout << "|      Введите новое         |" << endl;
			cout << "|    название категории:     |" << endl;
			cout << "|____________________________|" << endl;
			string categoryName;
			getline(cin, categoryName);
			category.lencategory_name = categoryName.copy(category.category_name, categoryName.size());
			category.category_name[category.lencategory_name] = '\0';
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
			printf("| %4d       | %30s   | %13s |\n", persons[i].personiD, persons[i].Fio, persons[i].passport);
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
					printf("| %4d       | %30s   | %12s |\n", persons[i].personiD, persons[i].Fio, persons[i].passport);
					cout << "|_______________________________________________________________|" << endl;
					cout << "|   Введите новое Ф.И.О гражданина:                             |" << endl;
					cout << "|_______________________________________________________________|" << endl;
					cout << ": ";
					string newfio;
					getline(cin, newfio);
					persons[i].lenFio = newfio.copy(persons[i].Fio, newfio.size());
					persons[i].Fio[persons[i].lenFio] = '\0';
					cout << "|_______________________________________________________________|" << endl;
					cout << "|   Введите паспорт гражданина:                                 |" << endl;
					cout << "|_______________________________________________________________|" << endl;
					cout << ": ";
					string newpassport;
					getline (cin,newpassport);
					persons[i].lenpassport = newpassport.copy(persons[i].passport, newpassport.size());
					persons[i].passport[persons[i].lenpassport] = '\0';
					break;
				}
			}
		}
		if (key == 'a') {
			Person person;
			cout << " _______________________________________________________________ " << endl;
			cout << "|   Вввод новой записи                                          |" << endl;
			cout << "|_______________________________________________________________|" << endl;
			cout << "|   Введите код гражданина:                                     |" << endl;
			cout << "|_______________________________________________________________|" << endl;
			cout << ": ";
			person.personiD = getInt();
			cout << " _______________________________________________________________ " << endl;
			cout << "|   Введите новое Ф.И.О гражданина:                             |" << endl;
			cout << "|_______________________________________________________________|" << endl;
			cout << ": ";
			string newfio;
			getline(cin, newfio);
			person.lenFio = newfio.copy(person.Fio, newfio.size());
			person.Fio[person.lenFio] = '\0';
			cout << " _______________________________________________________________ " << endl;
			cout << "|   Введите паспорт гражданина:                                 |" << endl;
			cout << "|_______________________________________________________________|" << endl;
			cout << ": ";
			string newpassport;
			getline(cin, newpassport);
			person.lenpassport = newpassport.copy(person.passport, newpassport.size());
			person.passport[person.lenpassport] = '\0'; 
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
//----------------------------------------------------------------------------------------------

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
void sortLockedRoom() {
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
			printf("|  %5d     | %5d      | %4d   |  %10s    |    %10s    |\n", lockedRooms[i].lockedRoomiD, lockedRooms[i].personiD, lockedRooms[i].roomiD, lockedRooms[i].star, lockedRooms[i].finis);
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

//Сортировка списка категорий
void sortCategory() {
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
			printf("| %4d      | %14s |\n", categories[i].categoryiD, categories[i].category_name);
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
			printf("| %4d       | %30s   | %13s |\n", persons[i].personiD, persons[i].Fio, persons[i].passport);
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
//-----------------------------------------------------------------------------------

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
