#ifndef CARS_HPP
#define CARS_HPP

#include <vector>
#include <iostream>

using namespace std;

class Car{
    public:
        Car(int carCode, string model);
        bool changeInt(int field, int newValue);
        bool changeStr(int field, string newValue);

        int getCarCode();
        string getModel();

        friend ostream& operator<<(ostream& os, const Car& sl);
    private:
        int carCode;
        string model;
};

class Cars{
    public:
        void addRow(int carCode, string model);
        bool deleteRow(int n);
        bool changeIntRow(int n, int field, int newValue);
        bool changeStrRow(int n, int field, string newValue);
        bool sortRows(int byField, int order);
        friend ostream& operator<<(ostream& os, const Cars& sls);
    private:
        vector <Car> rows;
};

#endif //CARS_HPP
