#include <iostream>
#include <fstream>
#include <cstring>
#include <locale>

///(Гусятинер Л.Б.) Изменить программу упражнения 3.10. так, чтобы входные данные поступали из файла input.txt, а результат записывался в файл output.txt.
/**
Программа выполнена студентом грцппы П1-17
Карандашев Н.К.
Дата выполненгия 12.05.20
**/

using namespace std;

int main(){
	setlocale(0,"");
	fstream in("input.txt");
	fstream out("output.txt");
    string s1;
    while(getline(in, s1)){
		for(size_t i=0; i<s1.length(); i++)
			if(!(isalpha(s1[i]) || isdigit(s1[i]) || s1[i]==' ')){
				s1.erase(i,1);
				i--;
			}
		out<<s1;
	}
}
