/*
Задача. Чтобы имя вводилась несколько раз.
*/
#include <iostream>
#include <windows.h>

using namespace std;

struct building     //Создаем структуру!
{
    string owner;       //здесь будет храниться имя владельца
}apartment1[100];

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale (LC_ALL, "rus");
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> apartment1[i].owner;
    }

   for (int i = 0; i < n; i++)
    {
        cout << "Владелец квартиры: " << apartment1[i].owner << endl;
    }

return 0;
}
