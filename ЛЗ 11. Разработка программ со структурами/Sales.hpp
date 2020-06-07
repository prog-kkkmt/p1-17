#ifndef SALES_HPP
#define SALES_HPP

#include <vector>
#include <iostream>

using namespace std;

class Sale{
    public:
        Sale(int managerCode, int carCode, string licensePlate, int buyerCode, string date, int price);
        bool changeInt(int field, int newValue);
        bool changeStr(int field, string newValue);

        int getManagerCode();
        int getCarCode();
        int getPrice();
        int getBuyerCode();
        string getDate();
        string getLicensePlate();

        friend ostream& operator<<(ostream& os, const Sale& sl);
    private:
        int managerCode;
        int carCode;
        string licensePlate;
        int buyerCode;
        string date;
        int price;
};

class Sales{
    public:
        void addRow(int managerCode, int carCode, string licensePlate, int buyerCode, string date, int price);
        bool deleteRow(int n);
        bool changeIntRow(int n, int field, int newValue);
        bool changeStrRow(int n, int field, string newValue);
        bool sortRows(int byField, int order);
        friend ostream& operator<<(ostream& os, const Sales& sls);
    private:
        vector <Sale> rows;
};

#endif //SALES_HPP
