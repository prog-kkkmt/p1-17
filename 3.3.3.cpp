#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	~String();


    /* Реализуйте этот метод. */
	void append(String &other)
    {
        char *str1 = new char[size + other.size + 1];
        
        strcpy(str1,str);
        strcat(str1,other.str);  
        delete [] str;
        str=str1;  
        size = size + other.size;
    }

	size_t size;
	char *str;
};
