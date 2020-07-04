///����� �2. ���������
///��������� ���������� ������������ ������� �������� ����������� ��������� �����.
///�������: ���������� (��� ����������, ���), ��������� (��� ���������, ���), ����������(���, �����), �������(��� ���������, ��� ����������,
///��������������� �����, ��� ����������, ����, ����).
///����������:
///-������� ����� ������
///-���� ������ ����������� ������ �����.

///�������� ������� ������ �1-17 ��������� �����

#include <iostream>
#include <locale>
#include <string>
#include "mod.h"


using namespace std;



int main()
{
    setlocale(LC_ALL, "Russian");
    Pokypateli p[100];
    Menejer me[100];
    Avtomobili av[100];
    Prodaji pr[100];

    int a, b, i;

    cout << "���������" << endl;

    cout << "������� ���-�� �����������." << endl;
    cin >> a;

    if (a != 0)
        cout << "�������: ��� ����������, ���." << endl;

    for (i = 0; i < a; ++i)
    {

        cin >> p[i].kod_pok >> p[i].fio;
    }
    cout << "������� ���-�� ����������." << endl;
    cin >> b;

    if (b != 0)
        cout << "�������: ��� ���������, ���" << endl;

    for (i = 0; i < b; ++i)
    {
        cin >> me[i].kod_men >> me[i].fio;
    }
    cout << "������� ���-�� �����������." << endl;
    cin >> b;
    int kolavto = b;

    if (b != 0)
        cout << "�������: ��� ����������, �����" << endl;

    for (i = 0; i < b; ++i)
    {
        cin >> av[i].kod_avto >> av[i].marka;
    }

    cout << "������� ���-�� ������." << endl;
    cin >> b;

    if (b != 0)
        cout << "�������: ��� ���������, ��� ����������, ��������������� �����, ��� ����������, ����, ����" << endl;

    for (i = 0; i < b; ++i)
    {
        cin >> pr[i].kod_men >> pr[i].kod_avto >> pr[i].gos_nomer >> pr[i].kod_pok >> pr[i].data >> pr[i].cena;
    }
    int m;


    while (true)
    {
        cout << "1 - ������� ����� ������" << endl;
        cout << "2 - ���� ������ ����������� ������ �����" << endl;
        cout << "0 - �����" << endl;
        cin >> m;
        if (m == 0)
            break;
        if (m == 1)
        {
            int kolvo = 0;
            float sred = 0;
            for (i = 0; i < b; ++i)
            {
                sred += pr[i].cena;
            }
            sred /= (float)b;
            cout << "������� ����� ������: " << sred << endl;
        }
        if (m == 2)
        {
            cout << "���� ������ ����������� ������ �����: " << (float)b / (float)kolavto * 100 << endl;
        }
    }

    cin >> m;
    return 0;
}
