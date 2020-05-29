#ifndef DECLARATION_H_INCLUDED
#define DECLARATION_H_INCLUDED

#include <iostream>
#include <locale>

using namespace std;

class Move {
public:
    Move();
    Move(double _x, double _y, double _z, double _step);

    void go_forward();//ось х в плюс
    void go_back();//ось х в минус
    void go_left();//ось z в плюс
    void go_right();//ось z в минус
    void go_up();//ось y в плюс
    void go_down();//ось y в минус
    void out();

private:
    double x;
    double y;
    double z;
    double step;
};

void menu(Move obj);
void about();
#endif // DECLARATION_H_INCLUDED
