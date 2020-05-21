/**Данная программа имеет перегрузку суммирования ввода деления и модуля
программа выполнена для ЛЗ16
Карандашев Н.К.
Дата выолнения 20.05.2020
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

        cout<<"1 - ввести 2 комплексных числа \n2 - сложить числа \n3 - умножить числа \n4 - деление без остатка \n5 - модуль первого комплексного числа \n6 - модуль второго комплексного числа\n7 - проверить равны ли они \n8- проверить больше ли первое \n9 - проверить больше ли второе0 - выход из программы\n";
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
			default: cout<<"Такого выбора нет"; break;
        }
    }while(k!=0);
    cout<<n1<<endl<<n2;
    return 0;
}
