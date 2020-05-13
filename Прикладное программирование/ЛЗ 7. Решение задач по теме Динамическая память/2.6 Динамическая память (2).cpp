/**
���������� ������� getline, ������� ��������� ����� ����� �����������, ���� �� ��������� ����� ������
��� �� �������� ������ �������� ������ ('\n'), � ���������� C-style ������ � ������������ ���������.

�������� ��������, ��� ��� ��� ������ ����� ������� ����������, �� ��� ����� ����� ������������
������ � �������� ������, ���� � ������ ����� ��������� ������ ��������, ��� �� �������.

������, ������������ �� ������� ����� ����������� ���������� delete[]. ������ �������� ������
('\n') ��������� � ������ �� �����, �� �� ��������, ��� � ����� C-style ������ ������ ���� �����������
������� ������.

���������� � ����������: ��� ���������� ������� ������� �� ������ ���������� ����� ���������������
�������, ���� ��� ��� �����. ���������� ������� main �� �����.
**/

#include <iostream>

using namespace std;

char *resize(const char *str, unsigned size, unsigned new_size)
{
	char *new_memory = new char[new_size];
    for (int i = 0; i < new_size; i++)
        new_memory[i] = str[i];
    delete[] str;
    return new_memory;
}

char *getline()
{
    int size = 1, index = 0;
    char c;
    char *memory = new char[size];
    while (cin.get(c) && (c != '\n') && (c != EOF))
    {
        memory[index] = c;
        index++;
        if (index == size)
        {
            memory = resize(memory, size, size * 2);
            size *= 2;
        }
    }
    memory[index] = '\0';
    return memory;
}

///���������: ������� �.�.
///���� ����������: 30.04.2020
///��������: https://stepik.org, ���� "���������������� �� ����� C++"
