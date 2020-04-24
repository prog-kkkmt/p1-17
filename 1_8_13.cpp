#include <iostream>

int logar(int a)
{
    int b = 2, c = 0;
    while (a >= b)
    {
        a /= b;
        c++;
    }
    return c;
}

using namespace std;

int main ()
{
    int t, d;
    int i;
    cin >> t;
    for(i = 0; i < t; i++)
    {
        cin >> d;
        cout << logar(d) << endl;
    }
    return 0;
}
