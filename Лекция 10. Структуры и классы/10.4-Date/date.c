/* ��������� "����". ���������� �������. ��������� �.�., 05.05.2020 */
#include "date.h"

struct Date date_diff(struct Date d2, struct Date d1) {
	/* �������� ���*/
    struct Date d3;
    d3.day = d2.day - d1.day;
    d3.month = d2.month - d1.month;
    if (d3.day < 0) {
        d3.day += 30;
        d3.month--;
    }
    d3.year = d2.year - d1.year;
    {
        if (d3.month < 0) {
            d3.month += 12;
            d3.year--;
        }
    }
    return d3;
};

int ge(struct Date d2, struct Date d1) {
    /* ����� ��, ��� d2 �� ������ (greater or equal), ��� d1 */
    /* ����������� � ����� ������ � ������� */
    return d2.year * 10000 + d2.month * 100 + d2.day >=
        d1.year * 10000 + d1.month * 100 + d1.day;
        /* return d2.year > d1.year ||
        d2.year == d1.year &&
        d2.month > d1.month ||
        (d2.month == d1.month && d2.day >= d1.day); */
}

int between(struct Date d, struct Date d1, struct Date d2) {
    /* ������ �� ���� � �������� */
    return ge(d, d1) && ge(d2, d);
}

struct Date intsToDate(int year, int month, int day) {
    /* �������� ���� �� 3� ����� */
    struct Date date = {year, month, day};
    return date;
};

struct Date strToDate(char *s) {
    /* �������� ���� �� ������. �������������� */
    /* ��������� ������ ��� ��������, ����� ������ � ���� ���� */
    struct Date date = {0,0,0};

    return date;
};
