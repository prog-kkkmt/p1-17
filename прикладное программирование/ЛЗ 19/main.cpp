/*Междугородная телефонная станция.
В базе хранится информация о продолжительности и стоимости междугородных звонков по России.
Таблицы:
Города (Код города, расстояние, Код тарифа)
Тариф (Код тарифа, минимальное расстояние, максимальное расстояние, цена); 
Разговоры (Код разговора, Код города, начало, продолжительность).
Доработать программу из лабораторного занятия 10.
Добавить пункты меню для ввода, редактирования, удаления и печати всех таблиц задания.
Выполнила : Озерова А.С. П1-17 16 мая 2020
*/
#include "talks.hpp"
#include "rate.hpp"
#include "city.hpp"

int main()
{
	int number;
	bool ok = true;
	cout << "1 - Rate \n2 - Talks \n3 - City \n4 - about program \n0 - exit\n";
	while(ok)
	{
		cout << "number of table : ";
		cin >> number;
		switch(number)
		{
			case 1:
			functRate();
			break;
			case 2:
			functTalks();
			break;
			case 3:
			functCity();
			break;
			case 4:
			aboutProgram();
			break;
			case 0:
			ok = false;
			break;
			default:
			cout << "incorrect number!" << endl;
			break;
		};
	}
	return 0;
}