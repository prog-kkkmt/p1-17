#include <iostream>

using namespace std;

int main() {
    string str1;
    string str2 = "";

    while (getline(cin, str1)) {
        str2 = str2 + str1 + ' ';
        cout << str2 << endl;
    }

    return 0;
}
