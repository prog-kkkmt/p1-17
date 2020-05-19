#include <iostream>

using namespace std;

int main() {
    string str1;
    string str2;

    getline(cin, str1);
    getline(cin, str2);

    cout << ((str1.size() == str2.size()) ? "Строки равны" : ((str1.size() > str2.size()) ? str1 : str2));

    return 0;
}

