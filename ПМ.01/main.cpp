//Звонарев П1-17
#include <locale>
#include "class.h"
void time_extraditions(books books, extraditions extraditions);
void popular_author(books books, extraditions extraditions);
/*
Таблицы:
книги (код книги, название,автор,жанр,год издания),
читатели (код читателя, фамилия,имя,отчество, № читательского билета),
выдача (код читателя, код книги,дата выдачи).
определить :
- наиболее читаемого автора
- выдачу книг по датам
*/
int main()
{
	//русская локаль
	setlocale(LC_ALL, "RUS");
	//иницилизация списков
	books books;
	books.load();
	extraditions extraditions;
	extraditions.load();
	readers readers;
	readers.load();
	//выданные книги по датам
	time_extraditions(books, extraditions);
	popular_author(books, extraditions);
}
//выданные книги по датам
void time_extraditions(books books, extraditions extraditions) {
	for (int i = 0; i != extraditions.list_extradition.size(); i++) {
		cout << "Выданные книги в " << extraditions.list_extradition[i].extradition_time <<  endl;
		for (int j = 0; j != extraditions.list_extradition.size(); j++) {
			if (extraditions.list_extradition[j].extradition_time == extraditions.list_extradition[i].extradition_time) {
				for (int k = 0; k != books.list_book.size(); k++)
					if (extraditions.list_extradition[j].book_ID == books.list_book[k].book_ID)
						cout << books.list_book[k].book_name << endl;
			}
		}
	}
}

//популярный автор
void popular_author(books books, extraditions extraditions) {
	short i, k, popular_index, frq, max_frq;
	popular_index = 0;
	max_frq = 1;
	for (i = 0; i < extraditions.list_extradition.size() - 1; i++) {
		frq = 1;
		for (k = i + 1; k < extraditions.list_extradition.size(); k++)
			if (extraditions.list_extradition[i].book_ID == extraditions.list_extradition[k].book_ID)
				frq += 1;
		if (frq > max_frq) {
			max_frq = frq;
			popular_index = i;
		}
	}
	if (max_frq > 1)
		cout << "Наиболее популярный автор: " << books.list_book[popular_index].book_author << endl;
}
