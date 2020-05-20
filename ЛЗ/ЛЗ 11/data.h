#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <cctype>
//добавить деструктор констуктор
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
void SortMenu(bool *exit);//Просмотр сортировок
void sortRoom();
void sortLockedRoom();
void sortCategory();
void sortPerson();
void printRoom();//Список номеров 
void printLockedRoom();//Занятые номера   
void printCategory();//Категории номеров 
void printPerson();//Информация о постояльцах
void EditMenu(bool *exit);// Редактирование таблицы
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
*/
