#include <iostream>

using namespace std;


int main() {
    string s1;
    string s2;

    getline(cin, s1);
    getline(cin, s2);

    cout << ((s1.length() == s2.length()) ? "true" : ((s1.length() > s2.length()) ? s1 : s2));

    return 0;
}
