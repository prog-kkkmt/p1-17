/*
25.04.2020
�������� ������ ������� �1-17
1.8.10.
������� ������ �� ����������� ��������� �� ������ �  ������/�������. �������� ���������, ������� ��������� ����� �����.
*/

#include <iostream>

using namespace std;

int main()
{
    int Kol;
    int a, b, i;
    cin >> Kol;
    for(i = 0; i < Kol; i++)
    {
        cin >> a >> b;
        cout << a + b << endl;
    }
    return 0;
}
