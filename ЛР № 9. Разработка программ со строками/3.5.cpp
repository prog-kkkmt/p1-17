///���������� 3.5. �������� ���������, �������� �� ������������ ���������� ����� ����� ������. �������� ��������� ���, ����� ��� ������ ��������� �����.
///��������: ������ �. �.
///����: 13.05.2020
#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main() {
    setlocale(0, "");
    string line;
    string word;
    cout << "������ ����������� ������: ";
    getline(cin, line);
    cout << line << endl;
    cout << "������ ����������� �����: ";
    while (cin >> word)
        cout << word << endl;
    return 0;
}
