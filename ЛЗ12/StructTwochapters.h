#ifndef STRUCTTWOCHAPTERS_H_INCLUDED
#define STRUCTTWOCHAPTERS_H_INCLUDED
#define maxlen 1000
#include <cstring>
#include <iostream>
#include <fstream>
#include <locale>
#define maxlen 1000
using namespace std;

struct CodeSystem{///ñòðóêòóðà äëÿ êîäà ñîáûòèÿ
    char name[maxlen];
    size_t name_size, Code_size;
    char Code[maxlen];
    CodeSystem(){};
    CodeSystem(int k){
		cout<<"ââåäèòå íàçâàíèå âèäà ñîáûòèÿ: ";
		cin.get();
		name_size = getline(name);
		cout<<"ââåäèòå êîä òàêîãî íàçâàíèÿ: ";
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

void Append(CodeSystem * &mas, size_t *n){///äîáàâëåíèå êîäà
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

void destroy(CodeSystem * &mas, size_t *n, int number){///óäàëåíèå îäíîãî êîäà
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

void settings(CodeSystem &mas){///èçìåíåíèå
	int k = 0;
	do{
		cout<<"\nââåäèòå íîìåð æåëàåìîãî èçìåíåíèÿ\n";
		cout<<"1 - èçìåíèòü íàçâàíèå âèäà ñîáûòèÿ"<<endl<<"2 - èçìåíèòü êîä ýòîãî íàçâàíèÿ"<<endl;
		cin>>k;
	}while(!(k==1 || k==2));
	switch(k){
		case 1:cout<<"Ââåäèòå íîâîå íàçâàíèå: "; cin>>mas.name; mas.name_size = strlen(mas.name); break;
		case 2:cout<<"Ââåäèòå íîâûé êîä: "; cin>>mas.Code;  mas.Code_size = strlen(mas.Code); break;

		}
}

void PrintAll(event * &mas, size_t *n, CodeSystem * &_mas, size_t *m){///*âûâåñòè âñå êîäû
cout<<"==============================================================================================================\n";
    for(int i=0; i<*n; i++){
		cout<<"=================================================================\n";
        cout<<"Èìÿ ñîáûòèÿ: ";
		cout<<mas[i].name;
		cout<<endl<<"Êîä âèäà ñîáûòèÿ: ";
		cout<<mas[i].ImportanceSobutionsVersions;
		cout<<endl<<"Êîä ñîáûòèÿ: ";
		cout<<mas[i].ImportanceSobutions;
		cout<<endl<<"Íà÷àëî: ";
		cout<<mas[i].StartTime.hours<<':';
		cout<<mas[i].StartTime.minuts;
		cout<<endl<<"Ïðîäîëæèòåëüíîñòü ìåðîïðèÿòèÿ: ";
		cout<<mas[i].EndTime.hours<<':';
		cout<<mas[i].EndTime.minuts;
		if(mas[i].been)
			cout<<"\nÂû ïîñåòèëè äàííîå çàíÿòèå\n";
		else
			cout<<"\nÍå áûëî ïîñåùåíèÿ\n";
    }
    cout<<"==============================================================================================================\n";
    cout<<"Êîäû ñîáûòèé\n";
		for(int i=0; i<*m; i++)
			cout<<_mas[i].name<<" - "<<_mas[i].Code<<endl;
}

void PrintAllFaile(event * &mas, size_t *n, CodeSystem * &_mas, size_t *m){///âûâåñòè âñþ èíôîðìàöèþ â ôàéë
	fstream f("printAll.txt");
	if(!f.is_open()){
		cout<<"Файл не может быть открыт"<<endl;
        	return;
    	}
	f<<"==============================================================================================================\n";
    for(int i=0; i<*n; i++){
		f<<"=================================================================\n";
        f<<"Èìÿ ñîáûòèÿ: ";
		f<<mas[i].name;
		f<<endl<<"Êîä âèäà ñîáûòèÿ: ";
		f<<mas[i].ImportanceSobutionsVersions;
		f<<endl<<"Êîä ñîáûòèÿ: ";
		f<<mas[i].ImportanceSobutions;
		f<<endl<<"Íà÷àëî: ";
		f<<mas[i].StartTime.hours<<':';
		f<<mas[i].StartTime.minuts;
		f<<endl<<"Ïðîäîëæèòåëüíîñòü ìåðîïðèÿòèÿ: ";
		f<<mas[i].EndTime.hours<<':';
		f<<mas[i].EndTime.minuts;
		if(mas[i].been)
			f<<"\nÂû ïîñåòèëè äàííîå çàíÿòèå\n";
		else
			f<<"\nÍå áûëî ïîñåùåíèÿ\n";
    }
    f<<"==============================================================================================================\n";
    f<<"Êîäû ñîáûòèé\n";
		for(int i=0; i<*m; i++)
			f<<_mas[i].name<<" - "<<_mas[i].Code<<endl;
	f.close();
}
#endif // STRUCTTWOCHAPTERS_H_INCLUDED
