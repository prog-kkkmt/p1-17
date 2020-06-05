//Задание 3.
//Разработать перегруженные функции для математических операций sum, div, prod, my_abs,
//eq (equal), gt(greater then) для комплексных чисел.
//Выполнил: Богомолов Максим П1-17
#include <iostream>
#include <cmath>

#include "Complex.hpp"

Complex Complex::operator+ (Complex &c){
    Complex b;

    b.x = x + c.x;
    b.y = y + c.y;

    return b;
}

Complex Complex::operator/ (Complex &c){
    Complex b;

    double r = c.x * c.x + c.y * c.y;
    b.x = (x * c.x + y * c.y) / r;
    b.y = (y * c.x - x * c.y) / r;

    return b;
}

Complex Complex::operator* (Complex &c){
    Complex b;

    b.x = x * c.x - y * c.y;
    b.y = x * c.y + c.x * y;

    return b;
}

bool operator==(Complex& left, Complex& right){
    return abs(left) == abs(right);
}

bool operator>(Complex& left, Complex& right){
    return abs(left) > abs(right);
}

ostream &operator<<(ostream &out, Complex &c){
   out << c.x << " + i" << c.y;

   return out;
}

istream &operator>>(istream &in, Complex &c){
   in >> c.x >> c.y;

   return in;
}

double abs(Complex c){
    return sqrt(c.x * c.x + c.y * c.y);
}
