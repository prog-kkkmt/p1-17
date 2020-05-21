#include <iostream>
#include <cmath>

using namespace std;

class Complex {
    public:
        double x;
        double y;

        Complex operator+ (Complex &c)
        {
            Complex b;

            b.x = x + c.x;
            b.y = y + c.y;

            return b;
        }

        Complex operator/ (Complex &c)
        {
            Complex b;
            
            double r = c.x * c.x + c.y * c.y;
            b.x = (x * c.x + y * c.y) / r;
            b.y = (y * c.x - x * c.y) / r;

            return b;
        }

        Complex operator* (Complex &c) // перегрузка оператора умножения
        {
            Complex b;

            b.x = x * c.x - y * c.y;
            b.y = x * c.y + c.x * y;

            return b;
        }

        double abs() {
            return sqrt(x * x + y * y);
        }

        friend bool operator==(Complex& left, Complex& right);
        friend bool operator>(Complex& left, Complex& right);

        friend ostream &operator<<(ostream &, Complex &);
        friend istream &operator>>(istream &, Complex &);
};

bool operator==(Complex& left, Complex& right) {
    return left.abs() == right.abs();
}

bool operator>(Complex& left, Complex& right) {
    return left.abs() > right.abs();
}

ostream &operator<<(ostream &out, Complex &c)
{
   out << c.x << " + i" << c.y;
 
   return out;
}
 
istream &operator>>(istream &in, Complex &c)
{
   in >> c.x >> c.y;
 
   return in;
}

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

    cout << "|" << a << "|" << " = " << a.abs() << endl;

    cout << a << " == " << b << " = " << (a == b) << endl;
    cout << a << " > " << b << " = " << (a > b) << endl;

    return 0;
}