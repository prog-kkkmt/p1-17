#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void input(int n, vector <int> &coef)
{
    int num;
    cout << "Введите коэффициенты многолчлена"<< endl;
    for (int i = 0; i < n + 1; i++)
    {
        cin >> num;
        coef.push_back(num);

    }
}

void input(int n, vector <double> &coef)
{
    double num;
    cout << "Введите значение многочленов: "<< endl;
    for (int i = 0; i < n + 1; i++)
    {
        cin >> num;
        coef.push_back(num);
        cout << coef.at(i);
    }
}

void output(vector <int> &coef)
{
    unsigned i, n;
    for (i = 0, n = coef.size() - 1; i < coef.size() - 1; i++, n--)
    {
        if (i != 0)
            cout.setf(ios::showpos);
        cout << coef.at(i) << "*x" << "^";
        cout.unsetf(cout.flags());
        cout << n;
    }
    cout.setf(ios::showpos);
    cout << coef.at(i);
    cout.unsetf(cout.flags());
    cout << endl;

}

void output(vector <double> &coef)
{
    unsigned i;
    for (i = coef.size() - 1; i > 0; i--)
    {
        if (i != coef.size()-1)
            cout.setf(ios::showpos);

        cout << fixed << setprecision (2) << coef.at(i) << "*x" << "^";
        cout.unsetf(cout.flags());
        cout << i;

    }
    cout.setf(ios::showpos);
    cout << fixed << setprecision (2) << coef.at(i);
    cout.unsetf(cout.flags());

    cout << endl;

}

vector <int> sum(vector <int> &coef1, vector <int> &coef2)
{
    unsigned n = (coef1.size() > coef2.size())? coef1.size(): coef2.size();

    vector <int> res;
    for (unsigned i = 0; i < n; i++)
         res.push_back(((i < coef1.size()) ? coef1.at(i) : 0) + ((i < coef2.size()) ? coef2.at(i) : 0));

    return res;
}
vector <double> sum(vector <double> &coef1, vector <double> &coef2)
{
    unsigned n = (coef1.size() > coef2.size())? coef1.size(): coef2.size();
    vector <double> res;
    for (unsigned i = 0; i < n; i++)
        res.push_back(((i < coef1.size()) ? coef1.at(i) : 0) + ((i < coef2.size()) ? coef2.at(i) : 0));

    return res;
}


vector <int> prod(vector <int> &coef1, vector <int> &coef2)
{
    unsigned n = (coef1.size() > coef2.size())? coef1.size(): coef2.size();
    vector <int> res;
    for (unsigned i = 0; i < n; i++)
        res.push_back(((i < coef1.size()) ? coef1.at(i) : 1) * ((i < coef2.size()) ? coef2.at(i) : 1));
    return res;
}
vector <double> prod(vector <double> &coef1, vector <double> &coef2)
{
    unsigned n = (coef1.size() > coef2.size())? coef1.size(): coef2.size();
    vector <double> res;
    for (unsigned i = 0; i < n; i++)
        res.push_back(((i < coef1.size()) ? coef1.at(i) : 1) * ((i < coef2.size()) ? coef2.at(i) : 1));
    return res;
}


vector <int> my_abs(vector <int> &coef)
{
    vector <int> res;
    for (unsigned i = 0; i < coef.size(); i++)
        res.push_back((coef.at(i) <= 0)? coef.at(i)*(-1): coef.at(i));

    return res;
}
vector <double> my_abs(vector <double> &coef)
{
    vector <double> res;
    for (unsigned i = 0; i < coef.size(); i++)
        res.push_back((coef.at(i) <= 0)? coef.at(i)*(-1): coef.at(i));

    return res;
}

bool my_equal(vector <int> &coef1, vector <int> &coef2)
{
    unsigned i;
    if (coef1.size() != coef2.size())
        return false;
    else
        for (i = 0; i < coef1.size() && coef1.at(i) == coef2.at(i); i++)
            ;
    cout << "i = " << i << endl;
    return (i != coef1.size())? false: true;

}
bool my_equal(vector <double> &coef1, vector <double> &coef2)
{
    unsigned i;
    if (coef1.size() != coef2.size())
        return false;
    else
        for (i = 0; i < coef1.size() && coef1.at(i) == coef2.at(i); i++)
            ;

    return (i != coef1.size())? false: true;

}

bool gt(vector <int> &coef1, vector <int> &coef2)
{
    unsigned i;
    int sum1, sum2;

    if (coef1.size() > coef2.size())
        return true;
    else
        if (coef1.size() == coef2.size())
            {
                for (i = 0; i < coef1.size(); i++)
                        sum1 += coef1.at(i);
                for (i = 0; i < coef2.size(); i++)
                        sum2 += coef2.at(i);

                return (sum1 > sum2)? true: false;
            }
    return false;
}
bool gt(vector <double> &coef1, vector <double> &coef2)
{
    unsigned i;
    double sum1, sum2;

    if (coef1.size() > coef2.size())
        return true;
    else
        if (coef1.size() == coef2.size())
            {
                for (i = 0; i < coef1.size(); i++)
                        sum1 += coef1.at(i);
                for (i = 0; i < coef2.size(); i++)
                        sum2 += coef2.at(i);

                return (sum1 > sum2)? true: false;
            }
    return false;
}

vector <int> diva(vector <int> coef, vector <int> coef2) {
	vector <int> res;
	vector <int> buff;
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
#endif // FUNCTIONS_HPP
