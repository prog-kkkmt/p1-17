#include <locale>
#include "class.h"

void total_voyages(stations stations, voyages voyages);

int main()
{
	//русская локаль
	setlocale(LC_ALL, "RUS");
	//иницилизация списков
	buses buses;
	buses.load();
	voyages voyages;
	voyages.load();
	stations stations;
	stations.load();
	//вывод количества пассажиров
	buses.total_capacity();
	//выввод всех рейсов
	total_voyages(stations, voyages);
}
void total_voyages(stations stations, voyages voyages) {
	for (int i = 0; i != stations.list_station.size(); i++) {
		int sum = 0;
		for (int j = 0; j != voyages.list_voyage.size(); j++) {
			if (stations.list_station[i].station_ID == voyages.list_voyage[j].station_ID) {
				sum++;
			}
		}
		cout << "Всего рейсов " << sum << " до станции: " << stations.list_station[i].station_name << endl;
	}
}