#include <iostream>

using namespace std;
int foo();
int main()
{    
 foo();
 return 0;
}

int foo(){
    int n = 0;
    cin >> n;
    if (n == 0) 
    {
        return 0;
    }
    else 
    {
        foo();
        cout << n << " ";
        return 0;
    }   
    
}
