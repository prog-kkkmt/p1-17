#ifndef MOD_H_INCLUDED
#define MOD_H_INCLUDED
#include <iostream>
#include <locale>
#include <string>

using namespace std;


struct Pokypateli
{
    int kod_pok;
    char fio[100];
};

struct Menejer
{
    int kod_men;
    char fio[100];
};

struct Avtomobili
{
    int kod_avto;
    char marka[100];
};

struct Prodaji
{
    int kod_men, kod_avto, gos_nomer, kod_pok, cena;
    string data;
};
#endif // MOD_H_INCLUDED
