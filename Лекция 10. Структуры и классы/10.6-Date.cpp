/* Структура "дата". Методы внутри структуры. Один файл. Гусятинер Л.Б., 05.05.2020 */
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct Date{ /* дата */
    int year; /* год */
    int month; /* месяц */
    int day; /* день */

	int ge(Date other) {
		/* Верно ли, что this не меньше (greater or equal), чем other */
		return
			other.year > year ||
			year == other.year && (month > other.month || month == other.month && day >= other.day);
	}

	int le(Date other) {
		/* Верно ли, что this не больше (less or equal), чем other */
		Date tmp = (*this);
		(*this) = other;
		other = tmp;
		return ge(other);
	}

	int between(Date d1, Date d2) {
		/* Входит ли дата в интервал */
		return ge(d1) && le(d2);
	}

	Date date_diff(Date other) {
		/* Разность дат */
		Date diff;
		diff.day = day - other.day;
		diff.month = month - other.month;
		if (diff.day < 0) {
			diff.day += 30;
			diff.month--;
		}
		diff.year = year - other.year;
		{
			if (diff.month < 0) {
				diff.month += 12;
				diff.year--;
			}
		}
		return diff;
	};
};

/* Верно ли, что d2 не меньше (greater or equal), чем d1 */
int ge(Date d2, Date d1);

/* Входит ли дата в интервал */
int between(Date d, Date d1, Date d2);

/* Получить дату из 3х чисел */
Date intsToDate(int year, int month, int day);

/* Получить дату из строки. Самостоятельно */
Date strToDate(char *s);

int main() {
    Date d1, d2;
	cin >> d1.year >> d1.month >> d1.day;
	cin >> d2.year >> d2.month >> d2.day;

    system("chcp 1251>nul");
    cout << "Дата 1 = " << d1.day << "." << d1.month << "." << d1.year << endl;
    cout << "Дата 2 = " << d2.day << "." << d2.month << "." << d2.year << endl;

    Date d3 = d2.date_diff(d1);
    cout << "Разность = " << d3.day << "." << d3.month << "." << d3.year << endl;

    /* получить дату из 3х чисел */
    int day, month, year;
    cin >> year >> month >> day;
    Date d4 = intsToDate(year, month, day);
    cout << "Дата 4 = " << d4.day << "." << d4.month << "." << d4.year << endl;

    /* вывести дату прописью */
    string months[] =
        {"", "января","февраля","марта","апреля","мая","июня","июля",
        "августа","сентября","октября","ноября","декабря"};
    cout << "Дата: " << d1.day << " " << months[d1.month] << " " << d1.year << endl;

    return 0;
}

Date intsToDate(int year, int month, int day) {
    /* Получить дату из 3х чисел */
    Date date = {year, month, day};
    return date;
};

Date strToDate(char *s) {
    /* Получить дату из строки. Самостоятельно */
    /* */
};
