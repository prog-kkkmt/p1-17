#include <iostream>

using namespace std;

int logarithm(int x)
{
    int p = 0;
    for(int i = 1; x > i; x /= 2)
        p++;
   return p;
}

int main()
{
    int x;
    int t;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> x;
        cout << logarithm(x) << endl;
    }
        return 0;
}
