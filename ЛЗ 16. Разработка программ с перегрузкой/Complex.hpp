//Задание 3.
//Разработать перегруженные функции для математических операций sum, div, prod, my_abs,
//eq (equal), gt(greater then) для комплексных чисел.
//Выполнил: Богомолов Максим П1-17
#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <iostream>
#include <cmath>

using namespace std;


class Complex {
    public:
        double x;
        double y;

        Complex operator+ (Complex &c);
        Complex operator/ (Complex &c);
        Complex operator* (Complex &c);

        friend bool operator==(Complex& left, Complex& right);
        friend bool operator>(Complex& left, Complex& right);

        friend ostream &operator<<(ostream &, Complex &);
        friend istream &operator>>(istream &, Complex &);

};

double abs(Complex c);

#endif //COMPLEX_HPP
