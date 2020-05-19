#include "data.h"
vector<Category> �ategories;
vector<Room> rooms;
vector<Person> persons;
vector<LockedRoom> lockedRooms;

//���������� �� ������ 
void Initialization() {
	string poof;

	ifstream f1("Category.txt");
	Category category;
	if (f1.is_open()) {
		while (!f1.eof()) {
			f1 >> category.categoryiD;
			getline(f1, poof, ' ');
			getline(f1, category.category_name);
			�ategories.push_back(category);
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

//������ � �����
void Save() {

	ofstream f1("Category.txt");
	
	if (f1.is_open()) {
		for (int i = 0; i != �ategories.size(); i++) {
			f1 << �ategories[i].categoryiD << " " << �ategories[i].category_name;
			if (i != �ategories.size() - 1)
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
	cout << "|        �������� ����� �����            |" << endl;
	cout << "|________________________________________|" << endl;
	cout << "|                                        |" << endl;
	cout << "|   1: ����� �������                     |" << endl;
	cout << "|   2: ���������� �������                |" << endl;
	cout << "|   3: �������������� �������            |" << endl;
	cout << "|________________________________________|" << endl;
	cout << "|                                        |" << endl;
	cout << "|   0: � ���������                       |" << endl;
	cout << "| Esc: �����                             |" << endl;
	cout << "|________________________________________|" << endl;

}

//���� ���������
void Menu() {
	Initialization();
	int key;
	bool exit = true;
	
	while (exit)
	{
		
		printDefaultMenu();
		switch ((key = _getch()))
		{
		case '1'://1: ����� ������� 
			StructMenu(&exit);
			break;
		case '2'://2: ���������� ������� 
			SortMenu(&exit);
			break;
		case '3'://3: �������������� �������
			EditMenu(&exit);
			break;
		case '0'://� ���������
			About(&exit);
			break;
		case 27://�����
			exit = false;
			break;
		default:
			break;
		}

	}
	Save();
}

//�������� �������
void StructMenu(bool *exit) {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ________________________________________ " << endl;
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

void SortMenu(bool *exit) {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ________________________________________ " << endl;
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

// �������������� �������
void EditMenu(bool *exit) {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ________________________________________ " << endl;
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
void About(bool *exit) {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ________________________________________ " << endl;
		cout << "|        � ���������                     |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|     ���������� ����������              |" << endl;
		cout << "|     �����  ����������� ���������       |" << endl;
		cout << "|                                        |" << endl;
		cout << "|                                        |" << endl;
		cout << "|     ������ 1.0.1�                      |" << endl;
		cout << "|     �����             ������� �.�.    |" << endl;
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
		system("cls");//������ (���	������, ��� ���������, �����, ����);
		cout << " ________________________________________ " << endl;
		cout << "|        ������ �������                  |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|  ���   |   ���     |  �����   | �����  |" << endl;
		cout << "| ������ | ��������� |          |  ����  |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		for (int i = 0; i != rooms.size(); i++)
			printf("| %4d   | %4d      | %5d    |  %2d    |\n", rooms[i].roomiD, rooms[i].categoryiD, rooms[i].num, rooms[i].beds);
		cout << "|        |           |          |        |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   0: �����                             |" << endl;
		cout << "|________________________________________|" << endl;
		key = _getch();
	}
}

//������� ������
void printLockedRoom(){
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
			printf("|  %5d     | %5d      | %4d   |  %10s    |    %10s    |\n", lockedRooms[i].lockedRoomiD, lockedRooms[i].personiD, lockedRooms[i].roomiD, lockedRooms[i].star.c_str(), lockedRooms[i].finis.c_str());
		cout << "|            |            |        |                |                  |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		cout << "|                                                                      |" << endl;
		cout << "|   0: �����                                                           |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		key = _getch();
	}
}

//��������� �������
void printCategory(){
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ____________________________" << endl;
		cout << "|     ��������� �������      |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|   ���     |    ��������    |" << endl;
		cout << "| ��������� |   ���������    |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|                            |" << endl;
		for (int i = 0; i != �ategories.size(); i++)		     
			printf("| %4d      | %14s |\n", �ategories[i].categoryiD, �ategories[i].category_name.c_str());
		cout << "|                            |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|                            |" << endl;
		cout << "|   0: �����                 |" << endl;
		cout << "|____________________________|" << endl;
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
			printf("| %4d       | %30s   | %13s |\n", persons[i].personiD,persons[i].Fio.c_str(),persons[i].passport.c_str());
		cout << "|                                                               |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|                                                               |" << endl;
		cout << "|   0: �����                                                    |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		key = _getch();
	}
}

void editRoom() {//+
	int key = 1;
	while (key != '0') {
		system("cls");//������ (���	������, ��� ���������, �����, ����);
		cout << " ________________________________________ " << endl;
		cout << "|        ������ �������                  |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|  ���   |   ���     |  �����   | �����  |" << endl;
		cout << "| ������ | ��������� |          |  ����  |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		for (int i = 0; i != rooms.size(); i++)
			printf("| %4d   | %4d      | %5d    |  %2d    |\n", rooms[i].roomiD, rooms[i].categoryiD, rooms[i].num, rooms[i].beds);
		cout << "|        |           |          |        |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   a: ��������         e: ������������� |" << endl;
		cout << "|   d: �������                           |" << endl;
		cout << "|   0: �����                             |" << endl;
		cout << "|________________________________________|" << endl;
		key = _getch();
		if (key == 'a') {
			cout << "|   ������� ����� ������   :             |" << endl;
			cout << "|________________________________________|" << endl;
			Room room;
			cin >> room.roomiD >> room.categoryiD >> room.num >> room.beds;//
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
					cout << "|________________________________________|" << endl;
					printf("| %4d   | %4d      | %5d    |  %2d    |\n", rooms[i].roomiD, rooms[i].categoryiD, rooms[i].num, rooms[i].beds);
					/*
					cout << "|________________________________________|" << endl;
					cout << "|   ������� ��� ������:              |" << endl;
					cout << "|________________________________________|" << endl;
					cout << ": ";
					int newRoomiD;
					newRoomiD = getInt();
					rooms[i].roomiD = newRoomiD;
					*/
					cout << "|________________________________________|" << endl;
					cout << "|   �������  ��� ���������:              |" << endl;
					cout << "|________________________________________|" << endl;
					cout << ": ";
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
			printf("|  %5d     | %5d      | %4d   |  %10s    |    %10s    |\n", lockedRooms[i].lockedRoomiD, lockedRooms[i].personiD, lockedRooms[i].roomiD, lockedRooms[i].star.c_str(), lockedRooms[i].finis.c_str());
		cout << "|            |            |        |                |                  |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		cout << "|                                                                      |" << endl;
		cout << "|   d: �������           e: �������������               a: ��������    |" << endl;
		cout << "|   0: �����                                                           |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		key = _getch();
		if (key == 'e') {
			cout << "|   ������� ��� ���������� :                                           |" << endl;
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
					cout << "|   ������� ����� ��� ����������:                                      |" << endl;
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
					cin >> newpersoniD;

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
					lockedRooms[i].star = newstart;
					cout << "|   ������� ����� ���� ����������:                                     |" << endl;
					cout << "|______________________________________________________________________|" << endl;
					cout << ": ";
					string newfinish;
					cin >> newfinish;
					lockedRooms[i].finis = newfinish;
				}
			}
			
		}
		if (key == 'a') {
			cout << "|   ������� ����� ������   :                                           |" << endl;
			cout << "|______________________________________________________________________|" << endl;
			LockedRoom lockedRoom; 
			lockedRoom.personiD = getInt();
			lockedRoom.roomiD = getInt();
			cin >> lockedRoom.star >> lockedRoom.finis;
			lockedRooms.push_back(lockedRoom);
		}
		if (key == 'd') {
			cout << "|   ������� ��� ���������� ��������� ������ :                          |" << endl;
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
		cout << " ____________________________" << endl;
		cout << "|     ��������� �������      |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|   ���     |    ��������    |" << endl;
		cout << "| ��������� |   ���������    |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|                            |" << endl;
		for (int i = 0; i != �ategories.size(); i++)
			printf("| %4d      | %14s |\n", �ategories[i].categoryiD, �ategories[i].category_name.c_str());
		cout << "|                            |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|                            |" << endl;
		cout << "|   e: �������������         |" << endl;
		cout << "|   a: ��������              |" << endl;
		cout << "|   d: �������               |" << endl;
		cout << "|   0: �����                 |" << endl;
		cout << "|____________________________|" << endl;
		key = _getch();
		if (key == 'e') {
			cout << "|   ������� ��� ���������   :|" << endl;
			cout << "|____________________________|" << endl;
			int searchiD;
			cout << ": ";
			searchiD = getInt();
			for (int i = 0; i != �ategories.size(); i++) {
				if (�ategories[i].categoryiD == searchiD) {
					printf("| %4d      | %14s |\n", �ategories[i].categoryiD, �ategories[i].category_name.c_str());

					cout << "|____________________________|" << endl;
					cout << "|      ������� �����         |" << endl;
					cout << "|    �������� ���������:     |" << endl;
					cout << "|____________________________|" << endl;
					cout << ": ";
					string newcategory_name;
					cin >> newcategory_name;
					�ategories[i].category_name = newcategory_name;
				}
			}

		}
		if (key == 'a') {
			cout << "|   ������� ����� ������:    |" << endl;
			cout << "|____________________________|" << endl;
			Category category;
			category.categoryiD = getInt();
			cin >> category.category_name;
			�ategories.push_back(category);
		}
		if (key == 'd') {
			cout << "|   ������� ��� ���������    |" << endl;
			cout << "|     ��������� ������:      |" << endl;
			cout << "|____________________________|" << endl;
			int searchiD;
			cout << ": ";
			searchiD = getInt();
			for (int i = 0; i != �ategories.size(); i++) {
				if (�ategories[i].categoryiD == searchiD) {
					�ategories.erase(�ategories.begin() + i);
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
			printf("| %4d       | %30s   | %13s |\n", persons[i].personiD, persons[i].Fio.c_str(), persons[i].passport.c_str());
		cout << "|                                                               |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|                                                               |" << endl;
		cout << "|   d: �������          e: �������������          a: ��������   |" << endl;
		cout << "|   0: �����                                                    |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		key = _getch();
		if (key == 'e') {
			cout << "|   ������� ��� ���������� :                                    |" << endl;
			cout << "|_______________________________________________________________|" << endl;
			int searchiD;
			cout << ": ";
			searchiD = getInt();
			for (int i = 0; i != persons.size(); i++) {
				if (persons[i].personiD == searchiD) {
					cout << " _______________________________________________________________ " << endl;
					printf("| %4d       | %30s   | %12s |\n", persons[i].personiD, persons[i].Fio.c_str(), persons[i].passport.c_str());
					cout << "|_______________________________________________________________|" << endl;
					cout << "|   ������� ����� �.�.� ����������:                             |" << endl;
					cout << "|_______________________________________________________________|" << endl;
					cout << ": ";
					string newfio;
					cin.clear();
					cin.ignore(10000, '\n');
					getline(cin, newfio);
					persons[i].Fio = newfio;
					cout << "|_______________________________________________________________|" << endl;
					cout << "|   ������� ������� ����������:                                 |" << endl;
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
			cout << "|   ������� ��� ���������� :                                    |" << endl;
			cout << "|_______________________________________________________________|" << endl;
			cout << ": ";
			person.personiD = getInt();
			cout << " _______________________________________________________________ " << endl;
			cout << "|   ������� �.�.� ����������:                                   |" << endl;
			cout << "|_______________________________________________________________|" << endl;
			cout << ": ";
			cin.clear();
			cin.ignore(10000, '\n');
			getline(cin, person.Fio);
			cout << " _______________________________________________________________ " << endl;
			cout << "|   ������� ������� ����������:                                 |" << endl;
			cout << "|_______________________________________________________________|" << endl;
			cout << ": ";
			string passport;
			getline(cin, passport);
			person.passport = passport.insert(0, " ");//fgets(nazv_sh, sizeof(nazv_sh), stdin); nazv_sh[strlen[nazv_sh] - 1] = 0;
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
	bool down = true;//���������� ������-����,����� �����-�����
	while (key != '0') {
		system("cls");//������ (���	������, ��� ���������, �����, ����);
		cout << " ________________________________________ " << endl;
		cout << "|        ���������� ������ �������       |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|  ���   |   ���     |  �����   | �����  |" << endl;
		cout << "| ������ | ��������� |          |  ����  |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		for (int i = 0; i != rooms.size(); i++)
			printf("| %4d   | %4d      | %5d    |  %2d    |\n", rooms[i].roomiD, rooms[i].categoryiD, rooms[i].num, rooms[i].beds);
		cout << "|        |           |          |        |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   ����������� ��:                      |" << endl;
		cout << "|   1: �� ���� ������                    |" << endl;
		cout << "|   2: �� ���� ���������                 |" << endl;
		cout << "|   3: �� ������                         |" << endl;
		cout << "|   4: �� ���������� ����                |" << endl;
		cout << "|   0: �����                             |" << endl;
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

//���������� ������ �������
void sortLockedRoom(){
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
			printf("|  %5d     | %5d      | %4d   |  %10s    |    %10s    |\n", lockedRooms[i].lockedRoomiD, lockedRooms[i].personiD, lockedRooms[i].roomiD, lockedRooms[i].star.c_str(), lockedRooms[i].finis.c_str());
		cout << "|            |            |        |                |                  |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		cout << "|                                                                      |" << endl;
		cout << "|   ����������� ��:                                                    |" << endl;
		cout << "|   1: ���� ����������                                                 |" << endl;
		cout << "|   2: ���� ����������                                                 |" << endl;
		cout << "|   3: ���� ������                                                     |" << endl;
		cout << "|   4: ���� ������                                                     |" << endl;
		cout << "|   5: ����� ����������                                                |" << endl;
		cout << "|   0: �����                                                           |" << endl;
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

//���������� ������ ��������� �������
void sortCategory(){
	int key = 1;
	bool down = true;//���������� ������-����,����� �����-�����
	while (key != '0') {
		system("cls");
		cout << " ____________________________" << endl;
		cout << "|     ���������� ������      |" << endl;
		cout << "|     ��������� �������      |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|   ���     |    ��������    |" << endl;
		cout << "| ��������� |   ���������    |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|                            |" << endl;
		for (int i = 0; i != �ategories.size(); i++)
			printf("| %4d      | %14s |\n", �ategories[i].categoryiD, �ategories[i].category_name.c_str());
		cout << "|                            |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|                            |" << endl;
		cout << "|   ����������� ��:          |" << endl;
		cout << "|   1: ����                  |" << endl;
		cout << "|   2: ��������              |" << endl;
		cout << "|   0: �����                 |" << endl;
		cout << "|____________________________|" << endl;
		key = _getch();
		switch (key) {
		case '1':
			if (down)
				sort(�ategories.begin(), �ategories.end(), [](const Category &p1, const Category &p2)
			{
				return p1.categoryiD > p2.categoryiD;
			});

			else
				sort(�ategories.begin(), �ategories.end(), [](const Category &p1, const Category &p2) {
				return p1.categoryiD < p2.categoryiD;
			});
			down = !down;
			break;
		case '2':
			if (down)
				sort(�ategories.begin(), �ategories.end(), [](const Category &p1, const Category &p2) {
				return p1.category_name > p2.category_name;
			});

			else
				sort(�ategories.begin(), �ategories.end(), [](const Category &p1, const Category &p2) {
				return p1.category_name < p2.category_name;
			});
			down = !down;
			break;
		}
	}
	
}

//���������� ������ �������
void sortPerson() {
	int key = 1;
	bool down = true;//���������� ������-����,����� �����-�����
	while (key != '0') {
		system("cls");
		cout << " _______________________________________________________________ " << endl;
		cout << "|            ���������� ���������� �� �����������               |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|    ���     |              �.�.�.              |   �������     |" << endl;
		cout << "| ���������� |            ����������            |  ����������   |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|                                                               |" << endl;
		for (int i = 0; i != persons.size(); i++)
			printf("| %4d       | %30s   | %13s |\n", persons[i].personiD, persons[i].Fio.c_str(), persons[i].passport.c_str());
		cout << "|                                                               |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|                                                               |" << endl;
		cout << "|   ����������� ��:                                             |" << endl;
		cout << "|   1: ���� ����������                                          |" << endl;
		cout << "|   2: �.�.�.                                                   |" << endl;
		cout << "|   3: ��������                                                 |" << endl;
		cout << "|   0: �����                                                    |" << endl;
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
		
//������ �� ������
int getInt() {//�������� �� ���������� ���� �����
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
			return value;
	}
}