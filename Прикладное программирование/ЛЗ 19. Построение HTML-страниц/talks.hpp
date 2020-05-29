#ifndef TALKS_HPP_INCLUDED
#define TALKS_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Talks//Города
{
	Talks();
	
	int codeT;
	int codeC;
	char* start;
	size_t start_len;
	int lasting; 
	~Talks();

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
void to_html(vector <Talks>& v);
#endif 