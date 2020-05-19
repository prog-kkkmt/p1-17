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
        cout << "Выберите действие: \n1 - Добавить\n2 - Удалить\n3 - Редактировать\n4 - Вывести список\n5 - Сохранить файл\n6 - Выход\n";
        cin >> a;
        switch (a)
        {
            case 1:
            cout << "Введите код документа: ";
            cin >> code;
            cout << "Введите вид документа: ";
            cin >> name;
            add(dt, code, name);
            break;

            case 2:
            cout << "Введите код документа: ";
            cin >> code;
            del(dt, code);
            break;

            case 3:
            cout << "Введите код документа: ";
            cin >> code;
            cout << "Выберите что изменить: 1 - код документа, 2 - вид документа";
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
            cout << "До свидания!" << endl;
            break;

            default:
            cout << "Ошибка!" << endl;
            break;
        }
    }
    return 0;
}
