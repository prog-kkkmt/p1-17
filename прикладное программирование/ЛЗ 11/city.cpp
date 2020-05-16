/*
Таблица:
Города (Код города, расстояние, Код тарифа)
*/
#include "city.hpp"

void functCity()
{
	vector <City> v;
	City city;
	int number;
	bool ok = true;

	input(v, city);

	cout << "1 - добавление \n2 - удаление \n3 - редактирование \n4 - вывод  \n5 - сортировка \n0 - выход \n";

	while(ok)
	{
		cout << "number : ";
		cin >> number;
		switch(number)
		{
			case 1:
			add(v, city);
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