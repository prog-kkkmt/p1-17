#ifndef DATE_H
#define DATE_H
/* ��������� "����". ��������� �.�., 05.05.2020 
  ������� ���� ��� ����������� ��������� */
struct Date{ /* ���� */
    int year; /* ��� */
    int month; /* ����� */
    int day; /* ���� */
};

/* �������� ��� */
Date date_diff(Date d2, Date d1);

/* ����� ��, ��� d2 �� ������ (greater or equal), ��� d1 */
int ge(Date d2, Date d1);

/* ������ �� ���� � �������� */
int between(Date d, Date d1, Date d2);

/* �������� ���� �� 3� ����� */
Date intsToDate(int year, int month, int day);

/* �������� ���� �� ������. �������������� */
Date strToDate(char *s);

#endif
