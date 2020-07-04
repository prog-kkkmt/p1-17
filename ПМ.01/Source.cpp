#include "header.h"
vector <Client> clients;
vector <Proizv> proizvs;
vector <Vidtex> vidtexs;
vector <Remont> remonts;
vector<Category> categories;


//���������� �� ������ 
void Initialization() {
	string poof;
	string str;
	string namet;
	string stars;
	string finiss;
	ifstream f1("klients.txt");
	ifstream f2("proizv.txt");
	ifstream f3("vidtexn.txt");
	ifstream f4("remont.txt");
	ifstream f5("category.txt");
	if (f1.is_open()) {
		while (!f1.eof()) {
			Client clienty;
			f1 >> clienty.code;
			getline(f1, poof, ' ');
			getline(f1, str);
			clienty.lenFio = str.copy(clienty.Fio, str.size());
			clienty.Fio[clienty.lenFio] = '\0';
			getline(f1, poof, ' ');
			getline(f1, poof, ' ');
			getline(f1, str);
			clienty.lengorod = str.copy(clienty.gorod, str.size());
			clienty.gorod[clienty.lengorod] = '\0';
			clients.push_back(clienty);
		}
		f1.close();
	}


	if (f2.is_open()) {
		while (!f2.eof()) {
			Proizv proizv;
			f2 >> proizv.code;
			getline(f2, str);
			proizv.lenname = str.copy(proizv.nname, str.size());
			proizv.nname[proizv.lenname] = '\0';
			proizvs.push_back(proizv);
		}
		f2.close();
	}


	if (f3.is_open()) {
		while (!f3.eof()) {
			Vidtex vidtex;
			f3 >> vidtex.code;
			getline(f3, str);
			vidtex.lenvid = str.copy(vidtex.vid, str.size());
			vidtex.vid[vidtex.lenvid] = '\0';
			vidtexs.push_back(vidtex);
		}
		f3.close();
	}

	if (f4.is_open()) {
		while (!f4.eof()) {
			Remont remont;
			f4 >> remont.coderem >> remont.codekl >> remont.codevidt >> remont.categoryiD;
			getline(f4, poof, ' ');
			getline(f4, namet, ':');
			remont.nametx = namet;
			f4 >> remont.star.finish_day;
			getline(f4, poof, '.');
			f4 >> remont.star.finish_mouth;
			getline(f4, poof, '.');
			f4 >> remont.star.finish_year;
			f4 >> remont.finis.finish_day;
			getline(f4, poof, '.');
			f4 >> remont.finis.finish_mouth;
			getline(f4, poof, '.');
			f4 >> remont.finis.finish_year;
			remonts.push_back(remont);
		}
		f4.close();
	}
	if (f5.is_open()) {
		while (!f5.eof()) {
			Category category;
			f5 >> category.categoryiD;
			getline(f5, poof, ' ');
			getline(f5, str);
			category.lencategory_name = str.copy(category.category_name, str.size());
			category.category_name[category.lencategory_name] = '\0';
			categories.push_back(category);
		}

		f5.close();
	}
}



void printDefaultMenu()
{
	system("cls");
	cout << " _________________________________________ " << endl;
	cout << "|         ����������� ����������          |" << endl;
	cout << "|             ������� �������             |" << endl;
	cout << "|_________________________________________|" << endl;
	cout << "|                                         |" << endl;
	cout << "|   1: ������� ������                     |" << endl;
	cout << "|   2: ������������� �������              |" << endl;
	cout << "|   3: ���������                          |" << endl;
	cout << "|_________________________________________|" << endl;
	cout << "|                                         |" << endl;
	cout << "|   Esc: �����                            |" << endl;
	cout << "|_________________________________________|" << endl << endl;
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
		case '2'://������������� ������
			neremont();
			break;
		case '3'://1: ��������� 
			sravn();
			break;
		case 27:// �����
			exit = false;
			break;
		default:
			break;
		}

	}
}

