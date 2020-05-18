#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <cctype>
using namespace std;
struct Category {
	int categoryiD;
	string category_name;
};

struct Room {
	int roomiD;
	int categoryiD;
	int num;
	int beds;
};

struct Person {
	int personiD;
	string Fio;
	string passport;
};

struct LockedRoom {
	int lockedRoomiD;
	int personiD;
	int roomiD;
	string star;
	string finis;
};

void Initialization();
void Save();
void printDefaultMenu();
void Menu();
void About(bool *exit);//О программе
void StructMenu(bool *exit);//Просмотр записей
void printRoom();//Список номеров 
void printLockedRoom();//Занятые номера   
void printCategory();//Категории номеров 
void printPerson();//Информация о постояльцах
void Edit();// Редактирование таблицы
void editRoom();//+
void editLockedRoom();
void editCategory();
void editPerson();
int getInt(); //проверка на корректный ввод числа
