#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {

    /* Реализуйте этот конструктор */
	String(size_t n, char c): size(n)
    {
        str = new char[n + 1];
        for (size_t i = 0; i < n; i++)
            str[i] = c;
        str[n] = '\0';
    }

    /* и деструктор */
	~String()
    {
        delete [] str;
    }


	size_t size;
	char *str;
};
