/*
��������� ������� ���������� � ������ 2.8 ������ � ����-�����,
��� ����������� ���������.
��������� ��������� ������ ������� �1-17
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1 = "Hello";
    cout << s1.size() << endl;
    string s2 = ", world!";
    s1 = s1 + s2;
    if (s1 == s2)
        cout << "s1 == s2" << endl;
    return 0;
}
