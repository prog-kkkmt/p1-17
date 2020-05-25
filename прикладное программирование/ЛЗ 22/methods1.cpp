#include <iostream>
#include <math.h>
using namespace std;

double f(double x)//уравнение
{
	return x * x - 2 * x - 4;
}

int Dichotomy ( double a, double b, double *c, double e) // дихотомия
{ 
	int k = 0;
	do
	{
		*c = (a + b) / 2;
		f(*c) * f(a) < 0 ? b = *c : a = *c;
		k++;
	}
	while (fabs(a - b) >= e);
	return k;
}

int Chord ( double a, double b, double *c, double e ) // хорды
{ 
	int k = 0;
	do
	{
		*c = a - f(a) / (f(b) - f(a)) * (b - a);
		f(*c) * f(a) > 0 ? a = *c : b = *c;
		k++;
	}
	while (fabs(f(*c)) >= e);
	return k;
}
double f1 ( double x ) //Первая производная функции f (x).
{
	return 2 * x - 2;
}

int Tangent ( double a, double b, double * c, double e ) //Ньютон(касательные)
{ 
	int k = 0;
	f(a) * 2 > 0 ? *c = a : *c = b; // 2 - вторая производная
	do
	{
		*c = *c - f(*c) / f1(*c);
		k++;
	}
	while (fabs(f(*c)) >= e);
	return k;
}
double fi ( double x, double L) 
{
	return ( x + L * f (x) );
}

int Iteration ( double *x, double L, double e ) //простые итерации
{ 
	int k = 0; 
	double x0;
	do
	{
		x0 = *x;
		*x = fi(x0, L);
		k++;
	}
	while ( fabs(x0 - *x) >= e);
	return k;
}
int main()
{
	double a, b, x, L, e;
	int k;
	cout << "Accuracy : ";
	cin >> e;

	cout<<"Interval : "; 
	cin >> a >> b; 

	cout << "x^2 - 2x - 4 = 0" << endl;

	cout << "Dichotomy :" << endl;
	k = Dichotomy (a, b, &x, e );
	cout << "x = " << x;
	cout << "\niterations = " << k << endl;

	cout << "Chord : " << endl;
	k = Chord (a, b, &x, e);
	cout << "x = " << x;
	cout << "\niterations = " << k << endl;

	cout << "Newton (tangents) :" << endl;
	k = Tangent (a, b,&x, e );
	cout << "x = " << x;
	cout << "\niterations = " << k << endl;

	cout << "Simple iteration :" << endl;
	x = a;
	cout << "L = ";
	cin >> L;
	k = Iteration (&x, L, e );
	cout << "x = " << x;
	cout << "\niterations = " << k << endl;
	return 0;
}