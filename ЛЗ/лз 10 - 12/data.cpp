#include "data.h"
vector<Category> �ategories;
vector<Room> rooms;
vector<Person> persons;
vector<LockedRoom> lockedRooms;

//���������� �� ������ 
void Initialization() {

	ifstream f1("Category.txt");
	Category category;

	if (f1.is_open()) {
		while (!f1.eof()) {
			f1 >> category.categoryiD;
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

void Save() {/*

ifstream f1("Category.txt");
	Category category;

	if (f1.is_open()) {
		while (!f1.eof()) {
			f1 >> category.categoryiD;
			getline(f1, category.category_name);
			�ategories.push_back(category);
		}			for (int i = 0; i != persons.size();i++)
		f3<<person.personiD<<" "<<person.Fio<< ':'<<person.passport<<endl;

		f1.close();
	}

	ifstream f2("Room.txt");
	Room room;
	if (f2.is_open()) {
		while (!f2.eof()) {
			f2 >> room.roomiD >> room.categoryiD >> room.num >> room.beds;
			rooms.push_back(room);
		}			for (int i = 0; i != persons.size();i++)
		f3<<person.personiD<<" "<<person.Fio<< ':'<<person.passport<<endl;

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
			for (int i = 0; i != persons.size();i++)
		f3<<person.personiD<<" "<<person.Fio<< ':'<<person.passport<<endl;

		}		vector<Category> �ategories;
vector<Room> rooms;
vector<Person> persons;
vector<LockedRoom> lockedRooms;
		
		f3.close();
	}
	
	ifstream f4("LockedRoom.txt");
	LockedRoom lockedRoom;
	if (f4.is_open()) {
		while (!f4.eof()) {
			f4 >> lockedRoom.lockedRoomiD >> lockedRoom.personiD >> lockedRoom.roomiD >> lockedRoom.star >> lockedRoom.finis;
			lockedRooms.push_back(lockedRoom);
		}			for (int i = 0; i != persons.size();i++)
		f3<<person.personiD<<" "<<person.Fio<< ':'<<person.passport<<endl;

		f4.close();
	}*/
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
		case '1'://1: ����� ������� +
			StructMenu(&exit);
			break;
		case '2'://2: ���������� ������� ?
			;
			break;
		case '3'://3: �������������� �������
			Edit();
			break;
		case '0'://� ���������+
			About(&exit);
			break;
		case 27://�����+
			exit = false;
			break;
		default:
			break;
		}

	}
}

// �������������� �������
void Edit() {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ________________________________________ " << endl;
		cout << "|        ������������� ������             |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   1: ������ �������                    |" << endl;
		cout << "|   2: ������� ������                    |" << endl;
		cout << "|   3: ��������� �������                 |" << endl;
		cout << "|   4: ���������� � �����������          |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   0: �����                             |" << endl;
		cout << "|                                        |" << endl;
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
		}
	}

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
		cout << "|     ������ 0.7.6�                      |" << endl;
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
		cout << " ___________________________" << endl;
		cout << "|     ��������� �������     |" << endl;
		cout << "|___________________________|" << endl;
		cout << "|   ���     |    ��������   |" << endl;
		cout << "| ��������� |   ���������   |" << endl;
		cout << "|___________________________|" << endl;
		cout << "|                           |" << endl;
		for (int i = 0; i != �ategories.size(); i++)		     
			printf("| %4d      | %12s  |\n", �ategories[i].categoryiD, �ategories[i].category_name.c_str());
		cout << "|                           |" << endl;
		cout << "|___________________________|" << endl;
		cout << "|                           |" << endl;
		cout << "|   0: �����                |" << endl;
		cout << "|___________________________|" << endl;
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
			printf("| %4d       | %30s   | %12s |\n", persons[i].personiD,persons[i].Fio.c_str(),persons[i].passport.c_str());
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
			cin >> room.roomiD >> room.categoryiD >> room.num >> room.beds;
			rooms.push_back(room);
		}
		if (key == 'e') {
			cout << "|   ������� ��� ������:                  |" << endl;
			cout << "|________________________________________|" << endl;
			int searchiD;
			cout << ": ";
			cin >> searchiD;
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
					cin >> newRoomiD;
					rooms[i].roomiD = newRoomiD;
					*/
					cout << "|________________________________________|" << endl;
					cout << "|   �������  ��� ���������:              |" << endl;
					cout << "|________________________________________|" << endl;
					cout << ": ";
					int newcategoryiD;
					cin >> newcategoryiD;
					rooms[i].categoryiD = newcategoryiD;
					cout << "|________________________________________|" << endl;
					cout << "|   �������  �����:                      |" << endl;
					cout << "|________________________________________|" << endl;
					cout << ": ";
					int newnum;
					cin >> newnum;
					rooms[i].num = newnum;
					cout << "|________________________________________|" << endl;
					cout << "|   ������� ���������� ����:             |" << endl;
					cout << "|________________________________________|" << endl;
					cout << ": ";
					int newbeds;
					cin >> newbeds;
					rooms[i].beds = newbeds;
				}
			}
		}
		if (key == 'd') {
			cout << "|   ������� ��� ������ ��������� ������: |" << endl;
			cout << "|________________________________________|" << endl;
			int searchiD;
			cout << ": ";
			cin >> searchiD;
			for (int i = 0; i != rooms.size(); i++) {
				if (rooms[i].roomiD == searchiD) {
					rooms.erase(rooms.begin() + i);
				}
			}
		}
	}
	Save();
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
		cout << "|   d: �������           e: �������������   	        a: ��������     |" << endl;
		cout << "|   0: �����                                                           |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		key = _getch();
		if (key == 'e') {
			cout << "|   ������� ��� ���������� :                                           |" << endl;
			cout << "|______________________________________________________________________|" << endl;
			int searchiD;
			cout << ": ";
			cin >> searchiD;
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
					cin >> newlockedRoomiD;
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
					cin >> newroomiD;
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
			Room room;
			cin >> room.roomiD >> room.categoryiD >> room.num >> room.beds;
			rooms.push_back(room);
		}
		if (key == 'd') {
			cout << "|   ������� ��� ���������� ��������� ������ :                          |" << endl;
			cout << "|______________________________________________________________________|" << endl;
			int searchiD;
			cout << ": ";
			cin >> searchiD;
			for (int i = 0; i != lockedRooms.size(); i++) {
				if (lockedRooms[i].lockedRoomiD == searchiD) {
					lockedRooms.erase(lockedRooms.begin() + i);
				}
			}
		}
	}
	Save();
}

