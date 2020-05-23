#ifndef RELEASE_HPP_
#define RELEASE_HPP_
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Release{

    int planCode; //Код план
    int prodCode; // Код изделия
    int quan;//Количество

};

void InPutRelease(vector <Release> &rel); //Функция ввода
void OutPutRelease(ofstream &f, vector <Release> &rel); //Функция вывода в файл
void OutPutHtmlRelease(ofstream &f, vector <Release> &rel);
void EditRelease(vector <Release> &rel); //Функция редактирования
void RemoveRelease(vector <Release> &rel); //Функция удаления
void SortRelease(vector <Release> &rel); //Функция сортировки по коду плана
void AboutProgRelease(ofstream &f); //Добавление в фалй информации о программе
void funcRelease();

#endif //RELEASE_HPP_



