#include "functionsForBuses.hpp"

void get(vector <Bus> buses)//функция возвращает список автобусов
{
    for (int i = 0; i < buses.size(); i++)
    {
        cout << buses[i].code << " ";
        cout << buses[i].marka << " ";
        cout << buses[i].number << " ";
        cout << buses[i].capacity << endl;
    }
    cout << endl;
}

void add(vector <Bus> &buses, string marka, string number, int capacity)//функция добавляет новый автобус в список
{
    Bus bus;
    bus.code = buses[buses.size() - 1].code + 1;//код автобуса генерируется сам
    bus.marka = marka;
    bus.number = number;
    bus.capacity = capacity;
    buses.push_back(bus);
    cout << endl;
}

void del(vector <Bus> &buses, int code)//функция удаляет автобус (по коду)  из списка 
{
    int proverka = 0;
    for (int i = 0; i < buses.size(); i++)
        if (buses[i].code == code)
        {
            proverka = 1;
            buses.erase(buses.begin() + i);
            break;
        }
    if (proverka == 0)
            cout << "Автобус с таким кодом не содержится в списке\n" << endl;
    cout << endl;
}

void edit(vector <Bus> &buses, int code, int field)//функция изменяет выбранное поле field (указывается номер поля) автобуса с кодом code
{
    string value_str;
    int value_int, i = 0, proverka = 0;
    for (int i = 0; i < buses.size(); i++)
        if (buses[i].code == code)
        {
            proverka = 1;
            switch (field)
            {
                case 1:
                cout << "Введите новый код: ";
                cin >> value_int;
                buses[i].code = value_int;
                break;

                case 2:
                cout << "Введите новую марку: ";
                cin >> value_str;
                buses[i].marka = value_str;
                break;

                case 3:
                cout << "Введите новый государственный номер: ";
                cin >> value_str;
                buses[i].number = value_str;
                break;

                case 4:
                cout << "Введите новую вместимость: ";
                cin >> value_int;
                buses[i].capacity = value_int;
                break;
            }
            break;
        }
    if (proverka == 0)
        cout << "Автобус с таким кодом не содержится в списке\n" << endl;
    cout << endl;
}

void saveToFile(vector <Bus> buses)//функция сохраняет изменения в текстовой файл
{
    ofstream file;
    file.open("Bus.txt");
    for (int i = 0; i < buses.size(); i++)
        file << buses[i].code << " " << buses[i].marka << " " << buses[i].number << " " << buses[i].capacity << endl;
    file.close();
}
