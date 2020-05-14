// Изменить программу упражнения 3.10. так, чтобы входные данные поступали из файла input.txt,
// а результат записывался в файл output.txt

//Выполнил: Пищулин Игорь
//14.05.2020

#include <fstream>
#include <iostream>

using namespace std;

int main() {
    string s1;
    ifstream inf("input.txt");
    getline(inf, s1);
    for (int i = 0; i < s1.length(); i++)
        if (s1[i] == '.' || s1[i] == ',' || s1[i] == ';' || s1[i] == ':') {
            s1.erase(i, 1);
        }

    ofstream outf("output.txt");
    outf << s1;

    return 0;
}