//�������� �������
void StructMenu(bool* exit) {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ____________________________________________ " << endl;
		cout << "|              ����������� ������            |" << endl;
		cout << "|____________________________________________|" << endl;
		cout << "|     1 : ������ ��������������              |" << endl;
		cout << "|     2 : ������ �� �������                  |" << endl;
		cout << "|     3 : ������ ��������                    |" << endl;
		cout << "|     4 : ������ �� ���� �������             |" << endl;
		cout << "|     5 : ������ �� ��������� �������        |" << endl;
		cout << "|____________________________________________|" << endl;
		cout << "|                                            |" << endl;
		cout << "|     0 : �����                              |" << endl;
		cout << "|     Esc: �����                             |" << endl;
		cout << "|____________________________________________|" << endl << endl;

		switch ((key = _getch()))
		{
		case '1'://1: ������ ������� 
			printProizv();
			break;
		case '2'://2: ������� ������
			printRemont();
			;
			break;
		case '3'://3: ��������� �������
			printClient();
			break;
		case '4'://4: ���������� � �����������
			printVidtex();
			break;
		case '5'://4: ���������� � �����������
			printCategory();
			break;
		case 27:
			*exit = false;
			key = '0';
			break;
		}
	}
}
//��������� ��������
void printCategory() {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ____________________________" << endl;
		cout << "|     ��������� ��������     |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|   ���     |    ��������    |" << endl;
		cout << "| ��������� |   ���������    |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|           |                |" << endl;
		for (int i = 0; i != categories.size(); i++)
			printf("| %4d      | %14s |\n", categories[i].categoryiD, categories[i].category_name);
		cout << "|           |                |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|                            |" << endl;
		cout << "|   0: �����                 |" << endl;
		cout << "|____________________________|" << endl;
		key = _getch();
	}
}

// ������ ��������������
void printProizv() {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ________________________________" << endl;
		cout << "|      ������ ��������������:    |" << endl;
		cout << "|________________________________|" << endl;
		cout << "| ���           | ��������       |" << endl;
		cout << "| ������������� | �������������  |" << endl;
		cout << "|________________________________|" << endl;
		for (int i = 0; i != proizvs.size(); i++)
			printf("| %4d          | %10s     |\n", proizvs[i].code, proizvs[i].nname);
		cout << "|    0: �����                    |" << endl;
		cout << "|________________________________|" << endl;
		key = _getch();
	}
}

//������
void printRemont() {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << "|                                        ������                                                         |" << endl;
		cout << "|_______________________________________________________________________________________________________|" << endl;
		cout << "|    ���     |    ���     |  ���   |   ���       |   ��������     |       ����       |      ����        |" << endl;
		cout << "|  �������   |  �������   |  ����� |   ��������� |   �������      |    ���������     |    ����������    |" << endl;
		cout << "|_______________________________________________________________________________________________________|" << endl;
		cout << "|                                                                                                       |" << endl;
		for (int i = 0; i != remonts.size(); i++) {
			printf("|  %5d     | %5d      | %4d   |       %3d   |  %10s    |", remonts[i].coderem, remonts[i].codekl, remonts[i].codevidt, remonts[i].categoryiD, remonts[i].nametx.c_str());
			cout << "     " << remonts[i].star.finish_day << "." << remonts[i].star.finish_mouth << "." << remonts[i].star.finish_year << "    |     " << remonts[i].finis.finish_day << "." << remonts[i].finis.finish_mouth << "." << remonts[i].finis.finish_year << "    |" << endl;
		}
		cout << "|            |            |        |             |                |                  |                  |" << endl;
		cout << "|_______________________________________________________________________________________________________|" << endl;
		cout << "|   0: �����                                                                                            |" << endl;
		cout << "|_______________________________________________________________________________________________________|" << endl;
		key = _getch();
	}
}

//������ ��������
void printClient() {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ___________________________________________________________" << endl;
		cout << "|                     ������ ��������                       |" << endl;
		cout << "|___________________________________________________________|" << endl;
		cout << "|   ���     |             ���             |       �����     |" << endl;
		cout << "|  �������  |                             |                 |" << endl;
		cout << "|___________|_____________________________|_________________|" << endl;
		for (int i = 0; i != clients.size(); i++)
			printf("| %4d      |  %24s   |  %14s |\n", clients[i].code, clients[i].Fio, clients[i].gorod);
		cout << "|___________________________________________________________|" << endl;
		cout << "|                                                           |" << endl;
		cout << "|   0: �����                                                |" << endl;
		cout << "|___________________________________________________________|" << endl;
		key = _getch();
	}
}

