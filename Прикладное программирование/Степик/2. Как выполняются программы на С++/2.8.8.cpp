/*
��������� ������� ���������� � ������ 2.8 ������ � ����-�����,
��� ����������� ���������.
��������� ��������� ������ ������� �1-17
*/

#include <string>
#include <fstream>

using namespace std;

int main()
{
    string name;
    ifstream input("i.txt");
    input >> name;
    ofstream output("o.txt");
    output << "Hi, " << name << endl;
    return 0;
}

