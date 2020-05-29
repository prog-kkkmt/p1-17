#ifndef DECLARATION_H_INCLUDED
#define DECLARATION_H_INCLUDED

#include <iostream>
#include <locale>

using namespace std;

class Move {
public:
    Move();
    Move(double _x, double _y, double _z, double _step);

    void go_forward();
    void go_back();
    void go_left();
    void go_right();
    void go_up();
    void go_down();
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
