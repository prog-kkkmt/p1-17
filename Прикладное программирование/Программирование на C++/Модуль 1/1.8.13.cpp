// Напишите программу для вычисления целочисленного логарифма по основанию 2.

#include <iostream>
using namespace std;

int log(int, int);

int main()
{
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        cout << log(2, x) << '\n';
    }
    
	return 0;
}

int log(int n, int x) {
    int i = 0;
    int num = 1;
    
    while (num <= x) {
        num *= n;
        i++;
    } 
    
    return i - 1;
}