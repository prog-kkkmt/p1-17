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