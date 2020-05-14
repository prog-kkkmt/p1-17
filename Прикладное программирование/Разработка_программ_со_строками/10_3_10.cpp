#include <iostream>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    string str;
    ifstream fInput("input.txt");
    getline(fInput, str);

    for (int i = 0; i < str.size(); i++)
        if (str[i] == '.' || str[i] == ',' || str[i] == ';' || str[i] == ':' || str[i] == '!' || str[i] == '?') {
            str.erase(i, 1);
        }
    ofstream fOutput("output.txt");
    fOutput << str;

    return 0;
}

