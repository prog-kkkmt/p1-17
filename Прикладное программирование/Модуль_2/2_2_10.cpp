/**Вам требуется написать программу, которая "переворачивает" последовательность положительных целых чисел.

Выполнила: Попкова Алена П1-17
Источник: Stepik.org "Программирование на языке C++" Computer Science Center (CS центр) 2.2.10 https://stepik.org/lesson/538/step/10
23.04.2020 **/
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
