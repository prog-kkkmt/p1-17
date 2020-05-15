#include "city.hpp"

void input(vector <City>& v, City city)
{
	ifstream in("test1.txt");
	while(in >> city.codeC >> city.dist >> city.codeR)
	{
		v.push_back(city);
	}
	in.close();
}

void output(vector <City> v)//копия т к нужен лишь вывод
{
	for(int i = 0; i < v.size(); i++)
		cout << v.at(i).codeC << "\t" << v.at(i).dist << "\t" << v.at(i).codeR << endl;
}

void update(vector <City>& v) 
{
	ofstream out("test1.txt");
	for(int i = 0; i < v.size(); i++)
	{
		out << v.at(i).codeC << "\t" << v.at(i).dist << "\t" << v.at(i).codeR << endl;
	}
	out.close();
}

void add(vector <City>& v, City city)
{
	cout << "city code/distance/rate code\n";
	cin >> city.codeC >> city.dist >> city.codeR;
	v.push_back(city);
	update(v);
}

void del(vector <City>& v)
{
	int number;
	cout << "enter the city's code to delete : ";
	cin >> number;
	for (int i = 0; i < v.size(); i++)
		if(v.at(i).codeC == number)
			v.erase(v.begin() + i);
	update(v);
}

void edit(vector <City>& v)
{
	int number;
	cout << "enter the city's code to edit : ";
	cin >> number;

	for (int i = 0; i < v.size(); i++)
	{
		if(v.at(i).codeC == number)
		{
			cout << "enter new city's code : ";
			cin >> v.at(i).codeC;
			
			cout << "enter new distance : ";
			cin >> v.at(i).dist;
			
			cout << "enter new rate's code : ";
			cin >> v.at(i).codeR;
		}	
	}
	update(v);
}