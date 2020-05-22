/*Разработать перегруженные функции для математических операций sum, div, prod, my_abs,
eq (equal), gt(greater then)
2. для комплексных чисел
Выполнила: Саполетова Анастасия
21.05.2020
*/

#include <iostream>
#include <complex>
using namespace std;

void sum(int, int, int, int);
void sum(double, double, double, double);

void div(int, int, int, int);
void div(double, double, double, double);

void prod(int, int, int, int);
void prod(double, double, double, double);

void my_abs(int, int);
void my_abs(double, double);

void eq(int, int, int, int);
void eq(double, double, double, double);

void gt(int, int, int, int);
void gt(double, double, double, double);

int main()
{
    sum(3, 1, 7, 2);
    sum(3.2, 4.5, 7.3, 3.4);
    div(6, 3, 4, 9);
    div(2.1, 4.8, 9.2, 5.5);
    prod(4, 6, 4, 3);
    prod(7.6, 5.3, 4.4, 7.3);
    my_abs(2, 3);
    my_abs(3.3, 4.4);
    eq(2, 7, 4, 6);
    eq(2.4, 3.3, 4.8, 1.2);
    gt(3, 1, 9, 6);
    gt(3.4, 4.2, 7.5, 1.5);

    return 0;
}
void sum(int a, int a_i, int b, int b_i)
{
    complex<int> z1(a, a_i);
    complex<int> z2(b, b_i);
    cout << "Sum = " << z1 + z2 << endl;
}
void sum(double a, double a_i, double b, double b_i)
{
    complex<double> z1(a, a_i);
    complex<double> z2(b, b_i);
    cout << "Sum = " << z1 + z2 << endl;
}
void div(int a, int a_i, int b, int b_i)
{
    complex<int> z1(a, a_i);
    complex<int> z2(b, b_i);
    cout << "Div = " << z1 / z2 << endl;
}
void div(double a, double a_i, double b, double b_i)
{
    complex<double> z1(a, a_i);
    complex<double> z2(b, b_i);
    cout << "Div = " << z1 / z2 << endl;
}
void prod(int a, int a_i, int b, int b_i)
{
    complex<int> z1(a, a_i);
    complex<int> z2(b, b_i);
    cout << "Prod = " << z1 * z2 << endl;
}
void prod(double a, double a_i, double b, double b_i)
{
    complex<double> z1(a, a_i);
    complex<double> z2(b, b_i);
    cout << "Prod = " << z1 * z2 << endl;
}
void my_abs(int a, int a_i)
{
    complex<int> z1(a, a_i);
    cout << "my_abs = " << abs(z1) << endl;
}
void my_abs(double a, double a_i)
{
    complex<double> z1(a, a_i);
    cout << "my_abs = " << abs(z1) << endl;
}
void eq(int a, int a_i, int b, int b_i)
{
    complex<int> z1(a, a_i);
    complex<int> z2(b, b_i);
    if(z1 == z2)
        cout << "Equal" << endl;
}
void eq(double a, double a_i, double b, double b_i)
{
    complex<double> z1(a, a_i);
    complex<double> z2(b, b_i);
    if(z1 == z2)
        cout << "Equal" << endl;
}
void gt(int a, int a_i, int b, int b_i)
{
    if ((a > b) && (a_i > b_i))
        cout << true;

}
void gt(double a, double a_i, double b, double b_i)
{
    if ((a > b) && (a_i > b_i))
        cout << true;

}
