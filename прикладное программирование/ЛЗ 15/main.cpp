#include "declaration.h"

int main()
{
    setlocale(0, "");
    char in;
    FindGameObjects obj2;
    archer obj3;
    khith obj4;
    cout << "������ ������ �������� �������� ��������������? y - ��| n - ���" << endl;
    cin >> in;
    if (in == 'y') {
        int temp_x, temp_y, temp_z, temp_step;
    cout << "������� x(����� �����), y(����� �����), z(����� �����), step(����� > 0): ";
    cin >> temp_x >> temp_y >> temp_z >> temp_step;
    Move obj(temp_x, temp_y, temp_z, temp_step);
    menu(obj, obj2, obj3, obj4);
    }
    else {
        Move obj;
        menu(obj, obj2, obj3, obj4);
    }
    return 0;
}
