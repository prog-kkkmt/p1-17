/*
15.05.2020
ЛЗ 10 - 11
Выполнил работу Бобнев Алексей П1-17.
Задание про автовокзалы. 1 вариант.
Задания для самостоятельных работ с использованием MS Access и MS Excel
Источник: https://nsportal.ru/sites/default/files/2020/05/05/ekon._inf.pdf
Страница 62.
Автобусы производят рейсы до станций по расписанию. Каждый
автобус вмещает не более определенного количества пассажиров.
Таблицы: Станции (Код станции, Название станции); Автобусы
(Код автобуса, Марка автобуса, Государственный номер, Вместимость);
Рейсы (Код рейса, Код станции, Код автобуса, Время отправления).
Определить:
– сколько выполняется рейсов до каждой станции?
– каково общее количество пассажиров?
*/

#include <iostream>
#include <windows.h>

using namespace std;

struct Stan
{
    int kod_stan;
    char naz[100];
};

struct Bus
{
    int kod_bus, number, vmest;
    string marka;

};

struct Reis
{
    int kod_reis, kod_stan, kod_bus;
    char time[100];

};

void swap_string(string *x, string *y)
{
    string marka = *x;
    *x = *y;
    *y = marka;
}

void swap_int(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Автовокзал V 0.0.1." << endl; ///Название программы

    Bus b[100];
    Reis r[100];

    int n; ///Количество автобусов
    int i, n1;


    cout << "Сколько всего автобусов?" << endl;
    cin >> n;

    if (n != 0) cout << "Введите: код автобуса, марку автобуса, гос-номер и вместимость автобуса" << endl;

    for (i = 0; i < n; ++i)
    {
        cin >> b[i].kod_bus >> b[i].marka >> b[i].number >> b[i].vmest;
    }

    cout << "Сколько всего рейсов?" << endl;
    cin >> n1;

    if (n1 != 0) cout << "Введите: код рейса, код станции, код автобуса и время отправления" << endl;

    for (i = 0; i < n1; ++i)
    {
        cin >> r[i].kod_reis >> r[i].kod_stan >> r[i].kod_bus >> r[i].time;
    }

    int menu; ///Меню
    cout << "1 - Общее число пассажиров" << endl;
    cout << "2 - О программе" << endl;
    cout << "3 - Сортировка по возрастанию" << endl;
    cout << "4 - Количество рейсов для каждой станции" << endl;
    cout << "5 - Вывод информации об автобусов" << endl;
    cout << "6 - Добавление автобусов" << endl;
    cout << "0 - Выход" << endl;
    cin >> menu;

    while ((menu == 1) || (menu == 2) || (menu == 3)  || (menu == 4) || (menu == 5) || (menu == 6))
    {
        if (menu == 1)
        {
            int kol = 0;
            for (i = 0; i < n; ++i)
            {
                kol += b[i].vmest;
            }
            cout << "Общее количество пассажиров: " << kol << endl;
        }

        if (menu == 2)
        {

            cout << "Выполнил программу про автовокзал Бобнев Алексей П1-17 (1 вариант)" << endl;
        }

        if (menu == 3)
        {
            int j;
            for (i = 0; i < n; ++i)
                for (j = 0; j < n - 1; ++j)
                {
                    if (b[j].vmest < b[j + 1].vmest)
                    {
                        swap_int(&b[j].kod_bus, &b[j + 1].kod_bus);///Использование собственной функции

                        swap_string(&b[j].marka, &b[j + 1].marka);///Использование собственной функции

                        swap_int(&b[j].number, &b[j + 1].number);///Использование собственной функции

                        swap_int(&b[j].vmest, &b[j + 1].vmest);///Использование собственной функции
                    }
                }

            for (i = 0; i < n; ++i)
                cout << b[i].kod_bus << " " << b[i].marka << " " << b[i].number << " " << b[i].vmest << endl;
        }

        if (menu == 4)
        {
            int n2, i, n3, j, p = 0, p1 = 0;
            for (i = 0; i < n1; ++i)
            {
                n2 = 0;
                n3 = r[i].kod_stan;
                for (j = 0; j < n1; ++j)
                    if (n3 == r[j].kod_stan) n2++;

                cout << r[i].kod_stan << " " << n2 << endl;
            }
        }

        if (menu == 5)
        {
            for (i = 0; i < n; ++i)
            {
                cout << b[i].kod_bus << " " << b[i].marka << " " << b[i].number << " " << b[i].vmest << endl;
            }
        }

        if (menu == 6)
        {
            cin >> b[n].kod_bus >> b[n].marka >> b[n].number >> b[n].vmest;
            n++;
        }

        cout << "1 - Общее число пассажиров" << endl;
        cout << "2 - О программе" << endl;
        cout << "3 - Сортировка по возрастанию" << endl;
        cout << "4 - Количество рейсов для каждой станции" << endl;
        cout << "5 - Вывод информации об автобусов" << endl;
        cout << "6 - Добавление автобусов" << endl;
        cout << "0 - Выход" << endl;
        cin >> menu;
    }

    return 0;
}
