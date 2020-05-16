/**
���������� ��������� �� ������������� ������� 10.
�������� ������ ���� ��� �����, ��������������, �������� � ������ ���� ������ �������.

�������:
������� (��� �������, �������� �������);
�������� (��� ��������, ����� ��������, ��������������� �����, �����������);
����� (��� �����, ��� �������, ��� ��������, ����� �����������).
**/

#include "bus.hpp"
#include "station.hpp"
#include "flights.hpp"

using namespace std;

int main()
{
    setlocale (LC_ALL, "Rus");
    int table = 1, vibor;
    ifstream file;
    vector <Bus> buses;
    Bus bus;
    vector <Station> station;
    Station st;
    vector <Flights> flights;
    Flights fl;

    while (table != 0)
    {
        cout << "1 - ������� \"�������\"\n2 - ������� \"��������\"\n3 - ������� \"�����\"\n0 - �����\n\n��������, � ����� �������� �� ������ ��������: ";
        cin >> table;

        switch(table)
        {
            case 0:
            break;

            case 1:
            vibor = 1;
            station.clear();
            file.open("Station.txt");
            while (file >> st.code >> st.name)
                station.push_back(st);
            file.close();
            while (vibor != 0)
            {
                cout << "1 - ��������\n2 - �������\n3 - �������������\n4 - ������� ������\n5 - ��������� ��������� � ����\n0 - ��������� � ������ �������\n\n�������� ��������: ";
                cin >> vibor;
                string name;
                int code, field;
                switch (vibor)
                {
                    case 0:
                    break;

                    case 1:
                    cout << "������� ��������: ";
                    cin >> name;
                    add_st(station, name);
                    break;

                    case 2:
                    cout << "������� ���: ";
                    cin >> code;
                    del_st(station, code);
                    break;

                    case 3:
                    cout << "������� ���: ";
                    cin >> code;
                    cout << "1 - ���\n2 - ��������\n\n�������� ����, ������� ���������� ��������: ";
                    cin >> field;
                    edit_st(station, code, field);
                    break;

                    case 4:
                    get_st(station);
                    break;

                    case 5:
                    saveToFile_st(station);
                    break;

                    default:
                    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                    cout << "! ������. ��������� ����� !" << endl;
                    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                    break;
                }
            }
            break;

            case 2:
            vibor = 1;
            buses.clear();
            file.open("Bus.txt");
            while (file >> bus.code >> bus.marka >> bus.number >> bus.capacity)
                buses.push_back(bus);
            file.close();

            while (vibor != 0)
            {
                cout << "1 - ��������\n2 - �������\n3 - �������������\n4 - ������� ������\n5 - ��������� ��������� � ����\n0 - ��������� � ������ �������\n\n�������� ��������: ";
                cin >> vibor;
                int code, capacity, field;
                string number, marka;
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
                    add_bus(buses,marka, number, capacity);
                    break;

                    case 2:
                    cout << "������� ���: ";
                    cin >> code;
                    del_bus(buses, code);
                    break;

                    case 3:
                    cout << "������� ���: ";
                    cin >> code;
                    cout << "1 - ���\n2 - �����\n3 - ��������������� �����\n4 - �����������\n�������� ����, ������� ���������� ��������: ";
                    cin >> field;
                    edit_bus(buses, code, field);
                    break;

                    case 4:
                    get_bus(buses);
                    break;

                    case 5:
                    saveToFile_bus(buses);
                    break;

                    default:
                    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                    cout << "! ������. ��������� ����� !" << endl;
                    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                    break;
                }
            }
            break;

            case 3:
            vibor = 1;
            flights.clear();
            file.open("Flights.txt");
            while (file >> fl.code_fl >> fl.code_st >> fl.code_bus >> fl.time)
                flights.push_back(fl);
            file.close();

            while (vibor != 0)
            {
                cout << "1 - ��������\n2 - �������\n3 - �������������\n4 - ������� ������\n5 - ��������� ��������� � ����\n0 - ��������� � ������ �������\n\n�������� ��������: ";
                cin >> vibor;
                int code_bus,  code_st, code_fl, field;
                string time;
                switch (vibor)
                {
                    case 0:
                    break;

                    case 1:
                    cout << "������� ��� �������: ";
                    cin >> code_st;
                    cout << "������� ��� ��������: ";
                    cin >> code_bus;
                    cout << "������� ���������������� �����������: ";
                    cin >> time;
                    add_fl(flights, code_st, code_bus, time);
                    break;

                    case 2:
                    cout << "������� ��� �����: ";
                    cin >> code_fl;
                    del_fl(flights, code_fl);
                    break;

                    case 3:
                    cout << "������� ��� �����: ";
                    cin >> code_fl;
                    cout << "1 - ��� �����\n2 - ��� �������\n3 - ��� ��������\n4 - ����� �����������\n�������� ����, ������� ���������� ��������: ";
                    cin >> field;
                    edit_fl(flights, code_fl, field);
                    break;

                    case 4:
                    get_fl(flights);
                    break;

                    case 5:
                    saveToFile_fl(flights);
                    break;

                    default:
                    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                    cout << "! ������. ��������� ����� !" << endl;
                    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                    break;
                }
            }
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
///���� ����������: 16.05.2020