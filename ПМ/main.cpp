#include "busclass.h"

void buses :: input()
{
	ifstream file("buses.txt");

	if (file.is_open())
	{
		while (!file.eof())
		{
			bus bus;
			file >> bus.bus_ID;
			file >> bus.bus_brand;
			file >> bus.bus_number;
			file >> bus.bus_capacity;
			list_bus.push_back(bus);
		}
		file.close();
	}
}

void buses :: total_capacity() 
{
	int sum = 0;
	for (int i = 0; i != list_bus.size(); i++) 
	{
		sum += list_bus[i].bus_capacity;
	}
	cout << "Number of passengers " << sum << endl;
}

void stations :: input()
{
	ifstream file("stations.txt");

	if (file.is_open()) 
	{
		while (!file.eof()) 
		{
			station station;
			file >> station.station_ID;
			file >> station.station_name;
			list_station.push_back(station);
		}
		file.close();
	}
}

void cruises :: input()
{
	ifstream file("cruise.txt");

	if (file.is_open()) 
	{
		while (!file.eof()) 
		{
			cruise cruise;
			file >> cruise.cruise_ID;
			file >> cruise.station_ID;
			file >> cruise.bus_ID;
			file >> cruise.departure_time;
			list_cruise.push_back(cruise);
		}
		file.close();
	}
}

void total_cruises(stations stations, cruises cruises) 
{
	for (int i = 0; i != stations.list_station.size(); i++)
	{
		int sum = 0;
		for (int j = 0; j != cruises.list_cruise.size(); j++)
		{
			if (stations.list_station[i].station_ID == cruises.list_cruise[j].station_ID)
			{
				sum++;
			}
		}
		cout << "Total cruises " << sum << " to the station: " << stations.list_station[i].station_name << endl;
	}
}

int main()
{
	buses buses;
	buses.input();
	cruises cruises;
	cruises.input();
	stations stations;
	stations.input();
	buses.total_capacity();
	total_cruises(stations, cruises);
}


