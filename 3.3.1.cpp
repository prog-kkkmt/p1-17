#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {

    /* Реализуйте этот конструктор */
	String(const char *str = "")
    {
         this -> size = (strlen(str));
         this -> str = (strcpy(new char [size + 1],str));
             
    }

	size_t size;
	char *str;
};
