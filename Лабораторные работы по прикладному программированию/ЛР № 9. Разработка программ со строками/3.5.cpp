///Óïðàæíåíèå 3.5. Íàïèøèòå ïðîãðàììó, ÷èòàþùóþ ñî ñòàíäàðòíîãî óñòðîéñòâà ââîäà öåëûå ñòðîêè. Èçìåíèòå ïðîãðàììó òàê, ÷òîáû îíà ÷èòàëà îòäåëüíûå ñëîâà.
///Âûïîëíèë: Þøàêîâ Í. Ð.
///Äàòà: 13.05.2020
#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main() {
    setlocale(0, "");
    string line;
    string word;
    cout << "Ñåé÷àñ ñ÷èòûâàåòñÿ ñòðîêà: ";
    getline(cin, line);
    cout << line << endl;
    cout << "Ñåé÷àñ ñ÷èòûâàþòñÿ ñëîâà: ";
    while (cin >> word)
        cout << word << endl;
    return 0;
}
