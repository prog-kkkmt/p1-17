#include <iostream>
#include "classDescription.h"
///� ���� ������ �������� �������� � ���������� �������� (�����, �������� � �������) � �� ����������.
/**�������: ���� ������� (��� ���� �������, �������� ����);
������� (��� �������, ��� ���� �������, �������� �������, ����� ������, �����������������, ������� � ����������).
����������:
� ������������� ���� �������� �������� ��� �� �����������;
� ��������� ������ ������������� ��� � ������� ����� ��������. **/

/**
�������� ������� ������ �1-17 ���������� �.�.
15,05,2020**/

using namespace std;
int main()
{
	size_t _size = 0;
    event *mas = new event[1];
    Append( mas, &_size);
    int k;
    do{
			cin.get();
			cin.get();
			system("cls");
		cout<<"1 - �������� �������"<<endl<<"2 - ������� �������"<<endl<<"3 - �������"<<endl<<"4 - �������������"<<endl<<"5 - ��������������� �� ������� �����������"<<endl<<"6 - ������� �� ����������"<<endl<<"7 - � ���������"<<endl<<"8 - ��������"<<endl<<"9 - ����� � ����"<<endl<<"0 - �����"<<endl;
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
    }while(k!=0);
    return 0;
}
