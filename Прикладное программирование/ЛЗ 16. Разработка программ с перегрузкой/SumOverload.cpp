#include "sumOverload.hpp"

drob operator +( drob &a,  drob &b)
{
    drob c;
    if (a.znam != b.znam)
    {
        c.chis = a.chis * b.znam + a.znam * b.chis;
        c.znam = a.znam * b.znam;
    }
    else
    {
        c.chis = a.chis + b.chis;
        c.znam = a.znam;
    }
    return c;
}

drob operator /( drob &a,  drob &b)
{
    drob c;
    c.chis = a.chis * b.znam;
    c.znam = a.znam * b.chis;
    return c;
}

drob operator *( drob &a,  drob &b)
{
    drob c;
    c.chis = a.chis * b.chis;
    c.znam = a.znam * b.znam;
    return c;
}

bool operator ==( drob &a,  drob &b)
{
    return ((a.chis == b.chis) && (a.znam == b.znam));
}

drob operator >(drob &a,  drob &b)
{
    return ((double(a.chis) / a.znam) > (double(b.chis) / b.znam) ? a : b);
}

drob my_abs(drob &a)
{
    a.chis = abs(a.chis);
    a.znam = abs(a.znam);
    return a;
}

ostream &operator <<(ostream &out,  drob &c)
{
    out << c.chis << "/" << c.znam;
    return out;
}

istream &operator >>(istream &in,  drob &c)
{
   in >> c.chis >> c.znam;
   return in;
}

drob :: drob(int x, int y) : chis(x), znam(y)
{}


