#include <iostream>

using namespace std;

void f();

int main()
{
    f();
	return 0;
}

void f() {
    int x;
    cin >> x;
    if (x == 0)
        return;
    f();
    cout << x << " ";
}
