#include <iostream>
using namespace std;

int main()
{
    char c = '\0';
    int space = 0;
    while (cin.get(c)) {
        if (c == ' ' && space == 0)
        {
            space = 1;
            cout << c;
        }
        if (c != ' ')
        {
            cout << c;
            space = 0;
        }
    }
	return 0;
}
