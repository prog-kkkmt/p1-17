/**
�������� ��������� ������ � ������ ������ ����������.
��������� ������ ��������� ������ ���������� ������, ���������� ����� ����������,
� ������� �� �� ������, �� ��� ��� ������ ����������.
**/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    getline (cin, str);
    int i = 0;
    while (str[i] != '\0')
    {
        if (ispunct(str[i]) && str[i] != ' ');
        else
           cout << str[i];
        i++;
    }
    return 0;
}

///���������: ������� �.�.
///���� ����������: 14.05.2020
