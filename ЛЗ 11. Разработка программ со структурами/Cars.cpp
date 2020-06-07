#include "Cars.hpp"

#include <vector>
#include <iostream>

using namespace std;

const int CARCODE = 0;
const int MODEL = 1;

const int DEC = 0;
const int ASC = 1;

//class Cars
void Cars::addRow(int carCode, string model){
    rows.push_back(Car(carCode, model));
}

bool Cars::deleteRow(int n){
    if (rows.size() <= 0) return false;
    rows.erase(rows.begin() + n - 1);
}
bool Cars::changeIntRow(int n, const int field, int newValue){
    if (n > rows.size()) return false;
    switch (field){
        case CARCODE:
            rows.at(n - 1).changeInt(field, newValue);
            return true;
            break;
        case MODEL:
            return false;
            break;
        default:
            return false;
    }
}

bool Cars::changeStrRow(int n, int field, string newValue){
    if (n > rows.size()) return false;
    switch (field){
        case MODEL:
            rows.at(n - 1).changeStr(field, newValue);
            return true;
            break;
        case CARCODE:
            return false;
            break;
        default:
            return false;
    }
}

bool Cars::sortRows(int byField, int order){
    Car buff = Car(0, "NONE");
    int intLeft, intRight;
    string strLeft, strRight;

    for(int i = 0; i < rows.size() - 1; i++){
        for(int j = i; j < rows.size(); j++){
            switch (byField){
                case MODEL:
                    if (byField == MODEL){
                        strLeft = rows.at(i).getModel();
                        strRight = rows.at(j).getModel();
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
                case CARCODE:
                    if (byField == CARCODE){
                        intLeft = rows.at(i).getCarCode();
                        intRight = rows.at(j).getCarCode();
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

ostream& operator<<(ostream& os, const Cars& sls){
    for (int i = 0; i < sls.rows.size(); i++){
        os << sls.rows.at(i) << endl;
    }
    return os;
}


//class Car
Car::Car(int carCode, string model){
    this->carCode = carCode;
    this->model = model;
}

bool Car::changeInt(int field, int newValue){
    switch (field){
        case CARCODE:
            this->carCode = newValue;
            return true;
            break;
        case MODEL:
            return false;
            break;
        default:
            return false;
    }
}
bool Car::changeStr(int field, string newValue){

    switch (field){
        case CARCODE:
            return false;
            break;
        case MODEL:
            this->model = newValue;
            return true;
            break;
        default:
            return false;
    }
}

int Car::getCarCode() { return this->carCode; }

string Car::getModel() { return this->model; }

ostream& operator<<(ostream& os, const Car& sl){
    os << "\t" << sl.carCode
        << "\t" << sl.model;
    return os;
}
