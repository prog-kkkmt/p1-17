#include "header.h"

vector<Category> categories;
vector<Room> rooms;
vector<Person> persons;
vector<LockedRoom> lockedRooms;

//���������� �� ������ 
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
			f1 >> category.price;
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

//������ � �����	
void Save() {

	ofstream f1("data//Category.txt");

	if (f1.is_open()) {
		for (int i = 0; i != categories.size(); i++) {
			f1 << categories[i].categoryiD << " " << categories[i].price << " " << categories[i].category_name;
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
//������ ��������� ����
void printDefaultMenu() {
	system("cls");
	cout << " ________________________________________ " << endl;
	cout << "|                                        |" << endl;
	cout << "|        �������� ����� �����            |" << endl;
	cout << "|________________________________________|" << endl;
	cout << "|                                        |" << endl;
	cout << "|   1: ����� �������                     |" << endl;
	cout << "|   2: ���������� �������                |" << endl;
	cout << "|   3: �������������� �������            |" << endl;
	cout << "|   4: ������ � html �������             |" << endl;
	cout << "|________________________________________|" << endl;
	cout << "|                                        |" << endl;
	cout << "|   0: � ���������                       |" << endl;
	cout << "| Esc: �����                             |" << endl;
	cout << "|________________________________________|" << endl;
}
//���� ���������
void Menu() {
	Initialization();//���������� �� ������ 
	int key;
	bool exit = true;

	while (exit)
	{

		printDefaultMenu();//������ ��������� ����
		switch ((key = _getch()))
		{
		case '1'://1: ����� ������� 
			StructMenu(&exit);
			break;
		case '2'://2: ���������� �������
			SortMenu(&exit);
			break;
		case '3'://4: �������������� �������
			EditMenu(&exit);
			break;
		case '4'://4: ������ � html
			htmlMenu(&exit);
			break;
		case '0'://� ���������+
			About(&exit);
			break;
		case 27:// �����
			exit = false;
			break;
		default:
			break;
		}

	}
	Save();//������ � �����
}
//�������� �������
void StructMenu(bool* exit) {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ________________________________________ " << endl;
		cout << "|                                        |" << endl;
		cout << "|        ����������� ������              |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   1: ������ �������                    |" << endl;
		cout << "|   2: ������� ������                    |" << endl;
		cout << "|   3: ��������� �������                 |" << endl;
		cout << "|   4: ���������� � �����������          |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   0: �����                             |" << endl;
		cout << "| Esc: �����                             |" << endl;
		cout << "|________________________________________|" << endl;

		switch ((key = _getch()))
		{
		case '1'://1: ������ ������� 
			printRoom();
			break;
		case '2'://2: ������� ������
			printLockedRoom();
			;
			break;
		case '3'://3: ��������� �������
			printCategory();
			break;
		case '4'://4: ���������� � �����������
			printPerson();
			break;
		case 27:
			*exit = false;
			key = '0';
			break;
		}
	}
}
//�������� ����������
void SortMenu(bool* exit) {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ________________________________________ " << endl;
		cout << "|                                        |" << endl;
		cout << "|        ����������� ������              |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   1: ������ �������                    |" << endl;
		cout << "|   2: ������� ������                    |" << endl;
		cout << "|   3: ��������� �������                 |" << endl;
		cout << "|   4: ���������� � �����������          |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   0: �����                             |" << endl;
		cout << "| Esc: �����                             |" << endl;
		cout << "|________________________________________|" << endl;

		switch ((key = _getch()))
		{
		case '1'://1:  ������ ������� 
			sortRoom();
			break;
		case '2'://2: ������� ������ 
			sortLockedRoom();
			break;
		case '3'://3: ��������� �������
			sortCategory();
			break;
		case '4'://4: ���������� � �����������
			sortPerson();
			break;
		case 27:
			*exit = false;
			key = '0';
			break;
		}
	}
}
// ������ � html �������
void htmlMenu(bool* exit) {
	int key = 1;
	system("MD html");

	while (key != '0') {
		system("cls");
		cout << " ________________________________________ " << endl;
		cout << "|                                        |" << endl;
		cout << "|        ������ ������� � html           |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   1: ������ �������                    |" << endl;
		cout << "|   2: ������� ������                    |" << endl;
		cout << "|   3: ��������� �������                 |" << endl;
		cout << "|   4: ���������� � �����������          |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   a: �������� ���                      |" << endl;
		cout << "|   0: �����                             |" << endl;
		cout << "| Esc: �����                             |" << endl;
		cout << "|________________________________________|" << endl;

		switch ((key = _getch()))
		{
		case '1'://1: ������ ������� 
			htmlprintRoom();
			system("html\\Room.html");
			break;
		case '2'://2: ������� ������
			htmlprintLockedRoom();
			system("html\\LockedRoom.html");
			break;
		case '3'://3: ��������� �������
			htmlprintCategory();
			system("html\\Category.html");
			break;
		case '4'://4: ���������� � �����������
			htmlprintPerson();
			system("html\\Person.html");
			break;
		case 'a'://4: �������� ��
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
// �������������� �������
void EditMenu(bool* exit) {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ________________________________________ " << endl;
		cout << "|                                        |" << endl;
		cout << "|        ������������� ������            |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   1: ������ �������                    |" << endl;
		cout << "|   2: ������� ������                    |" << endl;
		cout << "|   3: ��������� �������                 |" << endl;
		cout << "|   4: ���������� � �����������          |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   0: �����                             |" << endl;
		cout << "| Esc: �����                             |" << endl;
		cout << "|________________________________________|" << endl;

		switch ((key = _getch()))
		{
		case '1'://1: ������ ������� 
			editRoom();
			break;
		case '2'://2: ������� ������ 
			editLockedRoom();
			break;
		case '3'://3: ��������� �������
			editCategory();
			break;
		case '4'://4: ���������� � �����������
			editPerson();
			break;
		case 27:
			*exit = false;
			key = '0';
			break;
		}
	}

}
//� ���������
void About(bool* exit) {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ________________________________________ " << endl;
		cout << "|                                        |" << endl;
		cout << "|               � ���������              |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|        ���������� ����������           |" << endl;
		cout << "|     �����  ����������� ���������       |" << endl;
		cout << "|                                        |" << endl;
		cout << "|                                        |" << endl;
		cout << "|     ������ 1.3.21                      |" << endl;
		cout << "|     �����               ������� �.�.   |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   0: �����                             |" << endl;
		cout << "| Esc: �����                             |" << endl;
		cout << "|________________________________________|" << endl;
		if ((key = _getch()) == 27) {
			*exit = false;
			break;
		}
	}
}

//������ ������� 
void printRoom() {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ___________________________________________________" << endl;
		cout << "|                  ������ �������                   |" << endl;
		cout << "|___________________________________________________|" << endl;
		cout << "|  ���   |   ���     |  �����   | �����  |   ����   |" << endl;
		cout << "| ������ | ��������� |          |  ����  |   ����   |" << endl;
		cout << "|___________________________________________________|" << endl;
		cout << "|                                                   |" << endl;
		for (int i = 0; i != rooms.size(); i++) {
			printf("| %4d   | %4d      | %5d    |  %2d    ", rooms[i].roomiD, rooms[i].categoryiD, rooms[i].num, rooms[i].beds);
			for (int j = 0; j != categories.size(); j++)
				if (rooms[i].categoryiD == categories[j].categoryiD)
					printf("|  %2d    |", categories[j].price);
			cout << endl;
		}
		cout << "|___________________________________________________|" << endl;
		cout << "|                                                   |" << endl;
		cout << "|   0: �����                                        |" << endl;
		cout << "|___________________________________________________|" << endl;
		key = _getch();
	}
}

//������� ������
void printLockedRoom() {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ______________________________________________________________________ " << endl;
		cout << "|                            ������� ������                            |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		cout << "|    ���     |    ���     |  ���   |     ����       |       ����       |" << endl;
		cout << "| ���������� | ���������� | ������ |    ������      |    ����������    |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		cout << "|                                                                      |" << endl;
		for (int i = 0; i != lockedRooms.size(); i++)
			printf("|  %5d     | %5d      | %4d   |  %10s    |    %10s    |\n", lockedRooms[i].lockedRoomiD, lockedRooms[i].personiD, lockedRooms[i].roomiD, lockedRooms[i].star, lockedRooms[i].finis);
		cout << "|______________________________________________________________________|" << endl;
		cout << "|                                                                      |" << endl;
		cout << "|   0: �����                                                           |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		key = _getch();
	}
}

