#include <iostream>

using namespace std;

int main() {
    string str1;
    string str2;

    getline(cin, str1);
    getline(cin, str2);

    cout << ((str1 == str2) ? "Строки равны" : ((str1 > str2) ? str1 : str2));

    return 0;
}
