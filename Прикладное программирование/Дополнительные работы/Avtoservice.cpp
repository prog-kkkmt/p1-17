/*
22.04.2020
�������� ������ ������� �1-17
������: �������� ��������� ��� �����������.
*/
#include <iostream>
#include <windows.h>

using namespace std;

struct Data ///���������
{
    int day, month, year, money;
}d[100];

struct People
{
    string name, fam;
    int number_phone;
}p[100];

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "���������� V 0.0.1." << endl; ///�������� ���������

    int menu; ///����
    cout << "1 - �������" << endl;
    cout << "2 - ����������" << endl;
    cout << "0 - �����" << endl;
    cin >> menu;

    while ((menu == 1) || (menu == 2))
    {
        if (menu == 1)
        {
            int n; ///���������� �������
            cout << "������� ���������� �������:" << endl;
            cin >> n;
            cout << "������� ����, �����, ��� � �������:" << endl;
            int i; ///���������� ��� for
            for (i = 0; i < n; i++) cin >> d[i].day >> d[i].month >> d[i].year >> d[i].money;
            for (i = 0; i < n; i++)
            {
                cout << d[i].day << "." << d[i].month
                << "." << d[i].year << " " << d[i].money << " ���." << endl;
            }
        }

        if (menu == 2)
        {
            int n, i;
            cout << "������� ���������� �������:" << endl;
            cin >> n;
            cout << "������� ���, ������� � ����� �������� (������ 89165555555):" << endl;
            for (i = 0; i < n; i++)
            {
                cin >> p[i].name >> p[i].fam >> p[i].number_phone;
            }

            for (i = 0; i < n; i++)
            {
                cout << p[i].name << " " << p[i].fam << " " << p[i].number_phone << endl;
            }
        }

        cout << "1 - �������" << endl;
        cout << "2 - ����������" << endl;
        cout << "0 - �����" << endl;
        cin >> menu;
    }
    return 0;
}
