/*Напишите программу поиска в строке знаков пунктуации. 
Программа должна позволить ввести символьную строку, содержащую знаки пунктуации, 
и вывести ту же строку, но уже без знаков пунктуации.
*/
//Фатеев Д.И.

#include <iostream>
#include <string>
#include <cctype>

using namespace std;
 
int main() 
{
    string LINE;
    cout << "Enter the line: " << endl;
    getline(cin, LINE);
    cout << "String without punctuation: " << endl;
    for (int i = 0; i < LINE.length(); i++) 
    {
        if (!(ispunct(LINE[i])))
            cout << LINE[i];
    }
    cout << endl;
}