//��������� �������
void editCategory() {
	/*int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ___________________________" << endl;
		cout << "|     ��������� �������     |" << endl;
		cout << "|___________________________|" << endl;
		cout << "|   ���     |    ��������   |" << endl;
		cout << "| ��������� |   ���������   |" << endl;
		cout << "|___________________________|" << endl;
		cout << "|                           |" << endl;
		for (int i = 0; i != �ategories.size(); i++)
			printf("| %4d      | %12s  |\n", �ategories[i].categoryiD, �ategories[i].category_name.c_str());
		cout << "|                           |" << endl;
		cout << "|___________________________|" << endl;
		cout << "|                           |" << endl;
		cout << "|   e: �������������        |" << endl;
		cout << "|   a: ��������             |" << endl;
		cout << "|   d: �������              |" << endl;
		cout << "|   0: �����                |" << endl;
		cout << "|___________________________|" << endl;
		key = _getch();
		if (key == 'e'){
			cout << "|   ������� ��� ���������� :                                           |" << endl;
			cout << "|______________________________________________________________________|" << endl;
			int searchiD;
			cout << ": ";
			cin >> searchiD;
			for (int i = 0; i != lockedRooms.size(); i++) {
				if (lockedRooms[i].lockedRoomiD == searchiD) {
					if (key == 'e') {
						cout << " ______________________________________________________________________ " << endl;
						printf("|  %5d     | %5d      | %4d   |  %10s    |    %10s    |\n", lockedRooms[i].lockedRoomiD, lockedRooms[i].personiD, lockedRooms[i].roomiD, lockedRooms[i].star.c_str(), lockedRooms[i].finis.c_str());
						cout << "|______________________________________________________________________|" << endl;
						cout << "|   ������� ��� ����������:                                            |" << endl;
						cout << "|______________________________________________________________________|" << endl;
						cout << ": ";
						int newlockedRoomiD;
						cin >> newlockedRoomiD;
						lockedRooms[i].lockedRoomiD = newlockedRoomiD;
						cout << "|______________________________________________________________________|" << endl;
						cout << "|   ������� ��� ����������:                                            |" << endl;
						cout << "|______________________________________________________________________|" << endl;
						cout << ": ";
						int newpersoniD;
						cin >> newpersoniD;
						lockedRooms[i].personiD = newpersoniD;

					}
				}
			}
			if (key == 'd') {
			cout << "|  ������� ��� ���������    |" << endl;
			cout << "|    ��������� ������ :     |" << endl;
			cout << "|___________________________|" << endl;
			int searchiD;
			cout << ": ";
			cin >> searchiD;
			for (int i = 0; i != categories.size(); i++) {
				if (categories[i].categoryiD == searchiD) {
					categories.erase(categories.begin() + i);
				}
			}
		}
		}
	}*/
	Save();
}

