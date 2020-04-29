/**Íàïèøèòå ôóíêöèþ power, ðåàëèçóþùóþ âîçâåäåíèå öåëîãî ÷èñëà â íåîòðèöàòåëüíóþ öåëóþ ñòåïåíü.

Âûïîëíèëà: Ïîïêîâà Àëåíà Ï1-17
Èñòî÷íèê: Stepik.org "Ïðîãðàììèðîâàíèå íà ÿçûêå C++" Computer Science Center (CS öåíòð) 1.8.4. https://stepik.org/lesson/13377/step/4
23.04.2020 **/

#include <iostream>
using namespace std;

int power(int x, unsigned p) {
    return (p == 0)? 1: x * power(x, p - 1);
}

int main()
{
    int a;
    unsigned b;

    cin >> a >> b;
    cout << power(a, b);

  return 0;
}

