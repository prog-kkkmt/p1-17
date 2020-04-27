#include <iostream>
using namespace std;

int main()
{
    char c = '\0';
    char temp = c;
    while (cin.get(c)) {
        if (temp == ' ' and c == ' ')
            ;
        else {
            cout << c;
            temp = c;
        }
    }

	return 0;
}
