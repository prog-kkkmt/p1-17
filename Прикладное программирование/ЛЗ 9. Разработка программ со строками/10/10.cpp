/**
�������� ��������� ���������� 3.10. ���, ����� ������� ������ ��������� �� ����� input.txt,
� ��������� ����������� � ���� output.txt
**/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream input;
    ofstream output;
    string str;
    input.open("input.txt");
    getline(input, str);
    input.close();
    int i = 0;
    output.open("output.txt");
    while (str[i] != '\0')
    {
        if (ispunct(str[i]) && str[i] != ' ');
        else
            output << str[i];
        i++;
    }
    output.close();
    return 0;
}

///���������: ������� �.�.
///���� ����������: 14.05.2020
