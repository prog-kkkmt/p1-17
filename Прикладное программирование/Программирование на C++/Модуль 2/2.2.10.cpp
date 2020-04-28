// Вам требуется написать программу, которая "переворачивает" последовательность положительных целых чисел.

#include <iostream>

using namespace std;

int print() {
    int i;
    
    cin >> i;
    if (i == 0) 
        return 0;
    else
        print();
    cout << i << ' ';
    return 0;
}

int main()
{
    print();
	return 0;
}