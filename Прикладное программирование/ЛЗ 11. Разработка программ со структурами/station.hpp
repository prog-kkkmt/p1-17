#ifndef STATION_HPP_INCLUDED
#define STATION_HPP_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Station
{
   int code;
   string name;
};

void get_st(vector <Station> station);

void add_st(vector <Station> &station, string name);

void del_st(vector <Station> &station, int code);

void edit_st(vector <Station> &station, int code, int field);

void saveToFile_st(vector <Station> station);

#endif // STATION_HPP_INCLUDED
