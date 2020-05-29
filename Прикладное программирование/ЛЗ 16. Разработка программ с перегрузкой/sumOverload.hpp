#include <iostream>

using namespace std;

class drob
{
public:
    drob(int chis = 0, int znam = 1);
    int chis;
    int znam;
 
    friend bool operator ==(drob &a,  drob &b);
    friend ostream &operator <<(ostream &out,  drob &c);
    friend istream &operator >>(istream &in,  drob &c);
};

drob operator +( drob &a,  drob &b);
drob operator /( drob &a,  drob &b);
drob operator *( drob &a,  drob &b);
drob operator >(drob &a,  drob &b);
drob my_abs(drob &a);