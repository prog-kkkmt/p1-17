#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	~String();


    /* Реализуйте этот метод. */
	void append(String &other)
    {
        size += other.size;
        char *memory = new char[size + 1];
        strcpy(memory, str);
        strcat(memory, other.str);
        delete [] str;
        str = memory;
    }

	size_t size;
	char *str;
};
