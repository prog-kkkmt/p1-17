#include <stdio.h>

int ABS(int);                        //прототипы функций ABS
float ABS(float);

int main()
{
	int i; float a;
	printf("Введите целое число: ");
	scanf(" %d",&i);
	printf("Введите вещественное число: ");
	scanf(" %f",&a);
	printf("abs(%d)=%d; abs(%f)=%f \n",i,ABS(i),a,ABS(a));
	return 0;
}

int ABS(int a)                      //определение функции int ABS()
{
	if (a>=0)
		return a;
	else
		return  a;
}

float ABS(float a)               //определение функции float ABS()
{
	if (a>=0)
		return a;
	else
		return  a;
}