//���������� � �����������
void editPerson() {
	/*int key = 1;
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
			printf("| %4d       | %30s   | %12s |\n", persons[i].personiD, persons[i].Fio.c_str(), persons[i].passport.c_str());
		cout << "|                                                               |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|                                                               |" << endl;
		cout << "|   0: �����      e: �������������   	        a: ��������      |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		key = _getch();
		if (key == 'e') {
			cout << "|   ������� ��� ���������� :                                           |" << endl;
			cout << "|______________________________________________________________________|" << endl;
			int searchiD;
			cout << ": ";
			cin >> searchiD;
			for (int i = 0; i != lockedRooms.size(); i++) {
				if (lockedRooms[i].lockedRoomiD == searchiD) {
					cout << " ______________________________________________________________________ " << endl;
					printf("|  %5d     | %5d      | %4d   |  %10s    |    %10s    |\n", lockedRooms[i].lockedRoomiD, lockedRooms[i].personiD, lockedRooms[i].roomiD, lockedRooms[i].star.c_str(), lockedRooms[i].finis.c_str());
					cout << "|______________________________________________________________________|" << endl;
					cout << "|   ������� ��� ����������:                                            |" << endl;
					cout << "|______________________________________________________________________|" << endl;
					cout << ": ";
					int newlockedRoomiD;
					cin >> newlockedRoomiD;
					lockedRooms[i].lockedRoomiD = newlockedRoomiD;
					cout << "|______________________________________________________________________|" << endl;
					cout << "|   ������� ��� ����������:                                            |" << endl;
					cout << "|______________________________________________________________________|" << endl;
					cout << ": ";
					int newpersoniD;
					cin >> newpersoniD;
					lockedRooms[i].personiD = newpersoniD;
					cout << "|______________________________________________________________________|" << endl;
					cout << "|   ������� ��� ������:                                                |" << endl;
					cout << "|______________________________________________________________________|" << endl;
					cout << ": ";
					int newroomiD;
					cin >> newroomiD;
					lockedRooms[i].roomiD = newroomiD;
					cout << "|______________________________________________________________________|" << endl;
					cout << "|   ������� ���� ������:                                               |" << endl;
					cout << "|______________________________________________________________________|" << endl;
					cout << ": ";
					string  newstart;
					cin >> newstart;
					lockedRooms[i].star = newstart;
					cout << "|   ������� ���� ����������:                                           |" << endl;
					cout << "|______________________________________________________________________|" << endl;
					cout << ": ";
					string newfinish;
					cin >> newfinish;
					lockedRooms[i].finis = newfinish;
					cout << " ______________________________________________________________________ " << endl;
					cout << "|   �������������� ���������:                                            |" << endl;
					cout << "|______________________________________________________________________|" << endl;
					printf("|  %5d     | %5d      | %4d   |  %10s    |    %10s    |\n", lockedRooms[i].lockedRoomiD, lockedRooms[i].personiD, lockedRooms[i].roomiD, lockedRooms[i].star.c_str(), lockedRooms[i].finis.c_str());
					cout << "|______________________________________________________________________|" << endl;
				}
			}
	}*/
	Save();
}