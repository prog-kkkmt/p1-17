// Примером такого метода может послужить метод append — 
// он добавляет копию строки-аргумента в конец текущей строки (т.е. в конец строки, у которой он был вызван).
//Выполнил: Пищулин Игорь
//Источник: Stepik Computer Science Center (CS центр)
//Программирование на языке C++
//https://stepik.org/lesson/546/step/12
//26.04.2020
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	~String();


    /* Реализуйте этот метод. */
	void append(String &other)
{
 char *res = new char[size + other.size + 1];
 int i = 0;
 for (; i < size; i++)
   res[i] = str[i];
 for (int j = 0; j < other.size; i++, j++)
   res[i] = other.str[j];
 size = size + other.size;
 res[size] = '\0';
 
 delete [] str;
 
 str = res;
}
	size_t size;
	char *str;
};
