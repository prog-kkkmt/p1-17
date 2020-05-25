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
#include "Genre.hpp"
#include "Countries.hpp"
using namespace std;

int main(){
    vector <Stamp> stamps;
    vector <Genre> genre;
    vector <Country> country;
    Stamp obj;
    Genre obj1;
    Country obj2;
    bool menu = true;

    ifstream in("mark.txt");

    int choice;

    if (in.is_open()) {
        while(in >> obj.idStamp >> obj.idCountry >> obj.idGenre >> obj.year >> obj.price >> obj.num){
            stamps.push_back(obj);
        }
    }

    in.close();
    in.open("genre.txt");

    if (in.is_open()) {
        while(in >> obj1.idGenre >> obj1.title ){
            genre.push_back(obj1);
        }
    }
    in.close();
    in.open("Country.txt");

    if (in.is_open()) {
        while(in >> obj2.idCountry >> obj2.title ){
            country.push_back(obj2);
        }
    }
    in.close();

    while (menu) {
        cout << "Menu" << endl;
        cout << "1. Add row to database" << endl;
        cout << "2. Delete row from database" << endl;
        cout << "3. Edit row in database" << endl;
        cout << "4. Print of database" << endl;
        cout << "5. Sort" << endl;
        cout << "6. Writing in html" << endl;
        cout << "7. About the program" << endl;


        cin >> choice;

        switch (choice) {
            case 1:
                    cout << "1. Stamps" << endl;
                    cout << "2. Genre" << endl;
                    cout << "3. Country" << endl;
                    cin >> choice;
                    switch (choice) {
                        case 1: add(stamps); break;
                        case 2: add(genre); break;
                        case 3: add(country); break;
                        default: break;
                    }
                    break;

            case 2:
                    cout << "1. Stamps" << endl;
                    cout << "2. Genre" << endl;
                    cout << "3. Country" << endl;
                    cin >> choice;
                    switch (choice) {
                        case 1: removeR(stamps); break;
                        case 2: removeR(genre); break;
                        case 3: removeR(country); break;
                        default: break;
                    }
                    break;

            case 3:
                    cout << "1. Stamps" << endl;
                    cout << "2. Genre" << endl;
                    cout << "3. Country" << endl;
                    cin >> choice;
                    switch (choice) {
                        case 1: edit(stamps); break;
                        case 2: edit(genre); break;
                        case 3: edit(country); break;
                        default: break;
                    }
                    break;

            case 4:
                    cout << "1. Stamps" << endl;
                    cout << "2. Genre" << endl;
                    cout << "3. Country" << endl;
                    cin >> choice;
                    switch (choice) {
                        case 1: print(stamps); break;
                        case 2: print(genre); break;
                        case 3: print(country); break;
                        default: break;
                    }
                    break;

            case 5:
                    cout << "1. Stamps" << endl;
                    cout << "2. Genre" << endl;
                    cout << "3. Country" << endl;
                    cin >> choice;
                    switch (choice) {
                        case 1: sortBy(stamps); break;
                        case 2: sortBy(genre); break;
                        case 3: sortBy(country); break;
                        default: break;
                    }
                    break;

            case 6:

                    cout << "1. Stamps" << endl;
                    cout << "2. Genre" << endl;
                    cout << "3. Country" << endl;
                    cin >> choice;
                    switch (choice) {
                        case 1: OutPutHtmlStamp(stamps); break;
                        case 2: OutPutHtmlGenre(genre); break;
                        case 3: OutPutHtmlCountries(country); break;
                        default: break;
                    }
                    break;

            case 7: about(); break;
            default: menu = false; break;
        }
    }


    /*html.open("file.html", ios_base::app);
    html << "</body>" << endl << "</html>" << endl;*/

    return 0;
}
