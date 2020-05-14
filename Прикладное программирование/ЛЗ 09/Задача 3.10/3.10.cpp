#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream in("input.txt");
    fstream out("output.txt");

    string s;
    while(getline(in, s));
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '.' || s[i] == ',' || s[i] == ';' || s[i] == ':')
        {
            s.erase(i, 1);
        }
    out << s;

}
