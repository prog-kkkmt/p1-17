/*Туристский клуб организует одно – и многодневные пешеходные туры в группах с руководителем по разным маршрутам и разной
категории сложности.
Таблицы:
Маршруты (Код маршрута, название, продолжительность, категория сложности);
Руководители (Код руководителя, ФИО,телефон);
Группы (Код группы, название группы, Код маршрута, Код
руководителя, количество туристов, дата отправления).
Требуется:
– определить перечень групп на маршруте;
– построить сравнительную диаграмму количества туристов по
уровню сложности маршрутов.

*/


#include <iostream>
#include <windows.h>

using namespace std;

struct marshrut
{
    int kod_marsh;
    char prodol_marsh, kategor_slosh ;
    string nazvan_marsh;
};

struct rukovodit
{
    int kod_rukovod, tel_rukovod ;
    string fio;

};

struct gruppa
{
    int kod_grup, kod_marsh, kod_rukovod, kol_turist, data_otprav;
    string nazvan_grup;

};

int main()
{
      setlocale(LC_ALL, "Rus");
      marshrut m[50];
      rukovodit r[50];
      gruppa g[100];
      int n, a, b, i, n1, n2;

    cout << "Сколько всего маршрутов?" << endl;
    cin >> n;

    if (n != 0) cout << "Введите: код маршрута, название, продолжительность, категория сложности" << endl;

    for (i = 0; i < n; ++i)
    {
        cin >> m[i].kod_marsh >> m[i].prodol_marsh >> m[i].kategor_slosh >> m[i].nazvan_marsh;
    }

    cout << "Сколько всего руководителей?" << endl;
    cin >> n1;

    if (n1 != 0) cout << "Введите: код руководителя, телефон руководителя, ФИО" << endl;

    for (i = 0; i < n1; ++i)
    {
        cin >> r[i].kod_rukovod >> r[i].tel_rukovod >> r[i].fio;
    }
    cout << "Сколько всего групп?" << endl;
    cin >> n2;

    if (n2 != 0) cout << "Введите: код группы, код маршрута, код руководителя, кол-во туристов, дата отправления, название группы" << endl;

    for (i = 0; i < n2; ++i)
    {
        cin >> g[i].kod_grup >> g[i].kod_marsh >> g[i].kod_rukovod >> g[i].kol_turist >> g[i].data_otprav >> g[i].nazvan_grup;
    }
     int menu; ///Меню
    cout << "1 - Общее число групп" << endl;
    cout << "2 - число автобусов" << endl;
    cout << "3 - кол-во туристов " << endl;
    cout << "0 - Выход" << endl;
    cin >> menu;

    while ((menu == 1) || (menu == 2) || (menu == 3)  || (menu == 4))
    {
        if (menu == 1)
        {
             for (i = 0; i < n; i++)
    {
        cout << m[i].kod_marsh << m[i].prodol_marsh << m[i].kategor_slosh << m[i].nazvan_marsh;
    }
        }

        if (menu == 2)
        {
             for (i = 0; i < a; i++)
    {
        cout << r[i].kod_rukovod << r[i].tel_rukovod << r[i].fio;
    }
        }
        if (menu == 3)
        {
             for (i = 0; i < b; i++)
    {
        cout << g[i].kod_grup << g[i].kod_marsh << g[i].kod_rukovod << g[i].kol_turist << g[i].data_otprav << g[i].nazvan_grup;
    }
        }

         cout << "1 - Общее число групп" << endl;
         cout << "2 - число автобусов" << endl;
         cout << "3 - кол-во туристов " << endl;
         cout << "0 - Выход" << endl;
         cin >> menu;
    }
}
