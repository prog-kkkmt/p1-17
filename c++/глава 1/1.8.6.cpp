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
/*чтение с удалением лишних пробелов*/
/*Величко П1-17*/
/*https://stepik.org/lesson/13377/step/12?unit=3571*/
