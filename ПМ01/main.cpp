///Билет №2. Автосалон
///Менеджеры автосалона осуществляют продажу клиентам автомобилей различных марок.
///Таблицы: Покупатели (Код покупателя, ФИО), Менеджеры (Код менеджера, ФИО), Автомобили(код, марка), Продажи(Код менеджера, код автомобиля,
///государственный номер, код покупателя, дата, цена).
///Определить:
///-среднюю сумму сделки
///-долю продаж автомобилей разных марок.

///Выполнил студент группы П1-17 Канавская Мария

#include <iostream>
#include <locale>
#include <string>
#include "mod.h"


using namespace std;



int main()
{
    setlocale(LC_ALL, "Russian");
    Pokypateli p[100];
    Menejer me[100];
    Avtomobili av[100];
    Prodaji pr[100];

    int a, b, i;

    cout << "Автосалон" << endl;

    cout << "Введите кол-во покупателей." << endl;
    cin >> a;

    if (a != 0)
        cout << "Введите: код покупателя, ФИО." << endl;

    for (i = 0; i < a; ++i)
    {

        cin >> p[i].kod_pok >> p[i].fio;
    }
    cout << "Введите кол-во менеджеров." << endl;
    cin >> b;

    if (b != 0)
        cout << "Введите: код менеджера, ФИО" << endl;

    for (i = 0; i < b; ++i)
    {
        cin >> me[i].kod_men >> me[i].fio;
    }
    cout << "Введите кол-во автомобилей." << endl;
    cin >> b;
    int kolavto = b;

    if (b != 0)
        cout << "Введите: код автомобиля, марка" << endl;

    for (i = 0; i < b; ++i)
    {
        cin >> av[i].kod_avto >> av[i].marka;
    }

    cout << "Введите кол-во продаж." << endl;
    cin >> b;

    if (b != 0)
        cout << "Введите: код менеджера, код автомобиля, государственный номер, код покупателя, дата, цена" << endl;

    for (i = 0; i < b; ++i)
    {
        cin >> pr[i].kod_men >> pr[i].kod_avto >> pr[i].gos_nomer >> pr[i].kod_pok >> pr[i].data >> pr[i].cena;
    }
    int m;


    while (true)
    {
        cout << "1 - средняя сумма сделки" << endl;
        cout << "2 - доля продаж автомобилей разных марок" << endl;
        cout << "0 - выход" << endl;
        cin >> m;
        if (m == 0)
            break;
        if (m == 1)
        {
            int kolvo = 0;
            float sred = 0;
            for (i = 0; i < b; ++i)
            {
                sred += pr[i].cena;
            }
            sred /= (float)b;
            cout << "Средняя сумма сделки: " << sred << endl;
        }
        if (m == 2)
        {
            cout << "Доля продаж автомобилей разных марок: " << (float)b / (float)kolavto * 100 << endl;
        }
    }

    cin >> m;
    return 0;
}
