//Íàïèøèòå ïðîãðàììó, ÷èòàþùóþ ñî ñòàíäàðòíîãî óñòðîéñòâà ââîäà öåëûå ñòðîêè.
//Èçìåíèòå ïðîãðàììó òàê, ÷òîáû îíà ÷èòàëà îòäåëüíûå ñëîâà.
//Âûïîëíèëà: Ñóðêîâà Âàëåðèÿ Ï1-17
//Äàòà:14.05.2020


#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main()
{
    setlocale(0, " ");
    string stroka, slovo;
    cout << "Ñ÷èòûâàåò öåëûå ñòðîêè:";
        getline(cin, stroka);
            cout << stroka << endl;
    cout << "Ñ÷èòûâàåò îòäåëüíûå ñëîâà:";
        while (cin >> slovo)
            cout << slovo << endl;
    return 0;



}
