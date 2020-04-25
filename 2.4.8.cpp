// Напишите функцию поиска первого вхождения шаблона в текст

int strstr(const char *text, const char *pattern)
{
    int index = 0;
    if (!*pattern) return 0;
    if (!*text) return -1;
    cout << "TEST";
    while(*text) {
        cout << "TEST25";
        const char *t = text;
        const char *p = pattern;
        while(*t && *p){
            cout << endl << "TEST255";
            if (*t == *p) {
                cout << "1  " << *t << " " << *p;
                t++; p++;
            } else {
                cout << "2  " << *t << " " << *p;
                break;
            }
        }
        if (!*p) {
            cout << index;
            return index;

        }
        text++;
        index++;
    }
    return -1;
}