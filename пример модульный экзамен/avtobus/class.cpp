#include "class.h"
//������ ������ ��������  //������� (��� ��������, ����� ��������, ��������������� �����, �����������)
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
// ����� ���������� ���������� 
void buses::total_capacity() {
	int sum = 0;
	for (int i = 0; i != list_bus.size(); i++) {
		sum += list_bus[i].bus_capacity;
	}
	cout << "����� ���������� " << sum << endl;
}

//������ ������ ������� //������� (��� �������, �������� �������)
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

//������ ������ ����� 

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


