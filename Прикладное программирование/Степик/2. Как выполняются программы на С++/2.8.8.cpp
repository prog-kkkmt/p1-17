/*
Программа вручную переписана с лекции 2.8 Строки и ввод-вывод,
для закрепления материала.
Переписал программу Бобнев Алексей П1-17
*/

#include <string>
#include <fstream>

using namespace std;

int main()
{
    string name;
    ifstream input("i.txt");
    input >> name;
    ofstream output("o.txt");
    output << "Hi, " << name << endl;
    return 0;
}

