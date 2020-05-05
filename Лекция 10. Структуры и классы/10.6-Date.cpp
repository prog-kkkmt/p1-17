/* ��������� "����". ������ ������ ���������. ���� ����. ��������� �.�., 05.05.2020 */
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct Date{ /* ���� */
    int year; /* ��� */
    int month; /* ����� */
    int day; /* ���� */

	int ge(Date other) {
		/* ����� ��, ��� this �� ������ (greater or equal), ��� other */
		return
			other.year > year ||
			year == other.year && (month > other.month || month == other.month && day >= other.day);
	}

	int le(Date other) {
		/* ����� ��, ��� this �� ������ (less or equal), ��� other */
		Date tmp = (*this);
		(*this) = other;
		other = tmp;
		return ge(other);
	}

	int between(Date d1, Date d2) {
		/* ������ �� ���� � �������� */
		return ge(d1) && le(d2);
	}

	Date date_diff(Date other) {
		/* �������� ��� */
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

/* ����� ��, ��� d2 �� ������ (greater or equal), ��� d1 */
int ge(Date d2, Date d1);

/* ������ �� ���� � �������� */
int between(Date d, Date d1, Date d2);

/* �������� ���� �� 3� ����� */
Date intsToDate(int year, int month, int day);

/* �������� ���� �� ������. �������������� */
Date strToDate(char *s);

int main() {
    Date d1, d2;
	cin >> d1.year >> d1.month >> d1.day;
	cin >> d2.year >> d2.month >> d2.day;

    system("chcp 1251>nul");
    cout << "���� 1 = " << d1.day << "." << d1.month << "." << d1.year << endl;
    cout << "���� 2 = " << d2.day << "." << d2.month << "." << d2.year << endl;

    Date d3 = d2.date_diff(d1);
    cout << "�������� = " << d3.day << "." << d3.month << "." << d3.year << endl;

    /* �������� ���� �� 3� ����� */
    int day, month, year;
    cin >> year >> month >> day;
    Date d4 = intsToDate(year, month, day);
    cout << "���� 4 = " << d4.day << "." << d4.month << "." << d4.year << endl;

    /* ������� ���� �������� */
    string months[] =
        {"", "������","�������","�����","������","���","����","����",
        "�������","��������","�������","������","�������"};
    cout << "����: " << d1.day << " " << months[d1.month] << " " << d1.year << endl;

    return 0;
}

Date intsToDate(int year, int month, int day) {
    /* �������� ���� �� 3� ����� */
    Date date = {year, month, day};
    return date;
};

Date strToDate(char *s) {
    /* �������� ���� �� ������. �������������� */
    /* */
};
