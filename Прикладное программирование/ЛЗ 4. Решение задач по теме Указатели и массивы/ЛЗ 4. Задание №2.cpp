/**
����������� ��������� � ���� ��� ������ � �������� ����� ����� �� 10 ���������.
������ ����: ����������, ���������� �������������, ���������� �����, ������, �����.
��� ������� �������� (����� ������) ����������� �������, ����������� � �������� ����������
����� ������� �������� ������� � ���������� ���������.
**/

#include <iostream>
#include <locale>
#define SIZE 10

using namespace std;

void zapolnenie(int *a, int n)
{
    int k;
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> *(a + i);
    }
}

void vivod(int *a, int n)
{
    for (int i = 0; i < n; i++)
        cout << *(a + i) << " ";
    cout << endl;
}

int max_elem(int *a, int n)
{
    int max_el = *a;
    for (int i = 1; i < n; i++)
        if (*(a + i) > max_el)
            max_el = *(a + i);
    return max_el;
}

int summa(int *a, int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
        sum += *(a + i);
    return sum;
}

int main()
{
    setlocale (LC_ALL, "Rus");
    cout << "�������� ��������:\n1 - ����������\n2 - ���������� �������������\n3 - ���������� �����\n4 - ������\n0 - �����\n" << endl;
    int vibor, *m = new int[SIZE];
    cin >> vibor;
    while (vibor != 0)
    {
        switch (vibor)
        {
            case 1:
                zapolnenie(m, SIZE);
                break;

            case 2:
                cout << max_elem(m, SIZE) << endl;
                break;

            case 3:
                cout << summa(m, SIZE) << endl;
                break;

            case 4:
                vivod(m, SIZE);
                break;
        }
        cout << "�������� ��������:\n1 - ����������\n2 - ���������� �������������\n3 - ���������� �����\n4 - ������\n0 - �����\n" << endl;
        cin >> vibor;
    }
    return 0;
}

///���������: ������� �.�.
///���� ����������: 25.04.2020
