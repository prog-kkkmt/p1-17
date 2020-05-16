#ifndef CLASSDESCRIPTION_H_INCLUDED
#define CLASSDESCRIPTION_H_INCLUDED
#include <cstring>
#include <iostream>
#include <fstream>
#include <locale>
#define maxlen 1000

using namespace std;
struct Time{///струтктура для подсчета времени
	int hours;/// часы
	int minuts;///минуты
};

struct Date{///структура для даты
	int day;
	int month;
	int year;
};

/**Код события,
Код вида события,
название события,
время начала,
продолжительность,
отметка о выполнении).
**/

void MenuEvent(){

}

struct event{
	char ImportanceSobutions[maxlen]; ///Код события
	char name[maxlen];///название события
    char ImportanceSobutionsVersions[maxlen];///Код вида события
    size_t size_ImportanceSobutions, size_name, size_ImportanceSobutionsVersions;
    Time StartTime;///время начала
    Time EndTime;///продолжительность
    bool been;///отметка о присутвствии
    event(){};
    event(int){
		cout<<"введит имя события: ";
		size_name = getline(name);
		cout<<"введите код вида события: ";
		size_ImportanceSobutionsVersions = getline(ImportanceSobutionsVersions);
		cout<<"введите код события: ";
		size_ImportanceSobutions = getline(ImportanceSobutions);
		cout<<"введите час начала: ";
		cin>>StartTime.hours;
		cout<<"введите минуту начала: ";
		cin>>StartTime.minuts;
		cout<<"введите продолжительность часо: ";
		cin>>EndTime.hours;
		cout<<"введите продолжительность минут: ";
		cin>>EndTime.minuts;
			char c;
		do{
			cout<<"было ли выполнено событие (y - да, n - нет): ";
			cin.get(c);
			cin.get(c);
		}while(!(c=='y' || c=='Y' || c=='n' || c=='N'));
		been = (c=='y' || c=='Y')?1:0;
    }

    ~event(){
		delete [] name;
		delete [] ImportanceSobutions;
		delete [] ImportanceSobutionsVersions;
    }
    int getline(char s[]){
		int c, i;
		for(i = 0; ((c=cin.get())!=EOF)&& c!= '\n'; i++)
		s[i]=c;
		s[i] = '\0';
		return i;
	}
};
void Append(event * &mas, size_t *n){///добавление элемент
	setlocale(0,"");
	*n += 1;
	cin.get();
	event* temp = new event[*n];
	for(int i=0; i<*n-1; i++)
		temp[i] = mas[i];
    event _temp(1);
    temp[*n-1] = _temp;


	delete []mas;
	//cout<<temp[*n-1].name;
	mas=new event[*n];
	for(int i=0; i<*n; i++)
		mas[i] = temp[i];
}

void destroy(event * &mas, size_t *n, int number){///удаление одного элемента
	setlocale(0,"");
	int k=0;
	*n-=1;
    event *temp = new event[*n];
    for(int i=0; i<*n+1; i++)
        if(i!=number){
            temp[k++]=mas[i];
        }
    delete [] mas;
    mas = new event[*n];
    for(int i=0; i<*n; i++)
		mas[i] = temp[i];

}

void settings(event &mas){///изменение
	int k = 0;
	do{
		cout<<"\nвведите номер желаемого изменения\n";
		cout<<"1 - изменить имя"<<endl<<"2 - время начала"<<endl<<"3 - продолжительность"<<endl<<"4 - код события"<<endl<<"5 - код вида события"<<endl<<"6 - Посещаемость"<<endl;
		cin>>k;
	}while(k<1 || k>7);
	switch(k){
		case 1:cout<<"Введите новое имя: "; cin>>mas.name; mas.size_name = strlen(mas.name); break;
		case 2:cout<<"Введите новый час и минуту: "; cin>>mas.StartTime.hours>>mas.StartTime.minuts; break;
		case 3:cout<<"Введите продолжительность час и минуту: "; cin>>mas.EndTime.minuts>>mas.EndTime.minuts; break;
		case 4:cout<<"Введите новй код события: "; cin>>mas.ImportanceSobutions; mas.size_ImportanceSobutions = strlen(mas.ImportanceSobutions); break;
		case 5:cout<<"Введите новый код вида события: "; cin>>mas.ImportanceSobutionsVersions; mas.size_ImportanceSobutionsVersions = strlen(mas.ImportanceSobutionsVersions); break;
		case 6:
			char c;
			do{
				cout<<"было ли выполнено событие: ";
				cin.get(c);
				cin.get(c);
			}while(!(c=='y' || c=='Y' || c=='n' || c=='N'));
			mas.been= (c=='y' || c=='Y')?1:0; break;
		}
		///size_ImportanceSobutions, size_name, size_ImportanceSobutionsVersions;
}

void print(event * &mas, size_t *n){///вывод
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
}

void sorted(event * &mas, size_t *n){///сортировка
    int k;
    cout<<"1 - Отсортировать по имени"<<endl<<"2 - отсортировать по коду"<<endl<<"3 - Сначала пропущенные: ";
    cin>>k;
    if(k==1){
        for(int i=0; i<*n; i++)
			for(int j=0; j<i; j++)
                if(mas[i].name> mas[j].name){
                    event temp = mas[i];
                    mas[i]=mas[j];
                    mas[j]=temp;
                }
	}
	if(k==2){
		for(int i=0; i<*n; i++)
			for(int j=0; j<i; j++)
                if(mas[i].ImportanceSobutions> mas[j].ImportanceSobutions){
					event temp = mas[i];
                    mas[i]=mas[j];
                    mas[j]=temp;
                }
	}
	if(k==3){
		for(int i=0; i<*n; i++)
			for(int j=0; j<i; j++)
                if(mas[i].been< mas[j].been){
					event temp = mas[i];
                    mas[i]=mas[j];
                    mas[j]=temp;
                }

    }
};

void aboutprograms(){///О программе
	cout<<"Эта программа написана студентом группы П1-17 Карандашев николай. Для Выполнения лабораторного задания №10.\nДата выполнения 14.05.2020";
}



///относительную долю загрузки рабочего дня по приоритетам;
void PrintSob(event * &mas, size_t n){///вывнсти события за сегодня
    setlocale(0,"");
    cout<<"На сегодня запланировано - "<<n<<" мероприятий, показаны коды событий этих мероприятий\n";
    for(int i=0; i<n; i++){
        cout<<i<<" - "<<mas[i].ImportanceSobutionsVersions<<endl;
    }
}

void PrintDidNt(event * &mas, size_t n){///вывести непосещенные
    setlocale(0,"");
    int k=0,c=0;
	for(int i=0; i<n; i++){
        if(!mas[n].been)
			k++;
	}
	event *temp = new event[k];
	for(int i=0; i<n; i++)
		if(!mas[n].been)
			temp[c++]=mas[i];
	for(int i=0; i<k; i++)
		for(int j = 0; j<i; j++)
			if((temp[i].StartTime.hours>temp[j].StartTime.hours) ||(temp[i].StartTime.hours==temp[j].StartTime.hours && (temp[i].StartTime.minuts>temp[j].StartTime.minuts)))
			{
				event _temp=temp[i];
				temp[i]=temp[j];
				temp[j]=_temp;
			}
	for(int i=0; i<k; i++)
		cout<<temp[i].name << " - " << temp[i].StartTime.hours<<":"<<temp[i].StartTime.minuts;
}

void PrintFaile(event * &mas, size_t *n){///вывести в файл
    fstream f("output.txt");
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
    f.close();
}

#endif // CLASSDESCRIPTION_H_INCLUDED
