#include <iostream>

using namespace std;

void perevor()
{
    int a;
    cin >> a;
    if (a != 0)
    {
        perevor();
        cout << a << ' ';
    }
}

int main()
{
    perevor();
	return 0;
}
