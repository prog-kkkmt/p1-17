#ifndef __PRIK__
#define __PRIK__

#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Book 
{
	int code_b;
	string title;
	int year_of_publ;
};

void Menu();

void OutPut();

void InPut();

void Edit();

void Delete();

#endif
