#include <iostream>
using namespace std;
char obr(char);
int main() {
    char x;

    cin >> x;
    cout << obr(x) << endl;
    obr(x);

    return 0;
}
char obr(char x) {
    if (x == 0) return x;
    else {
        char c;
        cin >> c;
        cout << obr(c) << " ";
    }
    return x;
}