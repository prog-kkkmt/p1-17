// Разработать программы для реализации методов:  Ньютона ([1], 2.3.2.4)
// Пищулин Игорь 23.05.2020

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <double> diva(vector <double> coef, vector <double> coef2);

int main() {
	vector <double> coef;
	vector <double> coef2;
	int maxPow;
	double b;
	int i = 0;

	cout << "Enter max power = ";
	cin >> maxPow;

	cout << "Enter coef = ";

	for (int i = 0; i <= maxPow; i++) {
		cin >> b;
		coef.push_back(b);
	}

	cout << "Enter max power second = ";
	cin >> maxPow;

	cout << "Enter coef second = ";

	for (int i = 0; i <= maxPow; i++) {
		cin >> b;
		coef2.push_back(b);
	}

	vector <double> res;
	res = diva(coef, coef2);

	for (int i = 0; i < res.size(); i++)
		cout << res.at(i) << " ";

	return 0;
}

vector <double> diva(vector <double> coef, vector <double> coef2) {
	vector <double> res;
	vector <double> buff;
	int curI;

	int maxPow = coef2.size() - 1;
	int sizeRes = (coef.size() - 1) - (coef2.size() - 1) + 1;


	while (coef.size() > maxPow) {
		curI = sizeRes - ((coef.size() - 1) - (coef2.size() - 1) + 1);

		res.push_back(coef.at(0) / coef2.at(0));

		buff.resize(coef.size());
		for (int i = 0; i < coef2.size(); i++)
			buff.at(i) = (res.at(curI) * coef2.at(i));

		for (int i = 0; i < coef.size(); i++) {
			coef.at(i) = coef.at(i) - buff.at(i);
		}

	
		if (coef.at(0) == 0.0) {	
			coef.erase(coef.begin());
		}

		buff.clear();
	}

	int c = coef.size();

	for (int i = 0; i < c; i++)
		res.at(((res.size() - 1) - (c - 1)) + i) += coef.at(i);

	return res;
}