/* ��������� "����". ���������� ������� ToDo "2". ��������� �.�., 05.05.2020 */
#include <stdio.h>
#include <stdlib.h>
#include "date.h"

int main() {
    /* ToDo-����. ���� �������� ����� */
    /* 1 */
    /* ������� ���� */
    struct Date d1, d2;
    scanf("%d%d%d", &d1.year, &d1.month, &d1.day);
    scanf("%d%d%d", &d2.year, &d2.month, &d2.day);

    system("chcp 1251>nul");
    printf("���� 1 = %02d.%02d.%d\n", d1.day, d1.month, d1.year);
    printf("���� 2 = %02d.%02d.%d\n", d2.day, d2.month, d2.year);

    struct Date d3 = date_diff(d2, d1);
    printf("�������� = %02d.%02d.%d\n", d3.day, d3.month, d3.year);

    /* �������� ���� �� 3� ����� */
    int day, month, year;
    scanf("%d%d%d", &year, &month, &day);
    struct Date d4 = intsToDate(year, month, day);
    printf("���� 4 = %02d.%02d.%d\n", d4.day, d4.month, d4.year);

    /* ������� ���� �������� */
    char *months[] =
        {"", "������","�������","�����","������","���","����","����",
        "�������","��������","�������","������","�������"};
    printf("����: %d %s %d ����\n", d1.day, months[d1.month], d1.year);

    /* 2 */
    /* ����������� ��������������� ������� */
    /* ��������� ������ ���������� �� ������� 1 */
        /* ������ �� ���� � �������� ��� */
        /* �������� ���� �� ������ */
    /* 3 */
    /* ������� ��������� �� ��������� ����� ���������� � ���������� */
    return 0;
}
/* ������ ������ */
/*
1945
05
09
2020
05
05
���� 1 = 09.05.1945
���� 2 = 05.05.2020
�������� = 26.11.74
2019
12
31
���� 4 = 31.12.2019
����: 9 ��� 1945 ����

Process returned 0 (0x0)   execution time : 48.266 s
Press any key to continue.
*/
