/*
Станции(код станции, название станции)
*/

#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Station 
{
public:
	struct station
	{
		int codeS; //код станции
    	string name;//название
	};
	vector <station> vs;
	station s;
	string File;
	Station(string F); //конструктор   
};
