/**Напишите функцию, которая вычисляет длину C-style строки. Учтите, что завершающий нулевой символ считать не нужно

Выполнила: Попкова Алена П1-17
Источник: Stepik.org "Программирование на языке C++" Computer Science Center (CS центр) 2.4.6 https://stepik.org/lesson/540/step/6
25.04.2020*/
#include <iostream>
#include <string>
#define SIZE 100

using namespace std;

unsigned strlen(const char *str)
{
    int counNt = 0;
    while (*str != '\0')
    {
        counNt++;
        str++;
    }
    return counNt;
}

int main()
{
    char str[SIZE];

    cin.getline(str, SIZE);
    cout << strlen(str);

	return 0;
}

