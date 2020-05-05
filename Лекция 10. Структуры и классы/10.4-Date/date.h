#ifndef DATE_H
#define DATE_H
/* ��������� "����". ��������� �.�., 05.05.2020 */
struct Date{ /* ���� */
    int year; /* ��� */
    int month; /* ����� */
    int day; /* ���� */
};

/* �������� ���*/
struct Date date_diff(struct Date d2, struct Date d1);

/* ����� ��, ��� d2 �� ������ (greater or equal), ��� d1 */
int ge(struct Date d2, struct Date d1);

/* ������ �� ���� � �������� */
int between(struct Date d, struct Date d1, struct Date d2);

/* �������� ���� �� 3� ����� */
struct Date intsToDate(int year, int month, int day);

/* �������� ���� �� ������. �������������� */
struct Date strToDate(char *s);

#endif
