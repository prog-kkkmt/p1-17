#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

struct Client
{
    int code;
    string surname;
    string gorod;
};

void get(vector <Client> clients);

void add(vector <Client>& clients, int code, string surname, string gorod);

void delet(vector <Client>& clients, int code);

void edit(vector <Client>& clients);

void saveToFile(vector <Client> clients);

#endif