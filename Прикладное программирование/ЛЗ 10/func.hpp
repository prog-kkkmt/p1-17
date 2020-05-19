#ifndef FUNC_HPP_INCLUDED
#define FUNC_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct data
{
    int code;
    string name;
};

void get(vector <data> dt);

void add(vector <data> &dt, int code, string name);

void del(vector <data> &dt, int code);

void edit(vector <data> &dt, int code, int z);

void save(vector <data> dt);

#endif // FUNC_HPP_INCLUDED
