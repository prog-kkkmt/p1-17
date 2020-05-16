///ЛЗ 10_11
///Выполнил cтудент группы П1-17 Канавская Мария
///МДК.01.02 "Прикладное программирование"
///Составитель: Гусятинер Л.Б., 12.05.2020, МГОТУ ККМТ, П1-17, П2-17
///Задание про домашний бюджет. 7 вариант.
///Задания для самостоятельных работ с использованием MS Access и MS Excel
///ЗАДАНИЕ 1. В базе данных хранятся сведения о ежедневных тратах по
///статьям расходов.
///Таблицы: Статьи расходов (Код статьи, название); Разделы
///(Код раздела, название раздела, Код статьи, единица измерения); Расходы (Код расхода, Код раздела, дата, количество, цена). Например,
///продукты являются статьей, а черный хлеб – разделом.
///Определить:
///– месячный бюджет семьи;
///– долю каждой статьи в общем бюджете.
///ЗАДАНИЕ 2. Доработать программу из лабораторного занятия 10.
///Добавить пункты меню для ввода, редактирования, удаления и печати всех таблиц задания.
///16.05.2020

#include <iostream>
#include <locale>
#include <string>

using namespace std;

struct Stat
{
    int kod_stat;
    char naz[100];
};

struct Razd
{
    int kod_razd, kod_stat;
    string name_razd, ed_izm;
};

struct Rash
{
    int kod_rash, kod_razd, kolvo, tsena;
    string data;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Razd r[100];
    Rash ra[100];
    int a, b, i;

    cout << "Домашний бюджет" << endl;

    cout << "Введите кол-во разделов." << endl;
    cin >> a;

    if (a != 0)
        cout << "Введите: код раздела, название раздела, код статьи, единицу измерения." << endl;

    for (i = 0; i < a; ++i)
    {
        cin >> r[i].kod_razd >> r[i].name_razd >> r[i].kod_stat >> r[i].ed_izm;
    }
    cout << "Введите кол-во расходов." << endl;
    cin >> b;

    if (b != 0)
        cout << "Введите: код расходов, код раздела, дату, количество, цена" << endl;

    for (i = 0; i < b; ++i)
    {
        cin >> ra[i].kod_rash >> ra[i].kod_razd >> ra[i].data >> ra[i].kolvo >> ra[i].tsena;
    }
    int m;
    cout << "1 - месячный бюджет семьи" << endl;
    cout << "2 - доля каждой статьи в общем бюджете" << endl;
    cout << "3 - информаиця о программе" << endl;
    cout << "0 - выход" << endl;
    cin >> m;

      while ((m == 1) || (m == 2) || (m == 3))
    {
        if (m == 1)
        {
            int sum = 0;
            for (i = 0; i < b; ++i)
            {
                sum += ra[i].tsena;
            }

            cout << "Месячный бюджет семьи: " << sum << endl;
        }

        if (m == 2)
        {
            int sum = 0;
            for (i = 0; i < b; ++i)
            {
                sum += ra[i].tsena;
            }
            int dol;
        for (i = 0; i < b; ++i)
            {
                dol = (sum / ra[i].tsena) * 100;
            }
              cout << "Доля каждой статьи в общем бюджете: " << dol << endl;
        }
        if (m == 3)
        {

            cout << "Выполнил студент группы П1-17 Мария Канавская. Задание записано в коде." << endl;
        }
        cin >> m;
}
return 0;
}
