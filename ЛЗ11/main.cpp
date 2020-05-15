#include <iostream>
#include "classDescription.h"
#include "StructTwochapters.h"

///¬ базе данных хран€тс€ сведени€ о намеченных событи€х (делах, встречах и звонках) и их выполнении. во второй структуре хран€тс€ коды событий и их названи€
/**ƒоработать программу из лабораторного зан€ти€ 10.
ƒобавить пункты меню дл€ ввода, редактировани€, удалени€ и печати всех таблиц задани€.**/
/**
¬ыполнил студент группы ѕ1-17  арандашев Ќ. .
16,05,2020**/

using namespace std;
int main()
{
	setlocale(0,"");
	size_t _size = 0, m = 0;
    event *mas = new event[0];
    CodeSystem *code = new CodeSystem[0];
    //Append( mas, &_size);
	int k;
    do{
		cout<<"1-работа с событи€ми\n"<<"2-работа с кодами\n"<<"0 - выход\n";
		cin>>k;
		if(k==1){
			system("cls");
			cout<<"1 - добавить событие"<<endl<<"2 - удалить событие"<<endl<<"3 - вывести"<<endl<<"4 - отсортировать"<<endl<<"5 - запланированные на сегодн€ меропри€ти€"<<endl<<"6 - ¬ывести не посещенные"<<endl<<"7 - ќ программе"<<endl<<"8 - »зменить"<<endl<<"9 - вывод в файл"<<endl<<"0 - выход"<<endl;
			cout<<endl;
			cin>>k;
			switch(k){
				case 1:system("cls"); Append(mas, &_size); break;
				case 2:system("cls"); int n; cout<<"номер событи€ начина€ с 1: "; cin>>n; destroy(mas, &_size, n); break;
				case 3:system("cls"); print(mas, &_size); break;
				case 4:system("cls"); sorted(mas, &_size); break;
				case 5:system("cls"); PrintSob(mas, _size); break;
				case 6:system("cls"); PrintDidNt(mas, _size); break;
				case 7:system("cls"); aboutprograms(); break;
				case 9:system("cls"); PrintFaile(mas, &_size); break;
				case 8:system("cls"); cout<<"номер событи€ который вы жедаете изменить начина€ с 1: "; cin>>n; settings(mas[n-1]); break;
			}
			k=-1;
		}
		else if (k==2){
            cout<<"1 - добавить код\n2 - удалить код \n3 - изменить код\n4 - вывести все коды\n5 - вывести все в файл: ";
            cout<<endl;
			cin>>k;
            switch(k){
				case 1:system("cls"); Append(code, &m); break;
				case 2:system("cls"); int n; cout<<"номер кода начина€ с 1: "; cin>>n; destroy(code, &m, n); break;
				case 3:system("cls"); cout<<"номер кода который вы жедаете изменить: "; cin>>n; settings(code[n-1]); break;
				case 4:system("cls"); PrintAll(mas, &_size, code, &m); break;
				case 5:system("cls"); PrintAllFaile(mas, &_size, code, &m); break;
			}
			k=-1;
		}
        cin.get();
		cin.get();
    }while(k!=0);

    return 0;
}
