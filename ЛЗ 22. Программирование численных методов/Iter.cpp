#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <double> der(vector <double> coef);
double res(vector <double> coef, double x);

int main() {
    
	vector <double> coef;

	int maxPow;
    double x0;
    double num, rez;
	double e = 0.001;

	cout << "Enter max power = ";
	cin >> maxPow;

	cout << "Enter coef = ";

	for (int i = 0; i <= maxPow; i++) {
		cin >> num;
		coef.push_back(num);
	}
    
    cout << "x0= ";
    cin >> x0;
    do {
        
        rez = x0;
        x0 = res(coef, x0);
    
    } while (fabs(rez - x0) > e );

    

	cout << endl << "The root is equal" << x0;
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