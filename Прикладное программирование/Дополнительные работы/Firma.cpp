/*
14.05.2020
������ � ������� ��� ���������. ��� ������: https://stepik.org/lesson/544/step/2?unit=867.
� ������ ����� ���������, ��� �����.
�������� ������ ������� �1-17.
*/

#include <iostream>
#include <windows.h>

struct People///��������
{
    char fam[100], gorod[100];
    int kod_prodav;
    float com;
};

struct Zakazchik///��������
{
    int kod_z;
    char fam[100], gorod[100];
    int reit, kod_prodav;
};

struct Zakaz///�����
{
    int kod_za;
    int kod_prodav, kod_zakazchik;
    int data, sum;
};

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "����� V 0.0.1." << endl; ///�������� ���������

    People p;
    Zakazchik z;
    Zakaz za[100];

    int i;

    for (i = 0; i < 3; ++i)
    {
        cin >> za[i].kod_za >> za[i].kod_prodav >> za[i].kod_zakazchik >> za[i].data >> za[i].sum;
    }

    int menu; ///����
    cout << "1 - ����� ������� �����" << endl;
    cout << "0 - �����" << endl;
    cin >> menu;

    while (menu == 1)
    {
        if (menu == 1)
        {
            int max = 0;
            for (i = 0; i < 3; ++i)
            {
                if (za[i].sum >= max)
                    max = za[i].sum;
            }
            for (i = 0; i < 3; ++i)
            {
                if (za[i].sum == max)
                    cout << za[i].kod_za << " " << za[i].kod_prodav << " " << za[i].kod_zakazchik << " " << za[i].data << " " << za[i].sum << endl;
            }
        }
        cout << "1 - ����� ������� �����" << endl;
        cout << "0 - �����" << endl;
        cin >> menu;
    }

    /*cin >> p.kod_prodav >> p.fam >> p.gorod >> p.com;
    cout << p.kod_prodav << " " << p.fam << " " << p.gorod << " " << p.com << endl;

    cin >> z.kod_prodav >> z.fam >> z.gorod >> z.reit >> z.kod_prodav;
    cout << z.kod_prodav << " " << z.fam << " " << z.gorod << " " << z.reit << z.kod_prodav << endl;

    cin >> za.kod_za >> za.kod_prodav >> za.kod_zakazchik >> za.data >> za.sum;
    cout << za.kod_za << " " << za.kod_prodav << " " << za.kod_zakazchik << " " << za.data << za.sum << endl;*/
}
