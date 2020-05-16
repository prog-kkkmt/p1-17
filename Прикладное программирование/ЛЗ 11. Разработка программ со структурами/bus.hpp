#ifndef BUS_HPP_INCLUDED
#define BUS_HPP_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Bus
{
    int code;
    string marka;
    string number;
    int capacity;
};

void get_bus(vector <Bus> buses);

void add_bus(vector <Bus> &buses, string marka, string number, int capacity);

void del_bus(vector <Bus> &buses, int code);

void edit_bus(vector <Bus> &buses, int code, int field);

void saveToFile_bus(vector <Bus> buses);

#endif // BUS_HPP_INCLUDED
