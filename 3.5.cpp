//�������� ���������, �������� �� ������������ ���������� ����� ����� ������.
//�������� ��������� ���, ����� ��� ������ ��������� �����.
//���������: ������� ������� �1-17
//����:14.05.2020


#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main()
{
    setlocale(0, " ");
    string stroka, slovo;
    cout << "��������� ����� ������:";
        getline(cin, stroka);
            cout << stroka << endl;
    cout << "��������� ��������� �����:";
        while (cin >> slovo)
            cout << slovo << endl;
    return 0;



}
