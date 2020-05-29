#include "sumOverload.hpp"

int main()
{
    drob a, b, c;
    cin >> a >> b;

    c = a + b;
    cout << "Sum : " << a << " + " << b << " = " << c << endl;

    c = a / b;
    cout << "Div : " << a << " : " << b << " = " << c << endl;

    c = a * b;
    cout << "Prod : " << a << " * " << b << " = " << c << endl;

    cout << a << " = " << b << " ? ";
    (a == b) > 0 ? cout << "yes" :  cout << "no" << endl;

    c = a > b;
    cout << "The biggest : " << c << endl;

    c = my_abs(a);
    cout << " | " << a << " | " << " = " <<  c << endl ;

    return 0;
}

///Выполнила: Фролова Л.А.
