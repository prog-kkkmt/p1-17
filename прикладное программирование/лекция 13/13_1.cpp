#include <iostream>

using namespace std;

int ABS(int a)
{
	if (a >= 0)
		return a;
	else 
		return -a;
}
int ABS(float a)
{
	if (a >= 0)
		return a;
	else 
		return -a;
}

int main()
{
	int i;
	float a;
	cout << "chislo(int) = ";
	cin >> i;
	cout << "chislo(float) = ";
	cin >> a;
	cout << "absolute  value :\n" << ABS(i) << endl << ABS(a) << endl;
	return 0;
}
