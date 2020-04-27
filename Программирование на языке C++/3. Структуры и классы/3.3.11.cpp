#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {

    /* Ðåàëèçóéòå ýòîò êîíñòðóêòîð */
	String(size_t n, char c) : size(n), str(new char[n + 1]) {
        for (size_t i = 0; i != n; str[i] = c, ++i)
            ;
        str[n] = '\0';
    }

    /* è äåñòðóêòîð */
	~String() {
        delete [] str;
    }


	size_t size;
	char *str;
};