//��������� �������
void printCategory() {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " _____________________________________________" << endl;
		cout << "|            ��������� �������                |" << endl;
		cout << "|_____________________________________________|" << endl;
		cout << "|   ���     |    ��������    |      ����      |" << endl;
		cout << "| ��������� |   ���������    |   ���������    |" << endl;
		cout << "|_____________________________________________|" << endl;
		cout << "|                                             |" << endl;
		for (int i = 0; i != categories.size(); i++)
			printf("| %4d      | %14s | %14d |\n", categories[i].categoryiD, categories[i].category_name, categories[i].price);
		cout << "|                                             |" << endl;
		cout << "|_____________________________________________|" << endl;
		cout << "|                                             |" << endl;
		cout << "|   0: �����                                  |" << endl;
		cout << "|_____________________________________________|" << endl;
		key = _getch();
	}
}

//���������� � �����������
void printPerson() {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " _______________________________________________________________ " << endl;
		cout << "|                    ���������� � �����������                   |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|    ���     |              �.�.�.              |   �������     |" << endl;
		cout << "| ���������� |            ����������            |  ����������   |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|                                                               |" << endl;
		for (int i = 0; i != persons.size(); i++)
			printf("| %4d       | %30s   | %13s |\n", persons[i].personiD, persons[i].Fio, persons[i].passport);
		cout << "|                                                               |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|                                                               |" << endl;
		cout << "|   0: �����                                                    |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		key = _getch();
	}
}

//html������ ������� 
void htmlprintRoom() {
	ofstream html("html//Room.html");
	system("cls");
	cout << " ___________________________________________________" << endl;
	cout << "|                  ������ �������                   |" << endl;
	cout << "|___________________________________________________|" << endl;
	cout << "|  ���   |   ���     |  �����   | �����  |   ����   |" << endl;
	cout << "| ������ | ��������� |          |  ����  |   ����   |" << endl;
	cout << "|___________________________________________________|" << endl;
	cout << "|                                                   |" << endl;
	for (int i = 0; i != rooms.size(); i++) {
		printf("| %4d   | %4d      | %5d    |  %2d    ", rooms[i].roomiD, rooms[i].categoryiD, rooms[i].num, rooms[i].beds);
		for (int j = 0; j != categories.size(); j++)
			if (rooms[i].categoryiD == categories[j].categoryiD)
				printf("|  %2d    |", categories[j].price);
		cout << endl;
	}
	cout << "|___________________________________________________|" << endl;
	cout << "|                                                   |" << endl;
	cout << "|   0: �����                                        |" << endl;
	cout << "|___________________________________________________|" << endl;
	if (html.is_open()) {
		html << "<!DOCTYPE HTML>\n<html>\n<head>\n<! --   http-equiv=\"Content-Type\" content=\"text/html; charset=Windows-1251\"-->\n<title>������ �������</title>\n</head>\n";
		html << "<body>\n<table border=\"1\">\n <caption>������ �������</caption>\n";
		html << "<thead>\n <tr>\n";
		html << "<th>��� ������</th>\n" << "<th>��� ���������</th>\n" << "<th>�����</th>\n" << "<th>����� ����</th>\n" << "<th>���� �� ����</th>\n";
		html << "</tr>\n</thead>\n";
		html << "<tbody>";
		for (int i = 0; i != rooms.size(); i++) { //<tr>  </tr>
			html << "<tr>";
			html << "<td>" << rooms[i].roomiD << "</td>" << "<td>" << rooms[i].categoryiD << "</td>" << "<td>" << rooms[i].num << "</td>" << "<td>" << rooms[i].beds << "</td>";
			for (int j = 0; j != categories.size(); j++)
				if (rooms[i].categoryiD == categories[j].categoryiD)
					html << "<td>" << categories[j].price << "</td>";
			html << "</tr>\n";
		}
		html << "</tbody>\n";
		html << "</html>";
	}
}

