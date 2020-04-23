#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	~String();


    /* Реализуйте этот метод. */
	void append(String &other) {
        size += other.size;
        char *temp = new char[size + 1];
        strcpy(temp, str);
        strcat(temp, other.str);
        delete [] str;
        str = temp;
    }

	size_t size;
	char *str;
};
