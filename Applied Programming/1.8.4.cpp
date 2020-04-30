#include <iostream>
using namespace std;

int main()
{
    int a = 0;
    int b = 0;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;
        cout << a + b << endl;
    }
    return 0;
}
