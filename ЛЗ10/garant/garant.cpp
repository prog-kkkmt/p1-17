/**
По номеру в электронном журнале выбрать задание из раздела
"Задания для самостоятельных работ с использованием MS Access и MS Excel"
Выбрать одну (любую) таблицу.
Для выбранной таблицы разработать проект с меню, реализующий возможности
добавления, удаления, редактирования, вывода списка экземпляров таблицы.
Подготовить контрольный пример.
Номер варианта: №4
Таблица: Клиенты (Код клиента, ФИО, адрес);
**/

#include "header.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    vector <Client> clients;
    Client client;
    ifstream file;
    file.open("klients.txt");
    while (file >> client.code >> client.surname >> client.gorod)
    clients.push_back(client);
    file.close();

    int vibor = 1;
    int code, field;
    string surname, gorod;
    while (vibor != 0)
    {
        cout << " _________________________________________ " << endl;
        cout << "|  Гарантийная мастерская бытовой техники |" << endl;
        cout << "|_________________________________________|" << endl;
        cout << "|                                         |" << endl;
        cout << "|   1: Добавить                           |" << endl;
        cout << "|   2: Удалить                            |" << endl;
        cout << "|   3: Редактирование таблицы             |" << endl;
        cout << "|   4: Вывести список                     |" << endl;
        cout << "|   5: Сохранить изменения в файл         |" << endl;
        cout << "|   6: О программе                        |" << endl;
        cout << "|_________________________________________|" << endl;
        cout << "|                                         |" << endl;
        cout << "|   0: Выход                              |" << endl;
        cout << "|_________________________________________|" << endl << endl;

        cin >> vibor;
        cout << endl;
        switch (vibor)
        {
        case 0:
            break;

        case 1:
            cout << "Введите код клиента: ";
            cin >> code;
            cout << "Введите фамилию клиента: ";
            cin >> surname;
            cout << "Введите город клиента: ";
            cin >> gorod;
            add(clients, code, surname, gorod);
            break;

        case 2:
            cout << "Введите код: ";
            cin >> code;
            delet(clients, code);
            break;

        case 3:
            edit(clients);
            break;

        case 4:
            get(clients);
            break;

        case 5:
            saveToFile(clients);
            break;
        case 6:
            cout << "Консольное приложение учета клиентов." << endl;
            cout << "Автор:" << endl;
            cout << "Величко Валентин П1-17" << endl;
            break;

        default:
            cout << " Ошибка. Повторите набор)" << endl << endl;
            break;
        }
    }
    return 0;
}