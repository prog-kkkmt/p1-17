/*Выполнил: Пищулин Игорь*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <double> der(vector <double> coef);
double res(vector <double> coef, double x);

int main() {
	vector <double> coef;
	vector <double> firstDer;
	vector <double> secDer;
	int maxPow;
	double b;
	double x;
	double e = 0.01;
	double nextX;
	int i = 0;

	cout << "Enter max power = ";
	cin >> maxPow;

	cout << "Enter coef = ";

	for (int i = 0; i <= maxPow; i++) {
		cin >> b;
		coef.push_back(b);
	}

	cout << "Enter x" << i++ << " = ";
	cin >> x;

	cout << endl;

	firstDer = der(coef);
	secDer = der(firstDer);
	nextX = x - (res(coef, x) / res(firstDer, x));
	cout << "Enter x" << i++ << " = " << nextX << endl;

	if (res(coef, x) > 0 && res(secDer, x) > 0 || res(coef, x) < 0 && res(secDer, x) < 0) {
		while (abs(res(coef, nextX) - res(coef, x)) > e) {
			x = nextX;
			nextX = x - (res(coef, x) / res(firstDer, x));

			cout << "Enter x" << i++ << " = " << nextX << endl;
		}
	}

	cout << endl << "The root is equal " << nextX << " with accuracy " << e;

	return 0;
}

vector <double> der(vector <double> coef) {
	int maxPow = coef.size() - 1;
	vector <double> newc;

	for (int i = 0; i < maxPow; i++)
		newc.push_back((maxPow - i) * coef.at(i));

	return newc;
}

double res(vector <double> coef, double x) {
	int maxPow = coef.size() - 1;
	double res = 0.0;

	for (int i = 0; i <= maxPow; i++)
	{
		res += coef.at(i) * pow(x, (maxPow - i));
	}

	return res;
}
