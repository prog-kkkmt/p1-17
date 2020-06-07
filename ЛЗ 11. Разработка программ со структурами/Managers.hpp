#ifndef MANAGERS_HPP
#define MANAGERS_HPP

#include <vector>
#include <iostream>

using namespace std;

class Manager{
    public:
        Manager(int managerCode, string name);
        bool changeInt(int field, int newValue);
        bool changeStr(int field, string newValue);

        int getManagerCode();
        string getName();

        friend ostream& operator<<(ostream& os, const Manager& sl);
    private:
        int managerCode;
        string name;
};

class Managers{
    public:
        void addRow(int managerCode, string name);
        bool deleteRow(int n);
        bool changeIntRow(int n, int field, int newValue);
        bool changeStrRow(int n, int field, string newValue);
        bool sortRows(int byField, int order);
        friend ostream& operator<<(ostream& os, const Managers& sls);
    private:
        vector <Manager> rows;
};

#endif //MANAGERS_HPP
