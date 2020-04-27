#include <iostream>

char *resize(const char *str, unsigned size, unsigned new_size)
{
    char *new_str = new char[new_size];
    for (int i = 0; i < ((size > new_size) ? new_size : size); new_str[i] = str[i], i++)
        ;
    delete [] str;
    return new_str;
}

char *getline()
{
    char ch;
    char *str = new char[2];
    int i, size;
    for (i = 0, size = 1; std::cin.get(ch) && ch != '\n'; i++) {
        if (i == size) {
            str = resize(str, size, size * 2);
            size *= 2;
        }
        str[i] = ch;
    }
    str[i] = '\0';
    return str;
}
