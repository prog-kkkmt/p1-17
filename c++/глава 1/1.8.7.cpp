/*Напишите программу для вычисления целочисленного логарифма по основанию 2.*/
/*Величко П1-17*/
/*https://stepik.org/lesson/13377/step/13?unit=3571*/
#include <iostream>

using namespace std;

int logarithm(int x)
{
    int p = 0;
    for(int i = 1; x > i; x /= 2)
        p++;
   return p;
}

int main()
{
    int x;
    int t;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> x;
        cout << logarithm(x) << endl;
    }
        return 0;
}
