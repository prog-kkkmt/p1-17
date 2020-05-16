//Таблица Тариф (Код тарифа, минимальное расстояние, максимальное расстояние, цена); 
#include "rate.hpp"

void functRate()
{
	vector <Rate> v;
	Rate rate;
	int number;
	bool ok = true;

	input(v, rate);

	cout << "1 - добавление \n2 - удаление \n3 - редактирование \n4 - вывод  \n5 - сортировка \n0 - выход \n";

	while(ok)
	{
		cout << "number : ";
		cin >> number;
		switch(number)
		{
			case 1:
			add(v, rate);
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