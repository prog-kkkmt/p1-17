#include "Managers.hpp"

#include <vector>
#include <iostream>

using namespace std;

const int MANAGERCODE = 0;
const int NAME = 1;

const int DEC = 0;
const int ASC = 1;

//class Managers
void Managers::addRow(int managerCode, string name){
    rows.push_back(Manager(managerCode, name));
}

bool Managers::deleteRow(int n){
    if (rows.size() <= 0) return false;
    rows.erase(rows.begin() + n - 1);
}
bool Managers::changeIntRow(int n, const int field, int newValue){
    if (n > rows.size()) return false;
    switch (field){
        case MANAGERCODE:
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

bool Managers::changeStrRow(int n, int field, string newValue){
    if (n > rows.size()) return false;
    switch (field){
        case NAME:
            rows.at(n - 1).changeStr(field, newValue);
            return true;
            break;
        case MANAGERCODE:
            return false;
            break;
        default:
            return false;
    }
}

bool Managers::sortRows(int byField, int order){
    Manager buff = Manager(0, "NONE");
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
                case MANAGERCODE:
                    if (byField == MANAGERCODE){
                        intLeft = rows.at(i).getManagerCode();
                        intRight = rows.at(j).getManagerCode();
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

ostream& operator<<(ostream& os, const Managers& sls){
    for (int i = 0; i < sls.rows.size(); i++){
        os << sls.rows.at(i) << endl;
    }
    return os;
}


//class Manager
Manager::Manager(int managerCode, string name){
    this->managerCode = managerCode;
    this->name = name;
}

bool Manager::changeInt(int field, int newValue){
    switch (field){
        case MANAGERCODE:
            this->managerCode = newValue;
            return true;
            break;
        case NAME:
            return false;
            break;
        default:
            return false;
    }
}
bool Manager::changeStr(int field, string newValue){

    switch (field){
        case MANAGERCODE:
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

int Manager::getManagerCode() { return this->managerCode; }

string Manager::getName() { return this->name; }

ostream& operator<<(ostream& os, const Manager& sl){
    os << "\t" << sl.managerCode
        << "\t" << sl.name;
    return os;
}
