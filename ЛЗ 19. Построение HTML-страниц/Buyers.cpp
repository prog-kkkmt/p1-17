#include "Buyers.hpp"

#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

const int BUYERCODE = 0;
const int NAME = 1;

const int DEC = 0;
const int ASC = 1;

//class Buyers
void Buyers::addRow(int buyerCode, string name){
    rows.push_back(Buyer(buyerCode, name));
}

bool Buyers::deleteRow(int n){
    if (rows.size() <= 0) return false;
    rows.erase(rows.begin() + n - 1);
}
bool Buyers::changeIntRow(int n, const int field, int newValue){
    if (n > rows.size()) return false;
    switch (field){
        case BUYERCODE:
            rows.at(n - 1).changeInt(field, newValue);
            return true;
            break;
        case NAME:
            return false;
            break;
        default:
            return false;
    }
}

bool Buyers::changeStrRow(int n, int field, string newValue){
    if (n > rows.size()) return false;
    switch (field){
        case NAME:
            rows.at(n - 1).changeStr(field, newValue);
            return true;
            break;
        case BUYERCODE:
            return false;
            break;
        default:
            return false;
    }
}

bool Buyers::sortRows(int byField, int order){
    Buyer buff = Buyer(0, "NONE");
    int intLeft, intRight;
    string strLeft, strRight;

    for(int i = 0; i < rows.size() - 1; i++){
        for(int j = i; j < rows.size(); j++){
            switch (byField){
                case NAME:
                    if (byField == NAME){
                        strLeft = rows.at(i).getName();
                        strRight = rows.at(j).getName();
                    }


                    //sort
                    if(order == ASC && strLeft > strRight){
                            buff = rows.at(i);
                            rows.at(i) = rows.at(j);
                            rows.at(j) = buff;
                    }
                    if(order == DEC && strLeft < strRight){
                            buff = rows.at(i);
                            rows.at(i) = rows.at(j);
                            rows.at(j) = buff;
                    }
                    break;
                case BUYERCODE:
                    if (byField == BUYERCODE){
                        intLeft = rows.at(i).getBuyerCode();
                        intRight = rows.at(j).getBuyerCode();
                    }


                    //sort
                    if(order == ASC && intLeft > intRight){
                        buff = rows.at(i);
                        rows.at(i) = rows.at(j);
                        rows.at(j) = buff;
                    }
                    if(order == DEC && intLeft < intRight){
                        buff = rows.at(i);
                        rows.at(i) = rows.at(j);
                        rows.at(j) = buff;
                    }
                    break;
                default:
                    return false;
            }
        }
    }
    return false;
}

void Buyers::printToHtml(ofstream &f){
    f << "<H1>Покупатели</H1>"<< endl;
	f << "<table border = \"2 \">" << endl;
    f << "<tr id = \"header\">" << endl;
	f << "<td><i>Код покупателя</i></td>" << endl;
	f << "<td><i>ФИО</i></td>" << endl;
	f << "</tr>" << endl;
    for (unsigned i = 0; i < rows.size() ; i++)
    {
        f << "<tr>" << endl;
        f << "<td>" << rows.at(i).getBuyerCode() << "</td>" << endl;
        f << "<td>" << rows.at(i).getName() << "</td>" << endl;
        f << "</tr>" << endl;
     }
     f << "</table>" << endl;
}

ostream& operator<<(ostream& os, const Buyers& sls){
    for (int i = 0; i < sls.rows.size(); i++){
        os << sls.rows.at(i) << endl;
    }
    return os;
}


//class Buyer
Buyer::Buyer(int buyerCode, string name){
    this->buyerCode = buyerCode;
    this->name = name;
}

bool Buyer::changeInt(int field, int newValue){
    switch (field){
        case BUYERCODE:
            this->buyerCode = newValue;
            return true;
            break;
        case NAME:
            return false;
            break;
        default:
            return false;
    }
}
bool Buyer::changeStr(int field, string newValue){

    switch (field){
        case BUYERCODE:
            return false;
            break;
        case NAME:
            this->name = newValue;
            return true;
            break;
        default:
            return false;
    }
}

int Buyer::getBuyerCode() { return this->buyerCode; }

string Buyer::getName() { return this->name; }

ostream& operator<<(ostream& os, const Buyer& sl){
    os << "\t" << sl.buyerCode
        << "\t" << sl.name;
    return os;
}
