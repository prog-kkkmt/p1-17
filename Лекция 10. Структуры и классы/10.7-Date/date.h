/* ��������� "����". ��������� �.�., 05.05.2020 */
#ifndef DATE_H
#define DATE_H

struct Date{ /* ���� */
    int year; /* ��� */
    int month; /* ����� */
    int day; /* ���� */

    /* ����� ��, ��� d2 �� ������ (greater or equal), ��� d1 */
	int ge(Date other);

	/* ����� ��, ��� this �� ������ (less or equal), ��� other */
	int le(Date other);

	/* ������ �� ���� � �������� */
	int between(Date d1, Date d2);

	/* �������� ��� */
	Date date_diff(Date other);
};

/* �������� ���� �� 3� ����� */
Date intsToDate(int year, int month, int day);

/* �������� ���� �� ������. �������������� */
Date strToDate(char *s);

#endif // DATE_H
