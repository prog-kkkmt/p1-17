#include <iostream>
#include "classDescription.h"
#include "StructTwochapters.h"

///� ���� ������ �������� �������� � ���������� �������� (�����, �������� � �������) � �� ����������. �� ������ ��������� �������� ���� ������� � �� ��������
/**���������� ��������� �� ������������� ������� 10.
�������� ������ ���� ��� �����, ��������������, �������� � ������ ���� ������ �������.**/
/**
�������� ������� ������ �1-17 ���������� �.�.
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
		cout<<"1-������ � ���������\n"<<"2-������ � ������\n"<<"0 - �����\n";
		cin>>k;
		if(k==1){
			system("cls");
			cout<<"1 - �������� �������"<<endl<<"2 - ������� �������"<<endl<<"3 - �������"<<endl<<"4 - �������������"<<endl<<"5 - ��������������� �� ������� �����������"<<endl<<"6 - ������� �� ����������"<<endl<<"7 - � ���������"<<endl<<"8 - ��������"<<endl<<"9 - ����� � ����"<<endl<<"0 - �����"<<endl;
			cout<<endl;
			cin>>k;
			switch(k){
				case 1:system("cls"); Append(mas, &_size); break;
				case 2:system("cls"); int n; cout<<"����� ������� ������� � 1: "; cin>>n; destroy(mas, &_size, n); break;
				case 3:system("cls"); print(mas, &_size); break;
				case 4:system("cls"); sorted(mas, &_size); break;
				case 5:system("cls"); PrintSob(mas, _size); break;
				case 6:system("cls"); PrintDidNt(mas, _size); break;
				case 7:system("cls"); aboutprograms(); break;
				case 9:system("cls"); PrintFaile(mas, &_size); break;
				case 8:system("cls"); cout<<"����� ������� ������� �� ������� �������� ������� � 1: "; cin>>n; settings(mas[n-1]); break;
			}
			k=-1;
		}
		else if (k==2){
            cout<<"1 - �������� ���\n2 - ������� ��� \n3 - �������� ���\n4 - ������� ��� ����\n5 - ������� ��� � ����: ";
            cout<<endl;
			cin>>k;
            switch(k){
				case 1:system("cls"); Append(code, &m); break;
				case 2:system("cls"); int n; cout<<"����� ���� ������� � 1: "; cin>>n; destroy(code, &m, n); break;
				case 3:system("cls"); cout<<"����� ���� ������� �� ������� ��������: "; cin>>n; settings(code[n-1]); break;
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
