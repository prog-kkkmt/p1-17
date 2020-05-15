/**
�������� ���������, ������� ������ ��� ������ � ����������, ����� �� ���,
� ���� ���, ����� �� ��� ������. �������� ��������� ���, ����� ��� ���������, ����� �� ������
���������� �����, � ���� ���, �� ����� �� ��� �������.
**/

#include <iostream>
#include <string>

using namespace std;

int sravnenie_strok(string s1, string s2)
{
    if (s1 == s2)
        return 0;
    else if (s1 > s2)
        return 1;
    else if (s2 > s1)
        return 2;
}

int sravnenie_dlin(string s1, string s2)
{
    if (s1.size() == s2.size())
        return 0;
    else if (s1.size() > s2.size())
        return 1;
    else if (s2.size() > s1.size())
        return 2;
}

int main()
{
    setlocale (LC_ALL, "Rus");
    string str1 = "Zravstvuyte,", str2 = "Leonid Borisovich!";

    switch (sravnenie_strok(str1, str2))
        {
            case 0:
            cout << "������ �����" << endl;
            break;

            case 1:
            cout << "������ ������ ������ ������" << endl;
            break;

            case 2:
            cout << "������ ������ ������ ������" << endl;
            break;
        }

    switch (sravnenie_dlin(str1, str2))
        {
            case 0:
            cout << "����� ����� �����" << endl;
            break;

            case 1:
            cout << "����� ������ ������ ������ ������" << endl;
            break;

            case 2:
            cout << "����� ������ ������ ������ ������" << endl;
            break;
        }

    return 0;
}

///���������: ������� �.�.
///���� ����������: 14.05.2020
