#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	~String();


    /* Реализуйте конструктор копирования */
	String(const String &other): size(other.size)
    {
        str = new char[size + 1];
        for (size_t i = 0; i < size; i++)
            str[i] = other.str[i];
        str[size] = '\0';
    }


	void append(const String &other);

	size_t size;
	char *str;
};
