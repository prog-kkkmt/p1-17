#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class buses
{
public:
	int bus_ID; //id
	string bus_brand; //марка
	string bus_number; // госномер
	int bus_capacity; // вместимость
	void input();
	void total_capacity();
};

class stations
{
public:
	int station_ID; // id станции
	string station_name; // наименование 
	void input();
};

class cruises
{
public:
	int cruise_ID; // id рейса
	int station_ID; // id станции
	int bus_ID; //id автобуса
	string departure_time; // время отправления
	void input();
};
