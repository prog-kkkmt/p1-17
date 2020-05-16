#ifndef STRUCTTWOCHAPTERS_H_INCLUDED
#define STRUCTTWOCHAPTERS_H_INCLUDED
#define maxlen 1000
#include <cstring>
#include <iostream>
#include <fstream>
#include <locale>
#define maxlen 1000
using namespace std;

struct CodeSystem{///структура для кода события
    char name[maxlen];
    size_t name_size, Code_size;
    char Code[maxlen];
    CodeSystem(){};
    CodeSystem(int k){
		cout<<"введите название вида события: ";
		cin.get();
		name_size = getline(name);
		cout<<"введите код такого названия: ";
		Code_size = getline(Code);
    }
    ~CodeSystem(){
		delete []name;
		delete []Code;
    }
    int getline(char s[]){
		int c, i;
		for(i = 0; ((c=cin.get())!=EOF)&& c!= '\n'; i++)
		s[i]=c;
		s[i] = '\0';
		return i;
	}
};

void Append(CodeSystem * &mas, size_t *n){///добавление кода
	setlocale(0,"");
	*n += 1;
	CodeSystem* temp = new CodeSystem[*n];
	for(int i=0; i<*n-1; i++)
		temp[i] = mas[i];
		CodeSystem a(1);
		temp[*n-1] = a;
	delete []mas;
	mas=new CodeSystem[*n];
	for(int i=0; i<*n; i++)
		mas[i] = temp[i];
}

void destroy(CodeSystem * &mas, size_t *n, int number){///удаление одного кода
	setlocale(0,"");
	int k=0;
	*n-=1;
    CodeSystem *temp = new CodeSystem[*n];
    for(int i=0; i<*n+1; i++)
        if(i!=number){
            temp[k++]=mas[i];
        }
    delete [] mas;
    mas = new CodeSystem[*n];
    for(int i=0; i<*n; i++)
		mas[i] = temp[i];

}

void settings(CodeSystem &mas){///изменение
	int k = 0;
	do{
		cout<<"\nвведите номер желаемого изменения\n";
		cout<<"1 - изменить название вида события"<<endl<<"2 - изменить код этого названия"<<endl;
		cin>>k;
	}while(!(k==1 || k==2));
	switch(k){
		case 1:cout<<"Введите новое название: "; cin>>mas.name; mas.name_size = strlen(mas.name); break;
		case 2:cout<<"Введите новый код: "; cin>>mas.Code;  mas.Code_size = strlen(mas.Code); break;

		}
}

void PrintAll(event * &mas, size_t *n, CodeSystem * &_mas, size_t *m){///*вывести все коды
cout<<"==============================================================================================================\n";
    for(int i=0; i<*n; i++){
		cout<<"=================================================================\n";
        cout<<"Имя события: ";
		cout<<mas[i].name;
		cout<<endl<<"Код вида события: ";
		cout<<mas[i].ImportanceSobutionsVersions;
		cout<<endl<<"Код события: ";
		cout<<mas[i].ImportanceSobutions;
		cout<<endl<<"Начало: ";
		cout<<mas[i].StartTime.hours<<':';
		cout<<mas[i].StartTime.minuts;
		cout<<endl<<"Продолжительность мероприятия: ";
		cout<<mas[i].EndTime.hours<<':';
		cout<<mas[i].EndTime.minuts;
		if(mas[i].been)
			cout<<"\nВы посетили данное занятие\n";
		else
			cout<<"\nНе было посещения\n";
    }
    cout<<"==============================================================================================================\n";
    cout<<"Коды событий\n";
		for(int i=0; i<*m; i++)
			cout<<_mas[i].name<<" - "<<_mas[i].Code<<endl;
}

void PrintAllFaile(event * &mas, size_t *n, CodeSystem * &_mas, size_t *m){///вывести всю информацию в файл
	fstream f("printAll.txt");
	f<<"==============================================================================================================\n";
    for(int i=0; i<*n; i++){
		f<<"=================================================================\n";
        f<<"Имя события: ";
		f<<mas[i].name;
		f<<endl<<"Код вида события: ";
		f<<mas[i].ImportanceSobutionsVersions;
		f<<endl<<"Код события: ";
		f<<mas[i].ImportanceSobutions;
		f<<endl<<"Начало: ";
		f<<mas[i].StartTime.hours<<':';
		f<<mas[i].StartTime.minuts;
		f<<endl<<"Продолжительность мероприятия: ";
		f<<mas[i].EndTime.hours<<':';
		f<<mas[i].EndTime.minuts;
		if(mas[i].been)
			f<<"\nВы посетили данное занятие\n";
		else
			f<<"\nНе было посещения\n";
    }
    f<<"==============================================================================================================\n";
    f<<"Коды событий\n";
		for(int i=0; i<*m; i++)
			f<<_mas[i].name<<" - "<<_mas[i].Code<<endl;
	f.close();
}
#endif // STRUCTTWOCHAPTERS_H_INCLUDED
