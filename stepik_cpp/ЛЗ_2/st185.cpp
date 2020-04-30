#include <iostream>
using namespace std;

int main()
{
    int f = 2;
    char c = '\0';
    while (cin.get(c)) 
    {
        if(isalpha(c) || isdigit(c))
        {
            f = 2;
            cout << c;
        }
        if(c == ' ' && f == 2)
        {
            f = 1;
            cout << c;
        }    
    }

	return 0;
}
