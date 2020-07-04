#include <iostream>
#include <fstream>
#include "class_constructors.h"

using namespace std;

void razgovor::sort_razgovor()
{
    for(int i = 0; i < kol_razgovor-1; i++)
		for(int j = i; j < kol_razgovor-1; j++)
		{
			if(m_razgovor[i].start > m_razgovor[j].start)
				swap(m_razgovor[i], m_razgovor[j]); /// меняем элемент местами
		}
		for(int i = 0; i < kol_razgovor; i++)
			cout << m_razgovor[i].code_razgovora << " " << m_razgovor[i].code_goroda << " " << m_razgovor[i].start << " " << m_razgovor[i].prodolsh << endl;
};

void goroda::dolya()
{
 int sum = 0;
    for(int i = 0; i < tar.kol_tarif; i++)
		sum += tar.m_tarif[i].cena;
	for(int i = 0; i < kol_goroda; i++)
		for(int j = 0; j < tar.kol_tarif; j++)
			if(tar.m_tarif[j].code_tarifa == m_goroda[i].code_tarifa)
				cout << m_goroda[i].code_goroda << " - " << (float)tar.m_tarif[j].cena/(float)sum*100 << endl;

}
