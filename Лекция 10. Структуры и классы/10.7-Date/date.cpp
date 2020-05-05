/* Структура "дата". Методы внутри структуры. Один файл. Гусятинер Л.Б., 05.05.2020 */
#include <iostream>
#include <string>
#include <cstdlib>
#include "date.h"

using namespace std;

int Date::ge(Date other) {
    /* Верно ли, что this не меньше (greater or equal), чем other */
    return
        other.year > year ||
        (year == other.year && (month > other.month || (month == other.month && day >= other.day)));
}

int Date::le(Date other) {
    /* Верно ли, что this не больше (less or equal), чем other */
    Date tmp = (*this);
	(*this) = other;
	other = tmp;
	return ge(other);
}

int Date::between(Date d1, Date d2) {
    /* Входит ли дата в интервал */
    return ge(d1) && le(d2);
}

Date Date::date_diff(Date other) {
    /* Разность дат */
    Date diff;
    diff.day = day - other.day;
    diff.month = month - other.month;
    if (diff.day < 0) {
        diff.day += 30;
        diff.month--;
    }
    diff.year = year - other.year;
    if (diff.month < 0) {
        diff.month += 12;
        diff.year--;
    }

    return diff;
};

Date intsToDate(int year, int month, int day) {
    /* Получить дату из 3х чисел */
    Date date = {year, month, day};
    return date;
};

Date strToDate(char *s) {
    /* Получить дату из строки. Самостоятельно */
    /* */
    Date date = {0, 0, 0};
    return date;
};
