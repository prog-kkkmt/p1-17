//Таблица Разговоры (Код разговора, Код города, начало, продолжительность).
#include "talks.hpp"

void functTalks()
{

	vector <Talks> v;
	Talks talks;
	int number;
	bool ok = true;

	input(v, talks);

	while(ok)
	{
		cout << "number : ";
		cin >> number;
		switch(number)
		{
			case 1:
			add(v, talks);
			break;
			case 2:
			del(v);
			break;
			case 3:
			edit(v);
			break;
			case 4:
			output(v);
			break;
			case 5:
			sorting(v);
			break;
			case 0:
			ok = false;
			break;
			default:
			cout << "incorrect number!" << endl;
			break;
		};
	}
}