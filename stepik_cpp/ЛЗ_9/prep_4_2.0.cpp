/*Изменить программу упражнения 3.10. так, чтобы входные данные поступали из файла input.txt,
а результат записывался в файл output.txt
*/
//Фатеев Д.И.

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;    

bool readfile(string& LINE, const char* filename)
{
    ifstream in(filename);
    if(! in.is_open())
        return false;
    char strend = '\0';
    getline(in, LINE, strend);
    in.close();
    return (LINE.length() > 0);
}

int main()
{
    ofstream out("output.txt");
    string LINE;
    if(readfile(LINE, "input.txt"))
        for (int i = 0; i < LINE.length(); i++) 
        {
        if (!(ispunct(LINE[i])))
            out << LINE[i];
        }
        cout << endl;
    cout << "Line successfully edited!";
}
