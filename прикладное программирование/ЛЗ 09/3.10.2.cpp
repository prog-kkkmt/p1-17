/*
3.10.2 Изменить программу упражнения 3.10. так, чтобы входные данные поступали из файла input.txt,
а результат записывался в файл output.txt
Выполнила : Озерова А.С. П1-17 14 мая 2020
*/

#include <iostream>
#include <fstream>
using namespace std;

int main() 
{
 string line1;
 ifstream in("input.txt");
 ofstream out("output.txt");

 if(!in.is_open()) 
 	cout << "Файл не открыт";

 getline(in, line1);
 for(int i = 0; i < line1.size(); i++)
 {
 	if (line1[i] == '.' || line1[i] == ',' || line1[i] == ';')
 	{
 		line1.erase(i, 1);
 		i--;
 	}
 }
 out << line1;

 in.close();
 out.close();

 return 0;
}
