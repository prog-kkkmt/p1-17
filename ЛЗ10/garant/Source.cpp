#include "header.h"

void get(vector <Client> clients)///вывод
{
    cout << "Код  Фамилия Город" << endl;
    for (int i = 0; i < clients.size(); i++)
    {   
        cout << clients[i].code << " ";
        cout << clients[i].surname << " ";
        cout << clients[i].gorod << endl;
    }
    cout << endl;
}

void add(vector <Client>& clients, int code, string surname, string gorod)///Ввод
{
    Client client;
    client.code = code;
    client.surname = surname;
    client.gorod = gorod;
    clients.push_back(client);
    cout << endl;
}

void delet(vector <Client>& clients, int code)///Удаление
{
    int i = 0;
    for (int i = 0; i < clients.size(); i++)
        if (clients[i].code == code)
        {
            clients.erase(clients.begin() + i);
            cout << endl;
        }
        else cout << "Нет такого кода(" << endl;
}

void edit(vector <Client>& clients)///Редактировние
{
    string value_str;
    int value_int, i = 0, proverka = 0;
    int code, field;
    cout << "Введите код клиента: ";
    cin >> code;
    cout << endl;
    for (int i = 0; i < clients.size(); i++)
        if (clients[i].code == code)
        {
            proverka = 1;
            cout << "1 - Код\n2 - Фамилия\n3 - Город\nВыберите поле, которое необходимо изменить: ";
            cin >> field;
            switch (field)
            {
            case 1:
                cout << "Введите код: ";
                cin >> value_int;
                clients[i].code = value_int;
                break;

            case 2:
                cout << "Введите фамилию: ";
                cin >> value_str;
                clients[i].surname = value_str;
                break;

            case 4:
                cout << "Введите город: ";
                cin >> value_str;
                clients[i].gorod = value_str;
                break;
            }
            break;
        }
    if (proverka == 0)
        cout <<" Не прошло проверку\n" << endl;
}

void saveToFile(vector <Client> clients)///Сохранение в файл
{
    ofstream file;
    file.open("klients.txt");
    for (int i = 0; i < clients.size(); i++)
        file << clients[i].code << " " << clients[i].surname << " "  << clients[i].gorod << endl;
    file.close();
}