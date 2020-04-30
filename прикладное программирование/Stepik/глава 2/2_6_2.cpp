/*
Реализуйте функцию getline, которая считывает поток ввода посимвольно, пока не достигнет конца потока или не встретит символ переноса 
строки ('\n'), и возвращает C-style строку с прочитанными символами.
Обратите внимание, что так как размер ввода заранее неизвестен, то вам нужно будет перевыделять память в процессе чтения, если в потоке 
ввода оказалось больше символов, чем вы ожидали.
Память, возвращенная из функции будет освобождена оператором delete[]. Символ переноса строки ('\n') добавлять в строку не нужно, но не 
забудьте, что в конце C-style строки должен быть завершающий нулевой символ.
Требования к реализации: при выполнении данного задания вы можете определять любые вспомогательные функции, если они вам нужны. Определять 
функцию main не нужно.
Выполнила : Озерова А.С. П1-17 30.04.20
Источник : stepik, программирование на языке с++ Михаил Кринкин, 2.6.10, https://stepik.org/lesson/542/step/10?unit=865
*/
#include <iostream>
#define N 2
char *resize(const char *str, unsigned size, unsigned new_size)
{
	char * s = new char[new_size];
    for(int i = 0; i < (size < new_size ? size : new_size); i++)
        s[i] = str[i];
    delete[] str;
    return s;
}
char *getline()
{
    char ch;
    int i, size = 1;
    char *s = new char[N];
    for (i = 0; std::cin.get(ch) && ch != '\n'; i++) 
    {
        if (i == size) 
        {
            s = resize(s, size, size * 2);
            size *= 2;
        }
        s[i] = ch;
    }
    s[i] = '\0';
    return s;
}
