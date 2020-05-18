#ifndef COSITEMS_HPP_
#define COSTITEMS_HPP_
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct CostItem
 {
    int itemCode; //Код cтаьи
    string name; // Название

 };

void InPutItem(vector <CostItem> &item); //Функция ввода
void OutPutItem(ofstream &f, vector <CostItem> &item); //Функция вывода в файл
void EditItem(vector <CostItem> &item); //Функция редактирования
void RemoveItem(vector <CostItem> &item); //Функция удаления
void SortItem(vector <CostItem> &item); //Функция сортировки по номеру изделия
void AboutProgItem(ofstream &f); //Добавление в фалй информации о программе
void funcCostItem();

#endif //COSTITEMS_HPP_



