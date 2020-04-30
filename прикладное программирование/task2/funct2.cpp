#include <iostream>
void print_mas(int *a, int *q)
{
	for (; a != q; a++)
		std :: cout << *a << " ";
	std :: cout << std :: endl;
}
