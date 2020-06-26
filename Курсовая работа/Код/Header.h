#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <cctype>
#include <locale>
#include <cstring>
#include <locale>

using namespace std;

class Category {
public:

	int categoryiD;
	char* category_name;
	size_t lencategory_name;
	int price;
	Category() {
		lencategory_name = 20;
		category_name = new char[lencategory_name];
		categoryiD = 0;
		price = 0;

	}
	~Category() {
		category_name = 0;
		lencategory_name = 0;
	};

};

class Room {
public:
	int roomiD;
	int categoryiD;
	int num;
	int beds;
	Room() {
		roomiD = 0;
		categoryiD = 0;
		num = 0;
		beds = 0;
	}

};

class Person {
public:
	int personiD;
	char* Fio;
	size_t lenFio;
	char* passport;
	size_t lenpassport;
	Person() {
		personiD = 0;
		lenFio = 30;
		Fio = new char[lenFio];
		lenpassport = 30;
		passport = new char[lenpassport];
	}
	~Person() {
		lenFio = 0;
		lenpassport = 0;
	}
};

class LockedRoom {
public:
	int lockedRoomiD;
	int personiD;
	int roomiD;
	char* star;
	size_t lenstar;
	char* finis;
	size_t lenfinis;
	LockedRoom() {
		lockedRoomiD = 0;
		personiD = 0;
		roomiD = 0;
		lenstar = 30;
		star = new char[lenstar];
		lenfinis = 30;
		finis = new char[lenfinis];
	}
	~LockedRoom() {
		lenstar = 0;
		lenstar = 0;
	}
};

void Initialization();//Считывание из файлов 
void Save();//запись в файлы
void printDefaultMenu();//Печать основного меню
void Menu();//Меню программы
void StructMenu(bool* exit);//Просмотр записей
void SortMenu(bool* exit);//Просмотр сортировок
void htmlMenu(bool* exit);// Печать в html таблицы 
void EditMenu(bool* exit);// Редактирование таблицы
void About(bool* exit);//О программе

void sortRoom();//Сортировка списка номеров 
void sortLockedRoom();//Сортировка занятых номеров
void sortCategory();//Сортировка категории номеров
void sortPerson();//Сортировка информация о постояльцах

void printRoom();//Список номеров 
void printLockedRoom();//Занятые номера   
void printCategory();//Категории номеров 
void printPerson();//Информация о постояльцах

void htmlprintRoom();//htmlСписок номеров 
void htmlprintLockedRoom();//htmlЗанятые номера   
void htmlprintCategory();//htmlКатегории номеров 
void htmlprintPerson();//htmlИнформация о постояльцах
void htmlprintAll();//htmlВсехтаблиц на 1 странице

void editRoom();//Редактирование номеров
void editLockedRoom();//Редактирование занятые номера
void editCategory();//Редактирование номеров
void editPerson();//Редактирование номеров

int getInt(); //Проверка на корректный ввод числа