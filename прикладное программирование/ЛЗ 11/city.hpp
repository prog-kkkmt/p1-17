#ifndef CITY_HPP_INCLUDED
#define CITY_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct City//Города
{
	int codeC;
	int dist;
	int codeR;
	
};

void input(vector <City>& v, City city);
void output(vector <City> v);
void update(vector <City>& v); 
void add(vector <City>& v, City city);
void del(vector <City>& v);
void edit(vector <City>& v);
void aboutProgram();
void sorting(vector <City>& v);
void functCity();


#endif 