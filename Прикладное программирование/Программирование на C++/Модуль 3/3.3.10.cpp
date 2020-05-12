// В этой задаче вам требуется реализовать конструктор
//Выполнил: Пищулин Игорь
//Источник: Stepik Computer Science Center (CS центр)
//Программирование на языке C++
//https://stepik.org/lesson/546/step/10
//26.04.2020
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {


	String(const char *str = "")
{
 int size = strlen(str);
 char *s = new char[size + 1];
 this->size = size;
 strcpy(s, str);
 this->str = s;
}

	size_t size;
	char *str;
};
