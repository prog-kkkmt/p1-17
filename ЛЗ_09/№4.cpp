#include <iostream>
#include <string>
#include <locale>

///���������� 3.5. �������� ���������, �������� �� ������������ ���������� ����� ����� ������. �������� ��������� ���, ����� ��� ������ ��������� �����.
/**
��������� ��������� ��������� ������ �1-17
���������� �.�.
���� ����������� 12.05.20
**/
using namespace std;

int main() {
    setlocale(0, "");
    string str;
    string word;
    cout <<"������ ���� ������"<<endl;
    getline(cin, str);
    cout << str << endl;
    cout << "������ ������ �����"<<endl;
    while (cin >> word)
        cout << word << endl;

	return 0;
}
