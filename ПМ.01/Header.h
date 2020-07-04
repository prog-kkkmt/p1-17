#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <cctype>
#include <locale>
#include <cstring>
#include <sstream>
#include <locale>
#include <time.h>
#include < ctime >

using namespace std;

class Client {
public:

	int code;
	char* Fio;
	size_t lenFio;
	char* gorod;
	size_t lengorod;
	Client() {
		code = 0;
		lenFio = 30;
		Fio = new char[lenFio];
		lengorod = 15;
		gorod = new char[lengorod];
	}
	~Client() {
		lenFio = 0;
		lengorod = 0;
	};

};

class Proizv {
public:

	int code;
	int schet;
	char* nname;
	size_t lenname;
	Proizv() {
		lenname = 10;
		nname = new char[lenname];
		code = 0;
	}
	~Proizv() {
		schet = 0;
		lenname = 0;
	};

};

class Vidtex {
public:

	int code;
	char* vid;
	size_t lenvid;
	Vidtex() {
		lenvid = 20;
		vid = new char[lenvid];
		code = 0;
	}
	~Vidtex() {
		lenvid = 0;
	};

};

class Category {
public:

	int categoryiD;
	char* category_name;
	size_t lencategory_name;
	Category() {
		lencategory_name = 20;
		category_name = new char[lencategory_name];
		categoryiD = 0;
	}
	~Category() {
		category_name = 0;
		lencategory_name = 0;
	};

};


class Remont {
public:
	struct data
	{
		int finish_day;
		int finish_mouth;
		int finish_year;
	};
	data finis;
	data star;
	int coderem;
	int codekl;
	int codevidt;
	int categoryiD;
	string nametx;
};


void Initialization();
void printDefaultMenu();
void Menu();
void StructMenu(bool* exit);
void printProizv();
void printCategory();
void printRemont();
void printClient();
void printVidtex();
void neremont();
void sravn();