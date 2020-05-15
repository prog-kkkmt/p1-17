#ifndef HOTEL_H_INCLUDED
#define HOTEL_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Category {
    int categoryID;
    string category_name;
};

struct Room {
    int roomID;
    int categoryID;
    int number;
    int beds;
};

struct Person {
    int personID;
    string FIO;
    string passport;
};

struct Check_in {
    int check_inID;
    int personID;
    int roomID;
    string start;
    string finish;
};

void Start();
void Menu();
int Table_menu();
void Out(int k);
void Add(int k);
void Delete(int k);
void Edit(int k);
void Save(int k);

#endif // HOTEL_H_INCLUDED
