///���������� 3.10. �������� ��������� ������ � ������ ������ ����������. ��������� ������ ��������� ������ ���������� ������, ���������� ����� ����������,
///� ������� �� �� ������, �� ��� ��� ������ ����������.
///(��������� �.�.) �������� ��������� ���������� 3.10. ���, ����� ������� ������ ��������� �� ����� input.txt, � ��������� ����������� � ���� output.txt
///��������: ������ �. �.
///����: 13.05.2020

#include <iostream>
#include <string>
#include <fstream>
#include <locale>

using namespace std;

int main() {
    setlocale(0, "");
    string s1;
    ifstream file1;
    ofstream file2;
    file1.open("input.txt");
    file2.open("output.txt");
    getline(file1, s1);
    cout << "���� ������: " << s1 << endl;
    cout << "���� ������ ��� ������ ����������: ";
    for (string::size_type i = 0; i != s1.size(); ++i)
        if (!ispunct(s1[i])) {
            file2 << s1[i];
            cout << s1[i];
        }
    file1.close();
    file2.close();
    return 0;
}
