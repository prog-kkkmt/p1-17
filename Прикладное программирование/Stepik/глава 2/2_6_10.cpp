/*
Реализуйте функцию getline, которая считывает поток ввода посимвольно, пока не достигнет конца потока или не встретит символ переноса 
строки ('\n'), и возвращает C-style строку с прочитанными символами.
Обратите внимание, что так как размер ввода заранее неизвестен, то вам нужно будет перевыделять память в процессе чтения, 
если в потоке ввода оказалось больше символов, чем вы ожидали.
Память, возвращенная из функции будет освобождена оператором delete[]. Символ переноса строки ('\n') добавлять в строку не нужно, 
но не забудьте, что в конце C-style строки должен быть завершающий нулевой символ.
Требования к реализации: при выполнении данного задания вы можете определять любые вспомогательные функции, если они вам нужны. 
Определять функцию main не нужно.

Выполнил : Звонарёв Д.А. П1-17 30 апреля 2020
Источник : stepik, программирование на языке с++ Михаил Кринкин, 2.6.10, https://stepik.org/lesson/542/step/10?unit=865
*/

#include <iostream>
using namespace std;

char *resize(const char *str, unsigned size, unsigned new_size)
{
	char *new_data = new char[new_size];
    for(int i = 0; i < (size < new_size ? size : new_size); i++)
        *(new_data + i) = *(str + i);
    delete[] str;
    str = 0;
    return new_data;
}

char *getline()
{
    int i = 0;
    int size = 100;
    char *str = new char[size];
    int new_size = size;
    
    while (cin.get(str[i]))
    {
        if (str[i] == '\n')
            break;
        i++;
        if (i >= size)
        {
            new_size = size + 2;
            str = resize(str, size, new_size);
            size = new_size;
        }
    }
    str[i] = '\0';
    
    return str;
}
