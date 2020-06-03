#include <iostream>
#include <vector>
#include <fstream>
#include "Sales.hpp"

using namespace std;

int menu(Sales &salesTable);
void AboutProg(ofstream &f);

int main(){
    Sales salesTable = Sales();
    salesTable.addRow(1, 21, "n51m24", 41, "01.01.2001", 101);
    salesTable.addRow(3, 23, "forDelete", 43, "03.03.2003", 103);
    salesTable.addRow(4, 24, "u72y2q", 44, "04.04.2004", 104);
    salesTable.addRow(2, 22, "ha451a", 42, "02.02.2002", 102);

    menu(salesTable);

    /*
    cout << salesTable;
    cout << endl;
    salesTable.deleteRow(2);
    cout << salesTable;
    cout << endl;
    salesTable.sortRows(MANAGERCODE, ASC);
    cout << salesTable;
    cout << endl;
    salesTable.changeIntRow(3, MANAGERCODE, 3);
    cout << salesTable;
    */

    return 0;
}

int menu(Sales &salesTable)
{
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
            case 0:{
                int mC, cC, bC, p;
                string lP, d;
                cin >> mC >> cC >> lP >> bC >> d >> p;
                salesTable.addRow(mC, cC, lP, bC, d, p);
                f << "Добавление записи. Done!" << endl;
                break;
            }
            case 1:{
                int n;
                cout << "Введите номер строки: ";
                cin >> n;

                salesTable.deleteRow(n);

                f << "Удаление записи. Done!" << endl;
                break;
            }
            case 2:{
                int n;
                cout << "Введите номер строки: ";
                cin >> n;
                cout << "Выберите поле для изменения: ";

                int code;
                cin >> code;
                cout << "0: Код менеджера" << endl;
                cout << "1: Код машины" << endl;
                cout << "2: Государственный номер" << endl;
                cout << "3: Код покупателя" << endl;
                cout << "4: Дата" << endl;
                cout << "5: Цена" << endl;

                cout << "Введите новое значение: ";

                switch (code){
                    case LICENSEPLATE:
                        ;
                    case DATE:{
                        string newStrValue;
                        cin >> newStrValue;
                        salesTable.changeStrRow(n, code, newStrValue);
                        break;
                    }
                    case MANAGERCODE:
                        ;
                    case CARCODE:
                        ;
                    case BUYERCODE:
                        ;
                    case PRICE:{
                        int newIntValue;
                        cin >> newIntValue;
                        salesTable.changeIntRow(n, code, newIntValue);
                        break;
                    }
                    default:
                        cout << "Error";
                }

                f << "Редактирование записи. Done!" << endl;
                break;
            }
            case 3:{
                f << salesTable;
                f << endl;
                f << "Вывод в файл. Done!" << endl;
                break;
            }
            case 4:{
                int pole;
                cout << "Выберите поле для сортировки" << endl;
                cin >> pole;

                int order;
                cout << "Выберите тип сортировки" << endl;
                cout << "0: По убыванию" << endl;
                cout << "1: По возрастанию" << endl;
                cin >> order;
                salesTable.sortRows(pole, order);
                f << "Сортировка. Done!" << endl;
                break;
            }
            case 5:{
                AboutProg(f);
                break;
            }
            case 6:{
                cout << "Выход" << endl;
                break;
            }
            default:
                cout << "Error" << endl;
        }

    }while (num != 6);
}

void AboutProg(ofstream &f)
{
    f << "Продажи (Код менеджера, Код автомобиля, Государственный номер, Код покупателя, дата, цена)" << endl;
    f << "Источник: Экономическая информатика: лабораторный практикум / сост. О.В. Гусятинер, Л.Б. Гусятинер. – Ковров: ГОУ ВПО «КГТА имени В.А. Дегтярева», 2009" << endl;
    f << "https://nsportal.ru/sites/default/files/2020/05/05/ekon._inf.pdf" << endl;
    f << "Выполнил: Богомолов Максим П1-17" << endl;
    f << "15.05.2020"<< endl;
    f << "Функции программы:  Добавление записи, Удаление записи, Редактирование записи, Печать в файл, Сортировка, Вывод информаци \"О программе\" в файл" << endl;
}
