/**Статьи затрат (Код статьи, название)
Изделия(Код изделия, название)
Калькуляция (Код калькуляции, Код изделия, Код статьи, сумма)
План выпуска (Код плана, Код изделия, количество)

Источник: Экономическая информатика: лабораторный практикум / сост. О.В. Гусятинер, Л.Б. Гусятинер. –
Ковров: ГОУ ВПО «КГТА имени В.А. Дегтярева», 2009
https://nsportal.ru/sites/default/files/2020/05/05/ekon._inf.pdf

Выполнила: Попкова Алена П1-17
18.05.2020**/*/
#include <iostream>
#include "Costing.hpp"
#include "Release.hpp"
#include "CostItems.hpp"
#include "Products.hpp"


using namespace std;

int main()
{
    int num;
    setlocale(LC_ALL, "Russian");
    cout << "Введите номер таблицы для работы с ней:" << endl;
    cout << "0: Статьи затрат (Код статьи, Название)" << endl;
    cout << "1: Изделия (Код изделия, Название)" << endl;
    cout << "2: Калькуляция (Код калькуляции, Код изделия, Код статьи, сумма)" << endl;
    cout << "3: План выпуска (Код плана, Код изделия, Количество)" << endl;
    cout << "4: Выход" << endl;

    do{
        cout << "Введите номер таблицы для работы с ней: ";
        cin >> num;

        switch(num)
        {
        case 0:
            funcCostItem();
            break;
        case 1:
            funcProduct();
            break;
        case 2:
            funcCosting();
            break;
        case 3:
            funcRelease();
            break;
        case 4:
            cout << "Goodbye";
            break;
        default:
            cout << "Error" << endl;
        }
    } while (num != 4);
    return 0;
}