//html������� ������
void htmlprintLockedRoom() {
	ofstream html("html//LockedRoom.html");
	system("cls");
	cout << " ______________________________________________________________________ " << endl;
	cout << "|                            ������� ������                            |" << endl;
	cout << "|______________________________________________________________________|" << endl;
	cout << "|    ���     |    ���     |  ���   |     ����       |       ����       |" << endl;
	cout << "| ���������� | ���������� | ������ |    ������      |    ����������    |" << endl;
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
		html << "<!DOCTYPE HTML>\n<html>\n<head>\n<! --  http-equiv=\"Content-Type\" content=\"text/html; charset=Windows-1251\"-->\n<title>������� ������</title>\n</head>\n";
		html << "<body>\n<table border=\"1\">\n <caption>������� ������</caption>\n";
		html << "<thead>\n <tr>\n";
		html << "<th>��� ����������</th>\n" << "<th>��� ����������</th>\n" << "<th>��� ������</th>\n" << "<th>���� ������</th>\n" << "<th>���� ����������</th>\n";
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

//html��������� �������
void htmlprintCategory() {
	ofstream html("html//Category.html");

	system("cls");
	cout << " _____________________________________________" << endl;
	cout << "|            ��������� �������                |" << endl;
	cout << "|_____________________________________________|" << endl;
	cout << "|   ���     |    ��������    |      ����      |" << endl;
	cout << "| ��������� |   ���������    |    ���������   |" << endl;
	cout << "|_____________________________________________|" << endl;
	cout << "|                                             |" << endl;
	for (int i = 0; i != categories.size(); i++)
		printf("| %4d      | %14s | %14d |\n", categories[i].categoryiD, categories[i].category_name, categories[i].price);
	cout << "|                                             |" << endl;
	cout << "|_____________________________________________|" << endl;
	cout << "|                                             |" << endl;
	cout << "|   0: �����                                  |" << endl;
	cout << "|_____________________________________________|" << endl;
	if (html.is_open()) {
		html << "<!DOCTYPE HTML>\n<html>\n<head>\n<! --  http-equiv=\"Content-Type\" content=\"text/html; charset=Windows-1251\"-->\n<title>��������� �������</title>\n</head>\n";
		html << "<body>\n<table border=\"1\">\n <caption>��������� �������</caption>\n";
		html << "<thead>\n <tr>\n";
		html << "<th>��� ���������</th>\n" << "<th>�������� ���������</th>\n" << "<th> ���� ���������</th>\n";
		html << "</tr>\n</thead>\n";
		html << "<tbody>";
		for (int i = 0; i != categories.size(); i++) { //<tr>  </tr>
			html << "<tr>";
			html << "<td>" << categories[i].categoryiD << "</td>" << "<td>" << categories[i].category_name << "</td>" << "<td>" << categories[i].price << "</td>";
			html << "</tr>\n";
		}
		html << "</tbody>\n";
		html << "</html>";
	}

}

//html���������� � �����������
void htmlprintPerson() {
	ofstream html("html//Person.html");

	system("cls");
	cout << " _______________________________________________________________ " << endl;
	cout << "|                    ���������� � �����������                   |" << endl;
	cout << "|_______________________________________________________________|" << endl;
	cout << "|    ���     |              �.�.�.              |   �������     |" << endl;
	cout << "| ���������� |            ����������            |  ����������   |" << endl;
	cout << "|_______________________________________________________________|" << endl;
	cout << "|                                                               |" << endl;
	for (int i = 0; i != persons.size(); i++)
		printf("| %4d       | %30s   | %13s |\n", persons[i].personiD, persons[i].Fio, persons[i].passport);
	cout << "|                                                               |" << endl;
	cout << "|_______________________________________________________________|" << endl;
	cout << "|                                                               |" << endl;
	cout << "|   0: �����                                                    |" << endl;
	cout << "|_______________________________________________________________|" << endl;
	if (html.is_open()) {
		html << "<!DOCTYPE HTML>\n<html>\n<head>\n<! --   http-equiv=\"Content-Type\" content=\"text/html; charset=Windows-1251\"-->\n<title>���������� � �����������</title>\n</head>\n";
		html << "<body>\n<table border=\"1\">\n <caption>���������� � �����������</caption>\n";
		html << "<thead>\n <tr>\n";
		html << "<th>��� ���������</th>\n" << "<th> �.�.�. ����������</th>\n" << "<th> ������� ����������</th>\n";
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
//html���������� �� 1 ��������
void htmlprintAll() {
	ofstream html("html//All.html");
	if (html.is_open()) {
		html << "<!DOCTYPE HTML>\n<html>\n<head>\n<! --  http-equiv=\"Content-Type\" content=\"text/html; charset=Windows-1251\"-->\n<title>������ �������</title>\n</head>\n";
		html << "<body>\n<table border=\"1\">\n <caption>��������� �������</caption>\n";
		html << "<thead>\n <tr>\n";
		html << "<th>��� ���������</th>\n" << "<th>�������� ���������</th>\n" << "<th> ���� ���������</th>\n";
		html << "</tr>\n</thead>\n";
		html << "<tbody>";
		for (int i = 0; i != categories.size(); i++) { //<tr>  </tr>
			html << "<tr>";
			html << "<td>" << categories[i].categoryiD << "</td>" << "<td>" << categories[i].category_name << "</td>" << "<td>" << categories[i].price << "</td>";
			html << "</tr>\n";
		}
		html << "</tbody>\n";

		html << "<body>\n<table border=\"1\">\n <caption>������ �������</caption>\n";
		html << "<thead>\n <tr>\n";
		html << "<th>��� ������</th>\n" << "<th>��� ���������</th>\n" << "<th>�����</th>\n" << "<th>����� ����</th>\n" << "<th>���� ����</th>\n";
		html << "</tr>\n</thead>\n";
		html << "<tbody>";
		for (int i = 0; i != rooms.size(); i++) { //<tr>  </tr>
			html << "<tr>";
			html << "<td>" << rooms[i].roomiD << "</td>" << "<td>" << rooms[i].categoryiD << "</td>" << "<td>" << rooms[i].num << "</td>" << "<td>" << rooms[i].beds <<"</td>" ;
			for (int j = 0; j != categories.size(); j++)
				if (rooms[i].categoryiD == categories[j].categoryiD)
					html << "<td>" << categories[j].price << "</td>";
			html << "</tr>\n";
		}
		html << "</tbody>\n";

		html << "<body>\n<table border=\"1\">\n <caption>������� ������</caption>\n";
		html << "<thead>\n <tr>\n";
		html << "<th>��� ����������</th>\n" << "<th>��� ����������</th>\n" << "<th>��� ������</th>\n" << "<th>���� ������</th>\n" << "<th>���� ����������</th>\n";
		html << "</tr>\n</thead>\n";
		html << "<tbody>";
		for (int i = 0; i != lockedRooms.size(); i++) {
			html << "<tr>";
			html << "<td>" << lockedRooms[i].lockedRoomiD << "</td>" << "<td>" << lockedRooms[i].personiD << "</td>" << "<td>" << lockedRooms[i].roomiD << "</td>" << "<td>" << lockedRooms[i].star << "</td>" << "<td>" << lockedRooms[i].finis << "</td>";
			html << "</tr>\n";
		}
		html << "</tbody>\n";

		html << "<body>\n<table border=\"1\">\n <caption>���������� � �����������</caption>\n";
		html << "<thead>\n <tr>\n";
		html << "<th>��� ���������</th>\n" << "<th> �.�.�. ����������</th>\n" << "<th> ������� ����������</th>\n";
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

//������������� ������ �������
void editRoom() {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ___________________________________________________" << endl;
		cout << "|                  ������ �������                   |" << endl;
		cout << "|___________________________________________________|" << endl;
		cout << "|  ���   |   ���     |  �����   | �����  |   ����   |" << endl;
		cout << "| ������ | ��������� |          |  ����  |   ����   |" << endl;
		cout << "|___________________________________________________|" << endl;
		cout << "|                                                   |" << endl;
		for (int i = 0; i != rooms.size(); i++) {
			printf("| %4d   | %4d      | %5d    |  %2d    ", rooms[i].roomiD, rooms[i].categoryiD, rooms[i].num, rooms[i].beds);
			for (int j = 0; j != categories.size(); j++)
				if (rooms[i].categoryiD == categories[j].categoryiD)
					printf("|  %2d    |", categories[j].price);
			cout << endl;
		}
		cout << "|___________________________________________________|" << endl;
		cout << "|                                                   |" << endl;
		cout << "|   a: ��������         e: �������������            |" << endl;
		cout << "|   d: �������                                      |" << endl;
		cout << "|   0: �����                                        |" << endl;
		cout << "|___________________________________________________|" << endl;
		key = _getch();
		if (key == 'a') {
			cout << " ________________________________________ " << endl;
			cout << "|   ���������� ����� ������              |" << endl;
			cout << "|________________________________________|" << endl;
			cout << "|   ������� ��� ������:                  |" << endl;
			cout << "|________________________________________|" << endl;
			cout << ": ";
			Room room;
			int newRoomiD;
			newRoomiD = getInt();
			room.roomiD = newRoomiD;
			cout << "|   �������  ��� ���������:              |" << endl;
			cout << "|________________________________________|" << endl;
			cout << ": ";
			int newcategoryiD;
			newcategoryiD = getInt();
			room.categoryiD = newcategoryiD;
			cout << "|________________________________________|" << endl;
			cout << "|   �������  �����:                      |" << endl;
			cout << "|________________________________________|" << endl;
			cout << ": ";
			int newnum;
			newnum = getInt();
			room.num = newnum;
			cout << "|________________________________________|" << endl;
			cout << "|   ������� ���������� ����:             |" << endl;
			cout << "|________________________________________|" << endl;
			cout << ": ";
			int newbeds;
			newbeds = getInt();
			room.beds = newbeds;
			rooms.push_back(room);
		}
		if (key == 'e') {

			cout << "|   ������� ��� ������:                  |" << endl;
			cout << "|________________________________________|" << endl;
			int searchiD;
			cout << ": ";
			searchiD = getInt();
			for (int i = 0; i != rooms.size(); i++) {
				if (rooms[i].roomiD == searchiD) {
					int newcategoryiD;
					newcategoryiD = getInt();
					rooms[i].categoryiD = newcategoryiD;
					cout << "|________________________________________|" << endl;
					cout << "|   �������  �����:                      |" << endl;
					cout << "|________________________________________|" << endl;
					cout << ": ";
					int newnum;
					newnum = getInt();
					rooms[i].num = newnum;
					cout << "|________________________________________|" << endl;
					cout << "|   ������� ���������� ����:             |" << endl;
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
			cout << "|   ������� ��� ������ ��������� ������: |" << endl;
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

//������� ������
void editLockedRoom() {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ______________________________________________________________________ " << endl;
		cout << "|                            ������� ������                            |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		cout << "|    ���     |    ���     |  ���   |     ����       |       ����       |" << endl;
		cout << "| ���������� | ���������� | ������ |    ������      |    ����������    |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		cout << "|                                                                      |" << endl;
		for (int i = 0; i != lockedRooms.size(); i++)
			printf("|  %5d     | %5d      | %4d   |  %10s    |    %10s    |\n", lockedRooms[i].lockedRoomiD, lockedRooms[i].personiD, lockedRooms[i].roomiD, lockedRooms[i].star, lockedRooms[i].finis);
		cout << "|            |            |        |                |                  |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		cout << "|                                                                      |" << endl;
		cout << "|   d: �������           e: �������������               a: ��������    |" << endl;
		cout << "|   0: �����                                                           |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		key = _getch();
		if (key == 'e') {
			cout << "|   ������� ��� ����������:                                            |" << endl;
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
					cout << "|    ������� ����� ��� ����������:                                     |" << endl;
					cout << "|______________________________________________________________________|" << endl;
					cout << ": ";
					int newlockedRoomiD;
					newlockedRoomiD = getInt();
					lockedRooms[i].lockedRoomiD = newlockedRoomiD;
					*/
					cout << "|______________________________________________________________________|" << endl;
					cout << "|   ������� ����� ��� ����������:                                      |" << endl;
					cout << "|______________________________________________________________________|" << endl;
					cout << ": ";
					int newpersoniD;
					newpersoniD = getInt();
					lockedRooms[i].personiD = newpersoniD;
					cout << "|______________________________________________________________________|" << endl;
					cout << "|   ������� ����� ��� ������:                                          |" << endl;
					cout << "|______________________________________________________________________|" << endl;
					cout << ": ";
					int newroomiD;
					newroomiD = getInt();
					lockedRooms[i].roomiD = newroomiD;
					cout << "|______________________________________________________________________|" << endl;
					cout << "|   ������� ����� ���� ������:                                         |" << endl;
					cout << "|______________________________________________________________________|" << endl;
					cout << ": ";
					string  newstart;
					cin >> newstart;
					lockedRooms[i].lenstar = newstart.copy(lockedRooms[i].star, newstart.size());
					lockedRooms[i].star[lockedRooms[i].lenstar] = '\0';
					cout << "|   ������� ����� ���� ����������:                                     |" << endl;
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
			cout << "|    ���� ����� ������                                                 |" << endl;
			cout << "|______________________________________________________________________|" << endl;
			cout << "|______________________________________________________________________|" << endl;
			cout << "|    ������� ����� ��� ����������:                                     |" << endl;
			cout << "|______________________________________________________________________|" << endl;
			cout << ": ";
			LockedRoom lockedRoom;
			int newlockedRoomiD;
			newlockedRoomiD = getInt();
			lockedRoom.lockedRoomiD = newlockedRoomiD;
			cout << "|   ������� ����� ��� ����������:                                      |" << endl;
			cout << "|______________________________________________________________________|" << endl;
			cout << ": ";

			lockedRoom.personiD = getInt();
			cout << "|______________________________________________________________________|" << endl;
			cout << "|   ������� ����� ��� ������:                                          |" << endl;
			cout << "|______________________________________________________________________|" << endl;
			cout << ": ";
			lockedRoom.roomiD = getInt();
			cout << "|______________________________________________________________________|" << endl;
			cout << "|   ������� ����� ���� ������:                                         |" << endl;
			cout << "|______________________________________________________________________|" << endl;
			cout << ": ";
			string  newstart;
			cin >> newstart;
			lockedRoom.lenstar = newstart.copy(lockedRoom.star, newstart.size());
			lockedRoom.star[lockedRoom.lenstar] = '\0';
			cout << "|   ������� ����� ���� ����������:                                     |" << endl;
			cout << "|______________________________________________________________________|" << endl;
			cout << ": ";
			string newfinish;
			cin >> newfinish;
			lockedRoom.lenfinis = newfinish.copy(lockedRoom.finis, newfinish.size());
			lockedRoom.finis[lockedRoom.lenfinis] = '\0';
			lockedRooms.push_back(lockedRoom);
		}
		if (key == 'd') {
			cout << "|   ������� ��� ���������� ��������� ������:                           |" << endl;
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

//��������� �������
void editCategory() {
	int key = 1;

	while (key != '0') {
		system("cls");
		cout << " _____________________________________________" << endl;
		cout << "|            ��������� �������                |" << endl;
		cout << "|_____________________________________________|" << endl;
		cout << "|   ���     |    ��������    |      ����      |" << endl;
		cout << "| ��������� |   ���������    |   ���������    |" << endl;
		cout << "|_____________________________________________|" << endl;
		cout << "|                                             |" << endl;
		for (int i = 0; i != categories.size(); i++)
			printf("| %4d      | %14s | %14d |\n", categories[i].categoryiD, categories[i].category_name, categories[i].price);
		cout << "|                                             |" << endl;
		cout << "|_____________________________________________|" << endl;
		cout << "|                                             |" << endl;
		cout << "|             e: �������������                |" << endl;
		cout << "|             a: ��������                     |" << endl;
		cout << "|             d: �������                      |" << endl;
		cout << "|             0: �����                        |" << endl;
		cout << "|_____________________________________________|" << endl;
		key = _getch();
		if (key == 'e') {
			cout << "|   ������� ��� ���������:   |" << endl;
			cout << "|____________________________|" << endl;
			int searchiD;
			cout << ": ";
			searchiD = getInt();
			for (int i = 0; i != categories.size(); i++) {
				if (categories[i].categoryiD == searchiD) {
					cout << "______________________________" << endl;
					printf("| %4d      | %14s |\n", categories[i].categoryiD, categories[i].category_name);
					cout << "|____________________________|" << endl;
					cout << "|      ������� �����         |" << endl;
					cout << "|    �������� ���������:     |" << endl;
					cout << "|____________________________|" << endl;
					cout << ": ";
					string newcategory_name;
					cin >> newcategory_name;
					categories[i].lencategory_name = newcategory_name.copy(categories[i].category_name, newcategory_name.size());
					categories[i].category_name[categories[i].lencategory_name] = '\0';
					int newprice;
					cout << "|____________________________|" << endl;
					cout << "|      ������� �����         |" << endl;
					cout << "|       ���� �� ����  :      |" << endl;
					cout << "|____________________________|" << endl;
					cin >> newprice;
					categories[i].price = newprice;
					break;
				}
			}

		}
		if (key == 'a') {
			cout << "|   ������� ��� ���������:   |" << endl;
			cout << "|____________________________|" << endl;
			Category category;
			category.categoryiD = getInt();
			cout << "|____________________________|" << endl;
			cout << "|      ������� �����         |" << endl;
			cout << "|    �������� ���������:     |" << endl;
			cout << "|____________________________|" << endl;
			string categoryName;
			int newprice;
			getline(cin, categoryName);
			category.lencategory_name = categoryName.copy(category.category_name, categoryName.size());
			category.category_name[category.lencategory_name] = '\0';
			cout << "|____________________________|" << endl;
			cout << "|      ������� �����         |" << endl;
			cout << "|       ���� �� ����  :      |" << endl;
			cout << "|____________________________|" << endl;
			cin >> newprice;
			category.price = newprice;
			categories.push_back(category);
		}
		if (key == 'd') {
			cout << "|   ������� ��� ���������    |" << endl;
			cout << "|     ��������� ������:      |" << endl;
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

//���������� � �����������
void editPerson() {
	int key = 1;

	while (key != '0') {
		system("cls");
		cout << " _______________________________________________________________ " << endl;
		cout << "|                    ���������� � �����������                   |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|    ���     |              �.�.�.              |   �������     |" << endl;
		cout << "| ���������� |            ����������            |  ����������   |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|                                                               |" << endl;
		for (int i = 0; i != persons.size(); i++)
			printf("| %4d       | %30s   | %13s |\n", persons[i].personiD, persons[i].Fio, persons[i].passport);
		cout << "|                                                               |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|                                                               |" << endl;
		cout << "|   d: �������          e: �������������          a: ��������   |" << endl;
		cout << "|   0: �����                                                    |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		key = _getch();
		if (key == 'e') {
			cout << "|   ������� ��� ����������:                                     |" << endl;
			cout << "|_______________________________________________________________|" << endl;
			int searchiD;
			cout << ": ";
			searchiD = getInt();
			for (int i = 0; i != persons.size(); i++) {
				if (persons[i].personiD == searchiD) {
					cout << " _______________________________________________________________ " << endl;
					printf("| %4d       | %30s   | %12s |\n", persons[i].personiD, persons[i].Fio, persons[i].passport);
					cout << "|_______________________________________________________________|" << endl;
					cout << "|   ������� ����� �.�.� ����������:                             |" << endl;
					cout << "|_______________________________________________________________|" << endl;
					cout << ": ";
					string newfio;
					getline(cin, newfio);
					persons[i].lenFio = newfio.copy(persons[i].Fio, newfio.size());
					persons[i].Fio[persons[i].lenFio] = '\0';
					cout << "|_______________________________________________________________|" << endl;
					cout << "|   ������� ������� ����������:                                 |" << endl;
					cout << "|_______________________________________________________________|" << endl;
					cout << ": ";
					string newpassport;
					getline(cin, newpassport);
					persons[i].lenpassport = newpassport.copy(persons[i].passport, newpassport.size());
					persons[i].passport[persons[i].lenpassport] = '\0';
					break;
				}
			}
		}
		if (key == 'a') {
			Person person;
			cout << " _______________________________________________________________ " << endl;
			cout << "|   ����� ����� ������                                          |" << endl;
			cout << "|_______________________________________________________________|" << endl;
			cout << "|   ������� ��� ����������:                                     |" << endl;
			cout << "|_______________________________________________________________|" << endl;
			cout << ": ";
			person.personiD = getInt();
			cout << " _______________________________________________________________ " << endl;
			cout << "|   ������� ����� �.�.� ����������:                             |" << endl;
			cout << "|_______________________________________________________________|" << endl;
			cout << ": ";
			string newfio;
			getline(cin, newfio);
			person.lenFio = newfio.copy(person.Fio, newfio.size());
			person.Fio[person.lenFio] = '\0';
			cout << " _______________________________________________________________ " << endl;
			cout << "|   ������� ������� ����������:                                 |" << endl;
			cout << "|_______________________________________________________________|" << endl;
			cout << ": ";
			string newpassport;
			getline(cin, newpassport);
			person.lenpassport = newpassport.copy(person.passport, newpassport.size());
			person.passport[person.lenpassport] = '\0';
			persons.push_back(person);
		}
		if (key == 'd') {
			cout << "|   ������� ��� ����������                                      |" << endl;
			cout << "|     ��������� ������:                                         |" << endl;
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


//���������� ������ �������
void sortRoom() {
	int key = 1;
	bool down = true;
	while (key != '0') {
		system("cls");
		cout << " ___________________________________________________ " << endl;
		cout << "|              ���������� ������ �������            |" << endl;
		cout << "|___________________________________________________|" << endl;
		cout << "|  ���   |   ���     |  �����   | �����  |   ����   |" << endl;
		cout << "| ������ | ��������� |          |  ����  |   ����   |" << endl;
		cout << "|___________________________________________________|" << endl;
		cout << "|                                                   |" << endl;
		for (int i = 0; i != rooms.size(); i++) {
			printf("| %4d   | %4d      | %5d    |  %2d    |", rooms[i].roomiD, rooms[i].categoryiD, rooms[i].num, rooms[i].beds);
			for (int j = 0; j != categories.size(); j++)
				if (rooms[i].categoryiD == categories[j].categoryiD)
					printf("  %2d    |", categories[j].price);
			cout << endl;
		}
		cout << "|        |           |          |        |          |" << endl;
		cout << "|___________________________________________________|" << endl;
		cout << "|                                                   |" << endl;
		cout << "|            ����������� ��:                        |" << endl;
		cout << "|            1: �� ���� ������                      |" << endl;
		cout << "|            2: �� ���� ���������                   |" << endl;
		cout << "|            3: �� ������                           |" << endl;
		cout << "|            4: �� ���������� ����                  |" << endl;
		cout << "|            5: �� ����                             |" << endl;
		cout << "|            0: �����                               |" << endl;
		cout << "|___________________________________________________|" << endl;
		key = _getch();
		switch (key) {
		case '1':
			if (down)
				sort(rooms.begin(), rooms.end(), [](const Room& p1, const Room& p2)
					{
						return p1.roomiD > p2.roomiD;
					});

			else
				sort(rooms.begin(), rooms.end(), [](const Room& p1, const Room& p2)
					{
						return p1.roomiD < p2.roomiD;
					});
			down = !down;
			break;
		case '2':
			if (down)
				sort(rooms.begin(), rooms.end(), [](const Room& p1, const Room& p2)
					{
						return p1.categoryiD > p2.categoryiD;
					});

			else
				sort(rooms.begin(), rooms.end(), [](const Room& p1, const Room& p2)
					{
						return p1.categoryiD < p2.categoryiD;
					});
			down = !down;
			break;
		case '3':
			if (down)
				sort(rooms.begin(), rooms.end(), [](const Room& p1, const Room& p2)
					{
						return p1.num > p2.num;
					});

			else
				sort(rooms.begin(), rooms.end(), [](const Room& p1, const Room& p2)
					{
						return p1.num < p2.num;
					});
			down = !down;
			break;
		case '4':
			if (down)
				sort(rooms.begin(), rooms.end(), [](const Room& p1, const Room& p2)
					{
						return p1.beds > p2.beds;
					});

			else
				sort(rooms.begin(), rooms.end(), [](const Room& p1, const Room& p2)
					{
						return p1.beds < p2.beds;
					});
			down = !down;
			break;
		}
	}
}

//���������� ������ ������� �������
void sortLockedRoom() {
	int key = 1;
	bool down = true;//���������� ������-����,����� �����-�����
	while (key != '0') {
		system("cls");
		cout << " ______________________________________________________________________ " << endl;
		cout << "|                    ���������� ������ ������� �������                 |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		cout << "|    ���     |    ���     |  ���   |     ����       |       ����       |" << endl;
		cout << "| ���������� | ���������� | ������ |    ������      |    ����������    |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		cout << "|                                                                      |" << endl;
		for (int i = 0; i != lockedRooms.size(); i++)
			printf("|  %5d     | %5d      | %4d   |  %10s    |    %10s    |\n", lockedRooms[i].lockedRoomiD, lockedRooms[i].personiD, lockedRooms[i].roomiD, lockedRooms[i].star, lockedRooms[i].finis);
		cout << "|            |            |        |                |                  |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		cout << "|                                                                      |" << endl;
		cout << "|                      ����������� ��:                                 |" << endl;
		cout << "|                      1: ���� ����������                              |" << endl;
		cout << "|                      2: ���� ����������                              |" << endl;
		cout << "|                      3: ���� ������                                  |" << endl;
		cout << "|                      4: ���� ������                                  |" << endl;
		cout << "|                      5: ����� ����������                             |" << endl;
		cout << "|                      0: �����                                        |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		key = _getch();
		switch (key) {
		case '1':
			if (down)
				sort(lockedRooms.begin(), lockedRooms.end(), [](const LockedRoom& p1, const LockedRoom& p2)
					{
						return p1.lockedRoomiD > p2.lockedRoomiD;
					});

			else
				sort(lockedRooms.begin(), lockedRooms.end(), [](const LockedRoom& p1, const LockedRoom& p2)
					{
						return p1.lockedRoomiD < p2.lockedRoomiD;
					});
			down = !down;
			break;
		case '2':
			if (down)
				sort(lockedRooms.begin(), lockedRooms.end(), [](const LockedRoom& p1, const LockedRoom& p2)
					{
						return p1.personiD > p2.personiD;
					});

			else
				sort(lockedRooms.begin(), lockedRooms.end(), [](const LockedRoom& p1, const LockedRoom& p2)
					{
						return p1.personiD < p2.personiD;
					});
			down = !down;
			break;
		case '3':
			if (down)
				sort(lockedRooms.begin(), lockedRooms.end(), [](const LockedRoom& p1, const LockedRoom& p2)
					{
						return p1.roomiD > p2.roomiD;
					});

			else
				sort(lockedRooms.begin(), lockedRooms.end(), [](const LockedRoom& p1, const LockedRoom& p2)
					{
						return p1.roomiD < p2.roomiD;
					});
			down = !down;
			break;
		case '4':
			if (down)
				sort(lockedRooms.begin(), lockedRooms.end(), [](const LockedRoom& p1, const LockedRoom& p2)
					{
						return p1.star > p2.star;
					});

			else
				sort(lockedRooms.begin(), lockedRooms.end(), [](const LockedRoom& p1, const LockedRoom& p2)
					{
						return p1.star < p2.star;
					});
			down = !down;
			break;
		case '5':
			if (down)
				sort(lockedRooms.begin(), lockedRooms.end(), [](const LockedRoom& p1, const LockedRoom& p2)
					{
						return p1.finis > p2.finis;
					});

			else
				sort(lockedRooms.begin(), lockedRooms.end(), [](const LockedRoom& p1, const LockedRoom& p2)
					{
						return p1.finis < p2.finis;
					});
			down = !down;
			break;
		}
	}
}

//���������� ������ ���������
void sortCategory() {
	int key = 1;
	bool down = true;
	while (key != '0') {
		system("cls");
		cout << " _____________________________________________" << endl;
		cout << "|             ����������� ������              |" << endl;
		cout << "|             ��������� �������               |" << endl;
		cout << "|   ���     |    ��������    |      ����      |" << endl;
		cout << "| ��������� |   ���������    |   ���������    |" << endl;
		cout << "|_____________________________________________|" << endl;
		cout << "|                                             |" << endl;
		for (int i = 0; i != categories.size(); i++)
			printf("| %4d      | %14s | %14d |\n", categories[i].categoryiD, categories[i].category_name, categories[i].price);
		cout << "|                                             |" << endl;
		cout << "|_____________________________________________|" << endl;
		cout << "|_____________________________________________|" << endl;
		cout << "|                                             |" << endl;
		cout << "|               ����������� ��:               |" << endl;
		cout << "|               1: ����                       |" << endl;
		cout << "|               2: ��������                   |" << endl;
		cout << "|               3: ����                       |" << endl;
		cout << "|               0: �����                      |" << endl;
		cout << "|_____________________________________________|" << endl;
		key = _getch();
		switch (key) {
		case '1':
			if (down)
				sort(categories.begin(), categories.end(), [](const Category& p1, const Category& p2)
					{
						return p1.categoryiD > p2.categoryiD;
					});

			else
				sort(categories.begin(), categories.end(), [](const Category& p1, const Category& p2) {
				return p1.categoryiD < p2.categoryiD;
					});
			down = !down;
			break;
		case '2':
			if (down)
				sort(categories.begin(), categories.end(), [](const Category& p1, const Category& p2) {
				return p1.category_name > p2.category_name;
					});

			else
				sort(categories.begin(), categories.end(), [](const Category& p1, const Category& p2) {
				return p1.category_name < p2.category_name;
					});
			down = !down;
			break;
		case '3':
			if (down)
				sort(categories.begin(), categories.end(), [](const Category& p1, const Category& p2)
					{
						return p1.price > p2.price;
					});

			else
				sort(categories.begin(), categories.end(), [](const Category& p1, const Category& p2)
					{
						return p1.price < p2.price;
					});
			down = !down;
			break;
		}
	}

}

//���������� ���������� � ����������� 
void sortPerson() {
	int key = 1;
	bool down = true;
	while (key != '0') {
		system("cls");
		cout << " _______________________________________________________________ " << endl;
		cout << "|                   ���������� ���������� � �����������         |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|    ���     |              �.�.�.              |   �������     |" << endl;
		cout << "| ���������� |            ����������            |  ����������   |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|                                                               |" << endl;
		for (int i = 0; i != persons.size(); i++)
			printf("| %4d       | %30s   | %13s |\n", persons[i].personiD, persons[i].Fio, persons[i].passport);
		cout << "|                                                               |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|                                                               |" << endl;
		cout << "|                        ����������� ��:                        |" << endl;
		cout << "|                        1: ���� ����������                     |" << endl;
		cout << "|                        2: �.�.�.                              |" << endl;
		cout << "|                        3: ��������                            |" << endl;
		cout << "|                        0: �����                               |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		key = _getch();
		switch (key) {
		case '1':
			if (down)
				sort(persons.begin(), persons.end(), [](const Person& p1, const Person& p2)
					{
						return p1.personiD > p2.personiD;
					});

			else
				sort(persons.begin(), persons.end(), [](const Person& p1, const Person& p2)
					{
						return p1.personiD < p2.personiD;
					});
			down = !down;
			break;
		case '2':
			if (down)
				sort(persons.begin(), persons.end(), [](const Person& p1, const Person& p2)
					{
						return p1.Fio > p2.Fio;
					});

			else
				sort(persons.begin(), persons.end(), [](const Person& p1, const Person& p2)
					{
						return p1.Fio < p2.Fio;
					});
			down = !down;
			break;
		case '3':
			if (down)
				sort(persons.begin(), persons.end(), [](const Person& p1, const Person& p2)
					{
						return p1.passport > p2.passport;
					});

			else
				sort(persons.begin(), persons.end(), [](const Person& p1, const Person& p2)
					{
						return p1.passport < p2.passport;
					});
			down = !down;
			break;
		}


	}
}

//�������� �� ���������� ���� �����
int getInt() {
	int value;
	while (true) {
		cin >> value;
		if (cin.fail()) // ���� ���������� ���������� ���� ���������,
		{
			cin.clear(); // �� ���������� cin � '�������' ����� ������
			cout << "������� ������������� ����� �������� : ";
			cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
		}
		else
		{
			cin.clear();
			cin.ignore(32767, '\n');
			return value;
		}
	}
}