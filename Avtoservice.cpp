#include <iostream>
#include <windows.h>

using namespace std;

struct Data ///Структура
{
    int day, month, year, money;
}d[100];

struct People
{
    string name, fam;
    int number_phone;
}p[100];

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Автосервис V 0.0.1." << endl; ///Название программы

    int menu; ///Меню
    cout << "1 - Выручка" << endl;
    cout << "2 - Сотрудники" << endl;
    cout << "0 - Выход" << endl;
    cin >> menu;

    while ((menu == 1) || (menu == 2))
    {
        if (menu == 1)
        {
            int n; ///Количество записей
            cout << "Введите количество записей:" << endl;
            cin >> n;
            cout << "Введите день, месяц, год и выручку:" << endl;
            int i; ///Переменная для for
            for (i = 0; i < n; i++) cin >> d[i].day >> d[i].month >> d[i].year >> d[i].money;
            for (i = 0; i < n; i++)
            {
                cout << d[i].day << "." << d[i].month
                << "." << d[i].year << " " << d[i].money << " руб." << endl;
            }
        }

        if (menu == 2)
        {
            int n, i;
            cout << "Введите количество записей:" << endl;
            cin >> n;
            cout << "Введите имя, фамилия и номер телефона (Формат 89165555555):" << endl;
            for (i = 0; i < n; i++)
            {
                cin >> p[i].name >> p[i].fam >> p[i].number_phone;
            }

            for (i = 0; i < n; i++)
            {
                cout << p[i].name << " " << p[i].fam << " " << p[i].number_phone << endl;
            }
        }

        cout << "1 - Выручка" << endl;
        cout << "2 - Сотрудники" << endl;
        cout << "0 - Выход" << endl;
        cin >> menu;
    }
    return 0;
}
