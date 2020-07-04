#include "busclass.h"

vector<Buses>list_bus;
vector<Cruises>list_cruise;
vector<Stations>list_station;

//методы класса buses
void Buses :: input() //загрузка данных из файла
{
	//открываем на чтение файл
	ifstream file("buses.txt");
	//проверяем открыт ли он
	if (file.is_open())
	{
		while (!file.eof())
		{
			Buses bus;
			file >> bus.bus_ID;
			file >> bus.bus_brand;
			file >> bus.bus_number;
			file >> bus.bus_capacity;
			list_bus.push_back(bus);
		}
		//закрываем файл
		file.close();
	}
}

//методы класса buses
int Buses :: total_capacity() //подсчет общего числа пассажиров
{
	int sum = 0;
	for (int i = 0; i != list_bus.size(); i++) 
	{
		sum += list_bus[i].bus_capacity;
	}
	cout << "Number of passengers " << sum << endl;
}

//методы класса stations
void Stations :: input()
{
	//открываем на чтение файл
	ifstream file("stations.txt");
	//проверяем открыт ли он
	if (file.is_open()) 
	{
		while (!file.eof()) 
		{
			Stations station;
			file >> station.station_ID;
			file >> station.station_name;
			list_station.push_back(station);
		}
		//закрываем файл
		file.close();
	}
}

//методы класса cruises
void Cruises :: input()
{
	//открываем на чтение файл
	ifstream file("cruise.txt");
	//проверяем открыт ли он
	if (file.is_open()) 
	{
		while (!file.eof()) 
		{
			Cruises cruise;
			file >> cruise.cruise_ID;
			file >> cruise.station_ID;
			file >> cruise.bus_ID;
			file >> cruise.departure_time;
			list_cruise.push_back(cruise);
		}
		//закрываем файл
		file.close();
	}
}

//функция подсчета общего числа рейсов по станциям
void total_cruises(Stations stations, Cruises cruises) 
{
	for (int i = 0; i != list_station.size(); i++)
	{
		int sum = 0;
		for (int j = 0; j != list_cruise.size(); j++)
		{
			if (list_station[i].station_ID == list_cruise[j].station_ID)
			{
				sum++;
			}
		}
		cout << "Total cruises " << sum << " to the station: " << list_station[i].station_name << endl;
	}
}

int main()
{
	//инициализируем списки
	Buses buses;
	buses.input();
	Cruises cruises;
	cruises.input();
	Stations stations;
	stations.input();
	//колво пассажиров
	buses.total_capacity();
	//колво рейсов
	total_cruises(stations, cruises);
	return 0;
}


