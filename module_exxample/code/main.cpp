/*
Выполнила : Озерова А. П1-17
Дата : 24 июня 2020
*/

#include "StationClass.hpp"
#include "BusClass.hpp"
#include "TripClass.hpp"

int main()
{

    vector <int> v; 

    Station s("station.txt");
    Bus b("bus.txt");
    Trip t("trip.txt");

    bool ok = true;
    int choice = -1; //выбор

    while (choice != 0) 
    {
        cout << "\n1 - Station's trips\n2 - Number of passengers\n0 - exit\n";
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                cout << "Choose station" << endl;

                for (int i = 0; i < s.vs.size(); i++)
                    cout << s.vs.at(i).codeS << " - " << s.vs.at(i).name << endl;
                cout << "0 - exit\n";

                while(ok)
                {
                    int number;
                    v.clear();
                    cin >> number;

                    if (!number)
                        ok = false;
                    else
                    {
                        int kol = 0; //колво пассажиров
                        int idx = -1;
                        for (int i = 0; i < s.vs.size(); i++)
                        {
                            if (s.vs.at(i).codeS == number)
                                idx = i;
                        }
            
                        if (idx < 0) 
                            cout << "Incorrect code! Repeat, please " << endl;
                        else
                        {
                            for (int i = 0; i < t.vt.size(); i++) 
                            {
                                if (t.vt.at(i).codeS == number) 
                                v.push_back(t.vt.at(i).codeB);
                            }

                            cout << s.vs.at(idx).name << ":\nTrip = " << v.size()  << endl;
                        }
                    }
                }     
                break;
            }
            
            case 2:
            {
                int kol = 0;
                for (int i = 0; i < t.vt.size(); i++)
                {
                    for (int j = 0; j < b.vb.size(); j++)
                    {
                        if (t.vt.at(i).codeB == b.vb.at(j).codeB)
                            kol += b.vb.at(j).bulk;
                    }
                }
                cout << "Bulk = " << kol << endl;
                break;
            }

            case 0:
            {
                ok = false;
                break;
            }

            default:
            {
                cout << "Incorrect!\n";
                break;
            }
        } 
    }
    return 0;
}