#include <iostream>
using namespace std;

int main()
{
    char c;
    while((c = getchar()) != EOF)
    {
        if(c == ' ')
        {
            cout << c;
            while((c = getchar()) == ' ');
        }
           cout << c;
    }
    return 0;
}