//���������� � �����������
void printVidtex() {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << "|_______________________________________|" << endl;
		cout << "|                ��� �������            |" << endl;
		cout << "|_______________________________________|" << endl;
		cout << "|    ���     |          ��������        |" << endl;
		cout << "|   �������  |          �������         |" << endl;
		cout << "|_______________________________________|" << endl;
		cout << "|            |                          |" << endl;
		for (int i = 0; i != vidtexs.size(); i++)
			printf("|  %4d      |     %15s      |\n", vidtexs[i].code, vidtexs[i].vid);
		cout << "|                                       |" << endl;
		cout << "|_______________________________________|" << endl;
		cout << "|                                       |" << endl;
		cout << "|   0: �����                            |" << endl;
		cout << "|_______________________________________|" << endl;
		key = _getch();
	}
}

//������������� �������
void neremont() {
	int d;
	int m;
	int y;
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " _______________________________________________________________ " << endl;
		cout << "|   ������� ���� �� �������� ��������(dd mm yy):                |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cin >> d >> m >> y;
		system("cls");
		cout << "|                                    ������������� �������                                              |" << endl;
		cout << "|_______________________________________________________________________________________________________|" << endl;
		cout << "|    ���     |    ���     |  ���   |   ���       |   ��������     |       ����       |      ����        |" << endl;
		cout << "|  �������   |  �������   |  ����� |   ��������� |   �������      |    ���������     |    ����������    |" << endl;
		cout << "|_______________________________________________________________________________________________________|" << endl;
		cout << "|                                                                                                       |" << endl;
		for (int i = 0; i != remonts.size(); i++) {
			if ((y < remonts[i].finis.finish_year) || ((y == remonts[i].finis.finish_year) && (m < remonts[i].finis.finish_mouth)) || ((y == remonts[i].finis.finish_year) && (m == remonts[i].finis.finish_mouth) && (d < remonts[i].finis.finish_day))) {
				printf("|  %5d     | %5d      | %4d   |       %3d   |  %10s    |", remonts[i].coderem, remonts[i].codekl, remonts[i].codevidt, remonts[i].categoryiD, remonts[i].nametx.c_str());
				cout << "     " << remonts[i].star.finish_day << "." << remonts[i].star.finish_mouth << "." << remonts[i].star.finish_year << "    |     " << remonts[i].finis.finish_day << "." << remonts[i].finis.finish_mouth << "." << remonts[i].finis.finish_year << "    |" << endl;
			}
		}
		cout << "|            |            |        |             |                |                  |                  |" << endl;
		cout << "|_______________________________________________________________________________________________________|" << endl;
		cout << "|   0: �����                                                                                            |" << endl;
		cout << "|_______________________________________________________________________________________________________|" << endl;
		key = _getch();
	}
}


//���������
void sravn() {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " _______________________________________________________________ " << endl;
		cout << "|              ������� ���������� ������� ��������              |" << endl;
		cout << "|                 �� ������ ��������������                      |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|                  ��������� ��������:                          |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		for (int i = 0; i != categories.size(); i++)
			printf("| %4d         |  %14s                                |\n", categories[i].categoryiD, categories[i].category_name);
		cout << "|______________|________________________________________________|" << endl;
		for (int j = 0; j != remonts.size(); j++) {
			if ((remonts[j].categoryiD == categories[1].categoryiD)) {
				int i = remonts[j].codevidt;
				proizvs[i - 1].schet += 1;
			}
		}
		cout << " __________________________________________________________________________" << endl;
		cout << "| ���� ��������������:|  �������� ��������������:| ���-�� ������� �������� |" << endl;
		cout << "|_____________________|__________________________|_________________________|" << endl;
		for (int j = 0; j != proizvs.size(); j++)
			printf("| %4d                |  %10s              |          %5d          |\n", proizvs[j].code, proizvs[j].nname, proizvs[j].schet);
		cout << "|__________________________________________________________________________| " << endl;
		cout << "|    0: �����                                                              |" << endl;
		cout << "|__________________________________________________________________________|" << endl;
		key = _getch();
	}
}