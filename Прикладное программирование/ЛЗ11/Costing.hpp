#ifndef COSTING_HPP_
#define COSTING_HPP_
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Costing
 {
    int CostCode; //Код калькуляции
    int ProductName; // Код изделия
    int ItemCode; //Код статьи
    int sum; //Сумма
 };

void funcCosting();
void InPut(vector <Costing> &cost); //Функция ввода
void OutPut(ofstream &f, vector <Costing> &cost); //Функция вывода в файл
void OutPutHtml(ofstream &f, vector <Costing> &cost);
void Edit(vector <Costing> &cost); //Функция редактирования
void Remove(vector <Costing> &cost); //Функция удаления
void Sort(vector <Costing> &cost); //Функция сортировки по номеру изделия
void AboutProg(ofstream &f); //Добавление в фалй информации о программе

#endif //COSTING_HPP_
