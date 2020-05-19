#include "data.h"
vector<Category> ñategories;
vector<Room> rooms;
vector<Person> persons;
vector<LockedRoom> lockedRooms;

//Ñ÷èòûâàíèå èç ôàéëîâ 
void Initialization() {
	string poof;

	ifstream f1("Category.txt");
	Category category;
	if (f1.is_open()) {
		while (!f1.eof()) {
			f1 >> category.categoryiD;
			getline(f1, poof, ' ');
			getline(f1, category.category_name);
			ñategories.push_back(category);
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

//çàïèñü â ôàéëû
void Save() {

	ofstream f1("Category.txt");
	
	if (f1.is_open()) {
		for (int i = 0; i != ñategories.size(); i++) {
			f1 << ñategories[i].categoryiD << " " << ñategories[i].category_name;
			if (i != ñategories.size() - 1)
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
	cout << "|        Ãîñòåâàÿ êíèãà îòåëÿ            |" << endl;
	cout << "|________________________________________|" << endl;
	cout << "|                                        |" << endl;
	cout << "|   1: Âûâîä òàáëèöû                     |" << endl;
	cout << "|   2: Ñîðòèðîâêà òàáëèöû                |" << endl;
	cout << "|   3: Ðåäàêòèðîâàíèå òàáëèöû            |" << endl;
	cout << "|________________________________________|" << endl;
	cout << "|                                        |" << endl;
	cout << "|   0: Î ïðîãðàììå                       |" << endl;
	cout << "| Esc: Âûõîä                             |" << endl;
	cout << "|________________________________________|" << endl;

}

//Ìåíþ ïðîãðàììû
void Menu() {
	Initialization();
	int key;
	bool exit = true;
	
	while (exit)
	{
		
		printDefaultMenu();
		switch ((key = _getch()))
		{
		case '1'://1: Âûâîä òàáëèöû 
			StructMenu(&exit);
			break;
		case '2'://2: Ñîðòèðîâêà òàáëèöû 
			SortMenu(&exit);
			break;
		case '3'://3: Ðåäàêòèðîâàíèå òàáëèöû
			EditMenu(&exit);
			break;
		case '0'://Î ïðîãðàììå
			About(&exit);
			break;
		case 27://âûõîä
			exit = false;
			break;
		default:
			break;
		}

	}
	Save();
}

//Ïðîñìîòð çàïèñåé
void StructMenu(bool *exit) {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ________________________________________ " << endl;
		cout << "|        Ïðîñìîòðåòü çàïèñè              |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   1: Ñïèñîê íîìåðîâ                    |" << endl;
		cout << "|   2: Çàíÿòûå íîìåðà                    |" << endl;
		cout << "|   3: Êàòåãîðèè íîìåðîâ                 |" << endl;
		cout << "|   4: Èíôîðìàöèÿ î ïîñòîÿëüöàõ          |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   0: Íàçàä                             |" << endl;
		cout << "| Esc: Âûõîä                             |" << endl;
		cout << "|________________________________________|" << endl;

		switch ((key = _getch()))
		{
		case '1'://1: Ñïèñîê íîìåðîâ 
			printRoom();
			break;
		case '2'://2: Çàíÿòûå íîìåðà 
			printLockedRoom();
			;
			break;
		case '3'://3: Êàòåãîðèè íîìåðîâ
			printCategory();
			break;
		case '4'://4: Èíôîðìàöèÿ î ïîñòîÿëüöàõ
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
		cout << "|        Ñîðòèðîâàòü çàïèñè              |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   1: Ñïèñîê íîìåðîâ                    |" << endl;
		cout << "|   2: Çàíÿòûå íîìåðà                    |" << endl;
		cout << "|   3: Êàòåãîðèè íîìåðîâ                 |" << endl;
		cout << "|   4: Èíôîðìàöèÿ î ïîñòîÿëüöàõ          |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   0: Íàçàä                             |" << endl;
		cout << "| Esc: Âûõîä                             |" << endl;
		cout << "|________________________________________|" << endl;

		switch ((key = _getch()))
		{
		case '1'://1: Ñïèñîê íîìåðîâ 
			sortRoom();
			break;
		case '2'://2: Çàíÿòûå íîìåðà 
			sortLockedRoom();
			break;
		case '3'://3: Êàòåãîðèè íîìåðîâ
			sortCategory();
			break;
		case '4'://4: Èíôîðìàöèÿ î ïîñòîÿëüöàõ
			sortPerson();
			break;
		case 27:
			*exit = false;
			key = '0';
			break;
		}
	}
}

// Ðåäàêòèðîâàíèå òàáëèöû
void EditMenu(bool *exit) {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ________________________________________ " << endl;
		cout << "|        Ðåäàêòèðîâàòü çàïèñè            |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   1: Ñïèñîê íîìåðîâ                    |" << endl;
		cout << "|   2: Çàíÿòûå íîìåðà                    |" << endl;
		cout << "|   3: Êàòåãîðèè íîìåðîâ                 |" << endl;
		cout << "|   4: Èíôîðìàöèÿ î ïîñòîÿëüöàõ          |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   0: Íàçàä                             |" << endl;
		cout << "| Esc: Âûõîä                             |" << endl;
		cout << "|________________________________________|" << endl;

		switch ((key = _getch()))
		{
		case '1'://1: Ñïèñîê íîìåðîâ 
			editRoom();
			break;
		case '2'://2: Çàíÿòûå íîìåðà 
			editLockedRoom();
			break;
		case '3'://3: Êàòåãîðèè íîìåðîâ
			editCategory();
			break;
		case '4'://4: Èíôîðìàöèÿ î ïîñòîÿëüöàõ
			editPerson();
			break;
		case 27:
			*exit = false;
			key = '0';
			break;
		}
	}

}

//Î ïðîãðàììå
void About(bool *exit) {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ________________________________________ " << endl;
		cout << "|        Î ïðîãðàììå                     |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|     Êîíñîëüíîå ïðèëîæåíèå              |" << endl;
		cout << "|     ó÷åòà  ïîñåòèòåëåé ãîñòèíèöû       |" << endl;
		cout << "|                                        |" << endl;
		cout << "|                                        |" << endl;
		cout << "|     Âåðñèÿ 1.0.1ñ                      |" << endl;
		cout << "|     Àâòîð             Çâîíàð¸â Ä.À.    |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   0: Íàçàä                             |" << endl;
		cout << "| Esc: Âûõîä                             |" << endl;
		cout << "|________________________________________|" << endl;
		if ((key = _getch()) == 27) {
			*exit = false;
			break;
		}
	}
	
}

//Ñïèñîê íîìåðîâ 
void printRoom() {
	int key = 1;
	while (key != '0') {
		system("cls");//Íîìåðà (Êîä	íîìåðà, Êîä êàòåãîðèè, íîìåð, ìåñò);
		cout << " ________________________________________ " << endl;
		cout << "|        Ñïèñîê íîìåðîâ                  |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|  Êîä   |   Êîä     |  Íîìåð   | Âñåãî  |" << endl;
		cout << "| íîìåðà | êàòåãîðèè |          |  ìåñò  |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		for (int i = 0; i != rooms.size(); i++)
			printf("| %4d   | %4d      | %5d    |  %2d    |\n", rooms[i].roomiD, rooms[i].categoryiD, rooms[i].num, rooms[i].beds);
		cout << "|        |           |          |        |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   0: Íàçàä                             |" << endl;
		cout << "|________________________________________|" << endl;
		key = _getch();
	}
}

//Çàíÿòûå íîìåðà
void printLockedRoom(){
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ______________________________________________________________________ " << endl;
		cout << "|                            Çàíÿòûå íîìåðà                            |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		cout << "|    Êîä     |    Êîä     |  Êîä   |     Äàòà       |       Ñðîê       |" << endl;
		cout << "| ðàçìåùåíèÿ | ãðàæäàíèíà | íîìåðà |    âúåçäà      |    ïðîæèâàíèÿ    |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		cout << "|                                                                      |" << endl;
		for (int i = 0; i != lockedRooms.size(); i++)
			printf("|  %5d     | %5d      | %4d   |  %10s    |    %10s    |\n", lockedRooms[i].lockedRoomiD, lockedRooms[i].personiD, lockedRooms[i].roomiD, lockedRooms[i].star.c_str(), lockedRooms[i].finis.c_str());
		cout << "|            |            |        |                |                  |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		cout << "|                                                                      |" << endl;
		cout << "|   0: Íàçàä                                                           |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		key = _getch();
	}
}

//Êàòåãîðèè íîìåðîâ
void printCategory(){
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ____________________________" << endl;
		cout << "|     Êàòåãîðèè íîìåðîâ      |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|   Êîä     |    Íàçâàíèå    |" << endl;
		cout << "| êàòåãîðèè |   êàòåãîðèè    |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|                            |" << endl;
		for (int i = 0; i != ñategories.size(); i++)		     
			printf("| %4d      | %14s |\n", ñategories[i].categoryiD, ñategories[i].category_name.c_str());
		cout << "|                            |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|                            |" << endl;
		cout << "|   0: Íàçàä                 |" << endl;
		cout << "|____________________________|" << endl;
		key = _getch();
	}
}

//Èíôîðìàöèÿ î ïîñòîÿëüöàõ
void printPerson() {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " _______________________________________________________________ " << endl;
		cout << "|                    Èíôîðìàöèÿ î ïîñòîÿëüöàõ                   |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|    Êîä     |              Ô.È.Î.              |   Ïàñïîðò     |" << endl;
		cout << "| ãðàæäàíèíà |            ãðàæäàíèíà            |  ãðàæäàíèíà   |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|                                                               |" << endl;
		for (int i = 0; i != persons.size(); i++)
			printf("| %4d       | %30s   | %13s |\n", persons[i].personiD,persons[i].Fio.c_str(),persons[i].passport.c_str());
		cout << "|                                                               |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|                                                               |" << endl;
		cout << "|   0: Íàçàä                                                    |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		key = _getch();
	}
}

