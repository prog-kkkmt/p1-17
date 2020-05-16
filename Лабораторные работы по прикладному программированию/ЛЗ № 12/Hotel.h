#ifndef HOTEL_H_INCLUDED
#define HOTEL_H_INCLUDED

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <locale>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Category {
    Category();
    ~Category();

    int categoryID;
    char* category_name;
    size_t category_len;
};

struct Room {
    Room();

    int roomID;
    int categoryID;
    int number;
    int beds;
};

struct Person {
    Person();
    ~Person();

    int personID;
    char* FIO;
    size_t FIO_len;
    char* passport;
    size_t passport_len;
};

struct Check_in {
    Check_in();
    ~Check_in();

    int check_inID;
    int personID;
    int roomID;
    char* start;
    size_t start_len;
    char* finish;
    size_t finish_len;
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
