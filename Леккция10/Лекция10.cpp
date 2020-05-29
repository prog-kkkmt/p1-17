#include<iostream>
#include <cstring>
/**������� ���� � ���� ��.��.�� � ��������� �����**/
using namespace std;
/**�� ��������, ���� �������� ������������ ��������� �������:

21.05.1972 - �������� ������ ��� ���� ������ �������� ��������� ������� ����. ���������� ��� �������.**/
void printdate(string str){
	setlocale(0,"");
	int i=0;
	int k=0;
	int date[3]={0,0,0};
	for(int i=0; str[i]!='\0'; i++)
	{
		if(isdigit(str[i]))
            date[k]=date[k]*10 + str[i]-'0';
        if(str[i]=='.')
            k++;
	}
	cout<<date[0]<<" "<<date[1]<<" "<<date[2];
	switch(date[0]){
		case 1: cout<<"������ "; break;
		case 2: cout<<"������ "; break;
		case 3: cout<<"������ "; break;
		case 4: cout<<"��������� "; break;
		case 5: cout<<"����� "; break;
		case 6: cout<<"������ "; break;
		case 7: cout<<"������� "; break;
		case 8: cout<<"������� "; break;
		case 9: cout<<"������� "; break;
		case 10: cout<<"������� "; break;
		case 11: cout<<"������������ "; break;
		case 12: cout<<"����������� "; break;
		case 13: cout<<"����������� "; break;
		case 14: cout<<"������������� "; break;
		case 15: cout<<"����������� "; break;
		case 16: cout<<"������������ "; break;
		case 17: cout<<"����������� "; break;
		case 18: cout<<"������������� "; break;
		case 19: cout<<"������������� "; break;
		case 20: cout<<"��������� "; break;
		case 21: cout<<"�������� ������ "; break;
		case 22: cout<<"�������� ������ "; break;
		case 23: cout<<"�������� ������ "; break;
		case 24: cout<<"�������� ��������� "; break;
		case 25: cout<<"�������� ����� "; break;
		case 26: cout<<"�������� ������ "; break;
		case 27: cout<<"�������� ������� "; break;
		case 28: cout<<"�������� ������� "; break;
		case 29: cout<<"�������� ������� "; break;
		case 30: cout<<"��������� "; break;
		case 31: cout<<"�������� ������ "; break;
	}
	switch (date[1]){
		case 1: cout<<"������ "; break;
		case 2: cout<<"������� "; break;
		case 3: cout<<"����� "; break;
		case 4: cout<<"������ "; break;
		case 5: cout<<"��� "; break;
		case 6: cout<<"���� "; break;
		case 7: cout<<"����"; break;
		case 8: cout<<"������� "; break;
		case 9: cout<<"�������� "; break;
		case 10: cout<<"������� "; break;
		case 11: cout<<"������ "; break;
		case 12: cout<<"������� "; break;
	}
	switch (date[2]/1000){
		case 1: cout<<"���� ������ "; break;
		case 2: cout<<"��� ������ "; break;
	}
	switch (date[2]/100%10){
		case 1: cout<<"��� "; break;
		case 2: cout<<"������ " ; break;
		case 3: cout<<"������ "; break;
		case 4: cout<<"��������� "; break;
		case 5: cout<<"������� "; break;
		case 6: cout<<"��������� "; break;
		case 7: cout<<"������� "; break;
		case 8: cout<<"��������� "; break;
		case 9: cout<<"��������� "; break;
	}
	int temp =  date[2]%100;
	if(temp>20 && temp%10!=0){
		switch(temp/10){
			case 2: cout<<"�������� "; break;
			case 3: cout<<"�������� "; break;
			case 4: cout<<"����� "; break;
			case 5: cout<<"��������� "; break;
			case 6: cout<<"��������� "; break;
			case 7: cout<<"����������� "; break;
			case 8: cout<<"���������� "; break;
			case 9: cout<<"��������� "; break;
		}
		switch(temp%10){
			case 1: cout<<"������� "; break;
			case 2: cout<<"������� "; break;
			case 3: cout<<"�������� "; break;
			case 4: cout<<"���������� "; break;
			case 5: cout<<"������ "; break;
			case 6: cout<<"������� "; break;
			case 7: cout<<"�������� "; break;
			case 8: cout<<"�������� "; break;
			case 9: cout<<"�������� "; break;
		}
	}
	else
	{
		switch(temp){
			case 1: cout<<"������ "; break;
			case 2: cout<<"������ "; break;
			case 3: cout<<"������ "; break;
			case 4: cout<<"��������� "; break;
			case 5: cout<<"����� "; break;
			case 6: cout<<"������ "; break;
			case 7: cout<<"������� "; break;
			case 8: cout<<"������� "; break;
			case 9: cout<<"������� "; break;
			case 10: cout<<"������� "; break;
			case 11: cout<<"������������ "; break;
			case 12: cout<<"����������� "; break;
			case 13: cout<<"����������� "; break;
			case 14: cout<<"������������� "; break;
			case 15: cout<<"����������� "; break;
			case 16: cout<<"������������ "; break;
			case 17: cout<<"����������� "; break;
			case 18: cout<<"������������� "; break;
			case 19: cout<<"������������� "; break;
			case 20: cout<<"��������� "; break;
			case 30: cout<<"��������� "; break;
			case 40: cout<<"��������� "; break;
			case 50: cout<<"������������ "; break;
			case 60: cout<<"������������� "; break;
			case 70: cout<<"������������ "; break;
			case 80: cout<<"�������������� "; break;
			case 90: cout<<"����������� "; break;
		}
	}
	cout<<"���� "
}

int main(){
cout<<"������� ������ � ���� ��.��.����";
string str;
cin>>str;
printdate(str);
return 0;
}

