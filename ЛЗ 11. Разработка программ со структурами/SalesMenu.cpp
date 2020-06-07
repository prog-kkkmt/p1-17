#include <iostream>
#include <vector>
#include <fstream>

#include "Sales.hpp"
#include "AboutProg.hpp"

const int MANAGERCODE = 0;
const int CARCODE = 1;
const int LICENSEPLATE = 2;
const int BUYERCODE = 3;
const int DATE = 4;
const int PRICE = 5;

const int DEC = 0;
const int ASC = 1;

const int EXITCODESALES = 6;

int chooseFieldInSales(){
                //if (setlocale(LC_ALL, "Russian") == NULL){
                    //puts("Unable to set locale");
                //}

                cout << "0: Код менеджера" << endl;
                cout << "1: Код машины" << endl;
                cout << "2: Государственный номер" << endl;
                cout << "3: Код покупателя" << endl;
                cout << "4: Дата" << endl;
                cout << "5: Цена" << endl;

                cout << "Выберите поле для изменения: ";

                int code;
                cin >> code;

                cout << endl;

                return code;
}

int menu(Sales &salesTable, ofstream &f)
{
    int num;

    //if (setlocale(LC_ALL, "Russian") == NULL){
        //puts("Unable to set locale");
    //}

    do{
        cout << "0: Добавление записи"<< endl;
        cout << "1: Удаление записи"<< endl;
        cout << "2: Редактирование записи"<< endl;
        cout << "3: Печать"<< endl;
        cout << "4: Сортировка" << endl;
        cout << "5: О программе" << endl;
        cout << "6: Выход"<< endl;

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

                int code = chooseFieldInSales();

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
                cout << "Выберите поле для сортировки" << endl;

                int code = chooseFieldInSales();

                int order;
                cout << "Выберите тип сортировки" << endl;
                cout << "0: По убыванию" << endl;
                cout << "1: По возрастанию" << endl;
                cin >> order;
                salesTable.sortRows(code, order);
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

    }while (num != EXITCODESALES);

    return 0;
}
