/// программа на c++ по перезаписи функций
#include <iostream>

using namespace std;


class PolymorphFO
{
    public:

    /// функция с одним параметром типа int
    void func(int x)
    {
        cout << "Величина x: " << x << endl;
    }

    /// функция с таким же названием, но параметром типа double
    void func(double x)
    {
        cout << "Величина x: " << x << endl;
    }

    /// функция с таким же именем, но двумя параметрами типа int
    void func(int x, int y)
    {
        cout << "Величина x и y: " << x << ", " << y << endl;
    }
};

int main() {

    setlocale(LC_ALL, "Russian");

    PolymorphFO obj1;

    /// то, какая функция будет вызвана, определяет тип передаваемых данных
    /// первая 'func' вызвана
    obj1.func(7);

    /// вызвана вторая 'func'
    obj1.func(9.132);

    /// вызвана третья 'func'
    obj1.func(85,64);
    return 0;
}
