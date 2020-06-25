/*
Автобус(код автобуса, марка автобуса, гос номер, вместимость)
*/

#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Bus 
{
public:
	struct bus
	{
		int codeB; //код автобуса
    	string model; //марка автобуса
    	int number; //гос номер
    	int bulk; //вместимость
	};
	vector <bus> vb;
	bus b;
	string File;
	Bus(string F); //конструктор    
};
