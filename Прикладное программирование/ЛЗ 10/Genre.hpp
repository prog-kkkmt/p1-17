#include <iostream>

using namespace std;

struct Genre {
    int idGenre;
    string title;

};

void print(vector <Genre> obj) {
    for (int i = 0; i < obj.size(); i++)
        cout << obj.at(i).idGenre << '\t' << obj.at(i).title << endl;
    cout << endl;
}

void add(vector <Genre>& obj) {
    Genre b;

    cout << "Enter of idGenre: ";
    cin >> b.idGenre;
    cout << "Enter of title: ";
    cin >> b.title;

    obj.push_back(b);


    ofstream out("genre.txt");

    if (out.is_open())
    {
        for (int i = 0; i < obj.size(); i++) {
            out << obj.at(i).idGenre << '\t' << obj.at(i).title << endl;
        }

    }

}

void removeR(vector <Genre>& obj) {
    int id;

    cout << "Enter of idGenre: ";
    cin >> id;

    for (int i = 0; i < obj.size(); i++) {
        if (obj.at(i).idGenre == id) {
            obj.erase(obj.begin() + i);
        }
    }

    ofstream out("genre.txt");

    if (out.is_open())
    {
        for (int i = 0; i < obj.size(); i++) {
            out << obj.at(i).idGenre << '\t' << obj.at(i).title << endl;
        }
    }

}

void edit(vector <Genre>& obj) {
    int id;

    cout << "Enter of idGenre: ";
    cin >> id;
    int choice;
    int editField;

    for (int i = 0; i < obj.size(); i++) {
        if (obj.at(i).idGenre == id) {
            cout << "1. title" << endl;
            cout << "2. idGenre" << endl;

            cin >> choice;

            cin >> editField;

            switch (choice) {
                case 1: obj.at(i).title = editField; break;
                case 2: obj.at(i).idGenre = editField; break;

                default: break;
            }
        }
    }

    ofstream out("genre.txt");

    if (out.is_open())
    {
        for (int i = 0; i < obj.size(); i++) {
            out << obj.at(i).idGenre  << endl;
        }
    }

}

void sortBy(vector <Genre>& obj) {
    Genre b;
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

    ofstream out("genre.txt");

    if (out.is_open())
    {
        for (int i = 0; i < obj.size(); i++) {
            out << obj.at(i).idGenre << '\t' << obj.at(i).title << endl;
        }
    }
}

