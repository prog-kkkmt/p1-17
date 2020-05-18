#ifndef PRODUCTS_HPP_
#define PRODUCTS_HPP_
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Product
 {
    int prodCode; //Код изделия
    string name; // Название

 };

void InPutProd(vector <Product> &prod); //Функция ввода
void OutPutProd(ofstream &f, vector <Product> &prod); //Функция вывода в файл
void EditProd(vector <Product> &prod); //Функция редактирования
void RemoveProd(vector <Product> &prod); //Функция удаления
void SortProd(vector <Product> &prod); //Функция сортировки по коду изделия
void AboutProgProd(ofstream &f); //Добавление в фалй информации о программе
void funcProduct();

#endif //PRODUCTS_HPP_




