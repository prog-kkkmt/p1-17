/*���������: ����������� �.�., �1-17, 15.05.2020
���������� 3.7. �������� ���������, ������� ������ ��� ������ � ����������, ����� �� ���,
� ���� ���, ����� �� ��� ������. �������� ��������� ���, ����� ��� ���������, ����� �� ������
���������� �����, � ���� ���, �� ����� �� ��� �������.*/

#include <iostream>

using namespace std;

int main() {
    string str1;
    string str2;

    getline(cin, str1);
    getline(cin, str2);

    if (str1.size() == str2.size()){
    cout << "������ �����";
    }else if (str1.size() > str2.size()) {
    cout << str1;
    } else {
    cout << str2;
    }

    return 0;
}
