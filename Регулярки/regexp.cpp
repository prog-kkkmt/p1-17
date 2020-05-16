#include <iostream>
#include <string>
#include <regex>

using namespace std;
 
int main()
{
    string str;

    cout << ""
    cin >> str;

    regex re1(".*(a|xayy)"); // ECMA
    regex re2(".*(a|xayy)", std::regex::extended); // POSIX
 
    std::cout << "Searching for .*(a|xayy) in zzxayyzz:\n";
    std::smatch m;
    std::regex_search(str, m, re1);
    std::cout << " ECMA (depth first search) match: " << m[0] << '\n';

    return 0;

}