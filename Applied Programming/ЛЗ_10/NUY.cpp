#include "nuy.hpp"
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector <book> knigi;

void OutPut(){
	fstream hy ("pilomal.txt");
	Book kniga;
	if (hy.is_open()) 
	{
		while (!hy.eof())
		{
			f >> kniga.code_b;
			getline (hy, title);
			getline (hy, year_of_publ);
			knigi.push_back (kniga);
		}
	}
	hy.close();
}

void Menu ()
{
	bool alt = True;
	int atl;
	while(alt)
	{
		cout << "Select operating mode" << endl;
		     << "1) Display the entire list" << endl;
		     << "2) Adding" << endl;
		     << "3) Editing" << endl;
		     << "4) Removal" << endl;
		     << "5) Exit" << endl;
		     
		cin >> atl;

		system("cls");

		switch (atl)
		{
			default:
				break; 
			case 1: OutPut();
				break;
			case 2: Adding();
				break;
			case 3: Edit();
				break;
			case 4: Delete();
				break;
			case 5: break;
		}
	}
	
}

void Delete()
{
	int code;
	cout << "Enter code of the book";
	cin >> code;
	
	for ( int i = 0; i < knigi.size(); i++ )
		if (knigi[i].code_b == code)
			knigi.erase(knigi.begin() + i);
        
	ofstream out("pilomal.txt");
	for(int i = 0; i < v.size(); i++)
	{
		out << knigi.at(i).code_b << "\t" << knigi.at(i).title << "\t" << knigi.at(i).year_of_publ << endl;
	}
	out.close();
}

void Edit()
{
	int code;
	cout << "Enter the code of the book";
	cin >> code;
	
	for (int i = 0; i < knigi.size(); i++)
	{
		if (knigi.at(i).code == code)
		{
			cout << "Enter code of the book";
			cin >> knigi.at(i).code_b;
			cout << "Enter title of the book";
			cin >> knigi.at(i).code_b;
			cout << "Enter the year of publication";
			cin >> knigi.at(i).code_b;
		}
		
		ofstream out("pilomal.txt");
	for(int i = 0; i < v.size(); i++)
	{
		out << knigi.at(i).code_b << "\t" << knigi.at(i).title << "\t" << knigi.at(i).year_of_publ << endl;
	}
	out.close();
	}
}

void InPut()
{
	for (int i = 0; i < knigi.size(); i++)
		cout << knigi.at(i).code_b << "\t" << knigi.at(i).title << "\t" << knigi.at(i).year_of_publ << endl;
}
