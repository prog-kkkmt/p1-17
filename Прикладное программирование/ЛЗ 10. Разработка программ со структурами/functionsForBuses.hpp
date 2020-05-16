#ifndef FUNCTIONSFORBUSES_HPP_INCLUDED
#define FUNCTIONSFORBUSES_HPP_INCLUDED

#include <iostream>
#include <fstream>
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

void get(vector <Bus> buses);

void add(vector <Bus> &buses, string marka, string number, int capacity);

void del(vector <Bus> &buses, int code);

void edit(vector <Bus> &buses, int code, int field);

void saveToFile(vector <Bus> buses);

#endif // FUNCTIONSFORBUSES_HPP_INCLUDED
