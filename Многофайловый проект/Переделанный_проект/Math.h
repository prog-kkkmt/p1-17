#include <iostream>

#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED

using namespace std;

int abs(int * a)
{
    if (*a > -1) cout << *a;
    else
    {
        *a = *a * -1;
        cout << *a;
    }
    return 0;
}

#endif // MATH_H_INCLUDED
