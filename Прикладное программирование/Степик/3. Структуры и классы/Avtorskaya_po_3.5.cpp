/*
��������� ������.
��������� ������� ����� ������ �� �������.
�������� ������ ������� �1-17.
19.05.2020
*/


# include <iostream>

using namespace std;

struct r
{
    public:
    r()
    {
        float sum, skidka;
        cin >> sum;
        skidka = sum / 10;
        sum -= skidka;
        cout << sum;
    }

    private:
        int a;

};

int main()
{
    r();
    return 0;
}
