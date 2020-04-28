// Реализуйте функцию getline, которая считывает поток ввода посимвольно, пока не достигнет конца потока или не 
// встретит символ переноса строки ('\n'), и возвращает C-style строку с прочитанными символами.

#include <iostream>

using namespace std;

char *resize(const char *str, unsigned size, unsigned new_size)
{
	char *new_str = new char[new_size];
    
    for(int i = 0; i < new_size; i++)
        new_str[i] = str[i];
    
    delete [] str;

    return new_str;
}

char *getline()
{
    unsigned n = 100;
    char *line = new char[n];
    char c;
    unsigned size = 0;
    while (cin.get(c) && c != EOF && c != '\n') {
        if (size >= n) {
            line = resize(line, n, n * 2);
            n = n * 2;  
        }
        line[size] = c;
        size++;
    }
    if (size >= n) {
        line = resize(line, n, n * 2);
         n = n * 2;   
    }
    line[size] = '\0';
    return line;
}