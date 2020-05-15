#ifndef STRUCTTWOCHAPTERS_H_INCLUDED
#define STRUCTTWOCHAPTERS_H_INCLUDED
#include <cstring>
#include <iostream>
#include <fstream>
#include <locale>

using namespace std;

struct CodeSystem{///��������� ��� ���� �������
    string name;
    string Code;
};

void Append(CodeSystem * &mas, size_t *n){///���������� ����
	setlocale(0,"");
	*n += 1;
	CodeSystem* temp = new CodeSystem[*n];
	for(int i=0; i<*n-1; i++)
		temp[i] = mas[i];
		cout<<"������� �������� ���� �������: ";
		cin>>temp[*n-1].name;
		cout<<"������� ��� ������ ��������: ";
		cin>>temp[*n-1].Code;
	delete []mas;
	mas=new CodeSystem[*n];
	for(int i=0; i<*n; i++)
		mas[i] = temp[i];
}

void destroy(CodeSystem * &mas, size_t *n, int number){///�������� ������ ����
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

void settings(CodeSystem &mas){///���������
	int k = 0;
	do{
		cout<<"\n������� ����� ��������� ���������\n";
		cout<<"1 - �������� �������� ���� �������"<<endl<<"2 - �������� ��� ����� ��������"<<endl;
		cin>>k;
	}while(!(k==1 || k==2));
	switch(k){
		case 1:cout<<"������� ����� ��������: "; cin>>mas.name; break;
		case 2:cout<<"������� ����� ��� � ������: "; cin>>mas.Code; break;

		}
}

void PrintAll(event * &mas, size_t *n, CodeSystem * &_mas, size_t *m){///*������� ��� ����
cout<<"==============================================================================================================\n";
    for(int i=0; i<*n; i++){
		cout<<"=================================================================\n";
        cout<<"��� �������: ";
		cout<<mas[i].name;
		cout<<endl<<"��� ���� �������: ";
		cout<<mas[i].ImportanceSobutionsVersions;
		cout<<endl<<"��� �������: ";
		cout<<mas[i].ImportanceSobutions;
		cout<<endl<<"������: ";
		cout<<mas[i].StartTime.hours<<':';
		cout<<mas[i].StartTime.minuts;
		cout<<endl<<"����������������� �����������: ";
		cout<<mas[i].EndTime.hours<<':';
		cout<<mas[i].EndTime.minuts;
		if(mas[i].been)
			cout<<"\n�� �������� ������ �������\n";
		else
			cout<<"\n�� ���� ���������\n";
    }
    cout<<"==============================================================================================================\n";
    cout<<"���� �������\n";
		for(int i=0; i<*m; i++)
			cout<<_mas[i].name<<" - "<<_mas[i].Code<<endl;
}

void PrintAllFaile(event * &mas, size_t *n, CodeSystem * &_mas, size_t *m){///������� ��� ���������� � ����
	fstream f("printAll.txt");
	f<<"==============================================================================================================\n";
    for(int i=0; i<*n; i++){
		f<<"=================================================================\n";
        f<<"��� �������: ";
		f<<mas[i].name;
		f<<endl<<"��� ���� �������: ";
		f<<mas[i].ImportanceSobutionsVersions;
		f<<endl<<"��� �������: ";
		f<<mas[i].ImportanceSobutions;
		f<<endl<<"������: ";
		f<<mas[i].StartTime.hours<<':';
		f<<mas[i].StartTime.minuts;
		f<<endl<<"����������������� �����������: ";
		f<<mas[i].EndTime.hours<<':';
		f<<mas[i].EndTime.minuts;
		if(mas[i].been)
			f<<"\n�� �������� ������ �������\n";
		else
			f<<"\n�� ���� ���������\n";
    }
    f<<"==============================================================================================================\n";
    f<<"���� �������\n";
		for(int i=0; i<*m; i++)
			f<<_mas[i].name<<" - "<<_mas[i].Code<<endl;
}
#endif // STRUCTTWOCHAPTERS_H_INCLUDED
