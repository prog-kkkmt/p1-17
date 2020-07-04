#include "header.h"
vector <Client> clients;
vector <Proizv> proizvs;
vector <Vidtex> vidtexs;
vector <Remont> remonts;
vector<Category> categories;


//Считывание из файлов 
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
	cout << "|         Гарантийная мастерская          |" << endl;
	cout << "|             бытовой техники             |" << endl;
	cout << "|_________________________________________|" << endl;
	cout << "|                                         |" << endl;
	cout << "|   1: Вывести список                     |" << endl;
	cout << "|   2: Невыполненные ремонты              |" << endl;
	cout << "|   3: Сравнение                          |" << endl;
	cout << "|_________________________________________|" << endl;
	cout << "|                                         |" << endl;
	cout << "|   Esc: Выход                            |" << endl;
	cout << "|_________________________________________|" << endl << endl;
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
		case '2'://невыполненные работы
			neremont();
			break;
		case '3'://1: сравнение 
			sravn();
			break;
		case 27:// Выход
			exit = false;
			break;
		default:
			break;
		}

	}
}

//Просмотр записей
void StructMenu(bool* exit) {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ____________________________________________ " << endl;
		cout << "|              Просмотреть записи            |" << endl;
		cout << "|____________________________________________|" << endl;
		cout << "|     1 : Список производителей              |" << endl;
		cout << "|     2 : Список по ремонту                  |" << endl;
		cout << "|     3 : Список клиентов                    |" << endl;
		cout << "|     4 : Список по виду техники             |" << endl;
		cout << "|     5 : Список по категории ремонта        |" << endl;
		cout << "|____________________________________________|" << endl;
		cout << "|                                            |" << endl;
		cout << "|     0 : Назад                              |" << endl;
		cout << "|     Esc: Выход                             |" << endl;
		cout << "|____________________________________________|" << endl << endl;

		switch ((key = _getch()))
		{
		case '1'://1: Список номеров 
			printProizv();
			break;
		case '2'://2: Занятые номера
			printRemont();
			;
			break;
		case '3'://3: Категории номеров
			printClient();
			break;
		case '4'://4: Информация о постояльцах
			printVidtex();
			break;
		case '5'://4: Информация о постояльцах
			printCategory();
			break;
		case 27:
			*exit = false;
			key = '0';
			break;
		}
	}
}
//Категории ремонтов
void printCategory() {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ____________________________" << endl;
		cout << "|     Категории ремонтов     |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|   Код     |    Название    |" << endl;
		cout << "| категории |   категории    |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|           |                |" << endl;
		for (int i = 0; i != categories.size(); i++)
			printf("| %4d      | %14s |\n", categories[i].categoryiD, categories[i].category_name);
		cout << "|           |                |" << endl;
		cout << "|____________________________|" << endl;
		cout << "|                            |" << endl;
		cout << "|   0: Назад                 |" << endl;
		cout << "|____________________________|" << endl;
		key = _getch();
	}
}

// Список производителей
void printProizv() {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ________________________________" << endl;
		cout << "|      Список производителей:    |" << endl;
		cout << "|________________________________|" << endl;
		cout << "| Код           | Название       |" << endl;
		cout << "| производителя | производителя  |" << endl;
		cout << "|________________________________|" << endl;
		for (int i = 0; i != proizvs.size(); i++)
			printf("| %4d          | %10s     |\n", proizvs[i].code, proizvs[i].nname);
		cout << "|    0: Назад                    |" << endl;
		cout << "|________________________________|" << endl;
		key = _getch();
	}
}

