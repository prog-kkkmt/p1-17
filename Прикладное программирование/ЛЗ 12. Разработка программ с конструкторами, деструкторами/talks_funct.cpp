#include "talks.hpp"
#define MAXLEN 100
Talks :: Talks()
{
	cout << "1 - добавление \n2 - удаление \n3 - редактирование \n4 - вывод  \n5 - сортировка \n0 - выход \n";
	codeT = 0;
	codeC = 0;
	lasting = 0;
	start_len = 0;
}
Talks :: ~Talks()
{
	start_len = 0;
}

void input(vector <Talks>&v, Talks talks)
{
	char s[MAXLEN];
	ifstream in("test3.txt");
	while(!in.eof())
	{
		in >> talks.codeT >> talks.codeC >> s;
		talks.start_len = strlen(s) + 1;
		talks.start = new char[talks.start_len];
		strcat(talks.start, s);
		in >> talks.lasting;
		v.push_back(talks);
	}

	in.close();
}

void output(vector <Talks> v)//копия т к нужен лишь вывод
{
	for(int i = 0; i < v.size(); i++)
		cout << v.at(i).codeT << "\t" << v.at(i).codeC << "\t" << v.at(i).start << "\t" << v.at(i).lasting << endl;
}

void update(vector <Talks>& v) 
{
	ofstream out("test3.txt");
	for(int i = 0; i < v.size(); i++)
	{
		out << v.at(i).codeT << "\t" << v.at(i).codeC << "\t" << v.at(i).start << "\t" <<  v.at(i).lasting << endl;
	}
	out.close();
}

void add(vector <Talks>& v, Talks talks)
{
	char s[MAXLEN];
	cout << "talks code/city's code/start/lasting\n";
	cin >> talks.codeT >> talks.codeC >> s;
	talks.start_len = strlen(s) + 1;
	talks.start = new char[talks.start_len];
	strcat(talks.start, s);
	cin >> talks.lasting;
	v.push_back(talks);
	update(v);
}

void del(vector <Talks>& v)
{
	int number;
	cout << "enter the talks's code to delete : ";
	cin >> number;
	for (int i = 0; i < v.size(); i++)
		if(v.at(i).codeT == number)
			v.erase(v.begin() + i);
	update(v);
}

void edit(vector <Talks>& v)
{
	char s[MAXLEN];
	int number;
	cout << "enter the talks's code to edit : ";
	cin >> number;

	for (int i = 0; i < v.size(); i++)
	{
		if(v.at(i).codeT == number)
		{
			cout << "enter new talks's code : ";
			cin >> v.at(i).codeT;
			
			cout << "enter new city's code : ";
			cin >> v.at(i).codeC;

			cout << "enter start : ";
			cin >> s;
			v.at(i).start_len = strlen(s) + 1;
			delete [] v.at(i).start;
			v.at(i).start = new char[v.at(i).start_len];
			strcat(v.at(i).start, s);
			
			cout << "enter duration : ";
			cin >> v.at(i).lasting;
		}	
	}
	update(v);
}
void sorting(vector <Talks>& v)
{	
	for (int i = 0; i < v.size() - 1; i++)
	{
		for (int j = 0; j < v.size() - i - 1; j++)
		{
			if(v.at(j).codeT > v.at(j + 1).codeT)
				swap(v.at(j),v.at(j + 1));
		}
	}
	update(v);
	cout << "Ascending sort:\n";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i).codeT << "\t" << v.at(i).codeC << "\t" << v.at(i).start << "\t" << v.at(i).lasting << endl;
	}
}