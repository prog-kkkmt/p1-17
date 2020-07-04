#include <iostream>
#include <locale>
#include "classes.hpp"


using namespace std;

PSL::PSL()
{
	setlocale(LC_ALL, "Russian");
    string temp;
    fstream f("Уровень владения ПК.txt");
    if (!f.is_open())
    {
        cout << "Файл не может быть открыт" << endl;
    }
    cout << "Файл открыт" << endl;
    while (!f.eof())
    {
        psl_str++;
        getline(f, temp);
    }
    f.clear();
    f.seekg(0);
    ptr_4 = new pslstr[psl_str];
    for (int i = 0; i < psl_str; i++)
        f >> ptr_4[i].psl_code >> ptr_4[i].level;
}

Edu::Edu()
{
	setlocale(LC_ALL, "Russian");
    string temp;
    fstream f("Образование.txt");
    if (!f.is_open())
    {
        cout << "Файл не может быть открыт" << endl;
    }
    cout << "Файл открыт" << endl;
    while (!f.eof())
    {
        edu_str++;
        getline(f, temp);
    }
    f.clear();
    f.seekg(0);
    ptr_5 = new edustr[edu_str];
    for (int i = 0; i < edu_str; i++)
        f >> ptr_5[i].edu_code >> ptr_5[i].edu;
}

Pos::Pos()
{
	setlocale(LC_ALL, "Russian");
    string temp;
    fstream f("Должность.txt");
    if (!f.is_open())
    {
        cout << "Файл не может быть открыт" << endl;
    }
    cout << "Файл открыт" << endl;
    while (!f.eof())
    {
        pos_str++;
        getline(f, temp);
    }
    f.clear();
    f.seekg(0);
    ptr_2 = new posstr[pos_str];
    for (int i = 0; i < pos_str; i++)
        f >> ptr_2[i].pos_code >> ptr_2[i].name;
}

Prof::Prof()
{
	setlocale(LC_ALL, "Russian");
    string temp;
    fstream f("Профессия.txt");
    if (!f.is_open())
    {
        cout << "Файл не может быть открыт" << endl;
    }
    cout << "Файл открыт" << endl;
    while (!f.eof())
    {
        prof_str++;
        getline(f, temp);
    }
    f.clear();
    f.seekg(0);
    ptr_1 = new prostr[prof_str];
    for (int i = 0; i < prof_str; i++)
        f >> ptr_1[i].pro_code >> ptr_1[i].pro;
}

Vac::Vac()
{
	setlocale(LC_ALL, "Russian");
    string temp;
    fstream f("Вакансия.txt");
    if (!f.is_open())
    {
        cout << "Файл не может быть открыт" << endl;
    }
    cout << "Файл открыт" << endl;
    while (!f.eof())
    {
        vac_str++;
        getline(f, temp);
    }
    f.clear();
    f.seekg(0);
    ptr_3 = new vacstr[vac_str];
    for (int i = 0; i < vac_str; i++)
        f >> ptr_3[i].vac_code >> ptr_3[i].date >> ptr_3[i].vac_pos >> ptr_3[i].salary 
          >> ptr_3[i].actuality >> ptr_3[i].vac_pro_code >> ptr_3[i].vac_edu_code >> ptr_3[i].vac_psl_code;
}

void Menu::menu()
{
    cout << "1)Актуальные вакансии\n";
    cout << "2)Оклады по уровню владения ПК\n";
    cout << "3)Выход\n";
    cout << "\n";
    cout << "Выберете пункт меню: ";
}

//???????? ????? ?????? ???????? ????

int Menu::select_num(int n)
{
    int input;
    string s;
    getline(cin, s);
    while (sscanf(s.c_str(), "%d", &input) != 1 || input < 1 || input > n)
    {
        cout << "Неизвестная команда, повторите ввод: ";
        getline(cin, s);
    }
    return input;
}

//??????? ???????

void Menu::clear()
{
    static const int LINE_COUNT = 200;
    for (int i = 0; i < LINE_COUNT; i++)
        cout << "\n";
}

void Vac :: print_act_vac()
{
	int i = 0;
	for (int i = 0; i < vac_str; i++)
	{
		if (ptr_3[i].actuality == "open")
			cout << ptr_3[i].vac_pos << endl;
	}
}

void Vac :: print_sred_oklad()
{
	int i = 0;
	for (int i = 0; i < vac_str; i++)
	cout << ptr_3[i].salary << " " << ptr_3[i].vac_psl_code << endl;
}

int main()
{
    //?????????????? ??? ??????? ???? ???????
    Menu cmd;
    Vac v;
    setlocale(LC_ALL, "Russian");
    cmd.menu();
    int input;
    //??????? ?????????? ???? ??? ?????? case
    do
    {
        input = cmd.select_num(3);

        switch (input)
        {
        case 1:
        	v.print_act_vac();
            break;
        case 2:
        	v.print_sred_oklad();
            break;
        }
        if (input != 3)
            cout << endl;
    } while (input != 3);
    cout << "Конец работы программы";
    return 0;
}
