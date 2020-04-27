#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {

    /* Ðåàëèçóéòå ýòîò êîíñòðóêòîð */
	String(const char *str = "") : size(strlen(str)), str(new char[strlen(str) + 1]) {
        strcpy(this->str, str);
    }

	size_t size;
	char *str;
};
