// Заполняющий конструктор принимает число и символ, 
// и создает строку с заданным количеством повторений переданного символа.
//Выполнил: Пищулин Игорь
//Источник: Stepik Computer Science Center (CS центр)
//Программирование на языке C++
//https://stepik.org/lesson/546/step/11
//26.04.2020
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {

    /* Реализуйте этот конструктор */
	String(size_t n, char c)
{
 this->size = n;
 char *s = new char[n + 1];
 for (int i = 0; i < n; i++) {
  s[i] = c;
 }
 s[n] = '\0';
 this->str = s;
}
    /* и деструктор */
	~String() 
 {
  delete [] str;
 }


	size_t size;
	char *str;
};
