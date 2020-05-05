#include <iostream>
#include <fstream>
#include <string.h>
#include "ad.h"
#include "realize.h"

using namespace std;

/**база данных для подсчета успеваемости студентов одной группы по заданному предмету. программа подсчитывает для каждого студента посещаемость оценки и среднюю оценку. может производить сортировки по критериям а так же производит сохранение программы и автоматическую загрузку в случае обнаружения заданного файла**/
int main()
{
	setlocale(0,"");
	int k, sr;
	group s;
	do{
		system("cls");
        cout<<"Меню"<<endl;
        cout<<"добавить день - 1"<<endl;;
        cout<<"посмотреть всю инфомацию обо всей группе - 2"<<endl;
        cout<<"отсортировать - 3"<<endl;
        cout<<"вывод - 4"<<endl;
        cout<<"сохранение в файл - 5"<<endl;
        cout<<"закончить - 0"<<endl;
		cin>>k;
		switch (k){
   			case 1: s.NewDay(); break;
			case 2: s.PrintAllInformation(); break;
			case 3: cout<<"по фомилии - 0 "<<"по оценке - -1 "<<"по прогулам - 1"<<endl;
				cin>>sr;
				s.sorted(sr);
			break;
			case 4: cout<<s; break;
			case 5: ofstream new_file("groupe.txt"); new_file<<s; break;
		}

		system("pause");
	}while(k!=0);
}
