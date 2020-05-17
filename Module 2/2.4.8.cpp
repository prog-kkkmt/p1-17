// Напишите функцию поиска первого вхождения шаблона в текст
//Выполнил: Богомолов Максим П1-17
//Источник: Stepik Computer Science Center (CS центр)
//Программирование на языке C++
//2.4.8 https://stepik.org/lesson/540/step/8
//25.04.2020
int strstr(const char *text, const char *pattern)
{
    int index = 0;
    if (!*pattern) return 0;
    if (!*text) return -1;
    while(*text) {
        const char *t = text;
        const char *p = pattern;
        while(*t && *p){
            if (*t == *p) {
                t++; p++;
            } else {
                break;
            }
        }
        if (!*p) {
            return index;
        }
        text++;
        index++;
    }
    return -1;
}

