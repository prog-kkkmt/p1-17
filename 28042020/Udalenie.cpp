#include <iostream>
#include <windows.h>

using namespace std;

struct People
{
    string name;
    int number;
}p[100];

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "База данных" << endl;
    int n, i, num_avto = 1;
    cin >> n;
    for (i = 0; i < n; ++i)
    {
        p[i].number = num_avto;
        cin >> p[i].name;
        num_avto++;
    }
    for (i = 0; i < n; ++i)
    {
        cout << p[i].number << " " << p[i].name << endl;
    }
    int u;
    cin >> u;
    for (i = 0; i < n; ++i)
    {
        if (p[i].number == u)
        {
            for (i = u - 1; i < n; ++i)
            {
                p[i].number = p[i + 1].number - 1;
                p[i].name = p[i + 1].name;
            }
            n--;
        }
    }

    for (i = 0; i < n; ++i)
    {
        cout << p[i].number << " " << p[i].name << endl;
    }
    return 0;
}
