#include <iostream>
#include <cmath>
using namespace std;

int main()
{
int a, b, c, d; 
double r1, r2;
cin >> a >> b >> c;
d = (b*b) - 4 * a * c;
if(d > 0)
{
	r1 = (-b + sqrt(d))/(2 * a);
	r2 = (-b - sqrt(d))/(2 * a);
	cout << r1 << r2 << endl;
}
else if(d == 0)
{
	r1 = (-b + 0)/(2 * a);
	r2 = r1;
	cout << r1 << " " << r2 << endl;
}
else
	cout << "No real roots" << endl;
return 0;
}
