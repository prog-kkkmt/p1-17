#include <iostream>
#include <fstream>
#include <string.h>
#include "ad.h"
#include "realize.h"

using namespace std;

/**���� ������ ��� �������� ������������ ��������� ����� ������ �� ��������� ��������. ��������� ������������ ��� ������� �������� ������������ ������ � ������� ������. ����� ����������� ���������� �� ��������� � ��� �� ���������� ���������� ��������� � �������������� �������� � ������ ����������� ��������� �����**/
int main()
{
	setlocale(0,"");
	int k, sr;
	group s;
	do{
		system("cls");
        cout<<"����"<<endl;
        cout<<"�������� ���� - 1"<<endl;;
        cout<<"���������� ��� ��������� ��� ���� ������ - 2"<<endl;
        cout<<"������������� - 3"<<endl;
        cout<<"����� - 4"<<endl;
        cout<<"���������� � ���� - 5"<<endl;
        cout<<"��������� - 0"<<endl;
		cin>>k;
		switch (k){
   			case 1: s.NewDay(); break;
			case 2: s.PrintAllInformation(); break;
			case 3: cout<<"�� ������� - 0 "<<"�� ������ - -1 "<<"�� �������� - 1"<<endl;
				cin>>sr;
				s.sorted(sr);
			break;
			case 4: cout<<s; break;
			case 5: ofstream new_file("groupe.txt"); new_file<<s; break;
		}

		system("pause");
	}while(k!=0);
}
