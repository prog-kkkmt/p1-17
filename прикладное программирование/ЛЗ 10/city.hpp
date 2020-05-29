#ifndef CITY_HPP_INCLUDED
#define CITY_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct City//Города
{
	int codeC; //код города
	int dist; //расстояние
	int codeR; //код тарифа
};

void input(vector <City>& v, City city);//чтение из файла
void output(vector <City> v); //вывод
void update(vector <City>& v); //обновление
void add(vector <City>& v, City city);//добавление
void del(vector <City>& v);//удаление
void edit(vector <City>& v);//редактирование
void aboutProgram();//о программе
void sorting(vector <City>& v);//сортировка 

#endif 
