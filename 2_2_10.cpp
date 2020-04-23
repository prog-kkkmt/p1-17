/**Вам требуется написать программу, которая "переворачивает" последовательность положительных целых чисел.

Выполнила: Попкова Алена П1-17
Источник: Stepik.org Программирование в C++**/
#include <iostream>

using namespace std;

void flip()
{
    int num;
    cin >> num;
    if (num)
    {
        flip();
        cout << num << " ";
    }
}

int main()
{
    flip();

	return 0;
}
