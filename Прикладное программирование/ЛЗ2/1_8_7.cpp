/*Sample Input:

5
59218
50960
42043
42817
9998
Sample Output:

15
15
15
15
13*/
#include <iostream>
using namespace std;

int main()
{
    int t, a;
    cin >> t;
    while (t > 0)
    {
        cin >> a;
        int k = 1, count = 0;
        while (k <= a)
        {
            k *= 2;
            count++;
        }
        cout << count - 1 << "\n";
        t--;
    }
    return 0;
}

