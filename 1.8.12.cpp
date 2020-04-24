#include <iostream>
using namespace std;

int main()
{
    bool flag = false;

    char c = '\0';
    while (cin.get(c) && c != EOF) {
        if (c == ' ') {
            if (!flag)
                cout << c;
            flag = true;
        } else
            flag = false;
        
        if (!flag)
            cout << c;
    }

	return 0;
}