//Ремонт
void printRemont() {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << "|                                        Ремонт                                                         |" << endl;
		cout << "|_______________________________________________________________________________________________________|" << endl;
		cout << "|    Код     |    Код     |  Код   |   Код       |   Название     |       Дата       |      Дата        |" << endl;
		cout << "|  ремонта   |  клиента   |  произ |   категории |   техники      |    обращения     |    исполнения    |" << endl;
		cout << "|_______________________________________________________________________________________________________|" << endl;
		cout << "|                                                                                                       |" << endl;
		for (int i = 0; i != remonts.size(); i++) {
			printf("|  %5d     | %5d      | %4d   |       %3d   |  %10s    |", remonts[i].coderem, remonts[i].codekl, remonts[i].codevidt, remonts[i].categoryiD, remonts[i].nametx.c_str());
			cout << "     " << remonts[i].star.finish_day << "." << remonts[i].star.finish_mouth << "." << remonts[i].star.finish_year << "    |     " << remonts[i].finis.finish_day << "." << remonts[i].finis.finish_mouth << "." << remonts[i].finis.finish_year << "    |" << endl;
		}
		cout << "|            |            |        |             |                |                  |                  |" << endl;
		cout << "|_______________________________________________________________________________________________________|" << endl;
		cout << "|   0: Назад                                                                                            |" << endl;
		cout << "|_______________________________________________________________________________________________________|" << endl;
		key = _getch();
	}
}

//Список клиентов
void printClient() {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " ___________________________________________________________" << endl;
		cout << "|                     Список клиентов                       |" << endl;
		cout << "|___________________________________________________________|" << endl;
		cout << "|   Код     |             Фио             |       Адрес     |" << endl;
		cout << "|  клиента  |                             |                 |" << endl;
		cout << "|___________|_____________________________|_________________|" << endl;
		for (int i = 0; i != clients.size(); i++)
			printf("| %4d      |  %24s   |  %14s |\n", clients[i].code, clients[i].Fio, clients[i].gorod);
		cout << "|___________________________________________________________|" << endl;
		cout << "|                                                           |" << endl;
		cout << "|   0: Назад                                                |" << endl;
		cout << "|___________________________________________________________|" << endl;
		key = _getch();
	}
}

//Информация о постояльцах
void printVidtex() {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << "|_______________________________________|" << endl;
		cout << "|                Вид техники            |" << endl;
		cout << "|_______________________________________|" << endl;
		cout << "|    Код     |          Название        |" << endl;
		cout << "|   техники  |          техники         |" << endl;
		cout << "|_______________________________________|" << endl;
		cout << "|            |                          |" << endl;
		for (int i = 0; i != vidtexs.size(); i++)
			printf("|  %4d      |     %15s      |\n", vidtexs[i].code, vidtexs[i].vid);
		cout << "|                                       |" << endl;
		cout << "|_______________________________________|" << endl;
		cout << "|                                       |" << endl;
		cout << "|   0: Назад                            |" << endl;
		cout << "|_______________________________________|" << endl;
		key = _getch();
	}
}

//Невыполненные ремонты
void neremont() {
	int d;
	int m;
	int y;
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " _______________________________________________________________ " << endl;
		cout << "|   Введите дату на проверку ремонтов(dd mm yy):                |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cin >> d >> m >> y;
		system("cls");
		cout << "|                                    Невыполненные ремонты                                              |" << endl;
		cout << "|_______________________________________________________________________________________________________|" << endl;
		cout << "|    Код     |    Код     |  Код   |   Код       |   Название     |       Дата       |      Дата        |" << endl;
		cout << "|  ремонта   |  клиента   |  произ |   категории |   техники      |    обращения     |    исполнения    |" << endl;
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
		cout << "|   0: Назад                                                                                            |" << endl;
		cout << "|_______________________________________________________________________________________________________|" << endl;
		key = _getch();
	}
}


//Сравнение
void sravn() {
	int key = 1;
	while (key != '0') {
		system("cls");
		cout << " _______________________________________________________________ " << endl;
		cout << "|              Таблицы количества сложных ремонтов              |" << endl;
		cout << "|                 по разным производителям                      |" << endl;
		cout << "|_______________________________________________________________|" << endl;
		cout << "|                  Категории ремонтов:                          |" << endl;
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
		cout << "| Коды производитилей:|  Название производитилей:| Кол-во сложных ремонтов |" << endl;
		cout << "|_____________________|__________________________|_________________________|" << endl;
		for (int j = 0; j != proizvs.size(); j++)
			printf("| %4d                |  %10s              |          %5d          |\n", proizvs[j].code, proizvs[j].nname, proizvs[j].schet);
		cout << "|__________________________________________________________________________| " << endl;
		cout << "|    0: Назад                                                              |" << endl;
		cout << "|__________________________________________________________________________|" << endl;
		key = _getch();
	}
}