#ifndef BUYERS_HPP
#define BUYERS_HPP

#include <vector>
#include <iostream>

using namespace std;

class Buyer{
    public:
        Buyer(int buyerCode, string name);
        bool changeInt(int field, int newValue);
        bool changeStr(int field, string newValue);

        int getBuyerCode();
        string getName();

        friend ostream& operator<<(ostream& os, const Buyer& sl);
    private:
        int buyerCode;
        string name;
};

class Buyers{
    public:
        void addRow(int buyerCode, string name);
        bool deleteRow(int n);
        bool changeIntRow(int n, int field, int newValue);
        bool changeStrRow(int n, int field, string newValue);
        bool sortRows(int byField, int order);
        friend ostream& operator<<(ostream& os, const Buyers& sls);
    private:
        vector <Buyer> rows;
};

#endif //BUYERS_HPP
