/*Описать процедуру PowerA234(A, B, C, D), вычисляющую вторую,
третью и четвертую степень числа A и возвращающую эти степени со-
ответственно в переменных B, C и D (A — входной, B, C, D — выходные параметры;
все параметры являются вещественными). С помощью этой
процедуры найти вторую, третью и четвертую степень пяти данных чисел.*/

#include <stdio.h>
 
void PowerA234(float a, float *b, float *c, float *d)
{
   *b = a*a;
   *c = a*a*a;
   *d = a*a*a*a;
}
 
int main()
{
    int i;
    for(i = 1;i <= 5;++i){
        float a;
        scanf("%f", &a);
        float b, c, d;
        PowerA234(a, &b, &c, &d);
        printf("%.2f %.2f %.2f\n", b, c, d);
   }
    return 0;
}