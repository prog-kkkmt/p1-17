/**Напишите программу, которая суммирует целые числа.

Выполнила: Попкова Алена П1-17
Источник: Stepik.org Программирование в C++**/

#include <iostream>

using namespace std;

int main(){
    int T;
    int a, b;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> a >> b;
        cout << a + b << endl;
    }
    return 0;
}
