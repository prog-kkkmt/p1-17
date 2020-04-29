/**Напишите функцию поиска первого вхождения шаблона в текст.

Выполнила: Попкова Алена П1-17
Источник: Stepik.org Программирование в C++
25.04.2020**/

#include <iostream>
#define SIZE 100

using namespace std;


int strstr(const char *text, const char *pattern)
{
    for (*text != '\0')
    {
        for (i = 0, j = 0 ; *(pattern + j) != '/0' && *(text + i) == *(pattern + j); i++, j++)
            ;

    }

}
int main()
{
    char str1[SIZE], str2[SIZE];

    cin.getline(str1, SIZE);
    cin.getline(str2, SIZE);


	return 0;
}

