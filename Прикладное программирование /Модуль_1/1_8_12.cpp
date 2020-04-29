/**Напишите программу, которая посимвольно читает из std::cin, пока не достигнет конца потока ввода,
 и заменяет несколько подряд идущих пробелов одним и выводит полученный результат в std::cout.

Выполнила: Попкова Алена П1-17
Источник: Stepik.org "Программирование на языке C++" Computer Science Center (CS центр) 1.8.12. https://stepik.org/lesson/13377/step/12
23.04.2020 **/



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
