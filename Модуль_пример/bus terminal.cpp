/*Buses run to stations on a scheduled basis. Each  can accommodate no more than a certain
number of passengers
Tables:
stations (station code, station name),
es ( code,  brand, state number, capacity),
flights (flight code, station code,  code, departure time).
Identify:
- how many flights are operated to each station?
- what is the total number of passengers?
Finished: Sapoletova Anastasia
25.06.2020
*/
#include <iostream>
#include <fstream>
#include <vector>
#include "Stations.hpp"
#include "Bus.hpp"
#include "Trip.hpp"
using namespace std;

int main(){
    vector <Station> stations;  /*создание вектора*/
    vector <Bus> bus;
    vector <Trip> trip;
    vector <int> busN;
    Station obj = Station();
    Bus obj1 = Bus();
    Trip obj2 = Trip();
    bool menu = true;
    int counts = 0;
    int cap = 0;
    int indexS = -1;
    ifstream in("stations.txt");

    int choice;

    if (in.is_open()) {
        while(in >> obj.idStation >> obj.name){
            stations.push_back(obj);
        }
    }

    in.close();
    in.open("bus.txt");

    if (in.is_open()) {
        while(in >> obj1.idBus >> obj1.label >> obj1.number >> obj1.capacity){
            bus.push_back(obj1);
        }
    }
    in.close();
    in.open("trip.txt");

    if (in.is_open()) {
        while(in >> obj2.idTrip >> obj2.idStation >> obj2.idBus >> obj2.time ){
            trip.push_back(obj2);
        }
    }
    in.close();

    while (menu) {
        counts = 0;
        cap = 0;
        busN.clear();   /*удаление элементов вектора*/
        cout << "Menu" << endl;

        for (int i = 0; i < stations.size(); i++)
            cout << stations.at(i).idStation << ". " << stations.at(i).name << endl;

        cin >> choice;


        for (int i = 0; i < stations.size(); i++)
            if (stations.at(i).idStation == choice)
                indexS = i;

        if (indexS == -1) {
            cout << "Incorrect ID" << endl;
            continue;
        }

        for (int i = 0; i < trip.size(); i++) {
            if (trip.at(i).idStation == choice) {
                counts += 1;
                busN.push_back(trip.at(i).idBus);
            }
        }

        for (int i = 0; i < bus.size(); i++){
            for (int j = 0; j < busN.size(); j++){
                if (bus.at(i).idBus == busN.at(j))
                    cap += bus.at(i).capacity;
            }
        }

        cout << stations.at(indexS).name << ": Trip - " << counts << ", Capacity - " << cap << endl;
    }

    return 0;
}
