/******************************************************************************
Найдите все числа от 1 до n, представимые в виде суммы двух 
квадратов различных натуральных чисел.
*******************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
bool check(int n)
{
    
    for (int i = 1; i * i < n; i++) 
    {   
        double j = sqrt (n - i * i);
        if ((j == floor(j)) and (j != i)) 
            {
                return true; 
            }
    } 
    return false; 
}
int main() {
    int n;
    cin >> n;
    for (int k = 5; k <= n; k++)
        if (check(k))
            cout << k << " ";
    return 0;
}