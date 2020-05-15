/**����������� (��� �����������, ��� �������, ��� ������, �����)
��������: ������������� �����������: ������������ ��������� / ����. �.�. ���������, �.�. ���������. �
������: ��� ��� ����� ����� �.�. ���������, 2009
https://nsportal.ru/sites/default/files/2020/05/05/ekon._inf.pdf
���������: ������� ����� �1-17
15.05.2020**/


#include <iostream>
#include <fstream>
#include <vector>
#include "Costing.hpp"

using namespace std;

int main()
{
    vector <Costing> cost;
    int num;
    ofstream f("test.txt");

    setlocale(LC_ALL, "Russian");

    cout << "0: ���������� ������"<< endl;
    cout << "1: �������� ������"<< endl;
    cout << "2: �������������� ������"<< endl;
    cout << "3: ������"<< endl;
    cout << "4: ����������" << endl;
    cout << "5: � ���������" << endl;
    cout << "6: �����"<< endl;

    do{
        cout << "�������� ����� ��������: ";
        cin >> num;
        switch(num){
        case 0:
            InPut(cost);
            f << "���������� ������. Done!" << endl;
            break;
        case 1:
            Remove(cost);
            f << "�������� ������. Done!" << endl;
            break;

        case 2:
            Edit(cost);
            f << "�������������� ������. Done!" << endl;
            break;

        case 3:
            OutPut(f, cost);
            f << "����� � ����. Done!" << endl;
            break;

        case 4:
            Sort(cost);
            f << "����������. Done!" << endl;
            break;
        case 5:
            AboutProg(f);
            break;
        case 6:
            cout << "Goodbye!" << endl;
            break;

        default:
            cout << "Error" << endl;
        }

    }while (num != 6);
}
