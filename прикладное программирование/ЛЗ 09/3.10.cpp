/*
3.10. Напишите программу поиска в строке знаков пунктуации. 
Программа должна позволить ввести символьную строку, содержащую знаки пунктуации, 
и вывести ту же строку, но уже без знаков пунктуации.
Выполнила : Озерова А.С. П1-17 14 мая 2020
*/

#include <iostream>
using namespace std;

int main() 
{
 string line1;

 getline(cin, line1);
 for(int i = 0; i < line1.size(); i++)
 {
 	if (line1[i] == '.' || line1[i] == ',' || line1[i] == ';' || line1[i] == ':' || line1[i] == '?' || line1[i] == '!')
 	{
 		line1.erase(i, 1);
 		i--;
 	}
 }
 cout << line1;

 return 0;
}
