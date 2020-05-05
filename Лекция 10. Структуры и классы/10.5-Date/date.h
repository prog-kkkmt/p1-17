#ifndef DATE_H
#define DATE_H
/* Структура "дата". Гусятинер Л.Б., 05.05.2020 
  функции пока вне определения структуры */
struct Date{ /* дата */
    int year; /* год */
    int month; /* месяц */
    int day; /* день */
};

/* Разность дат */
Date date_diff(Date d2, Date d1);

/* Верно ли, что d2 не меньше (greater or equal), чем d1 */
int ge(Date d2, Date d1);

/* Входит ли дата в интервал */
int between(Date d, Date d1, Date d2);

/* Получить дату из 3х чисел */
Date intsToDate(int year, int month, int day);

/* Получить дату из строки. Самостоятельно */
Date strToDate(char *s);

#endif
