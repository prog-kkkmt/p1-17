#include "declaration.h"

Move::Move() {
    x = 0.0;
    y = 0.0;
    z = 0.0;
    step = 1.5;
}

Move::Move(double _x, double _y, double _z, double _step) {
    x = _x;
    y = _y;
    z = _z;
    step = _step;
}

void Move::out() {
    cout << "x: " << x << "\ny: " << y << "\nz: " << z << "\nstep: " << step << endl;
    cout << endl;
}

void Move::go_forward() {
    y += step;
}

void Move::go_back() {
    y -= step;
}

void Move::go_left() {
    x -= step;
}

void Move::go_right() {
    x += step;
}

void Move::go_up() {
    y += step;
}

void Move::go_down() {
    y -= step;
}

void menu(Move obj) {
    bool On = true;
    int action;
    while (On) {
        cout << "�������:\n" << "1: ��� ������������ ������\n" << "2: ��� ����������� �����\n" << "3: ��� ����������� �����\n" << "4: ��� ����������� ������\n" << "5: ��� ����������� �����\n" << "6: ��� ����������� ����\n" << "7: ���������� � ��������������� ���������\n" << "8: � ���������\n" << "9: �����" << endl;
        cin >> action;
        switch(action) {
            case 1: system("cls"); obj.go_forward(); break;
            case 2: system("cls"); obj.go_back(); break;
            case 3: system("cls"); obj.go_left(); break;
            case 4: system("cls"); obj.go_right(); break;
            case 5: system("cls"); obj.go_up(); break;
            case 6: system("cls"); obj.go_down(); break;
            case 7: system("cls"); obj.out(); break;
            case 8: system("cls"); about(); break;
            case 9: On = false; break;
            default: system("cls"); cout << "������ �������� ���" << endl; break;
        }
    }
}

void about() {
    cout << "����� ��� ������������\n���������� 18.06.2020 � ������ ���������� �� 13" << endl;
}
