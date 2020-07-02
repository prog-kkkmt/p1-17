#pragma once
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
/*
Каждый автобус вмещает не более определенного количества пассажиров
Таблицы: 
станции (код станции, название станции), 
автобусы (код автобуса, марка автобуса, государственный номер, вместимость),
рейсы (код рейса, код станции, код автобуса, время отправления).
*/
//пространство имен std
using namespace std;
//класс автобусов
class buses
{
public:
	struct bus //автобус (код автобуса, марка автобуса, государственный номер, вместимость)
	{
		int bus_ID;
		string bus_brand;
		string bus_number;
		int bus_capacity;
	};
	vector<bus>list_bus;
	void load();//загрузка списка автобусов
	void total_capacity();//вывод общего количества пассажиров
};

class stations
{
public:
	struct station //станции (код станции, название станции)
	{
		int station_ID;
		string station_name;
	};
	vector<station>list_station;
	void load();//загрузка списка станций
};

class voyages
{
public:
	struct voyage //рейсы (код рейса, код станции, код автобуса, время отправления).
	{
		int voyage_ID;
		int station_ID;
		int bus_ID;
		string departure_time;
	};
	vector<voyage>list_voyage;
	void load();//загрузка списка рейсов
};
 
