#include <iostream>
#include <vector>
#include <fstream>
#include <clocale>

#include "Cars.hpp"
#include "AboutProg.hpp"

const int CARCODE = 0;
const int MODEL = 1;

const int DEC = 0;
const int ASC = 1;

const int EXITCODECARS = 6;

int chooseFieldInCars(){
                //if (setlocale(LC_ALL, "Russian") == NULL){
                    //puts("Unable to set locale");
                //}

                cout << "0: Код машины" << endl;
                cout << "1: Марка" << endl;

                cout << "Выберите поле для изменения: ";

                int code;
                cin >> code;

                cout << endl;

                return code;
}

int menu(Cars &carsTable, ofstream &f)
{
    int num;

    //if (setlocale(LC_ALL, "") == NULL){
    //    puts("Unable to set locale");
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
                int bC;
                string nm;
                cin >> bC >> nm;
                carsTable.addRow(bC, nm);
                f << "Добавление записи. Done!" << endl;
                break;
            }
            case 1:{
                int n;
                cout << "Введите номер строки: ";
                cin >> n;

                carsTable.deleteRow(n);

                f << "Удаление записи. Done!" << endl;
                break;
            }
            case 2:{
                int n;
                cout << "Введите номер строки: ";
                cin >> n;

                int code = chooseFieldInCars();

                cout << "Введите новое значение: ";
                switch (code){
                    case MODEL:{
                        string newStrValue;
                        cin >> newStrValue;
                        carsTable.changeStrRow(n, code, newStrValue);
                        break;
                    }
                    case CARCODE:{
                        int newIntValue;
                        cin >> newIntValue;
                        carsTable.changeIntRow(n, code, newIntValue);
                        break;
                    }
                    default:
                        cout << "Error";
                }

                f << "Редактирование записи. Done!" << endl;
                break;
            }
            case 3:{
                f << carsTable;
                f << endl;
                f << "Вывод в файл. Done!" << endl;
                break;
            }
            case 4:{
                cout << "Выберите поле для сортировки" << endl;
                int code = chooseFieldInCars();

                int order;
                cout << "Выберите тип сортировки" << endl;
                cout << "0: По убыванию" << endl;
                cout << "1: По возрастанию" << endl;
                cin >> order;
                carsTable.sortRows(code, order);
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

    }while (num != EXITCODECARS);

    return 0;
}
