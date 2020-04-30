// Добавьте в класс String реализацию конструктора копирования.
//Выполнил: Пищулин Игорь
//Источник: Stepik Computer Science Center (CS центр)
//Программирование на языке C++
//https://stepik.org/lesson/550/step/10
//26.04.2020
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	~String();


    /* Реализуйте конструктор копирования */
	String(const String &other)
        : size(other.size), str(new char[other.size + 1])
    {
             for (int i = 0; i < other.size; i++)
                 str[i] = other.str[i];
             str[other.size] = '\0';
    }

	void append(const String &other);

	size_t size;
	char *str;
};
