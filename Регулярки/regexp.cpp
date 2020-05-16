#include <iostream>
#include <string>
#include <regex>

using namespace std;
 
int main()
{
    string str;
    string reg;

    cout << "\nEnter string: ";
    cin >> str;
    cout << "\nEnter regexp: ";
    cin >> reg;

    regex re(reg);
 
    cout << "\nSearching for " << reg << " in " << str << ":";
	smatch m;
    regex_search(str, m, re);
    cout << "\n1) " << m[0] << '\n';

    return 0;

}