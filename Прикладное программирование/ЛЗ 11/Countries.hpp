#include <iostream>

using namespace std;

struct Country {
    int idCountry;
    string title;

};

void OutPutHtmlCountries(vector <Country> &country){

    ofstream f("file.html");

    if (f.is_open())
    {
        for (int i = 0; i < country.size(); i++) {
            f << country.at(i).idCountry << '\t' << country.at(i).title << endl;
        }

    }

    f << "<H1>Страны</H1>"<< endl;
	f << "<table border = \"2 \">" << endl;
    f << "<tr>" << endl;
	f << "<td>Код страны</td>" << endl;
	f << "<td>Название</td>" << endl;
	f << "</tr>" << endl;

        for (unsigned i = 0; i < country.size() ; i++)
        {
      	 	f << "<tr>" << endl;
            f << "<td>" << country.at(i).idCountry << "</td>" << endl;
         	f << "<td>" << country.at(i).title<< "</td>"<< endl;
         	f << "</tr>" << endl;
         }
         f << "</table>" << endl;
 }

void print(vector <Country> obj) {
    for (int i = 0; i < obj.size(); i++)
        cout << obj.at(i).idCountry << '\t' << obj.at(i).title << endl;
    cout << endl;
}

void add(vector <Country>& obj) {
    Country b;

    cout << "Enter of idCountry: ";
    cin >> b.idCountry;
    cout << "Enter of title: ";
    cin >> b.title;

    obj.push_back(b);


    ofstream out("Country.txt");

    if (out.is_open())
    {
        for (int i = 0; i < obj.size(); i++) {
            out << obj.at(i).idCountry << '\t' << obj.at(i).title << endl;
        }

    }

}

void removeR(vector <Country>& obj) {
    int id;

    cout << "Enter of idCountry: ";
    cin >> id;

    for (int i = 0; i < obj.size(); i++) {
        if (obj.at(i).idCountry == id) {
            obj.erase(obj.begin() + i);
        }
    }

    ofstream out("Country.txt");

    if (out.is_open())
    {
        for (int i = 0; i < obj.size(); i++) {
            out << obj.at(i).idCountry << '\t' << obj.at(i).title << endl;
        }
    }

}

void edit(vector <Country>& obj) {
    int id;

    cout << "Enter of idCountry: ";
    cin >> id;
    int choice;
    int editField;

    for (int i = 0; i < obj.size(); i++) {
        if (obj.at(i).idCountry == id) {
            cout << "1. title" << endl;
            cout << "2. idCountry" << endl;

            cin >> choice;

            cin >> editField;

            switch (choice) {
                case 1: obj.at(i).title = editField; break;
                case 2: obj.at(i).idCountry = editField; break;

                default: break;
            }
        }
    }

    ofstream out("Country.txt");

    if (out.is_open())
    {
        for (int i = 0; i < obj.size(); i++) {
            out << obj.at(i).idCountry  << endl;
        }
    }

}

void sortBy(vector <Country>& obj) {
    Country b;
    int choice;
    string sortFieldI;
    string sortFieldJ;



    for (int i = 0; i < obj.size()- 1; i++) {
        sortFieldI = obj.at(i).title;
        for (int j = i; j < obj.size(); j++) {
            sortFieldJ = obj.at(j).title;
            if (sortFieldI > sortFieldJ) {
                b = obj.at(j);
                obj.at(j) = obj.at(i);
                obj.at(i) = b;

                sortFieldI = sortFieldJ;
            }
        }
    }

    ofstream out("Country.txt");

    if (out.is_open())
    {
        for (int i = 0; i < obj.size(); i++) {
            out << obj.at(i).idCountry << '\t' << obj.at(i).title << endl;
        }
    }
}


