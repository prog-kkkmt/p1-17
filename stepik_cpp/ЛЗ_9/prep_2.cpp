/* Напишите программу, которая читает две строки и уведомляет, равны ли они, 
а если нет, какая из них больше. Измените программу так, чтобы она указывала, имеют ли строки 
одинаковую длину, и если нет, то какая из них длинней.
*/
//Фатеев Д.И.

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string LINE_1, LINE_2;
    cout << "Enter the first line: \n";
    getline(cin, LINE_1);
    cout << "Enter the second line: \n";
    getline(cin, LINE_2);

    if(LINE_1.length() > LINE_2.length())
    {
        cout << "Line are not equal. First more.\nFirst line length: " << LINE_1.length() << "\nSecond line length: " << LINE_2.length() << endl;
    }
    else if (LINE_1.length() <  LINE_2.length())
    {
        cout << "Line are not equal. Second more.\nFirst line length: " << LINE_1.length() << "\nSecond line length: " << LINE_2.length() << endl;
    }
    else if (LINE_1.length() == LINE_2.length())
    {
        cout << "Line are equal. \nLine length: " << LINE_1.length() << endl;;
    }
    
}