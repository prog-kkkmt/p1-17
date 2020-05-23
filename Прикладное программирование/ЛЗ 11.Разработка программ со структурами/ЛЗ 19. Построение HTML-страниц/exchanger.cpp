#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>

#include "database.hpp"

using namespace std;

template <typename T>
void get(vector <T>& cur, string filename);
template <typename T>
void print(vector <T> cur);
template <typename T>
void add(vector <T>& cur, string filename);
template <typename T>
void deleteRow(vector <T>& cur, string filename);
template <typename T>
void edit(vector <T>& cur, string filename);
bool sortByName(Currency v1, Currency v2);
bool sortByCourse(Currency v1, Currency v2);
void sortBy(vector <Currency> cur);
template <typename T>
void outputHTML(vector <T> cur, string filename);
void about();

int main() {
    vector <Currency> cur;
    vector <Customer> cus;
    vector <Deal> deals;

    get<Currency>(cur, "input/currency.txt");
    get<Customer>(cus, "input/customer.txt");
    get<Deal>(deals, "input/deal.txt");

    bool mainLoop = true;

    int choise;

    while (mainLoop) {
        system("cls");
        cout << "MENU ( DATABASE OF CURRENCY AND ITS EXCHANGE RATE IN RUBLES )" << endl;
        cout << "1. Print of DB" << endl;
        cout << "2. Add of row to DB" << endl;
        cout << "3. Remove of row from DB" << endl;
        cout << "4. Edit of row in DB" << endl;
        cout << "5. Sorting Currency rows only by.." << endl;
        cout << "6. Output DB table in HTML" << endl;
        cout << "7. About the program" << endl;
        cout << endl << "Any keys. Quit" << endl;


        choise = getch() - 48;

        switch(choise){
            case 1: 
                    system("cls");
                    
                    cout << "1. Currency" << endl;
                    cout << "2. Customers" << endl;
                    cout << "3. Deals" << endl;
                    cout << endl << "Any keys. Quit" << endl;

                    choise = getch() - 48;

                    switch (choise) {
                        case 1: print<Currency>(cur); break;
                        case 2: print<Customer>(cus); break;
                        case 3: print<Deal>(deals); break;
                        default: break;
                    }
                    break;
            case 2:  
                    system("cls");
                    
                    cout << "1. Currency" << endl;
                    cout << "2. Customers" << endl;
                    cout << "3. Deals" << endl;
                    cout << endl << "Any keys. Quit" << endl;

                    choise = getch() - 48;

                    switch (choise) {
                        case 1: add<Currency>(cur, "input/currency.txt"); break;
                        case 2: add<Customer>(cus, "input/customer.txt"); break;
                        case 3: add<Deal>(deals, "input/deal.txt"); break;
                        default: break;
                    }
                    break;
            case 3:
                    system("cls");
                    
                    cout << "1. Currency" << endl;
                    cout << "2. Customers" << endl;
                    cout << "3. Deals" << endl;
                    cout << endl << "Any keys. Quit" << endl;

                    choise = getch() - 48;

                    switch (choise) {
                        case 1: deleteRow<Currency>(cur, "input/currency.txt"); break;
                        case 2: deleteRow<Customer>(cus, "input/customer.txt"); break;
                        case 3: deleteRow<Deal>(deals, "input/deal.txt"); break;
                        default: break;
                    }
                    break;
            case 4:  
                    system("cls");
                    
                    cout << "1. Currency" << endl;
                    cout << "2. Customers" << endl;
                    cout << "3. Deals" << endl;
                    cout << endl << "Any keys. Quit" << endl;

                    choise = getch() - 48;

                    switch (choise) {
                        case 1: edit<Currency>(cur, "input/currency.txt"); break;
                        case 2: edit<Customer>(cus, "input/customer.txt"); break;
                        case 3: edit<Deal>(deals, "input/deal.txt"); break;
                        default: break;
                    }
                    break;
            case 5: sortBy(cur); break;
            case 6: 
                    system("cls");
                    
                    cout << "1. Currency" << endl;
                    cout << "2. Customers" << endl;
                    cout << "3. Deals" << endl;
                    cout << endl << "Any keys. Quit" << endl;

                    choise = getch() - 48;

                    switch (choise) {
                        case 1: outputHTML<Currency>(cur, "output/currency.html"); break;
                        case 2: outputHTML<Customer>(cus, "output/customer.html"); break;
                        case 3: outputHTML<Deal>(deals, "output/deal.html"); break;
                        default: break;
                    }
                    break;
            case 7: about(); break;
            default: mainLoop = false; break;
        }

    }

    return 0;
}
