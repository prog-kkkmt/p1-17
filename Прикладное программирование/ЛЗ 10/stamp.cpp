/*17. Philatelist's guide.
The database contains information about your personal stamp collection
Database table: Brands (brand Code, country Code, genre Code, year of release, price, album number)
Finished: Sapoletova Anastasia
15.05.2020
*/
#include <iostream>
#include <fstream>
#include <vector>
#include "stamp.hpp"
using namespace std;

int main(){
    vector <Stamp> stamps;
    Stamp obj;
    bool menu = true;
    ifstream in("mark.txt");

    int choice;

    if (in.is_open()) {
        while(in >> obj.idStamp >> obj.idCountry >> obj.idGenre >> obj.year >> obj.price >> obj.num){
            stamps.push_back(obj);
        }
    }

    while (menu) {
        cout << "Menu" << endl;
        cout << "1. Add row to database" << endl;
        cout << "2. Delete row from database" << endl;
        cout << "3. Edit row in database" << endl;
        cout << "4. Print of database" << endl;
        cout << "5. Sort" << endl;
        cout << "6. About the program" << endl;


        cin >> choice;

        switch (choice) {
            case 1: add(stamps); break;
            case 2: removeR(stamps); break;
            case 3: edit(stamps); break;
            case 4: print(stamps); break;
            case 5: sortBy(stamps); break;
            case 6: about(); break;
            default: break;
        }
    }




    return 0;
}
