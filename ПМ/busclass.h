#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class buses
{
public:
	struct bus
	{
		int bus_ID;
		string bus_brand;
		string bus_number;
		int bus_capacity;
	};
	vector<bus>list_bus;
	void input();
	void total_capacity();
};

class stations
{
public:
	struct station 
	{
		int station_ID;
		string station_name;
	};
	vector<station>list_station;
	void input();
};

class cruises
{
public:
	struct cruise 
	{
		int cruise_ID;
		int station_ID;
		int bus_ID;
		string departure_time;
	};
	vector<cruise>list_cruise;
	void input();
};
