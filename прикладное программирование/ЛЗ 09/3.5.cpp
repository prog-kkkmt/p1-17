/*
3.5. Напишите программу, читающую со стандартного устройства ввода целые строки. Измените 
программу так, чтобы она читала отдельные слова.
Выполнила : Озерова А.С. П1-17 14 мая 2020
*/

#include <iostream>
using namespace std;

int main() 
{
 string line;

 cout << "Чтение целой строки" << endl;
 getline(cin, line);
 cout << line << endl;

 cout << "Чтение по словам" << endl;
 while(cin >> line)
  cout << line << endl;
 	
 return 0;
}
