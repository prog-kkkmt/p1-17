/* Структура "дата". Реализация раздела ToDo "2". Гусятинер Л.Б., 05.05.2020 */
#include <stdio.h>
#include <stdlib.h>
#include "date.h"

int main() {
    /* ToDo-лист. Наша дорожная карта */
    /* 1 */
    /* создать даты */
    struct Date d1, d2;
    scanf("%d%d%d", &d1.year, &d1.month, &d1.day);
    scanf("%d%d%d", &d2.year, &d2.month, &d2.day);

    system("chcp 1251>nul");
    printf("Дата 1 = %02d.%02d.%d\n", d1.day, d1.month, d1.year);
    printf("Дата 2 = %02d.%02d.%d\n", d2.day, d2.month, d2.year);

    struct Date d3 = date_diff(d2, d1);
    printf("Разность = %02d.%02d.%d\n", d3.day, d3.month, d3.year);

    /* получить дату из 3х чисел */
    int day, month, year;
    scanf("%d%d%d", &year, &month, &day);
    struct Date d4 = intsToDate(year, month, day);
    printf("Дата 4 = %02d.%02d.%d\n", d4.day, d4.month, d4.year);

    /* вывести дату прописью */
    char *months[] =
        {"", "января","февраля","марта","апреля","мая","июня","июля",
        "августа","сентября","октября","ноября","декабря"};
    printf("Дата: %d %s %d года\n", d1.day, months[d1.month], d1.year);

    /* 2 */
    /* разработать соответствующие функции */
    /* следующие задачи перенесены из раздела 1 */
        /* входит ли дата в интервал дат */
        /* получить дату из строки */
    /* 3 */
    /* разбить программу на отдельные файлы заголовков и реализации */
    return 0;
}
/* Пример вывода */
/*
1945
05
09
2020
05
05
Дата 1 = 09.05.1945
Дата 2 = 05.05.2020
Разность = 26.11.74
2019
12
31
Дата 4 = 31.12.2019
Дата: 9 мая 1945 года

Process returned 0 (0x0)   execution time : 48.266 s
Press any key to continue.
*/
