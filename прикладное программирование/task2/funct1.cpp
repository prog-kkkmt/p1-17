#include <iostream>
void fill_mas(int *a, int *q)
{
	int n;
	std :: cout << "введите элементы массива" << std :: endl;
	for (; a != q; a++)
	{
		std :: cin >> n;
		*a = n;
	}
}
