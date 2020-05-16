#ifndef RATE_HPP_INCLUDED
#define RATE_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Rate//Города
{
	int codeR;
	int mindist;
	int maxdist;
	double price;
};

void input(vector <Rate>& v, Rate rate);
void output(vector <Rate> v);
void update(vector <Rate>& v); 
void add(vector <Rate>& v, Rate rate);
void del(vector <Rate>& v);
void edit(vector <Rate>& v);
void sorting(vector <Rate>& v);
void functRate();

#endif 