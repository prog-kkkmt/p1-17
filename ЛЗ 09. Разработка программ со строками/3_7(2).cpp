// Напишите программу, которая читает две строки и уведомляет, равны ли они, 
// а если нет, какая из них больше. Измените программу так, чтобы она указывала, имеют ли строки 
// одинаковую длину, и если нет, то какая из них длинней.

//Выполнил: Богомолов Максим П1-17
//14.05.2020

#include <iostream>

using namespace std;


int main() {
    string s1;
    string s2;

    getline(cin, s1);
    getline(cin, s2);

    If (s1 == s2) cout << "Lines are equal";
        else if (s1 > s2) cout << s1;
            else cout << s2;

    return 0;
}
