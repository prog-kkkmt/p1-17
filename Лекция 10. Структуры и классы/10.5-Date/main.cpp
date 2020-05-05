/* Структура "дата". Реализация раздела ToDo "2". Гусятинер Л.Б., 05.05.2020 */
#include <iostream>
#include <cstdlib>
#include <string>
#include "date.h"

using namespace std;
// Не всегда хорошо, но для учебного кода пока подойдёт
int main() {
    Date d1, d2;
	cin >> d1.year >> d1.month >> d1.day;
	cin >> d2.year >> d2.month >> d2.day;

    system("chcp 1251>nul");
    cout << "Дата 1 = " << d1.day << "." << d1.month << "." << d1.year << endl;
    cout << "Дата 2 = " << d2.day << "." << d2.month << "." << d2.year << endl;

    Date d3 = date_diff(d2, d1);
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
