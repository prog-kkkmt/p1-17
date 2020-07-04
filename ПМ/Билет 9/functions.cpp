#include "classes.hpp"
#include "structors.hpp"

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

PSL::PSL()
{
    string temp;
    fstream f("Уровень владения ПК.txt");
    if (!f.is_open())
    {
        cout << "Ошибка открытия файла";
    }
    cout << "Файл открыт";
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
    string temp;
    fstream f("Образование.txt");
    if (!f.is_open())
    {
        cout << "Ошибка открытия файла";
    }
    cout << "Файл открыт";
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
    string temp;
    fstream f("Должность.txt");
    if (!f.is_open())
    {
        cout << "Ошибка открытия файла";
    }
    cout << "Файл открыт";
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
    string temp;
    fstream f("Профессия.txt");
    if (!f.is_open())
    {
        cout << "Ошибка открытия файла";
    }
    cout << "Файл открыт";
    while (!f.eof())
    {
        pro_str++;
        getline(f, temp);
    }
    f.clear();
    f.seekg(0);
    ptr_1 = new prostr[prof_str];
    for (int i = 0; i < prof_str; i++)
        f >> ptr_1[i].pro_code >> ptr_4[i].pro;
}

Vac::Vac()
{
    string temp;
    fstream f("Вакансии.txt");
    if (!f.is_open())
    {
        cout << "Ошибка открытия файла";
    }
    cout << "Файл открыт";
    while (!f.eof())
    {
        psl_str++;
        getline(f, temp);
    }
    f.clear();
    f.seekg(0);
    ptr_3 = new vacstr[vac_str];
    for (int i = 0; i < vac_str; i++)
        f >> ptr_3[i].vac_code >> ptr_3[i].date >> ptr_3[i].vac_pos >> ptr_3[i].salary 
          >> ptr_3[i].actuality >> ptr_3[i].vac_pro_code >> ptr_3[i].vac_edu_code >> ptr_3[i].vac_psl_code;
}