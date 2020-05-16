/**
По номеру в электронном журнале выбрать задание из раздела
"Задания для самостоятельных работ с использованием MS Access и MS Excel"
Выбрать одну (любую) таблицу.
Для выбранной таблицы разработать проект с меню, реализующий возможности
добавления, удаления, редактирования, вывода списка экземпляров таблицы.
Подготовить контрольный пример.

Номер варианта: №1 (21 % 20)
Таблица: Автобусы(Код автобуса, Марка автобуса, Государственный номер, Вместимость)
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
        cout << "1 - Добавить\n2 - Удалить\n3 - Редактировать\n4 - Вывести список\n5 - Сохранить изменения в файл\n0 - Выход\n\nВыберите действие: ";
        cin >> vibor;
        switch (vibor)
        {
            case 0:
            break;

            case 1:
            cout << "Введите марку: ";
            cin >> marka;
            cout << "Введите государственный номер: ";
            cin >> number;
            cout << "Введите вместимость: ";
            cin >> capacity;
            add(buses,marka, number, capacity);
            break;

            case 2:
            cout << "Введите код: ";
            cin >> code;
            del(buses, code);
            break;

            case 3:
            cout << "Введите код: ";
            cin >> code;
            cout << "1 - Код\n2 - Марка\n3 - Государственный номер\n4 - Вместимость\nВыберите поле, которое необходимо изменить: ";
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
            cout << "! Ошибка. Повторите выбор !" << endl;
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
            break;
        }
    }
    return 0;
}

///Выполнила: Фролова Л.А.
///Дата выполнения: 15.05.2020

