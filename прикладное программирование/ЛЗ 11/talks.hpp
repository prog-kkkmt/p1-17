#ifndef TALKS_HPP_INCLUDED
#define TALKS_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Talks//Города
{
	int codeT;
	int codeC;
	string start;
	int lasting;
};

void input(vector <Talks>& v, Talks talks);
void output(vector <Talks> v);
void update(vector <Talks>& v); 
void add(vector <Talks>& v, Talks talks);
void del(vector <Talks>& v);
void edit(vector <Talks>& v);
void sorting(vector <Talks>& v);
void aboutprogram();
void functTalks();
#endif 