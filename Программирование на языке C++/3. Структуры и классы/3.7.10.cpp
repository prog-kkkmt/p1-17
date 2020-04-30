///Задание: Добавьте в класс String реализацию конструктора копирования. 
///Инвариант класса остается тем же 
///(в size хранится размер строки без завершающего 0 символа, str указывает на C-style строку, т. е. с завершающим нулевым символом).
///Требования к реализации: вы можете заводить любые вспомогательные методы или функции, 
///но не реализуйте заново методы из предыдущих заданий — они уже реализованы. При реализации не нужно вводить или выводить что-либо. 
///Реализовывать main не нужно. Не используйте функции из cstdlib (malloc, calloc, realloc и free).
///Источник: Stepic Программирование на языке C++ https://stepik.org/7 от Computer Science Center(CS центр) 
///Глава 3, раздел 7, шаг 10. https://stepik.org/lesson/550/step/10
///Выполнил: Юшаков Н. Р. 24.04.2020.
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	~String();


    /* Ðåàëèçóéòå êîíñòðóêòîð êîïèðîâàíèÿ */
	String(const String &other) : size(other.size), str(new  char[size + 1]) {
        strcpy(str, other.str);
    }


	void append(const String &other);

	size_t size;
	char *str;
};
