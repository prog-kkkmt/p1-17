/**Напишите функцию поиска первого вхождения шаблона в текст.

Выполнила: Попкова Алена П1-17
Источник: Stepik.org "Программирование на языке C++" Computer Science Center (CS центр) 2.4.8 https://stepik.org/lesson/540/step/8
25.04.2020 **/

#include <iostream>
#define SIZE 100

using namespace std;

int strstr(const char *text, const char *pattern)
{
    int Count = 0, i = 1;
    bool flag = false;

    if(*pattern)
        do {
            while(text[Count] && text[Count] != *pattern)
            Count++;

            if(text[Count]) {
                flag = true;

                while(pattern[i] && flag) {
                    if(text[Count + i] && text[Count + i] == pattern[i])
                        i++;
                    else
                        flag = false;
                }
            }
        } while(text[++Count] && !flag);
    else
        flag = true;

    return flag ? Count : -1;
}
int main()
{
    char str1[SIZE], str2[SIZE];

    cin.getline(str1, SIZE);
    cin.getline(str2, SIZE);
    cout << strstr(str1, str2);

	return 0;
}

