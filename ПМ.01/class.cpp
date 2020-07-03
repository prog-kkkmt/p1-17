//Звонарев П1-17
#include "class.h"
//методы класса книги  
void books::load()//загрузка списка книг
{
	ifstream f("books.txt");

	if (f.is_open()) {
		while (!f.eof()) {
			book book;
			f >> book.book_ID;
			f >> book.book_name;
			f >> book.book_author;
			f >> book.book_genre;
			f >> book.book_yaer;
			list_book.push_back(book);
		}
		f.close();
	}
}

//методы класса читатели
void readers::load()//загрузка списка читателей
{
	ifstream f("readers.txt");

	if (f.is_open()) {
		while (!f.eof()) {
			reader reader;
			f >> reader.reader_ID;
			f >> reader.readers_fam;
			f >> reader.readers_name;
			f >> reader.readers_otc;
			f >> reader.readers_ticket;
			list_reader.push_back(reader);
		}
		f.close();
	}
}

//методы класса выданные книги
void extraditions::load()//загрузка списка выданных книг
{
	ifstream f("extraditions.txt");

	if (f.is_open()) {
		while (!f.eof()) {
			extradition extradition;
			f >> extradition.reader_ID;
			f >> extradition.book_ID;
			f >> extradition.extradition_time;
			list_extradition.push_back(extradition);
		}
		f.close();
	}
}