void editRoom() {//+
	int key = 1;
	while (key != '0') {
		system("cls");//Íîìåðà (Êîä	íîìåðà, Êîä êàòåãîðèè, íîìåð, ìåñò);
		cout << " ________________________________________ " << endl;
		cout << "|        Ñïèñîê íîìåðîâ                  |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|  Êîä   |   Êîä     |  Íîìåð   | Âñåãî  |" << endl;
		cout << "| íîìåðà | êàòåãîðèè |          |  ìåñò  |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		for (int i = 0; i != rooms.size(); i++)
			printf("| %4d   | %4d      | %5d    |  %2d    |\n", rooms[i].roomiD, rooms[i].categoryiD, rooms[i].num, rooms[i].beds);
		cout << "|        |           |          |        |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   a: Äîáàâèòü         e: Ðåäàêòèðîâàòü |" << endl;
		cout << "|   d: Óäàëèòü                           |" << endl;
		cout << "|   0: Íàçàä                             |" << endl;
		cout << "|________________________________________|" << endl;
		key = _getch();
		if (key == 'a') {
			cout << "|   Ââåäèòå íîâóþ çàïèñü   :             |" << endl;
			cout << "|________________________________________|" << endl;
			Room room;
			cin >> room.roomiD >> room.categoryiD >> room.num >> room.beds;//
			rooms.push_back(room);
		}
		if (key == 'e') {
			cout << "|   Ââåäèòå êîä íîìåðà:                  |" << endl;
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
					cout << "|   Ââåäèòå êîä íîìåðà:              |" << endl;
					cout << "|________________________________________|" << endl;
					cout << ": ";
					int newRoomiD;
					newRoomiD = getInt();
					rooms[i].roomiD = newRoomiD;
	 				*/
					cout << "|________________________________________|" << endl;
					cout << "|   Ââåäèòå  êîä êàòåãîðèè:              |" << endl;
					cout << "|________________________________________|" << endl;
					cout << ": ";
					int newcategoryiD;
					newcategoryiD = getInt();
					rooms[i].categoryiD = newcategoryiD;
					cout << "|________________________________________|" << endl;
					cout << "|   Ââåäèòå  íîìåð:                      |" << endl;
					cout << "|________________________________________|" << endl;
					cout << ": ";
					int newnum;
					newnum = getInt();
					rooms[i].num = newnum;
					cout << "|________________________________________|" << endl;
					cout << "|   Ââåäèòå êîëè÷åñòâî ìåñò:             |" << endl;
					cout << "|________________________________________|" << endl;
					cout << ": ";
					int newbeds;
					newbeds = getInt();
					rooms[i].beds = newbeds;
				}
			}
		}
		if (key == 'd') {
			cout << "|   Ââåäèòå êîä íîìåðà óäàëÿåìîé çàïèñè: |" << endl;
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

//Çàíÿòûå íîìåðà
void editLockedRoom() {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ______________________________________________________________________ " << endl;
		cout << "|                            Çàíÿòûå íîìåðà                            |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		cout << "|    Êîä     |    Êîä     |  Êîä   |     Äàòà       |       Ñðîê       |" << endl;
		cout << "| ðàçìåùåíèÿ | ãðàæäàíèíà | íîìåðà |    âúåçäà      |    ïðîæèâàíèÿ    |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		cout << "|                                                                      |" << endl;
		for (int i = 0; i != lockedRooms.size(); i++)
			printf("|  %5d     | %5d      | %4d   |  %10s    |    %10s    |\n", lockedRooms[i].lockedRoomiD, lockedRooms[i].personiD, lockedRooms[i].roomiD, lockedRooms[i].star.c_str(), lockedRooms[i].finis.c_str());
		cout << "|            |            |        |                |                  |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		cout << "|                                                                      |" << endl;
		cout << "|   d: Óäàëèòü           e: Ðåäàêòèðîâàòü               a: Äîáàâèòü    |" << endl;
		cout << "|   0: Íàçàä                                                           |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		key = _getch();
		if (key == 'e') {
			cout << "|   Ââåäèòå êîä ðàçìåùåíèÿ :                                           |" << endl;
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
					cout << "|   Ââåäèòå íîâûé êîä ðàçìåùåíèÿ:                                      |" << endl;
					cout << "|______________________________________________________________________|" << endl;
					cout << ": ";
					int newlockedRoomiD;
					newlockedRoomiD = getInt();
					lockedRooms[i].lockedRoomiD = newlockedRoomiD;
					*/
					cout << "|______________________________________________________________________|" << endl;
					cout << "|   Ââåäèòå íîâûé êîä ãðàæäàíèíà:                                      |" << endl;
					cout << "|______________________________________________________________________|" << endl;
					cout << ": ";
					int newpersoniD;
					cin >> newpersoniD;

					lockedRooms[i].personiD = newpersoniD;
					cout << "|______________________________________________________________________|" << endl;
					cout << "|   Ââåäèòå íîâûé êîä íîìåðà:                                          |" << endl;
					cout << "|______________________________________________________________________|" << endl;
					cout << ": ";
					int newroomiD;
					newroomiD = getInt();
					lockedRooms[i].roomiD = newroomiD;
					cout << "|______________________________________________________________________|" << endl;
					cout << "|   Ââåäèòå íîâóþ äàòó âúåçäà:                                         |" << endl;
					cout << "|______________________________________________________________________|" << endl;
					cout << ": ";
					string  newstart;
					cin >> newstart;
					lockedRooms[i].star = newstart;
					cout << "|   Ââåäèòå íîâûé ñðîê ïðîæèâàíèÿ:                                     |" << endl;
					cout << "|______________________________________________________________________|" << endl;
					cout << ": ";
					string newfinish;
					cin >> newfinish;
					lockedRooms[i].finis = newfinish;
				}
			}
			
		}
		if (key == 'a') {
			cout << "|   Ââåäèòå íîâóþ çàïèñü   :                                           |" << endl;
			cout << "|______________________________________________________________________|" << endl;
			LockedRoom lockedRoom; 
			lockedRoom.personiD = getInt();
			lockedRoom.roomiD = getInt();
			cin >> lockedRoom.star >> lockedRoom.finis;
			lockedRooms.push_back(lockedRoom);
		}
		if (key == 'd') {
			cout << "|   Ââåäèòå êîä ðàçìåùåíèÿ óäàëÿåìîé çàïèñè :                          |" << endl;
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

//Êàòåãîðèè íîìåðîâ
void editCategory() {
	int key = 1;
	 while (key != '0') {
		system("cls");
		cout << " ____________________________" << endl;
		cout << "|     Êàòåãîðèè íîìåðîâ      |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|   Êîä     |    Íàçâàíèå    |" << endl;
		cout << "| êàòåãîðèè |   êàòåãîðèè    |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|                            |" << endl;
		for (int i = 0; i != ñategories.size(); i++)
			printf("| %4d      | %14s |\n", ñategories[i].categoryiD, ñategories[i].category_name.c_str());
		cout << "|                            |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|                            |" << endl;
		cout << "|   e: Ðåäàêòèðîâàòü         |" << endl;
		cout << "|   a: Äîáàâèòü              |" << endl;
		cout << "|   d: Óäàëèòü               |" << endl;
		cout << "|   0: Íàçàä                 |" << endl;
		cout << "|____________________________|" << endl;
		key = _getch();
		if (key == 'e') {
			cout << "|   Ââåäèòå êîä êàòåãîðèè   :|" << endl;
			cout << "|____________________________|" << endl;
			int searchiD;
			cout << ": ";
			searchiD = getInt();
			for (int i = 0; i != ñategories.size(); i++) {
				if (ñategories[i].categoryiD == searchiD) {
					printf("| %4d      | %14s |\n", ñategories[i].categoryiD, ñategories[i].category_name.c_str());

					cout << "|____________________________|" << endl;
					cout << "|      Ââåäèòå íîâîå         |" << endl;
					cout << "|    íàçâàíèå êàòåãîðèè:     |" << endl;
					cout << "|____________________________|" << endl;
					cout << ": ";
					string newcategory_name;
					cin >> newcategory_name;
					ñategories[i].category_name = newcategory_name;
				}
			}

		}
		if (key == 'a') {
			cout << "|   Ââåäèòå íîâóþ çàïèñü:    |" << endl;
			cout << "|____________________________|" << endl;
			Category category;
			category.categoryiD = getInt();
			cin >> category.category_name;
			ñategories.push_back(category);
		}
		if (key == 'd') {
			cout << "|   Ââåäèòå êîä êàòåãîðèè    |" << endl;
			cout << "|     óäàëÿåìîé çàïèñè:      |" << endl;
			cout << "|____________________________|" << endl;
			int searchiD;
			cout << ": ";
			searchiD = getInt();
			for (int i = 0; i != ñategories.size(); i++) {
				if (ñategories[i].categoryiD == searchiD) {
					ñategories.erase(ñategories.begin() + i);
					break;
				}
			}
		}
	}
}

//Èíôîðìàöèÿ î ïîñòîÿëüöàõ
void editPerson() {
	int key = 1;

	while (key != '0') {
		system("cls");
		cout << " _______________________________________________________________ " << endl;
		cout << "|                    Èíôîðìàöèÿ î ïîñòîÿëüöàõ                   |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|    Êîä     |              Ô.È.Î.              |   Ïàñïîðò     |" << endl;
		cout << "| ãðàæäàíèíà |            ãðàæäàíèíà            |  ãðàæäàíèíà   |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|                                                               |" << endl;
		for (int i = 0; i != persons.size(); i++)
			printf("| %4d       | %30s   | %13s |\n", persons[i].personiD, persons[i].Fio.c_str(), persons[i].passport.c_str());
		cout << "|                                                               |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|                                                               |" << endl;
		cout << "|   d: Óäàëèòü          e: Ðåäàêòèðîâàòü          a: Äîáàâèòü   |" << endl;
		cout << "|   0: Íàçàä                                                    |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		key = _getch();
		if (key == 'e') {
			cout << "|   Ââåäèòå êîä ãðàæäàíèíà :                                    |" << endl;
			cout << "|_______________________________________________________________|" << endl;
			int searchiD;
			cout << ": ";
			searchiD = getInt();
			for (int i = 0; i != persons.size(); i++) {
				if (persons[i].personiD == searchiD) {
					cout << " _______________________________________________________________ " << endl;
					printf("| %4d       | %30s   | %12s |\n", persons[i].personiD, persons[i].Fio.c_str(), persons[i].passport.c_str());
					cout << "|_______________________________________________________________|" << endl;
					cout << "|   Ââåäèòå íîâîå Ô.È.Î ãðàæäàíèíà:                             |" << endl;
					cout << "|_______________________________________________________________|" << endl;
					cout << ": ";
					string newfio;
					cin.clear();
					cin.ignore(10000, '\n');
					getline(cin, newfio);
					persons[i].Fio = newfio;
					cout << "|_______________________________________________________________|" << endl;
					cout << "|   Ââåäèòå ïàñïîðò ãðàæäàíèíà:                                 |" << endl;
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
			cout << "|   Ââåäèòå êîä ãðàæäàíèíà :                                    |" << endl;
			cout << "|_______________________________________________________________|" << endl;
			cout << ": ";
			person.personiD = getInt();
			cout << " _______________________________________________________________ " << endl;
			cout << "|   Ââåäèòå Ô.È.Î ãðàæäàíèíà:                                   |" << endl;
			cout << "|_______________________________________________________________|" << endl;
			cout << ": ";
			cin.clear();
			cin.ignore(10000, '\n');
			getline(cin, person.Fio);
			cout << " _______________________________________________________________ " << endl;
			cout << "|   Ââåäèòå ïàñïîðò ãðàæäàíèíà:                                 |" << endl;
			cout << "|_______________________________________________________________|" << endl;
			cout << ": ";
			string passport;
			getline(cin, passport);
			person.passport = passport.insert(0, " ");//fgets(nazv_sh, sizeof(nazv_sh), stdin); nazv_sh[strlen[nazv_sh] - 1] = 0;
			persons.push_back(person);
		}
		if (key == 'd') {
			cout << "|   Ââåäèòå êîä ãðàæäàíèíà                                      |" << endl;
			cout << "|     óäàëÿåìîé çàïèñè:                                         |" << endl;
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

//ñîðòèðîâêà ñïèñêà íîìåðîâ
void sortRoom() {
	int key = 1;
	bool down = true;//ñîðòèðîâêó ñâåðõó-âíèç,èíà÷å ñíèçó-ââåðõ
	while (key != '0') {
		system("cls");//Íîìåðà (Êîä	íîìåðà, Êîä êàòåãîðèè, íîìåð, ìåñò);
		cout << " ________________________________________ " << endl;
		cout << "|        Ñîðòèðîâêà ñïèñêà íîìåðîâ       |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|  Êîä   |   Êîä     |  Íîìåð   | Âñåãî  |" << endl;
		cout << "| íîìåðà | êàòåãîðèè |          |  ìåñò  |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		for (int i = 0; i != rooms.size(); i++)
			printf("| %4d   | %4d      | %5d    |  %2d    |\n", rooms[i].roomiD, rooms[i].categoryiD, rooms[i].num, rooms[i].beds);
		cout << "|        |           |          |        |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|                                        |" << endl;
		cout << "|   Ñîðòèðîâàòü ïî:                      |" << endl;
		cout << "|   1: Ïî êîäó íîìåðà                    |" << endl;
		cout << "|   2: Ïî êîäó êàòåãîðèè                 |" << endl;
		cout << "|   3: Ïî íîìåðó                         |" << endl;
		cout << "|   4: Ïî êîëè÷åñòâó ìåñò                |" << endl;
		cout << "|   0: Íàçàä                             |" << endl;
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

//ñîðòèðîâêà ñïèñêà íîìåðîâ
void sortLockedRoom(){
	int key = 1;
	bool down = true;//ñîðòèðîâêó ñâåðõó-âíèç,èíà÷å ñíèçó-ââåðõ
	while (key != '0') {
		system("cls");
		cout << " ______________________________________________________________________ " << endl;
		cout << "|                    Ñîðòèðîâêà ñïèñêà çàíÿòûõ íîìåðîâ                 |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		cout << "|    Êîä     |    Êîä     |  Êîä   |     Äàòà       |       Ñðîê       |" << endl;
		cout << "| ðàçìåùåíèÿ | ãðàæäàíèíà | íîìåðà |    âúåçäà      |    ïðîæèâàíèÿ    |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		cout << "|                                                                      |" << endl;
		for (int i = 0; i != lockedRooms.size(); i++)
			printf("|  %5d     | %5d      | %4d   |  %10s    |    %10s    |\n", lockedRooms[i].lockedRoomiD, lockedRooms[i].personiD, lockedRooms[i].roomiD, lockedRooms[i].star.c_str(), lockedRooms[i].finis.c_str());
		cout << "|            |            |        |                |                  |" << endl;
		cout << "|______________________________________________________________________|" << endl;
		cout << "|                                                                      |" << endl;
		cout << "|   Ñîðòèðîâàòü ïî:                                                    |" << endl;
		cout << "|   1: Êîäó ðàçìåùåíèÿ                                                 |" << endl;
		cout << "|   2: Êîäó ãðàæäàíèíà                                                 |" << endl;
		cout << "|   3: Êîäó íîìåðà                                                     |" << endl;
		cout << "|   4: Äàòå âúåçäà                                                     |" << endl;
		cout << "|   5: Ñðîêó ïðîæèâàíèÿ                                                |" << endl;
		cout << "|   0: Íàçàä                                                           |" << endl;
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

//ñîðòèðîâêà ñïèñêà êàòåãîðèé íîìåðîâ
void sortCategory(){
	int key = 1;
	bool down = true;//ñîðòèðîâêó ñâåðõó-âíèç,èíà÷å ñíèçó-ââåðõ
	while (key != '0') {
		system("cls");
		cout << " ____________________________" << endl;
		cout << "|     Ñîðòèðîâêà ñïèñêà      |" << endl;
		cout << "|     êàòåãîðèé íîìåðîâ      |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|   Êîä     |    Íàçâàíèå    |" << endl;
		cout << "| êàòåãîðèè |   êàòåãîðèè    |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|                            |" << endl;
		for (int i = 0; i != ñategories.size(); i++)
			printf("| %4d      | %14s |\n", ñategories[i].categoryiD, ñategories[i].category_name.c_str());
		cout << "|                            |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|                            |" << endl;
		cout << "|   Ñîðòèðîâàòü ïî:          |" << endl;
		cout << "|   1: Êîäó                  |" << endl;
		cout << "|   2: Íàçâàíèþ              |" << endl;
		cout << "|   0: Íàçàä                 |" << endl;
		cout << "|____________________________|" << endl;
		key = _getch();
		switch (key) {
		case '1':
			if (down)
				sort(ñategories.begin(), ñategories.end(), [](const Category &p1, const Category &p2)
			{
				return p1.categoryiD > p2.categoryiD;
			});

			else
				sort(ñategories.begin(), ñategories.end(), [](const Category &p1, const Category &p2) {
				return p1.categoryiD < p2.categoryiD;
			});
			down = !down;
			break;
		case '2':
			if (down)
				sort(ñategories.begin(), ñategories.end(), [](const Category &p1, const Category &p2) {
				return p1.category_name > p2.category_name;
			});

			else
				sort(ñategories.begin(), ñategories.end(), [](const Category &p1, const Category &p2) {
				return p1.category_name < p2.category_name;
			});
			down = !down;
			break;
		}
	}
	
}

//ñîðòèðîâêà ñïèñêà ãðàæäàí
void sortPerson() {
	int key = 1;
	bool down = true;//ñîðòèðîâêó ñâåðõó-âíèç,èíà÷å ñíèçó-ââåðõ
	while (key != '0') {
		system("cls");
		cout << " _______________________________________________________________ " << endl;
		cout << "|            Ñîðòèðîâêà èíôîðìàöèè ïî ïîñòîÿëüöàì               |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|    Êîä     |              Ô.È.Î.              |   Ïàñïîðò     |" << endl;
		cout << "| ãðàæäàíèíà |            ãðàæäàíèíà            |  ãðàæäàíèíà   |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|                                                               |" << endl;
		for (int i = 0; i != persons.size(); i++)
			printf("| %4d       | %30s   | %13s |\n", persons[i].personiD, persons[i].Fio.c_str(), persons[i].passport.c_str());
		cout << "|                                                               |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|                                                               |" << endl;
		cout << "|   Ñîðòèðîâàòü ïî:                                             |" << endl;
		cout << "|   1: Êîäó ãðàæäàíèíà                                          |" << endl;
		cout << "|   2: Ô.È.Î.                                                   |" << endl;
		cout << "|   3: Ïàñïîðòó                                                 |" << endl;
		cout << "|   0: Íàçàä                                                    |" << endl;
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
		
//çàùèòà îò äóðàêà
int getInt() {//ïðîâåðêà íà êîððåêòíûé ââîä ÷èñåë
	int value;
	while (true) {
		cin >> value;
		if (cin.fail()) // åñëè ïðåäûäóùåå èçâëå÷åíèå áûëî íåóäà÷íûì,
		{
			cin.clear(); // òî âîçâðàùàåì cin â 'îáû÷íûé' ðåæèì ðàáîòû
			cout << "Ââåäèòå öåëî÷èñëåííîå ÷èñëî ïîâòîðíî : ";
			cin.ignore(32767, '\n'); // è óäàëÿåì çíà÷åíèÿ ïðåäûäóùåãî ââîäà èç âõîäíîãî áóôåðà
		}
		else
			return value;
	}
}
