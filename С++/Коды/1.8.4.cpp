#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int a, b, c;
    cin>>a>>b>>c;
    double d = b * b - 4 * a * c, x1, x2;
    if (d == 0)
    {
        x1=(-b+sqrt(d))/(2*a);
        x2=(-b-sqrt(d))/(2*a);
        cout<<x1<<endl;
        cout<<x2<<endl;
    }
     if(d>0)
    {
        x1=(-b+sqrt(d))/(2*a);
        x2=(-b-sqrt(d))/(2*a);
        cout<<x1<<endl;
        cout<<x2<<endl;
    }
    if(d<0)
    {
        cout<<"No real roots"<<endl;

}

    return 0;
}
