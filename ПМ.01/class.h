//Звонарев П1-17
#pragma once
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

//пространство имен std
using namespace std;
//класс книг
class books
{
public:
	struct book //книги (код книги, название,автор,жанр,год издания)
	{
		int book_ID;
		string book_name;
		string book_author;
		string book_genre;
		int book_yaer;
	};
	//список книг
	vector<book>list_book;
	void load();//загрузка списка книг
};
//класс читателей
class readers
{
public:
	struct reader //читатели (код читателя, фамилия,имя,отчество, № читательского билета)
	{
		int reader_ID;
		string readers_fam;
		string readers_name;
		string readers_otc;
		int readers_ticket;
	};
	vector<reader>list_reader;
	void load();//загрузка списка читателей
};

class extraditions
{
public:
	struct extradition //выдача (код читателя, код книги,дата выдачи)..
	{
		int reader_ID;
		int book_ID;
		string extradition_time;
	};
	vector<extradition>list_extradition;
	void load();//загрузка списка  выдач
};
