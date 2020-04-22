#include <iostream>

using namespace std;

int logg(int x)
{
    int p = 0;
    for(int i = 1; x > i; x/=2)
        p++;
   return p;
}

int main()
{
    int a;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> a;
        cout << logg(a) << endl;
    }
        return 0;
}
