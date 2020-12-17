/*Case7.Единицы массы пронумерованы следующим образом: 1 — килограмм,
2 — миллиграмм, 3 — грамм, 4 — тонна, 5 — центнер. Дан номер единицы массы (целое число в диапазоне 1–5) и масса тела в этих единицах
(вещественное число). Найти массу тела в килограммах.*/

#include <stdio.h>
 
int main()
{
   int n;
   float m;
   scanf ("%d", &n);
   scanf ("%f", &m);
 
   switch (n) {
   case 1:
       printf("%f\n",m) ;
       break;
   case 2:
       printf("%f\n",m/1000000) ;
       break;
   case 3:
       printf("%f\n",m/1000) ;
       break;
   case 4:
       printf("%f\n",m*1000) ;
       break;
   case 5:
       printf("%f\n",m*100) ;
       break;
   }
   return 0;
}