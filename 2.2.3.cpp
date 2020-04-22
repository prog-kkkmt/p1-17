#include <iostream>

using namespace std;

void foo()
{
    int n;
    cin >> n;
    if (n != 0)
    {          
        foo();
        cout << n << " ";
    }
}

int main()
{
    foo();
    return 0;
}
