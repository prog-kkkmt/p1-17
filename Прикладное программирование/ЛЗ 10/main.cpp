#include "func.hpp"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    vector <data> dt;
    data d;
    ifstream file;
    file.open("vidi dokumentov.txt");
    while(file >> d.code >> d.name)
        dt.push_back(d);
    file.close();

    int a = 1;
    int code, z;
    string name;
    while (a != 0)
    {
        cout << "�������� ��������: \n1 - ��������\n2 - �������\n3 - �������������\n4 - ������� ������\n5 - ��������� ����\n6 - �����\n";
        cin >> a;
        switch (a)
        {
            case 1:
            cout << "������� ��� ���������: ";
            cin >> code;
            cout << "������� ��� ���������: ";
            cin >> name;
            add(dt, code, name);
            break;

            case 2:
            cout << "������� ��� ���������: ";
            cin >> code;
            del(dt, code);
            break;

            case 3:
            cout << "������� ��� ���������: ";
            cin >> code;
            cout << "�������� ��� ��������: 1 - ��� ���������, 2 - ��� ���������";
            cin >> z;
            edit(dt, code, z);
            break;

            case 4:
            get(dt);
            break;

            case 5:
            save(dt);
            break;

            case 6:
            cout << "�� ��������!" << endl;
            break;

            default:
            cout << "������!" << endl;
            break;
        }
    }
    return 0;
}
