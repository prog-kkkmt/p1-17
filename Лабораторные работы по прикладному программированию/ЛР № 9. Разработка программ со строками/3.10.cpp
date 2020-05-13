///Упражнение 3.10. Напишите программу поиска в строке знаков пунктуации. Программа должна позволить ввести символьную строку, содержащую знаки пунктуации,
///и вывести ту же строку, но уже без знаков пунктуации.
///(Гусятинер Л.Б.) Изменить программу упражнения 3.10. так, чтобы входные данные поступали из файла input.txt, а результат записывался в файл output.txt
///Выполнил: Юшаков Н. Р.
///Дата: 13.05.2020

#include <iostream>
#include <string>
#include <fstream>
#include <locale>

using namespace std;

int main() {
    setlocale(0, "");
    string s1;
    ifstream file1;
    ofstream file2;
    file1.open("input.txt");
    file2.open("output.txt");
    getline(file1, s1);
    cout << "Ваша строка: " << s1 << endl;
    cout << "Ваша строка без знаков пунктуации: ";
    for (string::size_type i = 0; i != s1.size(); ++i)
        if (!ispunct(s1[i])) {
            file2 << s1[i];
            cout << s1[i];
        }
    file1.close();
    file2.close();
    return 0;
}
