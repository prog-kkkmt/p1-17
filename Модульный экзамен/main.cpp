#include <iostream>
#include "class_constructors.h"

using namespace std;

int main()
{
    setlocale(0, " ");
	int k;
	goroda a;
	razgovor b;
	bool f = true;
	while(f)
        {
        cout << "0-�����\n1--	���������� ������ ����������� � ������� ����������� ������� ������\n2--	���������� ���� ��������� ���������� �� ������� ������ � ����� ���������" << endl;
        cin >> k;
        switch(k)
        {
        case 0: f = false; break;
        case 1: b.sort_razgovor(); break;
        case 2: a.dolya(); break;
        }
        system("pause");
        system("cls");
	}
    return 0;
}
