///Задание: Завершите класс String, добавив к нему оператор присваивания. Будьте аккуратны при работе с памятью. 
///Инвариант класса остается тем же 
///(в size хранится размер строки без завершающего 0 символа, str указывает на C-style строку, т. е. с завершающим нулевым символом).
///Требования к реализации: вы можете заводить любые вспомогательные методы или функции, 
///но не реализуйте заново методы из предыдущих заданий — они уже реализованы. При реализации не нужно вводить или выводить что-либо. 
///Реализовывать main не нужно. Не используйте функции из cstdlib (malloc, calloc, realloc и free).
///Источник: Stepic Программирование на языке C++ https://stepik.org/7 от Computer Science Center(CS центр) 
///Глава 3, раздел 7, шаг 11. https://stepik.org/lesson/550/step/11
///Выполнил: Юшаков Н. Р. 24.04.2020.
#include <algorithm> // std::swap
#include <cstddef>   // size_t
#include <cstring>   // strlen, strcpy

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	String(const String &other);
	~String();

    /* Ðåàëèçóéòå îïåðàòîð ïðèñâàèâàíèÿ */
	String &operator=(const String &other) {
        if (this != &other)
            String(other).swap(*this);
        return *this;
    }

	void append(const String &other);

    void swap(String &a) {
        std::swap(size, a.size);
        std::swap(str, a.str);
    }

	size_t size;
	char *str;
};
