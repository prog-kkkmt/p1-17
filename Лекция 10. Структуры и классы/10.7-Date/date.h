/* Структура "дата". Гусятинер Л.Б., 05.05.2020 */
#ifndef DATE_H
#define DATE_H

struct Date{ /* дата */
    int year; /* год */
    int month; /* месяц */
    int day; /* день */

    /* Верно ли, что d2 не меньше (greater or equal), чем d1 */
	int ge(Date other);

	/* Верно ли, что this не больше (less or equal), чем other */
	int le(Date other);

	/* Входит ли дата в интервал */
	int between(Date d1, Date d2);

	/* Разность дат */
	Date date_diff(Date other);
};

/* Получить дату из 3х чисел */
Date intsToDate(int year, int month, int day);

/* Получить дату из строки. Самостоятельно */
Date strToDate(char *s);

#endif // DATE_H
