#include <iostream>
using namespace std;

int main()
{
    int t, a, b;
    cin >> t;
    while (t > 0)
    {
        cin >> a;
        cin >> b;
        cout << a + b << "\n";
        t--;
    }
    return 0;
}
