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
    z += step;
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
        cout << "Ââåäèòå:\n" << "1: Äëÿ ïåðåäâèæåíèÿ âïåðåä\n" << "2: Äëÿ ïåðåìåùåíèÿ íàçàä\n" << "3: Äëÿ ïåðåìåùåíèÿ âëåâî\n" << "4: Äëÿ ïåðåìåùåíèÿ âïðàâî\n" << "5: Äëÿ ïåðåìåùåíèÿ ââåðõ\n" << "6: Äëÿ ïåðåìåùåíèÿ âíèç\n" << "7: Èíôîðìàöèÿ î ìåñòîíàõîæäåíèè ïåðñîíàæà\n" << "8: Î ïðîãðàììå\n" << "9: Âûõîä" << endl;
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
            default: system("cls"); cout << "Òàêîãî äåéñòâèÿ íåò" << endl; break;
        }
    }
}

void about() {
    cout << "Êëàññ äëÿ ïåðåäâèæåíèÿ\nÐàçðàáîòàí 18.06.2020 â ðàìêàõ âûïîëíåíèÿ ËÇ 13" << endl;
}
