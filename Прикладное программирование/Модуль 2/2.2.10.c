/*��� ��������� �������� ���������, ������� "��������������" ������������������ ������������� �����
�����. �� ���� �������� ������������������ ����������� ��������� ������������� ����� �����.
������������������ ������������� �����. ��������� ������� ��� ������������������ � �������� �������.
��������: ���������� ���������
��������: Stepik Computer Science Center (CS �����)
���������������� �� ����� C++
2.2.10 https://stepik.org/lesson/538/step/10
24.04.2020
*/
#include <iostream>

using namespace std;


void rec()
{
    int n = 0;
    cin >> n;
    if ( n == 0 )
        return;
    rec();
    cout << n << " ";

}

int main()
{
    rec();

    return 0;
}
