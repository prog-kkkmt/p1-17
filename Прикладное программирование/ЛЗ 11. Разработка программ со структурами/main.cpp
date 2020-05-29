/**
Доработать программу из лабораторного занятия 10.
Добавить пункты меню для ввода, редактирования, удаления и печати всех таблиц задания.

Таблицы:
Станции (Код станции, Название станции);
Автобусы (Код автобуса, Марка автобуса, Государственный номер, Вместимость);
Рейсы (Код рейса, Код станции, Код автобуса, Время отправления).
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
        cout << "1 - Таблица \"Станции\"\n2 - Таблица \"Автобусы\"\n3 - Таблица \"Рейсы\"\n0 - Выход\n\nВыберите, с какой таблицей вы хотите работать: ";
        cin >> table;//выбор таблицы (списка)

        switch(table)
        {
            case 0:
            break;

            case 1://если выбрана таблица "Станции"
                vibor = 1;
                station.clear();
                file.open("Station.txt");
                while (file >> st.code >> st.name)
                    station.push_back(st);//забираем информацию из текстового файла
                file.close();
                
                while (vibor != 0)//пока пользователь не решит закончить работу с этой таблицей
                {
                    cout << "1 - Добавить\n2 - Удалить\n3 - Редактировать\n4 - Вывести список\n5 - Сохранить изменения в файл\n0 - Вернуться к выбору таблицы\n\nВыберите действие: ";                    
                    cin >> vibor;//выбор действия
                    string name;
                    int code, field;
                    switch (vibor)
                    {
                        case 0:
                        break;

                        case 1://добавить станцию
                            cout << "Введите название: ";
                            cin >> name;
                            add_st(station, name);
                        break;

                        case 2://удалить станцию
                            cout << "Введите код: ";
                            cin >> code;
                            del_st(station, code);
                        break;

                        case 3://изменить поле станции
                            cout << "Введите код: ";
                            cin >> code;
                            cout << "1 - Код\n2 - Название\n\nВыберите поле, которое необходимо изменить: ";
                            cin >> field;
                            edit_st(station, code, field);
                        break;

                        case 4://вывести список станций
                            get_st(station);
                        break;

                        case 5://сохранить изменения списка станций в файл
                            saveToFile_st(station);
                        break;

                        default://в случае некорректно выбранного действия
                            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                            cout << "! Ошибка. Повторите выбор !" << endl;
                            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                        break;
                    }
                }
            break;

            case 2://если выбрана таблица "Автобусы"
                vibor = 1;
                buses.clear();
                file.open("Bus.txt");
                while (file >> bus.code >> bus.marka >> bus.number >> bus.capacity)
                    buses.push_back(bus);//забираем информацию из текстового файла
                file.close();

                while (vibor != 0)//пока пользователь не решит закончить работу с этой таблицей
                {
                    cout << "1 - Добавить\n2 - Удалить\n3 - Редактировать\n4 - Вывести список\n5 - Сохранить изменения в файл\n0 - Вернуться к выбору таблицы\n\nВыберите действие: ";
                    cin >> vibor;//выбор действия
                    int code, capacity, field;
                    string number, marka;
                    switch (vibor)
                    {
                        case 0:
                        break;

                        case 1://добавить автобус
                            cout << "Введите марку: ";
                            cin >> marka;
                            cout << "Введите государственный номер: ";
                            cin >> number;
                            cout << "Введите вместимость: ";
                            cin >> capacity;
                            add_bus(buses,marka, number, capacity);
                        break;

                        case 2://удалить автобус
                            cout << "Введите код: ";
                            cin >> code;
                            del_bus(buses, code);
                        break;

                        case 3://изменить поле автобуса
                            cout << "Введите код: ";
                            cin >> code;
                            cout << "1 - Код\n2 - Марка\n3 - Государственный номер\n4 - Вместимость\nВыберите поле, которое необходимо изменить: ";
                            cin >> field;
                            edit_bus(buses, code, field);
                        break;

                        case 4://вывести спиок автобусов
                            get_bus(buses);
                        break;

                        case 5://сохранить изменения списка автобусов в файл
                            saveToFile_bus(buses);
                        break;

                        default://в случае некорректно выбранного действия
                            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                            cout << "! Ошибка. Повторите выбор !" << endl;
                            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                        break;
                    }
                }
            break;

            case 3://если выбрана таблица "Рейсы"
                vibor = 1;
                flights.clear();
                file.open("Flights.txt");
                while (file >> fl.code_fl >> fl.code_st >> fl.code_bus >> fl.time)
                    flights.push_back(fl);//забираем информацию из текстового файла
                file.close();

                while (vibor != 0)//пока пользователь не решит закончить работу с этой таблицей
                {
                    cout << "1 - Добавить\n2 - Удалить\n3 - Редактировать\n4 - Вывести список\n5 - Сохранить изменения в файл\n0 - Вернуться к выбору таблицы\n\nВыберите действие: ";
                    cin >> vibor;//выбор действия
                    int code_bus,  code_st, code_fl, field;
                    string time;

                    switch (vibor)
                    {
                        case 0:
                        break;

                        case 1://добавить рейс
                            cout << "Введите код станции: ";
                            cin >> code_st;
                            cout << "Введите код автобуса: ";
                            cin >> code_bus;
                            cout << "Введите время отправления: ";
                            cin >> time;
                            add_fl(flights, code_st, code_bus, time);
                        break;

                        case 2://удалить рейс
                            cout << "Введите код рейса: ";
                            cin >> code_fl;
                            del_fl(flights, code_fl);
                        break;

                        case 3://изменить поле рейса
                            cout << "Введите код рейса: ";
                            cin >> code_fl;
                            cout << "1 - Код рейса\n2 - Код станции\n3 - Код автобуса\n4 - Время отправления\nВыберите поле, которое необходимо изменить: ";
                            cin >> field;
                            edit_fl(flights, code_fl, field);
                        break;

                        case 4://вывести список рейсов
                            get_fl(flights);
                        break;

                        case 5://сохранить изменения списка рейсов в файл
                            saveToFile_fl(flights);
                        break;

                        default://в случае некорректно выбранного действия
                            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                            cout << "! Ошибка. Повторите выбор  !" << endl;
                            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                        break;
                    }
                }
            break;

            default://в случае некорректного выбора таблицы (списка)
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                cout << "! Ошибка. Повторите выбор  !" << endl;
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
            break;
        }
    }
    return 0;
}

///Выполнила: Фролова Л.А.
///Дата выполнения: 16.05.2020
