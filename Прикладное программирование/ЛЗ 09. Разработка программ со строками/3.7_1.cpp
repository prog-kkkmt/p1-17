#include <iostream>

using namespace std;

string s2;

int main() {
    string s1;
    string s2;

    getline(cin, s1);
    getline(cin, s2);

    cout << ((s1 == s2) ? "true" : ((s1 > s2) ? s1 : s2));

    return 0;
}
