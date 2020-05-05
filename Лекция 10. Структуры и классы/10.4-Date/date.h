#ifndef DATE_H
#define DATE_H
/* Структура "дата". Гусятинер Л.Б., 05.05.2020 */
struct Date{ /* дата */
    int year; /* год */
    int month; /* месяц */
    int day; /* день */
};

/* Разность дат*/
struct Date date_diff(struct Date d2, struct Date d1);

/* Верно ли, что d2 не меньше (greater or equal), чем d1 */
int ge(struct Date d2, struct Date d1);

/* Входит ли дата в интервал */
int between(struct Date d, struct Date d1, struct Date d2);

/* Получить дату из 3х чисел */
struct Date intsToDate(int year, int month, int day);

/* Получить дату из строки. Самостоятельно */
struct Date strToDate(char *s);

#endif
