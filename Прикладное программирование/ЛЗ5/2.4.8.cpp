/*Напишите функцию поиска первого вхождения шаблона в текст. В качестве первого параметра функция принимает текст (C-style строка), в которой нужно искать шаблон. В качестве второго параметра строку-шаблон (C-style строка), которую нужно найти. Функция возвращает позицию первого вхождения строки-шаблона,
если он присутствует в строке (помните, что в C++ принято считать с 0), и -1,
если шаблона в тексте нет.*/
int strstr(const char *text, const char *pattern)
{
    int index = 0;
    if (*pattern == '\0')
        return 0;
    while (*text != '\0')
    {
        if (*text == *pattern)
        {
            const char* newPattern = pattern;
            const char* newText = text;
            while (*newText == *newPattern && *newPattern != '\0')
            {
                newText++;
                newPattern++;
            }
            if (*newPattern == '\0')
                return index;
        }
        text++;
        index++;
    }
    return -1;
}
