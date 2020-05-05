/* ��������� "����". ���������� ������� ToDo "2". ��������� �.�., 05.05.2020 */
#include <iostream>
#include <cstdlib>
#include <string>
#include "date.h"

using namespace std;
// �� ������ ������, �� ��� �������� ���� ���� �������
int main() {
    Date d1, d2;
	cin >> d1.year >> d1.month >> d1.day;
	cin >> d2.year >> d2.month >> d2.day;

    system("chcp 1251>nul");
    cout << "���� 1 = " << d1.day << "." << d1.month << "." << d1.year << endl;
    cout << "���� 2 = " << d2.day << "." << d2.month << "." << d2.year << endl;

    Date d3 = date_diff(d2, d1);
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
