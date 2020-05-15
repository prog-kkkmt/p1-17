/*Междугородная телефонная станция.
Города (Код города, расстояние, Код тарифа)
Для выбранной таблицы разработать проект с меню, реализующий возможности 
добавления, удаления, редактирования, вывода списка экземпляров таблицы.
*/
#include "city.hpp"

int main()
{
	vector <City> v;
	City city;
	int number;
	bool ok = true;

	input(v, city);

	cout << "1 - добавление \n2 - удаление \n3 - редактирование \n4 - вывод \n5 - выход \n";

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
			ok = false;
			break;
			default:
			cout << "incorrect number!" << endl;
			break;
		};
	}
	
	return 0;
}