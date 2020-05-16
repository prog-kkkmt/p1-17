/*Òóðèñòñêèé êëóá îðãàíèçóåò îäíî – è ìíîãîäíåâíûå ïåøåõîäíûå òóðû â ãðóïïàõ ñ ðóêîâîäèòåëåì ïî ðàçíûì ìàðøðóòàì è ðàçíîé
êàòåãîðèè ñëîæíîñòè.
Òàáëèöû:
Ìàðøðóòû (Êîä ìàðøðóòà, íàçâàíèå, ïðîäîëæèòåëüíîñòü, êàòåãîðèÿ ñëîæíîñòè);
Ðóêîâîäèòåëè (Êîä ðóêîâîäèòåëÿ, ÔÈÎ,òåëåôîí);
Ãðóïïû (Êîä ãðóïïû, íàçâàíèå ãðóïïû, Êîä ìàðøðóòà, Êîä
ðóêîâîäèòåëÿ, êîëè÷åñòâî òóðèñòîâ, äàòà îòïðàâëåíèÿ).
Òðåáóåòñÿ:
– îïðåäåëèòü ïåðå÷åíü ãðóïï íà ìàðøðóòå;
– ïîñòðîèòü ñðàâíèòåëüíóþ äèàãðàììó êîëè÷åñòâà òóðèñòîâ ïî
óðîâíþ ñëîæíîñòè ìàðøðóòîâ.

*/


#include <iostream>
#include <windows.h>

using namespace std;

struct marshrut
{
    int kod_marsh;
    char prodol_marsh, kategor_slosh ;
    string nazvan_marsh;
};

struct rukovodit
{
    int kod_rukovod, tel_rukovod ;
    string fio;

};

struct gruppa
{
    int kod_grup, kod_marsh, kod_rukovod, kol_turist, data_otprav;
    string nazvan_grup;

};

int main()
{
      setlocale(LC_ALL, "Rus");
      marshrut m[50];
      rukovodit r[50];
      gruppa g[100];
      int n, a, b, i, n1, n2;

    cout << "Ñêîëüêî âñåãî ìàðøðóòîâ?" << endl;
    cin >> n;

    if (n != 0) cout << "Ââåäèòå: êîä ìàðøðóòà, íàçâàíèå, ïðîäîëæèòåëüíîñòü, êàòåãîðèÿ ñëîæíîñòè" << endl;

    for (i = 0; i < n; ++i)
    {
        cin >> m[i].kod_marsh >> m[i].prodol_marsh >> m[i].kategor_slosh >> m[i].nazvan_marsh;
    }

    cout << "Ñêîëüêî âñåãî ðóêîâîäèòåëåé?" << endl;
    cin >> n1;

    if (n1 != 0) cout << "Ââåäèòå: êîä ðóêîâîäèòåëÿ, òåëåôîí ðóêîâîäèòåëÿ, ÔÈÎ" << endl;

    for (i = 0; i < n1; ++i)
    {
        cin >> r[i].kod_rukovod >> r[i].tel_rukovod >> r[i].fio;
    }
    cout << "Ñêîëüêî âñåãî ãðóïï?" << endl;
    cin >> n2;

    if (n2 != 0) cout << "Ââåäèòå: êîä ãðóïïû, êîä ìàðøðóòà, êîä ðóêîâîäèòåëÿ, êîë-âî òóðèñòîâ, äàòà îòïðàâëåíèÿ, íàçâàíèå ãðóïïû" << endl;

    for (i = 0; i < n2; ++i)
    {
        cin >> g[i].kod_grup >> g[i].kod_marsh >> g[i].kod_rukovod >> g[i].kol_turist >> g[i].data_otprav >> g[i].nazvan_grup;
    }
     int menu; ///Ìåíþ
    cout << "1 - Îáùåå ÷èñëî ãðóïï" << endl;
    cout << "2 - ÷èñëî àâòîáóñîâ" << endl;
    cout << "3 - êîë-âî òóðèñòîâ " << endl;
    cout << "0 - Âûõîä" << endl;
    cin >> menu;

    while ((menu == 1) || (menu == 2) || (menu == 3)  || (menu == 4))
    {
        if (menu == 1)
        {
             for (i = 0; i < n; i++)
    {
        cout << m[i].kod_marsh << m[i].prodol_marsh << m[i].kategor_slosh << m[i].nazvan_marsh;
    }
        }

        if (menu == 2)
        {
             for (i = 0; i < a; i++)
    {
        cout << r[i].kod_rukovod << r[i].tel_rukovod << r[i].fio;
    }
        }
        if (menu == 3)
        {
             for (i = 0; i < b; i++)
    {
        cout << g[i].kod_grup << g[i].kod_marsh << g[i].kod_rukovod << g[i].kol_turist << g[i].data_otprav << g[i].nazvan_grup;
    }
        }

         cout << "1 - Îáùåå ÷èñëî ãðóïï" << endl;
         cout << "2 - ÷èñëî àâòîáóñîâ" << endl;
         cout << "3 - êîë-âî òóðèñòîâ " << endl;
         cout << "0 - Âûõîä" << endl;
         cin >> menu;
    }
   return 0;
}
