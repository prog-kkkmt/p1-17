/*
Finished: Sapoletova Anastasia
03.07.2020
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include "Hall.hpp"
#include "Film.hpp"
#include "Sale.hpp"
using namespace std;

int main(){
    vector <Hall> halls;  /*создание вектора*/
    vector <Film> films;
    vector <Sale> sales;
    vector < pair <string, int> > sales_v;
    pair <string, int> p;
    int percent = 0;
    Hall obj = Hall();
    Film obj1 = Film();
    Sale obj2 = Sale();
    bool menu = true;
    int counts = -1;
    int cap = 0;
    int lastID = -1;
    int indexH = -1;
    string title;
    string genre;
    ifstream in("Hall.txt");

    int choice;

    if (in.is_open()) {
        while(in >> obj.idHall >> obj.capacity){
            halls.push_back(obj);
        }
    }

    in.close();
    in.open("Film.txt");

    if (in.is_open()) {
        while(in >> obj1.idFilm >> obj1.title >> obj1.genre){
            films.push_back(obj1);
        }
    }
    in.close();
    in.open("Sale.txt");

    if (in.is_open()) {
        while(in >> obj2.idSale >> obj2.idFilm >> obj2.idHall >> obj2.time >> obj2.idPlace ){
            sales.push_back(obj2);
        }
    }
    in.close();
    int curr_film = 0;
    string curr_genre;
    int buff = -1;
    int sum = 0;
    for (int i = 0; i < sales.size(); i++) {
        for (int j = 0; j < films.size(); j++)
            if (films.at(j).idFilm == sales.at(i).idFilm) {
                curr_genre = films.at(j).genre;
                curr_film = j;
                sum++;
            } else {
                if (sum > buff) {
                    buff = sum;
                    genre = curr_genre;
                }
                sum = 1;
            }
    }
    cout << "Most Popular - " << genre << endl;

    while (menu) {
        counts = -1;
        lastID = -1;
        indexH = -1;
        sales_v.clear();
        //busN.clear();   /*удаление элементов вектора*/
        cout << "Menu" << endl;

        for (int i = 0; i < halls.size(); i++)
            cout << "Hall " << halls.at(i).idHall << endl;

        cin >> choice;
        for (int i = 0; i < halls.size(); i++)
            if (halls.at(i).idHall == choice) {
                //cout << "True" << endl;
                indexH = i;
            }
        //cout << indexH;
        if (indexH == -1) {
            cout << "Incorrect ID Hall" << endl;
            continue;
        }

        for (int i = 0; i < sales.size(); i++)
            if (sales.at(i).idHall == choice) {
                //cout << sales.at(i).time << endl;
                //cout << counts << endl;
                ////cout << title << endl;
                if (sales.at(i).idFilm == lastID) {
                    sales_v.at(counts).second += 1;
                    //cout << "SEC = " << sales_v.at(counts).second << endl;
                } else {
                    //cout << "else" << endl;
                    for (int j = 0; j < films.size(); j++)
                        if (films.at(j).idFilm == sales.at(i).idFilm)
                            title = films.at(j).title;
                    p.first = title;
                    p.second = 1;
                    sales_v.push_back(p);
                    counts += 1;
                    lastID = sales.at(i).idFilm;
                }
            }

        if (sales_v.empty()) {
            cout << "No sales" << endl;
            continue;
        }



        for (int i = 0; i < sales_v.size(); i++) {
            cout << sales_v.at(i).first << " - " << sales_v.at(i).second * 100 / halls.at(indexH).capacity << "%" << endl;
        }

        for (int i = 0; i < sales_v.size(); i++) {
            int r = sales_v.at(i).second * 100 / halls.at(indexH).capacity;
            for (int j = 0; j < films.size(); j++)
                if (films.at(j).title == sales_v.at(i).first)
                    if (r < percent)
                        percent += r;
                    else {
                        percent = r;
                        genre = films.at(j).genre;
                    }
        }


    }

    return 0;
}

