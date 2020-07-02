/// ��������� �� c++ �� ���������� �������
#include <iostream>

using namespace std;


class PolymorphFO
{
    public:

    /// ������� � ����� ���������� ���� int
    void func(int x)
    {
        cout << "�������� x: " << x << endl;
    }

    /// ������� � ����� �� ���������, �� ���������� ���� double
    void func(double x)
    {
        cout << "�������� x: " << x << endl;
    }

    /// ������� � ����� �� ������, �� ����� ����������� ���� int
    void func(int x, int y)
    {
        cout << "�������� x � y: " << x << ", " << y << endl;
    }
};

int main() {

    setlocale(LC_ALL, "Russian");

    PolymorphFO obj1;

    /// ��, ����� ������� ����� �������, ���������� ��� ������������ ������
    /// ������ 'func' �������
    obj1.func(7);

    /// ������� ������ 'func'
    obj1.func(9.132);

    /// ������� ������ 'func'
    obj1.func(85,64);
    return 0;
}
