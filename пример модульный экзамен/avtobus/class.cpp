#include "class.h"
//методы класса автобусы  //автобус (код автобуса, марка автобуса, государственный номер, вместимость)
void buses::load()
{
	ifstream f("buses.txt");

	if (f.is_open()) {
		while (!f.eof()) {
			bus bus;
			f >> bus.bus_ID;
			f >> bus.bus_brand;
			f >> bus.bus_number;
			f >> bus.bus_capacity;
			list_bus.push_back(bus);
		}
		f.close();
	}
}
// общее количество пассажиров 
void buses::total_capacity() {
	int sum = 0;
	for (int i = 0; i != list_bus.size(); i++) {
		sum += list_bus[i].bus_capacity;
	}
	cout << "Всего пассажиров " << sum << endl;
}

//методы класса станции //станции (код станции, название станции)
void stations::load()
{
	ifstream f("stations.txt");

	if (f.is_open()) {
		while (!f.eof()) {
			station station;
			f >> station.station_ID;
			f >> station.station_name;
			list_station.push_back(station);
		}
		f.close();
	}
}

//методы класса рейсы 

void voyages::load()
{
	ifstream f("voyages.txt");

	if (f.is_open()) {
		while (!f.eof()) {
			voyage voyage;
			f >> voyage.voyage_ID;
			f >> voyage.station_ID;
			f >> voyage.bus_ID;
			f >> voyage.departure_time;
			list_voyage.push_back(voyage);
		}
		f.close();
	}
}


