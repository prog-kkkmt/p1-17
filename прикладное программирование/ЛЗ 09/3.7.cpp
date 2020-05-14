/*
3.7. Напишите программу, которая читает две строки и уведомляет, равны ли они, 
а если нет, какая из них больше. Измените программу так, чтобы она указывала, имеют ли строки 
одинаковую длину, и если нет, то какая из них длинней.
Выполнила : Озерова А.С. П1-17 14 мая 2020
*/

#include <iostream>
using namespace std;

int main() 
{
 string line1, line2;

 cout << "stroki : " << endl;
 getline(cin, line1);
 getline(cin, line2);

 cout << "Равны ли? какая из строк больше?" << endl;
 if (line1 != line2)
 	cout << "the biggest : " << (line1 > line2 ? line1 : line2) << endl;
 else
 	cout << "lines are equal" << endl;

 cout << "Одинаковой ли длины? какая длинней?" << endl;
 if (line1.size() != line2.size())
 	cout << "the longest : " << (line1.size() > line2.size() ? line1 : line2) << endl;
 else
 	cout << "line's length  are equal" << endl;
 	
 return 0;
}
