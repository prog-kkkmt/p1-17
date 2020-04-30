/*
Булатников 21.04
Реализованные в предыдущих заданиях конструкторы и деструктор берут на себя работу 
по управлению ресурсами. Теперь можно дополнить структуру String различными полезными методами.

Для работы со строками можно придумать множество полезных методов (подумайте, 
какие методы пригодились бы вам, и чего вам не хватает для их реализации). Примером такого
метода может послужить метод append — он добавляет копию строки-аргумента в конец 
текущей строки (т.е. в конец строки, у которой он был вызван). */
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
