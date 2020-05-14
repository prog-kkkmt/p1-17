#include <iostream>

using namespace std;

int main() {
    string s1;
    string s2 = "";

    while (getline(cin, s1)) {
        s2 = s2 + s1 + ' ';
        cout << s2 << endl;
    }

    return 0;
}
