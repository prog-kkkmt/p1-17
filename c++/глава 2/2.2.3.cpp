#include <iostream>
using namespace std;
void foo()
{
    int chislo;
    cin >> chislo;
    if (chislo != 0)
    {          
        foo();
        cout << chislo << " ";
    }
}

int main()
{
    foo();
    return 0;
}
