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

void get(vector <Client> clients);///Вывод

void add(vector <Client>& clients, int code, string surname, string gorod);///Ввод

void delet(vector <Client>& clients, int code);///Удаление

void edit(vector <Client>& clients);///Редактирование

void saveToFile(vector <Client> clients);///Сохранение в файл

#endif
