/*
�� 12
�������� ������ ������ ������� �1-17.
���.01.02 "���������� ����������������"
�� 12. ���������� �������� � ��������������, �������������
�����������: ��������� �.�., 12.05.2020, ����� ����, �1-17, �2-17
������� ��� �����������. 1 �������.
������� ��� ��������������� ����� � �������������� MS Access � MS Excel
��������: https://nsportal.ru/sites/default/files/2020/05/05/ekon._inf.pdf
�������� 62.
�������� ���������� ����� �� ������� �� ����������. ������
������� ������� �� ����� ������������� ���������� ����������.
�������: ������� (��� �������, �������� �������); ��������
(��� ��������, ����� ��������, ��������������� �����, �����������);
����� (��� �����, ��� �������, ��� ��������, ����� �����������).
����������:
� ������� ����������� ������ �� ������ �������?
� ������ ����� ���������� ����������?
�������. ��� �������������� � ��-11 ������� � ���� �� ������� "���� ������"
1. ������ ���� name (��� ������������) ���� std::string � ��������� �������� 2 ����:
- char *name; // ��������� �� ���
- size_t len; // ����� ������ � ������
2. �������� (��������) �����������
3. �������� ����������
��������� ���������.
����� *.cpp � *.h (*.hpp), test.txt, Readme.md � ����� ����� � �������� ������������ ������� 12.
15.05.2020
*/

#include <iostream>
#include <locale>
#include <string>

using namespace std;

struct Stan
{
    int kod_stan;
    char naz[100];
};

struct Bus
{
    int kod_bus, number, vmest;
    string marka;

};

struct Reis
{
    int kod_reis, kod_stan, kod_bus;
    char time[100];

};

void swap_string(string *x, string *y)
{
    string marka = *x;
    *x = *y;
    *y = marka;
}

void swap_int(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

struct AN //�����
{
    private:
    string fam, name, date , number;

    public:
    AN()
    {
        cout << "�������: �������, ��� , ���� �������� � ����� �������� ���������" << endl;
        cin >> fam >> name >> date >> number;
        cout << "�������: " << fam << endl;
        cout << "���: " << name << endl;
        cout << "���� ��������: " << date << endl;
        cout << "����� ��������: " << number << endl;
        cout << fam.length() << endl;
    }

    ~AN()
    {
        cout << "��� �������� ����������" << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "���������� V 0.0.1." << endl; ///�������� ���������

    Bus b[100];
    Reis r[100];

    int n; ///���������� ���������
    int i, n1;


    cout << "������� ����� ���������?" << endl;
    cin >> n;

    if (n != 0) cout << "�������: ��� ��������, ����� ��������, ���-����� � ����������� ��������" << endl;

    for (i = 0; i < n; ++i)
    {
        cin >> b[i].kod_bus >> b[i].marka >> b[i].number >> b[i].vmest;
    }

    cout << "������� ����� ������?" << endl;
    cin >> n1;

    if (n1 != 0) cout << "�������: ��� �����, ��� �������, ��� �������� � ����� �����������" << endl;

    for (i = 0; i < n1; ++i)
    {
        cin >> r[i].kod_reis >> r[i].kod_stan >> r[i].kod_bus >> r[i].time;
    }

    int menu; ///����
    cout << "1 - ����� ����� ����������" << endl;
    cout << "2 - � ���������" << endl;
    cout << "3 - ���������� �� �����������" << endl;
    cout << "4 - ���������� ������ ��� ������ �������" << endl;
    cout << "5 - ����� ���������� �� ���������" << endl;
    cout << "6 - ���������� ���������" << endl;
    cout << "7 - ������ ���������" << endl;
    cout << "0 - �����" << endl;
    cin >> menu;

    while ((menu == 1) || (menu == 2) || (menu == 3)  || (menu == 4) || (menu == 5) || (menu == 6)  || (menu == 7))
    {
        if (menu == 1)
        {
            int kol = 0;
            for (i = 0; i < n; ++i)
            {
                kol += b[i].vmest;
            }
            cout << "����� ���������� ����������: " << kol << endl;
        }

        if (menu == 2)
        {

            cout << "�������� ��������� ��� ���������� ������ ������� �1-17 (1 �������)" << endl;
        }

        if (menu == 3)
        {
            int j;
            for (i = 0; i < n; ++i)
                for (j = 0; j < n - 1; ++j)
                {
                    if (b[j].vmest < b[j + 1].vmest)
                    {
                        swap_int(&b[j].kod_bus, &b[j + 1].kod_bus);///������������� ����������� �������

                        swap_string(&b[j].marka, &b[j + 1].marka);///������������� ����������� �������

                        swap_int(&b[j].number, &b[j + 1].number);///������������� ����������� �������

                        swap_int(&b[j].vmest, &b[j + 1].vmest);///������������� ����������� �������
                    }
                }

            for (i = 0; i < n; ++i)
                cout << b[i].kod_bus << " " << b[i].marka << " " << b[i].number << " " << b[i].vmest << endl;
        }

        if (menu == 4)
        {
            int n2, i, n3, j, p = 0, p1 = 0;
            for (i = 0; i < n1; ++i)
            {
                n2 = 0;
                n3 = r[i].kod_stan;
                for (j = 0; j < n1; ++j)
                    if (n3 == r[j].kod_stan) n2++;

                cout << r[i].kod_stan << " " << n2 << endl;
            }
        }

        if (menu == 5)
        {
            for (i = 0; i < n; ++i)
            {
                cout << b[i].kod_bus << " " << b[i].marka << " " << b[i].number << " " << b[i].vmest << endl;
            }
        }

        if (menu == 6)
        {
            cin >> b[n].kod_bus >> b[n].marka >> b[n].number >> b[n].vmest;
            n++;
        }

        if (menu == 7) AN();

        cout << "1 - ����� ����� ����������" << endl;
        cout << "2 - � ���������" << endl;
        cout << "3 - ���������� �� �����������" << endl;
        cout << "4 - ���������� ������ ��� ������ �������" << endl;
        cout << "5 - ����� ���������� �� ���������" << endl;
        cout << "6 - ���������� ���������" << endl;
        cout << "7 - ������ ���������" << endl;
        cout << "0 - �����" << endl;
        cin >> menu;

    }

    return 0;
}
