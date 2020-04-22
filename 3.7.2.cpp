#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	~String();


    /* Реализуйте конструктор копирования */
	String(const String &other):
    String()
    {
         append(other);   
    }
        


	void append(const String &other);

	size_t size;
	char *str;
};
