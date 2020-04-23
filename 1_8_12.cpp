/**Напишите программу, которая посимвольно читает из std::cin, пока не достигнет конца потока ввода,
 и заменяет несколько подряд идущих пробелов одним и выводит полученный результат в std::cout.

Выполнила: Попкова Алена П1-17
Источник: Stepik.org Программирование в C++**/

#include <iostream>

using namespace std;

int main()
{
    char c = '\0';
    char prev_c = '\0';

    while (cin.get(c)) {
        if (c == ' ' && prev_c == ' ')
            continue;
        cout << c;
        prev_c = c;

    }

    return 0;
}
