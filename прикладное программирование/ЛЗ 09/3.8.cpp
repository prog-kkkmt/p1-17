/*
3.8. Напишите программу, способную читать строки со стандартного устройства ввода и соединять 
их в одну большую строку. Отобразите полученную строку. Измените программу так, чтобы отделить 
соседние введенные строки пробелами.
Выполнила : Озерова А.С. П1-17 14 мая 2020
*/

#include <iostream>
using namespace std;

int main() 
{
 string line1, line, line2;
 
 while(getline(cin, line))
 {
 	line1 += line;
 	line2 += line + " ";
 }
 	

 cout << "Summary line : " << line1 << endl;
 line2.pop_back();
 cout << "Summary line with spaces : " << line2 << endl;
 	
 return 0;
}
