#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {

    /* Реализуйте этот конструктор */
	String(const char *s = "")
    {
         size = strlen(s);
         str = new char[size + 1];
         strcpy(str, s);
         str[size] = '\0';
    }

	size_t size;
	char *str;

};
