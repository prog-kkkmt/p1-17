#include "func.hpp"

void get(vector <data> dt)
{
    for (int i = 0; i < dt.size(); i++)
    {
        cout << dt[i].code << " ";
        cout << dt[i].name << endl;
    }
    cout << endl;
}

void add(vector <data> &dt, int code, string name)
{
    data dt;
    dt.code = code;
    dt.name = name;
    dt.push_back(dt);
    cout << endl;
}

void del(vector <data> &dt, int code)
{
    int i = 0;
    while (dt[i].code != code)
        i++;
    dt.erase(dt.begin() + i);
    cout << endl;
}

void edit(vector <data> &dt, int code, int z)
{
    string newname;
    int newcode, i = 0, a = 0;
    for (i = 0; i < dt.size(); i++)
        if (dt[i].code == code)
        {
            a = 1;
            switch (z)
            {
                case 1:
                cin >> newcode;
                dt[i].code = newcode;
                break;

                case 2:
                cin >> newname;
                dt[i].name = newname;
                break;
            }
            break;
        }
        if (a == 0)
            cout << "Ошибка!" << endl;
}

void save(vector <data> dt)
{
    ofstream file;
    file.open("vidi dokumentov.txt");
    for (int i = 0; i < dt.size(); i++)
        file << dt[i].code << " " << dt[i].name << endl;
    file.close();
}
