#include "flights.hpp"

void get_fl(vector <Flights> flights)//функция возвращает список рейсов
{
    for (int i = 0; i < flights.size(); i++)
    {
        cout << flights[i].code_fl << " ";
        cout << flights[i].code_st << " ";
        cout << flights[i].code_bus << " ";
        cout << flights[i].time << endl;
    }
    cout << endl;
}

void add_fl(vector <Flights> &flights, int code_st, int code_bus, string time)//функция добавляет рейс в список
{
    Flights fl;
    fl.code_fl = flights[flights.size() - 1].code_fl + 1;
    fl.code_st = code_st;
    fl.code_bus = code_bus;
    fl.time = time;
    flights.push_back(fl);
    cout << endl;
}

void del_fl(vector <Flights> &flights, int code_fl)//функция удаляет рейс по его коду
{
    int proverka = 0;
    for (int i = 0; i < flights.size(); i++)
        if (flights[i].code_fl == code_fl)
        {
            proverka = 1;
            flights.erase(flights.begin() + i);
            break;
        }
    if (proverka == 0)
            cout << "Рейс с таким кодом не содержится в списке\n" << endl;
    cout << endl;
}

void edit_fl(vector <Flights> &flights, int code_fl, int field)//функция меняет значение поля по коду рейса
{
    string value_str;
    int value_int, i = 0, proverka = 0;
    for (int i = 0; i < flights.size(); i++)
        if (flights[i].code_fl == code_fl)
        {
            proverka = 1;
            switch (field)
            {
                case 1:
                cout << "Введите новый код рейса: ";
                cin >> value_int;
                flights[i].code_fl = value_int;
                break;

                case 2:
                cout << "Введите новый код станции: ";
                cin >> value_int;
                flights[i].code_st = value_int;
                break;

                case 3:
                cout << "Введите новый код автобуса: ";
                cin >> value_int;
                flights[i].code_bus = value_int;
                break;

                case 4:
                cout << "Введите новое время отправления: ";
                cin >> value_str;
                flights[i].time = value_str;
                break;
            }
            break;
        }
    if (proverka == 0)
        cout << "Рейс с таким кодом не содержится в списке\n" << endl;
    cout << endl;
}

void saveToFile_fl(vector <Flights> flights)//сохранить изменения в файл
{
    ofstream file;
    file.open("Flights.txt");
    for (int i = 0; i < flights.size(); i++)
        file << flights[i].code_fl << " " << flights[i].code_st << " " << flights[i].code_bus << " " << flights[i].time << endl;
    file.close();
    cout << endl;
}
