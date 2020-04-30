//https://stepik.org/lesson/538/step/10?unit=861
//Фатеев Д.И.

#include <iostream>

using namespace std;

int print_obr()
{
    int a;
    cin >> a;
    if(a != 0)
    {
        print_obr();
        cout << a << " ";
    }       
}


int main()
{
    print_obr();
	return 0;
}
