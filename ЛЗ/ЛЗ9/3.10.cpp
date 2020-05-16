///Упражнение 3.10. Напишите программу поиска в строке знаков пунктуации. Программа должна позволить ввести символьную строку, содержащую знаки пунктуации, и вывести ту же строку, но уже без знаков пунктуации.
///(Гусятинер Л.Б.) Изменить программу упражнения 3.10. так, чтобы входные данные поступали из файла input.txt, а результат записывался в файл output.txt
////Сделал Величко В.А.
////Дата: 13.05.2020

#include <iostream>
#include <string>
#include <fstream>
#include <locale>

using namespace std;
int main () {
ifstream input("input.txt");
string s;
int line;
getline(input, s);
line = s.size ();
ofstream output("output.txt");
for (int i = 0; i < line; i++)
	if (s[i] != '.' && s[i] != ',' && s[i] != '!' && s[i] != ';' && s[i] != ':' && s[i] != '?' )
		output << s[i];		
return 0;
}
