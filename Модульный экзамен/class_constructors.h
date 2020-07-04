#ifndef CLASS_CONSTRUCTORS_H_INCLUDED
#define CLASS_CONSTRUCTORS_H_INCLUDED

#include <iostream>
#include <fstream>

using namespace std;

struct tarif_str
{
	string code_tarifa;
	int min_rast, max_rast, cena;
};
struct goroda_str
{
	string code_goroda, code_tarifa;
	int rast;
};
struct razgovor_str
{
	string code_razgovora, code_goroda,start,prodolsh;
};
class tarif
{
	public:
		tarif()
		{
			setlocale(0, "");
			fstream f("tarif.txt");
			if(!f.is_open())
                {
				cout << "Файл не открыт";
                }
			while(!f.eof())
			{
				kol_tarif++;
				f >> m_tarif[kol_tarif-1].code_tarifa >> m_tarif[kol_tarif-1].min_rast >> m_tarif[kol_tarif-1].max_rast >> m_tarif[kol_tarif-1].cena; ///чтение строк в файле
			}
		}
		int kol_tarif = 0;
        tarif_str m_tarif[100]; ///массив для 100 элементов
};
class goroda
{
	public:
		goroda()
		{
			setlocale(0, "");
			fstream f("goroda.txt");
			if(!f.is_open())
                {
				cout << "Файл не открыт";
                }
			while(!f.eof())
			{
				kol_goroda++;
				f >> m_goroda[kol_goroda-1].code_goroda >> m_goroda[kol_goroda-1].rast >> m_goroda[kol_goroda-1].code_tarifa;
			}
		}
		 void dolya();
		tarif tar;
		int kol_goroda = 0;
        goroda_str m_goroda[100];
};

class razgovor
{
	public:
		razgovor()
		{
			setlocale(0, "");
			fstream f("razgovor.txt");
			if(!f.is_open())
                {
				cout << "Файл не открыт";
                }
			while(!f.eof())
			{
				kol_razgovor++;
				f >> m_razgovor[kol_razgovor-1].code_razgovora >> m_razgovor[kol_razgovor-1].code_goroda >> m_razgovor[kol_razgovor-1].start >> m_razgovor[kol_razgovor-1].prodolsh;
			}
		}
        void sort_razgovor();
		int kol_razgovor = 0;
        razgovor_str m_razgovor[100];
};
#endif // CLASS_CONSTRUCTORS_H_INCLUDED
