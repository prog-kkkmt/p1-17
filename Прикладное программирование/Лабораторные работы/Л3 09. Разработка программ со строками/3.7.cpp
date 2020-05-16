/*Выполнила: Феоктистова А.С., П1-17, 15.05.2020
Упражнение 3.7. Напишите программу, которая читает две строки и уведомляет, равны ли они,
а если нет, какая из них больше. Измените программу так, чтобы она указывала, имеют ли строки
одинаковую длину, и если нет, то какая из них длинней.*/

#include <iostream>

using namespace std;

int main() {
    string str1;
    string str2;

    getline(cin, str1);
    getline(cin, str2);

    if (str1.size() == str2.size()){
    cout << "Строки равны";
    }else if (str1.size() > str2.size()) {
    cout << str1;
    } else {
    cout << str2;
    }

    return 0;
}
