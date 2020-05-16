/**Калькуляция (Код калькуляции, Код изделия, Код статьи, сумма)
Источник: Экономическая информатика: лабораторный практикум / сост. О.В. Гусятинер, Л.Б. Гусятинер. –
Ковров: ГОУ ВПО «КГТА имени В.А. Дегтярева», 2009
https://nsportal.ru/sites/default/files/2020/05/05/ekon._inf.pdf
Выполнила: Попкова Алена П1-17
15.05.2020**/


#include <iostream>
#include <fstream>
#include <vector>
#include "Costing.hpp"

using namespace std;

int main()
{
    vector <Costing> cost;
    int num;
    ofstream f("test.txt");

    setlocale(LC_ALL, "Russian");

    cout << "0: Добавление записи"<< endl;
    cout << "1: Удаление записи"<< endl;
    cout << "2: Редактирование записи"<< endl;
    cout << "3: Печать"<< endl;
    cout << "4: Сортировка" << endl;
    cout << "5: О программе" << endl;
    cout << "6: Выход"<< endl;

    do{
        cout << "Выберите номер действия: ";
        cin >> num;
        switch(num){
        case 0:
            InPut(cost);
            f << "Добавление записи. Done!" << endl;
            break;
        case 1:
            Remove(cost);
            f << "Удаление записи. Done!" << endl;
            break;

        case 2:
            Edit(cost);
            f << "Редактирование записи. Done!" << endl;
            break;

        case 3:
            OutPut(f, cost);
            f << "Вывод в файл. Done!" << endl;
            break;

        case 4:
            Sort(cost);
            f << "Сортировка. Done!" << endl;
            break;
        case 5:
            AboutProg(f);
            break;
        case 6:
            cout << "Goodbye!" << endl;
            break;

        default:
            cout << "Error" << endl;
        }

    }while (num != 6);
}
