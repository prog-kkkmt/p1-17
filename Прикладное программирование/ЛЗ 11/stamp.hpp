#include <iostream>

using namespace std;

struct Stamp {
    int idStamp;
    int idCountry;
    int idGenre;
    int year;
    int price;
    int num;
};

void OutPutHtmlStamp(vector <Stamp> &stamp){
    ofstream f("file.html");

    if (f.is_open())
    {
        for (int i = 0; i < stamp.size(); i++) {
            f << stamp.at(i).idStamp << '\t' << stamp.at(i).idCountry << '\t' << stamp.at(i).idGenre << '\t' << stamp.at(i).year << '\t' << stamp.at(i).price << '\t' << stamp.at(i).num << endl;
        }

    }
    f << "<H1>Марки</H1>"<< endl;
	f << "<table border = <\"2 \">" << endl;
    f << "<tr>" << endl;
	f << "<td>Код марки</td>" << endl;
	f << "<td>Код страны</td>" << endl;
	f << "<td>Код жанра</td>" << endl;
	f << "<td>Год выпуска</td>" << endl;
	f << "<td>Цена</td>" << endl;
	f << "<td>Номер альбома</td>" << endl;
	f << "</tr>" << endl;

        for (unsigned i = 0; i < stamp.size() ; i++)
        {
      	 	f << "<tr>" << endl;
            f << "<td>" << stamp.at(i).idStamp << "</td>" << endl;
         	f << "<td>" << stamp.at(i).idCountry << "</td>"<< endl;
            f << "<td>" << stamp.at(i).idGenre << "</td>" << endl;
         	f << "<td>" << stamp.at(i).year<< "</td>"<< endl;
            f << "<td>" << stamp.at(i).price << "</td>" << endl;
         	f << "<td>" << stamp.at(i).num << "</td>"<< endl;
         	f << "</tr>" << endl;
         }
         f << "</table>" << endl;
 }

void print(vector <Stamp> obj) {
    for (int i = 0; i < obj.size(); i++)
        cout << obj.at(i).idStamp << '\t' << obj.at(i).idCountry << '\t' << obj.at(i).idGenre << '\t' << obj.at(i).year << '\t' << obj.at(i).price << '\t' << obj.at(i).num << endl;
    cout << endl;
}

void add(vector <Stamp>& obj) {
    Stamp b;

    cout << "Enter of idStamp: ";
    cin >> b.idStamp;
    cout << "Enter of idCountry: ";
    cin >> b.idCountry;
    cout << "Enter of idGenre: ";
    cin >> b.idGenre;
    cout << "Enter of year: ";
    cin >> b.year;
    cout << "Enter of price: ";
    cin >> b.price;
    cout << "Enter of num: ";
    cin >> b.num;

    obj.push_back(b);


    ofstream out("mark.txt");

    if (out.is_open())
    {
        for (int i = 0; i < obj.size(); i++) {
            out << obj.at(i).idStamp << '\t' << obj.at(i).idCountry << '\t' << obj.at(i).idGenre << '\t' << obj.at(i).year << '\t' << obj.at(i).price << '\t' << obj.at(i).num << endl;
        }

    }

}
void about(){
    cout << "The database contains information about your personal stamp collection" << endl;
    cout << "Database table: Brands (brand Code, country Code, genre Code, year of release, price, album number)" << endl;
    cout << "Finished: Sapoletova Anastasia" << endl;
    cout << "15.05.2020" << endl;
    }


void removeR(vector <Stamp>& obj) {
    int id;

    cout << "Enter of idStamp: ";
    cin >> id;

    for (int i = 0; i < obj.size(); i++) {
        if (obj.at(i).idStamp == id) {
            obj.erase(obj.begin() + i);
        }
    }

    ofstream out("mark.txt");

    if (out.is_open())
    {
        for (int i = 0; i < obj.size(); i++) {
            out << obj.at(i).idStamp << '\t' << obj.at(i).idCountry << '\t' << obj.at(i).idGenre << '\t' << obj.at(i).year << '\t' << obj.at(i).price << '\t' << obj.at(i).num << endl;
        }
    }

}

void edit(vector <Stamp>& obj) {
    int id;

    cout << "Enter of idStamp: ";
    cin >> id;
    int choice;
    int editField;

    for (int i = 0; i < obj.size(); i++) {
        if (obj.at(i).idStamp == id) {
            cout << "1. idCountry" << endl;
            cout << "2. idGenre" << endl;
            cout << "3. year" << endl;
            cout << "4. price" << endl;
            cout << "4. num" << endl;

            cin >> choice;

            cin >> editField;

            switch (choice) {
                case 1: obj.at(i).idCountry = editField; break;
                case 2: obj.at(i).idGenre = editField; break;
                case 3: obj.at(i).year = editField; break;
                case 4: obj.at(i).price = editField; break;
                case 5: obj.at(i).num = editField; break;
                default: break;
            }
        }
    }

    ofstream out("mark.txt");

    if (out.is_open())
    {
        for (int i = 0; i < obj.size(); i++) {
            out << obj.at(i).idStamp << '\t' << obj.at(i).idCountry << '\t' << obj.at(i).idGenre << '\t' << obj.at(i).year << '\t' << obj.at(i).price << '\t' << obj.at(i).num << endl;
        }
    }

}

void sortBy(vector <Stamp>& obj) {
    Stamp b;
    int choice;
    int sortFieldI;
    int sortFieldJ;

    cout << "1. idCountry" << endl;
    cout << "2. idGenre" << endl;
    cout << "3. year" << endl;
    cout << "4. price" << endl;
    cout << "5. num" << endl;

    cin >> choice;


    for (int i = 0; i < obj.size()- 1; i++) {
        switch (choice) {
            case 1: sortFieldI = obj.at(i).idCountry; break;
            case 2: sortFieldI = obj.at(i).idGenre ; break;
            case 3: sortFieldI = obj.at(i).year ; break;
            case 4: sortFieldI = obj.at(i).price; break;
            case 5: sortFieldI = obj.at(i).num ; break;
            default: break;
        }
        for (int j = i; j < obj.size(); j++) {
            switch (choice) {
                case 1: sortFieldJ = obj.at(j).idCountry; break;
                case 2: sortFieldJ = obj.at(j).idGenre; break;
                case 3: sortFieldJ = obj.at(j).year; break;
                case 4: sortFieldJ = obj.at(j).price; break;
                case 5: sortFieldJ = obj.at(j).num; break;
                default: break;
            }
            if (sortFieldI > sortFieldJ) {
                b = obj.at(j);
                obj.at(j) = obj.at(i);
                obj.at(i) = b;

                sortFieldI = sortFieldJ;
            }
        }
    }

    ofstream out("mark.txt");

    if (out.is_open())
    {
        for (int i = 0; i < obj.size(); i++) {
            out << obj.at(i).idStamp << '\t' << obj.at(i).idCountry << '\t' << obj.at(i).idGenre << '\t' << obj.at(i).year << '\t' << obj.at(i).price << '\t' << obj.at(i).num << endl;
        }
    }
}
