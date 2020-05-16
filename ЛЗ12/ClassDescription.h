#ifndef CLASSDESCRIPTION_H_INCLUDED
#define CLASSDESCRIPTION_H_INCLUDED
#include <cstring>
#include <iostream>
#include <fstream>
#include <locale>
#define maxlen 1000

using namespace std;
struct Time{///ñòðóòêòóðà äëÿ ïîäñ÷åòà âðåìåíè
	int hours;/// ÷àñû
	int minuts;///ìèíóòû
};

struct Date{///ñòðóêòóðà äëÿ äàòû
	int day;
	int month;
	int year;
};

/**Êîä ñîáûòèÿ,
Êîä âèäà ñîáûòèÿ,
íàçâàíèå ñîáûòèÿ,
âðåìÿ íà÷àëà,
ïðîäîëæèòåëüíîñòü,
îòìåòêà î âûïîëíåíèè).
**/

void MenuEvent(){

}

struct event{
	char ImportanceSobutions[maxlen]; ///Êîä ñîáûòèÿ
	char name[maxlen];///íàçâàíèå ñîáûòèÿ
    char ImportanceSobutionsVersions[maxlen];///Êîä âèäà ñîáûòèÿ
    size_t size_ImportanceSobutions, size_name, size_ImportanceSobutionsVersions;
    Time StartTime;///âðåìÿ íà÷àëà
    Time EndTime;///ïðîäîëæèòåëüíîñòü
    bool been;///îòìåòêà î ïðèñóòâñòâèè
    event(){};
    event(int){
		cout<<"ââåäèò èìÿ ñîáûòèÿ: ";
		size_name = getline(name);
		cout<<"ââåäèòå êîä âèäà ñîáûòèÿ: ";
		size_ImportanceSobutionsVersions = getline(ImportanceSobutionsVersions);
		cout<<"ââåäèòå êîä ñîáûòèÿ: ";
		size_ImportanceSobutions = getline(ImportanceSobutions);
		cout<<"ââåäèòå ÷àñ íà÷àëà: ";
		cin>>StartTime.hours;
		cout<<"ââåäèòå ìèíóòó íà÷àëà: ";
		cin>>StartTime.minuts;
		cout<<"ââåäèòå ïðîäîëæèòåëüíîñòü ÷àñî: ";
		cin>>EndTime.hours;
		cout<<"ââåäèòå ïðîäîëæèòåëüíîñòü ìèíóò: ";
		cin>>EndTime.minuts;
			char c;
		do{
			cout<<"áûëî ëè âûïîëíåíî ñîáûòèå (y - äà, n - íåò): ";
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
void Append(event * &mas, size_t *n){///äîáàâëåíèå ýëåìåíò
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

void destroy(event * &mas, size_t *n, int number){///óäàëåíèå îäíîãî ýëåìåíòà
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

void settings(event &mas){///èçìåíåíèå
	int k = 0;
	do{
		cout<<"\nââåäèòå íîìåð æåëàåìîãî èçìåíåíèÿ\n";
		cout<<"1 - èçìåíèòü èìÿ"<<endl<<"2 - âðåìÿ íà÷àëà"<<endl<<"3 - ïðîäîëæèòåëüíîñòü"<<endl<<"4 - êîä ñîáûòèÿ"<<endl<<"5 - êîä âèäà ñîáûòèÿ"<<endl<<"6 - Ïîñåùàåìîñòü"<<endl;
		cin>>k;
	}while(k<1 || k>7);
	switch(k){
		case 1:cout<<"Ââåäèòå íîâîå èìÿ: "; cin>>mas.name; mas.size_name = strlen(mas.name); break;
		case 2:cout<<"Ââåäèòå íîâûé ÷àñ è ìèíóòó: "; cin>>mas.StartTime.hours>>mas.StartTime.minuts; break;
		case 3:cout<<"Ââåäèòå ïðîäîëæèòåëüíîñòü ÷àñ è ìèíóòó: "; cin>>mas.EndTime.minuts>>mas.EndTime.minuts; break;
		case 4:cout<<"Ââåäèòå íîâé êîä ñîáûòèÿ: "; cin>>mas.ImportanceSobutions; mas.size_ImportanceSobutions = strlen(mas.ImportanceSobutions); break;
		case 5:cout<<"Ââåäèòå íîâûé êîä âèäà ñîáûòèÿ: "; cin>>mas.ImportanceSobutionsVersions; mas.size_ImportanceSobutionsVersions = strlen(mas.ImportanceSobutionsVersions); break;
		case 6:
			char c;
			do{
				cout<<"áûëî ëè âûïîëíåíî ñîáûòèå: ";
				cin.get(c);
				cin.get(c);
			}while(!(c=='y' || c=='Y' || c=='n' || c=='N'));
			mas.been= (c=='y' || c=='Y')?1:0; break;
		}
		///size_ImportanceSobutions, size_name, size_ImportanceSobutionsVersions;
}

void print(event * &mas, size_t *n){///âûâîä
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
}

void sorted(event * &mas, size_t *n){///ñîðòèðîâêà
    int k;
    cout<<"1 - Îòñîðòèðîâàòü ïî èìåíè"<<endl<<"2 - îòñîðòèðîâàòü ïî êîäó"<<endl<<"3 - Ñíà÷àëà ïðîïóùåííûå: ";
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

void aboutprograms(){///Î ïðîãðàììå
	cout<<"Ýòà ïðîãðàììà íàïèñàíà ñòóäåíòîì ãðóïïû Ï1-17 Êàðàíäàøåâ íèêîëàé. Äëÿ Âûïîëíåíèÿ ëàáîðàòîðíîãî çàäàíèÿ ¹10.\nÄàòà âûïîëíåíèÿ 14.05.2020";
}



///îòíîñèòåëüíóþ äîëþ çàãðóçêè ðàáî÷åãî äíÿ ïî ïðèîðèòåòàì;
void PrintSob(event * &mas, size_t n){///âûâíñòè ñîáûòèÿ çà ñåãîäíÿ
    setlocale(0,"");
    cout<<"Íà ñåãîäíÿ çàïëàíèðîâàíî - "<<n<<" ìåðîïðèÿòèé, ïîêàçàíû êîäû ñîáûòèé ýòèõ ìåðîïðèÿòèé\n";
    for(int i=0; i<n; i++){
        cout<<i<<" - "<<mas[i].ImportanceSobutionsVersions<<endl;
    }
}

void PrintDidNt(event * &mas, size_t n){///âûâåñòè íåïîñåùåííûå
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

void PrintFaile(event * &mas, size_t *n){///âûâåñòè â ôàéë
    fstream f("output.txt");
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
    f.close();
}

#endif // CLASSDESCRIPTION_H_INCLUDED
