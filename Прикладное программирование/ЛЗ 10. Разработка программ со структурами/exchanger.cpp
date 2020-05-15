#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>

#include "currency.hpp"

using namespace std;

void print(vector <Currency> cur);
void add(vector <Currency>& cur);

int main() {
    vector <Currency> cur;

    Currency buff;

    bool mainLoop = true;

    ifstream in("currency.txt");

    if (in.is_open())
    {
        while (in >> buff.ID >> buff.name >> buff.course)
        {
            cur.push_back(buff);
        }
    }

    in.close();

    int choise;

    while (mainLoop) {
        system("cls");
        cout << "MENU ( DATABASE OF CURRENCY AND ITS EXCHANGE RATE IN RUBLES )" << endl;
        cout << "1. Print of DB" << endl;
        cout << "2. Add of row to DB" << endl;
        cout << "3. Remove of row from DB" << endl;
        cout << "4. Edit of row in DB" << endl;
        cout << endl << "Any keys. Quit" << endl;


        choise = getch() - 48;

        switch(choise){
            case 1: print(cur); break;
            case 2: add(cur); break;
            case 3: deleteRow(cur); break;
            case 4: edit(cur); break;
            default: mainLoop = false; break;
        }

    }

    return 0;
}
