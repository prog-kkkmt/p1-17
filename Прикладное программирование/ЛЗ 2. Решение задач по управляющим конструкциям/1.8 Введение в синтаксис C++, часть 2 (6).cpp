/**
�������� ���������, ������� ����������� ������ �� std::cin, ���� �� ��������� ����� ������
�����, � �������� ��������� ������ ������ �������� ����� � ������� ���������� ��������� �
std::cout. ������� ������ ��������, ����� �������� ������� �� �����. ��� ���������� �������
��� �� ����������� ������������ �������������� �������, � ������: ���������, ������������
������������ � ��������, ���� ���� �� ��� � ���� �������. �� ������ ���������� �����
��������������� �������, ���� ��� ��� �����.
**/

#include <iostream>
using namespace std;

int main()
{
    char c, post_c = '\0';
    while (cin.get(c)) {
        if (c == ' ' && post_c == ' ') ;
        else
            cout << c;
        post_c = c;
    }
	return 0;
}

///���������: ������� �.�.
///���� ����������: 22.04.2020
///��������: https://stepik.org, ���� "���������������� �� ����� C++"
