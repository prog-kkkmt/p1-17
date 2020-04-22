#include <iostream>

using namespace std;

void reverse() {
    int a;
    cin >> a;
    if (a == 0)
        return;
    reverse();
    cout << a << " ";
}

int main()
{
    reverse();
	return 0;
}
