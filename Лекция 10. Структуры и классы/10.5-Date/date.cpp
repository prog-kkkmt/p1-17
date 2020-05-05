/* ��������� "����". ���������� �������. ��������� �.�., 05.05.2020 */
#include "date.h"

Date date_diff(Date d2, Date d1) {
	/* �������� ���*/
    Date d3;
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

int ge(Date d2, Date d1) {
    /* ����� ��, ��� d2 �� ������ (greater or equal), ��� d1 */
    /* ����������� � ����� ������ � ������� */
    return d2.year * 10000 + d2.month * 100 + d2.day >=
        d1.year * 10000 + d1.month * 100 + d1.day;
        /* return d2.year > d1.year ||
        d2.year == d1.year &&
        d2.month > d1.month ||
        (d2.month == d1.month && d2.day >= d1.day); */
}

int between(Date d, Date d1, Date d2) {
    /* ������ �� ���� � �������� */
    return ge(d, d1) && ge(d2, d);
}

Date intsToDate(int year, int month, int day) {
    /* �������� ���� �� 3� ����� */
    Date date = {year, month, day};
    return date;
};

Date strToDate(char *s) {
    /* �������� ���� �� ������. �������������� */
    /* ��������� ������ ��� ��������, ����� ������ � ���� ���� */
    Date date = {0,0,0};

    return date;
};
