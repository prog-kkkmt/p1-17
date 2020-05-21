#ifndef REALIZE_H_INCLUDED
#define REALIZE_H_INCLUDED
#include <iostream>
#include <complex>
#include <locale>;
using namespace std;
istream& operator >>(istream&, complex<double> &z){
	setlocale(0,"");
	double temp, _temp;
	cout<<"вещественная  часть: ";
	cin>>temp;
	cout<<"мнимая часть: ";
	cin>>_temp;
	complex<double> TempComplex(temp, _temp);
	z = TempComplex;
}
complex<double> operator + (complex<double> &n, complex<double> &z){
	///cout<<real(z);
	///cout<<conj(z)
	complex<double> TempComplex((real(z)+real(n)), (imag(z) + imag(n)));
    return TempComplex;
}

complex<double> operator / (complex<double> &n, complex<double> &z){

	double temp = real(n)/real(z);
	double _temp = imag(n)/imag(z);
	complex<double> TempComplex(temp, _temp);
	return TempComplex;
}
complex<double> operator * (complex<double> &n, complex<double> &z){

	double temp = real(n)*real(z) - imag(n)*imag(z);
	double _temp = imag(n)*imag(z) - real(z)*imag(n);
	complex<double> TempComplex(temp, _temp);
	return TempComplex;
}

complex<double> My_abs(complex<double> &n){
	if(real(n)<0){
		complex<double> temp(-real(n), imag(n));
		return temp;
	}
	return n;
}

bool operator > (complex<double> &n, complex<double> &z){

	if(imag(n)>imag(z))
		return true;
	if(imag(n)==imag(z) && real(n)>real(z))
		return true;
	return false;

}

bool operator < (complex<double> &n, complex<double> &z){
	if(!(n>z) && !(n==z))
		return true;
	return false;
}

bool operator == (complex<double> &n, complex<double> &z){
    if(real(n)==real(z) && imag(n)==imag(z))
		return true;
	return false;
}

/**ostream& operator << (ostream&, const complex<double> &z){

};**/

#endif // REALIZE_H_INCLUDED
