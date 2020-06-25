/*
Рейсы(код рейса, код станции, код автобуса, время прибытия)
*/

#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Trip 
{
public:
	struct trip
	{
		int codeT; //код рейса
    	int codeS; //код станции
    	int codeB; //код автобуса
    	string time; //время прибытия
	};
	vector <trip> vt;
	trip t;
	string File;
	Trip(string F); //конструктор   
};
