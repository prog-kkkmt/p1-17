/**
�� ������ � ����������� ������� ������� ������� �� �������
"������� ��� ��������������� ����� � �������������� MS Access � MS Excel"
������� ���� (�����) �������.
��� ��������� ������� ����������� ������ � ����, ����������� �����������
����������, ��������, ��������������, ������ ������ ����������� �������.
����������� ����������� ������.

����� ��������: �1 (21 % 20)
�������: ��������(��� ��������, ����� ��������, ��������������� �����, �����������)
**/

#include "functionsForBuses.hpp"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    vector <Bus> buses;
    Bus bus;
    ifstream file;
    file.open("Bus.txt");
    while(file >> bus.code >> bus.marka >> bus.number >> bus.capacity)
        buses.push_back(bus);
    file.close();

    int vibor = 1;
    int code, capacity, field;
    string marka, number;
    while (vibor != 0)
    {
        cout << "1 - ��������\n2 - �������\n3 - �������������\n4 - ������� ������\n5 - ��������� ��������� � ����\n0 - �����\n\n�������� ��������: ";
        cin >> vibor;
        switch (vibor)
        {
            case 0:
            break;

            case 1:
            cout << "������� �����: ";
            cin >> marka;
            cout << "������� ��������������� �����: ";
            cin >> number;
            cout << "������� �����������: ";
            cin >> capacity;
            add(buses,marka, number, capacity);
            break;

            case 2:
            cout << "������� ���: ";
            cin >> code;
            del(buses, code);
            break;

            case 3:
            cout << "������� ���: ";
            cin >> code;
            cout << "1 - ���\n2 - �����\n3 - ��������������� �����\n4 - �����������\n�������� ����, ������� ���������� ��������: ";
            cin >> field;
            edit(buses, code, field);
            break;

            case 4:
            get(buses);
            break;

            case 5:
            saveToFile(buses);
            break;

            default:
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
            cout << "! ������. ��������� ����� !" << endl;
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
            break;
        }
    }
    return 0;
}

///���������: ������� �.�.
///���� ����������: 15.05.2020

