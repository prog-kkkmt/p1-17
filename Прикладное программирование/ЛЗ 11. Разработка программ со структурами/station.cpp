#include "station.hpp"

void get_st(vector <Station> station)
{
    for (int i = 0; i < station.size(); i++)
    {
        cout << station[i].code << " ";
        cout << station[i].name << endl;
    }
    cout << endl;
}

void add_st(vector <Station> &station, string name)
{
    Station st;
    st.code = station[station.size() - 1].code + 1;
    st.name = name;
    station.push_back(st);
    cout << endl;
}

void del_st(vector <Station> &station, int code)
{
    int proverka = 0;
    for (int i = 0; i < station.size(); i++)
        if (station[i].code == code)
        {
            proverka = 1;
            station.erase(station.begin() + i);
            break;
        }
    if (proverka == 0)
            cout << "Станция с таким кодом не содержится в списке\n" << endl;
    cout << endl;
}

void edit_st(vector <Station> &station, int code, int field)
{
    string value_str;
    int value_int, proverka = 0;
    for (int i = 0; i < station.size(); i++)
        if (station[i].code == code)
        {
            proverka = 1;
            switch (field)
            {
                case 1:
                cout << "Введите новое значение поля: ";
                cin >> value_int;
                station[i].code = value_int;
                break;

                case 2:
                cout << "Введите новое значение поля: ";
                cin >> value_str;
                station[i].name = value_str;
                break;
            }
            break;
        }
    if (proverka == 0)
        cout << "Станция с таким кодом не содержится в списке\n" << endl;
    cout << endl;
}

void saveToFile_st(vector <Station> station)
{
    ofstream file;
    file.open("Station.txt");
    for (int i = 0; i < station.size(); i++)
        file << station[i].code << " " << station[i].name << endl;
    file.close();
    cout << endl;
}
