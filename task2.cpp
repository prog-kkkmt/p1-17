/*Разработать программу с меню для работы с массивом целых чисел из 10 элементов.
Пункты меню: Заполнение, Нахождение максимального, Нахождение суммы, Печать, Выход.
Для каждого действия (кроме выхода) разработать функцию, принимающую в качестве параметров 
адрес первого элемента массива и количество элементов.*/

#include <iostream>
#define SIZE 10
using namespace std;


void fill_mas(int *a, int *q)
{
	int n;
	cout << "введите элементы массива" << endl;
	for (; a != q; a++)
	{
		cin >> n;
		*a = n;
	}
}

void print_mas(int *a, int *q)
{
	for (; a != q; a++)
		cout << *a << " ";
	cout << endl;
}

int max(int *a, int *q)
{
	int max = *a;
	for(; a != q; a++)
		if(*a > max)
			max = *a;
	return max;
}

int sum(int *a, int *q)
{
	int sum = 0;
	for(; a != q; a++)
		sum += *a;
	return sum;
}

int main(void)
{
	int a[SIZE];
	bool ok = true;
	int c;
	cout << "1 - заполнение \n2 - нахождение максимума \n3 - нахождение суммы \n4 - печать \n5 - выход \n";
	
	while(ok)
	{
		cout << "number : ";
		cin >> c;
		switch(c)
		{
			case 1:
			fill_mas(a, a + SIZE);
			break;
			case 2:
			cout << "максимум : " << max(a, a + SIZE) << endl;
			break;
			case 3:
			cout << "сумма : " << sum(a, a + SIZE) << endl;
			break;
			case 4:
			print_mas(a, a + SIZE);
			break;
			case 5: 
			ok = false;
			break;
			default: 
				cout << "неправильный номер" << endl;
		}
	}
	return 0;
}
