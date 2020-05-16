#ifndef FLIGHTS_HPP_INCLUDED
#define FLIGHTS_HPP_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Flights
{
    int code_fl;
    int code_st;
    int code_bus;
    string time;
};

void get_fl(vector <Flights> flights);

void add_fl(vector <Flights> &flights, int code_st, int code_bus, string time);

void del_fl(vector <Flights> &flights, int code_fl);

void edit_fl(vector <Flights> &flights, int code_fl, int field);

void saveToFile_fl(vector <Flights> flights);

#endif // FLIGHTS_HPP_INCLUDED
