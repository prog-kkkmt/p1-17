//Задание 3. 
//Разработать перегруженные функции для математических операций sum, div, prod, my_abs,
//eq (equal), gt(greater then) для комплексных чисел.
//Выполнил: Богомолов Максим П1-17
#include <iostream>
#include <cmath>

#include "Complex.hpp"

int main() {
    Complex a;
    Complex b;

    Complex c;

    cin >> a >> b;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    c = a + b;

    cout << a << " + " << b << " = " << c << endl;
    
    c = a / b;

    cout << a << " / " << b << " = " << c << endl;

    c = a * b;

    cout << a << " * " << b << " = " << c << endl;

    cout << "|" << a << "|" << " = " << abs(a) << endl;

    cout << a << " == " << b << " = " << (a == b) << endl;
    cout << a << " > " << b << " = " << (a > b) << endl;

    return 0;
}
