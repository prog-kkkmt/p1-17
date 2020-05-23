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

struct Category {

	int categoryiD;
	char *category_name;
	size_t lencategory_name;
	Category() {
		lencategory_name = 20;
		category_name = new char[lencategory_name];
		categoryiD = 0;

	}
	~Category() {
		category_name = 0;
		lencategory_name = 0;
	};
};

struct Room {

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

struct Person {

	int personiD;
	char *Fio;
	size_t lenFio;
	char *passport;
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

struct LockedRoom {

	int lockedRoomiD;
	int personiD;
	int roomiD;
	char *star;
	size_t lenstar;
	char *finis;
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
	~LockedRoom(){
		lenstar = 0;
		lenstar = 0;
	}
};

void Initialization();
void Save();
void printDefaultMenu();
void Menu();
void StructMenu(bool *exit);//Просмотр записей
void SortMenu(bool *exit);//Просмотр сортировок
void htmlMenu(bool *exit);// Печать в html таблицы 
void EditMenu(bool *exit);// Редактирование таблицы
void About(bool *exit);//О программе

void sortRoom();
void sortLockedRoom();
void sortCategory();
void sortPerson();

void printRoom();//Список номеров 
void printLockedRoom();//Занятые номера   
void printCategory();//Категории номеров 
void printPerson();//Информация о постояльцах

void htmlprintRoom();//htmlСписок номеров 
void htmlprintLockedRoom();//htmlЗанятые номера   
void htmlprintCategory();//htmlКатегории номеров 
void htmlprintPerson();//htmlИнформация о постояльцах
void htmlprintAll();//htmlВсехтаблиц на 1 странице

void editRoom();//+
void editLockedRoom();
void editCategory();
void editPerson();

int getInt(); //проверка на корректный ввод числа
/*5. Гостиница.
В базе данных хранятся сведения о свободных и занятых однои многоместных номерах разной категории и проживающих.
Таблицы: Категории (Код категории, название); Номера (Код
номера, Код категории, номер, мест); Граждане (Код гражданина,
ФИО, паспорт); Размещение (Код размещения, Код гражданина, Код
номера, дата въезда, срок проживания).
Определить:
– количество полностью свободных номеров, то есть тех, в которых не поселены граждане;
– сравнительную степень занятости (в процентах) номеров по
категориям.

Доработать программу из лабораторного занятия 11.
Добавить пункты меню печати всех таблиц задания в формате *.html.

Ожидаемый результат (включая домашнее задание).
Файлы *.cpp и *.h (*.hpp), *.html, Readme.md в своей ветке в подпапке Лабораторное занятие 11.

*/
