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

struct Person {
    int personID;
    string FIO;
    string passport;
};

void Start();
void Menu();
void Out();
void Add();
void Delete();
void Edit();
void Save();

#endif // HOTEL_H_INCLUDED
