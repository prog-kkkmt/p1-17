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
	double a, x;
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

	cout << "Enter a and b [a; b]" << " = ";
	cin >> a >> b;

	x = (b + a) / 2;

	cout << endl;

	// cout << "[" << a << "; " << x << "; " << b << "] = " << "[" << res(coef, a) << "; " << res(coef, x) <<"; " << res(coef, b) << "]" << endl;

	while (abs(b - a) > e) {
		double aR = res(coef, a);
		double xR = res(coef, x);
		double bR = res(coef, b);

		// cout << "[" << x << "; " << b << "] = " << "[" << xR << "; " << bR << "]" << endl;

		if (aR > 0 && bR > 0 && xR > 0 || aR < 0 && bR < 0 && xR < 0) {
			double i = abs(b - a);
			if (aR < xR && xR < bR) {
				a -= i;
				b -= i;
			} else {
				a += i;
				b += i;
			}
		} else {
			if (xR * bR < 0)
				a = x;
			else
				b = x;
		}
		

		x = (b + a) / 2;
	}

	cout << endl << "The root is equal in [" << a << "; " << b << "] with accuracy " << e;

	return 0;
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