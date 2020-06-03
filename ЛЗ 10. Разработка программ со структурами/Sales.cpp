#include "Sales.hpp"
#include <vector>
#include <iostream>

using namespace std;

//class Sales
void Sales::addRow(int managerCode, int carCode, string licensePlate, int buyerCode, string date, int price){
    rows.push_back(Sale(managerCode, carCode, licensePlate, buyerCode, date, price));
}

bool Sales::deleteRow(int n){
    if (rows.size() <= 0) return false;
    rows.erase(rows.begin() + n - 1);
}
bool Sales::changeIntRow(int n, const int field, int newValue){
    if (n > rows.size()) return false;
    switch (field){
        case MANAGERCODE:
            ;
        case CARCODE:
            ;
        case BUYERCODE:
            ;
        case PRICE:
            rows.at(n - 1).changeInt(field, newValue);
            return true;
            break;
        case DATE:
            ;
        case LICENSEPLATE:
            return false;
            break;
        default:
            return false;
    }
}

bool Sales::changeStrRow(int n, int field, string newValue){
    if (n > rows.size()) return false;
    switch (field){
        case LICENSEPLATE:
            ;
        case DATE:
            rows.at(n - 1).changeStr(field, newValue);
            return true;
            break;
        case MANAGERCODE:
            ;
        case CARCODE:
            ;
        case BUYERCODE:
            ;
        case PRICE:
            return false;
            break;
        default:
            return false;
    }
}

bool Sales::sortRows(int byField, int order){
    Sale buff = Sale(0, 0, "NONE", 0, "NONE", 0);
    int intLeft, intRight;
    string strLeft, strRight;

    for(int i = 0; i < rows.size() - 1; i++){
        for(int j = i; j < rows.size(); j++){
            switch (byField){
                case LICENSEPLATE:
                    if (byField == LICENSEPLATE){
                        strLeft = rows.at(i).getLicensePlate();
                        strRight = rows.at(j).getLicensePlate();
                    }
                case DATE:
                    if (byField == DATE){
                        strLeft = rows.at(i).getDate();
                        strRight = rows.at(j).getDate();
                    }

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
                case CARCODE:

                    if (byField == CARCODE){
                        intLeft = rows.at(i).getCarCode();
                        intRight = rows.at(j).getCarCode();
                    }
                case BUYERCODE:
                    if (byField == BUYERCODE){
                        intLeft = rows.at(i).getBuyerCode();
                        intRight = rows.at(j).getBuyerCode();
                    }
                case PRICE:
                    if (byField == PRICE){
                        intLeft = rows.at(i).getPrice();
                        intRight = rows.at(j).getPrice();
                    }


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

ostream& operator<<(ostream& os, const Sales& sls){
    for (int i = 0; i < sls.rows.size(); i++){
        os << sls.rows.at(i) << endl;
    }
    return os;
}

//class Sale
Sale::Sale(int managerCode, int carCode, string licensePlate, int buyerCode, string date, int price){
    this->managerCode = managerCode;
    this->carCode = carCode;
    this->licensePlate = licensePlate;
    this->buyerCode = buyerCode;
    this->date = date;
    this->price = price;
}

bool Sale::changeInt(int field, int newValue){
    switch (field){
        case MANAGERCODE:
            this->managerCode = newValue;
            return true;
            break;
        case CARCODE:
            this->carCode = newValue;
            return true;
            break;
        case LICENSEPLATE:
            this->licensePlate = newValue;
            return true;
            break;
        case BUYERCODE:
            this->buyerCode = newValue;
            return true;
            break;
        case DATE:
            return false;
            break;
        case PRICE:
            this->price = newValue;
            return true;
            break;
        default:
            return false;
    }
}
bool Sale::changeStr(int field, string newValue){

    switch (field){
        case MANAGERCODE:
            return false;
            break;
        case CARCODE:
            return false;
            break;
        case LICENSEPLATE:
            return false;
            break;
        case BUYERCODE:
            return false;
            break;
        case DATE:
            this->date = newValue;
            return true;
            break;
        case PRICE:
            return false;
            break;
        default:
            return false;
    }
}

int Sale::getManagerCode() { return this->managerCode; }

int Sale::getCarCode() { return this->carCode; }

int Sale::getPrice() { return this->price; }

int Sale::getBuyerCode() { return this->buyerCode; }

string Sale::getDate() { return this->date; }

string Sale::getLicensePlate() { return this->licensePlate; }

ostream& operator<<(ostream& os, const Sale& sl){
    os << sl.managerCode
        << "\t" << sl.carCode
        << "\t" << sl.licensePlate
        << "\t" << sl.buyerCode
        << "\t" << sl.date
        << "\t" << sl.price;
    return os;
}
