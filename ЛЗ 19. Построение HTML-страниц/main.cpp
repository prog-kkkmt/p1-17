#include <iostream>
#include <vector>
#include <fstream>
#include <clocale>
#include <locale>

#include "Buyers.hpp"
#include "BuyersMenu.hpp"

#include "Managers.hpp"
#include "ManagersMenu.hpp"

#include "Cars.hpp"
#include "CarsMenu.hpp"

#include "Sales.hpp"
#include "SalesMenu.hpp"

#include "AboutProg.hpp"

using namespace std;

const int EXITCODEMAIN = 6;

int chooseMenu(){
                //if (setlocale(LC_ALL, "Russian") == NULL){
                    //puts("Unable to set locale");
                //}

                cout << "0: Покупатели" << endl;
                cout << "1: Менеджеры" << endl;
                cout << "2: Автомобили" << endl;
                cout << "3: Продажи" << endl;
                cout << "4: Печать в html" << endl;
                cout << "5: О программе" << endl;
                cout << "6: Выход" << endl;

                cout << "Выберите таблицу: ";

                int code;
                cin >> code;

                cout << endl;

                return code;
}

int main(){
    setlocale (LC_ALL, "Russian");

    Buyers buyersTable = Buyers();
    buyersTable.addRow(1, "BuyerFirst");
    buyersTable.addRow(3, "BuyerThird");
    buyersTable.addRow(4, "BuyerThourth");
    buyersTable.addRow(2, "BuyerSecond");

    Managers managersTable = Managers();
    managersTable.addRow(1, "ManagerFirst");
    managersTable.addRow(3, "ManagerThird");
    managersTable.addRow(4, "ManagerThourth");
    managersTable.addRow(2, "ManagerSecond");

    Cars carsTable = Cars();
    carsTable.addRow(1, "CarFirst");
    carsTable.addRow(3, "CarThird");
    carsTable.addRow(4, "CarThourth");
    carsTable.addRow(2, "CarSecond");

    Sales salesTable = Sales();
    salesTable.addRow(1, 21, "n51m24", 41, "01.01.2001", 101);
    salesTable.addRow(3, 23, "forDelete", 43, "03.03.2003", 103);
    salesTable.addRow(4, 24, "u72y2q", 44, "04.04.2004", 104);
    salesTable.addRow(2, 22, "ha451a", 42, "02.02.2002", 102);

    int code;

    ofstream f("test.txt");

    do{
        code = chooseMenu();




        //if (setlocale(LC_ALL, "Russian") == NULL){
            //puts("Unable to set locale");
        //}

        switch(code){
            case 0:{
                menu(buyersTable, f);
                break;
            }
            case 1:{
                menu(managersTable, f);
                break;
            }
            case 2:{
                menu(carsTable, f);
                break;
            }
            case 3:{
                menu(salesTable, f);
                break;
            }
            case 4:{
                ofstream f2("test.html");

                buyersTable.printToHtml(f2);
                managersTable.printToHtml(f2);
                carsTable.printToHtml(f2);
                salesTable.printToHtml(f2);
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

    }while (code != EXITCODEMAIN);



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
