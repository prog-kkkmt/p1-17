#include "rate.hpp"

void input(vector <Rate>& v, Rate rate)
{
	ifstream in("test2.txt");
	while(in >> rate.codeR >> rate.mindist >> rate.maxdist >> rate.price)
	{
		v.push_back(rate);
	}
	in.close();
}

void output(vector <Rate> v)//копия т к нужен лишь вывод
{
	for(int i = 0; i < v.size(); i++)
		cout << v.at(i).codeR << "\t" << v.at(i).mindist << "\t" << v.at(i).maxdist << "\t" << v.at(i).price << endl;
}

void update(vector <Rate>& v) 
{
	ofstream out("test2.txt");
	for(int i = 0; i < v.size(); i++)
	{
		out << v.at(i).codeR << "\t" << v.at(i).mindist << "\t" << v.at(i).maxdist << "\t" <<  v.at(i).price << endl;
	}
	out.close();
}

void add(vector <Rate>& v, Rate rate)
{
	cout << "rate code/min distance/max distance/price\n";
	cin >> rate.codeR >> rate.mindist >> rate.maxdist >> rate.price;
	v.push_back(rate);
	update(v);
}

void del(vector <Rate>& v)
{
	int number;
	cout << "enter the rate's code to delete : ";
	cin >> number;
	for (int i = 0; i < v.size(); i++)
		if(v.at(i).codeR == number)
			v.erase(v.begin() + i);
	update(v);
}

void edit(vector <Rate>& v)
{
	int number;
	cout << "enter the rate's code to edit : ";
	cin >> number;

	for (int i = 0; i < v.size(); i++)
	{
		if(v.at(i).codeR == number)
		{
			cout << "enter new rate's code : ";
			cin >> v.at(i).codeR;
			
			cout << "enter new min distance : ";
			cin >> v.at(i).mindist;

			cout << "enter new max distance : ";
			cin >> v.at(i).maxdist;
			
			cout << "enter new price : ";
			cin >> v.at(i).price;
		}	
	}
	update(v);
}
void sorting(vector <Rate>& v)
{	
	for (int i = 0; i < v.size() - 1; i++)
	{
		for (int j = 0; j < v.size() - i - 1; j++)
		{
			if(v.at(j).codeR > v.at(j + 1).codeR)
			{
				swap(v.at(j).codeR, v.at(j + 1).codeR);
				swap(v.at(j).mindist, v.at(j + 1).mindist);
				swap(v.at(j).maxdist, v.at(j + 1).maxdist);
				swap(v.at(j).price, v.at(j + 1).price);
			}
		}
	}
	update(v);
	cout << "Ascending sort:\n";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i).codeR << "\t" << v.at(i).mindist << "\t" << v.at(i).maxdist << "\t" << v.at(i).price << endl;
	}
}