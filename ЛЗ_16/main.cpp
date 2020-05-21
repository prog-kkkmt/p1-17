/**������ ��������� ����� ���������� ������������ ����� ������� � ������
��������� ��������� ��� ��16
���������� �.�.
���� ��������� 20.05.2020
**/

#include <iostream>
#include <complex>
#include "realize.h"
using namespace std;

istream& operator >>(istream&, complex<double> &z);
complex<double> operator + (complex<double> &n, complex<double> &z);
complex<double> operator * (complex<double> &n, complex<double> &z);
complex<double> operator / (complex<double> &n, complex<double> &z);
bool operator == (complex<double> &n, complex<double> &z);
bool operator > (complex<double> &n, complex<double> &z);
bool operator < (complex<double> &n, complex<double> &z);
complex<double> My_abs(complex<double> &n);
int main()
{
	setlocale(0,"");
	complex<double> n1;
    complex<double> n2;
    cin>>n1;
    cout<<n1<<endl;
    cin>>n2;
    cout<<n2<<endl;
    int k;
    do{

        cout<<"1 - ������ 2 ����������� ����� \n2 - ������� ����� \n3 - �������� ����� \n4 - ������� ��� ������� \n5 - ������ ������� ������������ ����� \n6 - ������ ������� ������������ �����\n7 - ��������� ����� �� ��� \n8- ��������� ������ �� ������ \n9 - ��������� ������ �� ������0 - ����� �� ���������\n";
        cin>>k;
        switch(k){
			case 1: cin>>n1>>n2; break;
			case 2: cout<<n1+n2<<endl; break;
			case 3: cout<<n1*n2<<endl; break;
			case 4: cout<<n1/n2<<endl; break;
			case 5: cout<<My_abs(n1)<<endl; break;
			case 6: cout<<My_abs(n2)<<endl; break;
			case 7: if(n1<n2)
				cout<<"right"<<endl;
			break;
			case 8: if(n1>n2)
				cout<<"right"<<endl;
			break;
			case 9: if(n1<n2)
				cout<<"right"<<endl;
			break;
			case 0: break;
			default: cout<<"������ ������ ���"; break;
        }
    }while(k!=0);
    cout<<n1<<endl<<n2;
    return 0;
}
