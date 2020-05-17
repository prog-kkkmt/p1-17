// Вам требуется написать программу, которая "переворачивает" последовательность положительных целых чисел.
//Выполнил: Богомолов Максим П1-17
//Источник: Stepik Computer Science Center (CS центр)
//Программирование на языке C++
//2.2.10 https://stepik.org/lesson/538/step/10
//25.04.2020
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
