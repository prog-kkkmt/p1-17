// Завершите класс String, добавив к нему оператор присваивания.
//Выполнил: Пищулин Игорь
//Источник: Stepik Computer Science Center (CS центр)
//Программирование на языке C++
//https://stepik.org/lesson/550/step/11
//26.04.2020
#include <algorithm> // std::swap
#include <cstddef>   // size_t
#include <cstring>   // strlen, strcpy

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	String(const String &other);
	~String();

    /* Реализуйте оператор присваивания */
	String &operator=(const String &other)
    {
        if (this != &other) {
            delete [] str;
            size = other.size;
            str = new char[size + 1];
            for (int i = 0; i < size; i++)
                 str[i] = other.str[i];
            str[size] = '\0';
        }
        return *this;
    }

	void append(const String &other);

	size_t size;
	char *str;
};
