#ifndef CLASSDESCRIPTION_H_INCLUDED
#define CLASSDESCRIPTION_H_INCLUDED
#include <cstring>
#include <iostream>
#include <fstream>
#include <locale>
#define maxlen 1000

using namespace std;
struct Time{///���������� ��� �������� �������
	int hours;/// ����
	int minuts;///������
};

struct Date{///��������� ��� ����
	int day;
	int month;
	int year;
};

/**��� �������,
��� ���� �������,
�������� �������,
����� ������,
�����������������,
������� � ����������).
**/

void MenuEvent(){

}

struct event{
	char ImportanceSobutions[maxlen]; ///��� �������
	char name[maxlen];///�������� �������
    char ImportanceSobutionsVersions[maxlen];///��� ���� �������
    size_t size_ImportanceSobutions, size_name, size_ImportanceSobutionsVersions;
    Time StartTime;///����� ������
    Time EndTime;///�����������������
    bool been;///������� � ������������
    event(){};
    event(int){
		cout<<"������ ��� �������: ";
		size_name = getline(name);
		cout<<"������� ��� ���� �������: ";
		size_ImportanceSobutionsVersions = getline(ImportanceSobutionsVersions);
		cout<<"������� ��� �������: ";
		size_ImportanceSobutions = getline(ImportanceSobutions);
		cout<<"������� ��� ������: ";
		cin>>StartTime.hours;
		cout<<"������� ������ ������: ";
		cin>>StartTime.minuts;
		cout<<"������� ����������������� ����: ";
		cin>>EndTime.hours;
		cout<<"������� ����������������� �����: ";
		cin>>EndTime.minuts;
			char c;
		do{
			cout<<"���� �� ��������� ������� (y - ��, n - ���): ";
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
void Append(event * &mas, size_t *n){///���������� �������
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

void destroy(event * &mas, size_t *n, int number){///�������� ������ ��������
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

void settings(event &mas){///���������
	int k = 0;
	do{
		cout<<"\n������� ����� ��������� ���������\n";
		cout<<"1 - �������� ���"<<endl<<"2 - ����� ������"<<endl<<"3 - �����������������"<<endl<<"4 - ��� �������"<<endl<<"5 - ��� ���� �������"<<endl<<"6 - ������������"<<endl;
		cin>>k;
	}while(k<1 || k>7);
	switch(k){
		case 1:cout<<"������� ����� ���: "; cin>>mas.name; mas.size_name = strlen(mas.name); break;
		case 2:cout<<"������� ����� ��� � ������: "; cin>>mas.StartTime.hours>>mas.StartTime.minuts; break;
		case 3:cout<<"������� ����������������� ��� � ������: "; cin>>mas.EndTime.minuts>>mas.EndTime.minuts; break;
		case 4:cout<<"������� ���� ��� �������: "; cin>>mas.ImportanceSobutions; mas.size_ImportanceSobutions = strlen(mas.ImportanceSobutions); break;
		case 5:cout<<"������� ����� ��� ���� �������: "; cin>>mas.ImportanceSobutionsVersions; mas.size_ImportanceSobutionsVersions = strlen(mas.ImportanceSobutionsVersions); break;
		case 6:
			char c;
			do{
				cout<<"���� �� ��������� �������: ";
				cin.get(c);
				cin.get(c);
			}while(!(c=='y' || c=='Y' || c=='n' || c=='N'));
			mas.been= (c=='y' || c=='Y')?1:0; break;
		}
		///size_ImportanceSobutions, size_name, size_ImportanceSobutionsVersions;
}

void print(event * &mas, size_t *n){///�����
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
}

void sorted(event * &mas, size_t *n){///����������
    int k;
    cout<<"1 - ������������� �� �����"<<endl<<"2 - ������������� �� ����"<<endl<<"3 - ������� �����������: ";
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

void aboutprograms(){///� ���������
	cout<<"��� ��������� �������� ��������� ������ �1-17 ���������� �������. ��� ���������� ������������� ������� �10.\n���� ���������� 14.05.2020";
}



///������������� ���� �������� �������� ��� �� �����������;
void PrintSob(event * &mas, size_t n){///������� ������� �� �������
    setlocale(0,"");
    cout<<"�� ������� ������������� - "<<n<<" �����������, �������� ���� ������� ���� �����������\n";
    for(int i=0; i<n; i++){
        cout<<i<<" - "<<mas[i].ImportanceSobutionsVersions<<endl;
    }
}

void PrintDidNt(event * &mas, size_t n){///������� ������������
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

void PrintFaile(event * &mas, size_t *n){///������� � ����
    fstream f("output.txt");
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
    f.close();
}

#endif // CLASSDESCRIPTION_H_INCLUDED
