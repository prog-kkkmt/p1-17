/*
��������� ������. �������� ������ ������� �1-17.
���� ���������: ������������ ���� ���, ������� � ������� ��������.
������������ ��� � ����.
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string name, fam, phone;
    int date;
    cout << "Enter name, familia and phone" << endl;
    cin >> name >> fam >> phone;
    ofstream output("o1.txt");
    output << "Hi, " << name << " " << fam << " " << phone << endl;
    return 0;
}

