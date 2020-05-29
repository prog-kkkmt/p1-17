#include "declaration.h"

int main()
{
    setlocale(0, "");
    char in;
    FindGameObjects obj2;
    cout << "Хотите задать параметры движения самостоятельно? y - да| n - нет" << endl;
    cin >> in;
    if (in == 'y') {
        int temp_x, temp_y, temp_z, temp_step;
    cout << "Введите x(любое число), y(любое число), z(любое число), step(число > 0): ";
    cin >> temp_x >> temp_y >> temp_z >> temp_step;
    Move obj(temp_x, temp_y, temp_z, temp_step);
    menu(obj, obj2);
    }
    else {
        Move obj;
        menu(obj, obj2);
    }
    return 0;
}

///Выполнила: Фролова Л.А.
