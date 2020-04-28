#include <iostream>

using namespace std;

int main()
{
    cout << "Hello" << endl;
    int a, b;
    cin >> a >> b;
    cout << a << " " << b << endl;
    int i;
    for (i = 0; i < 5; ++i) cout << a;
    cout << endl;
    if (a > b) cout << "Big is " << a << endl;
    else  cout << "Big is " << b << endl;
    int c;
    c = 0;
    while (c != 10)
    {
        cout << c << endl;
        c++;
    }
}
