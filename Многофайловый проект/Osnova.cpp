/*
Многофайловый проект. Программа выводит какие есть модели у марки и страну, в которой марка производится.
Выполнил Бобнев Алексей П1-17.
23.06.2020
*/

#include <iostream>
#include "Avtomobili.h"
#include "Country.h"

using namespace std;

int main()
{
    int menu;
    cin >> menu;
    while ((menu == 1) || (menu == 2))
    {
        if (menu == 1)
        {
            Audi();
            BMW();
        }
        if (menu == 2)
        {
            Marka_audi();
            Marka_subaru();
        }
        cin >> menu;
    }
    return 0;
}
