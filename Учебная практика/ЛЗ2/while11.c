/*While11. Дано целое число N (> 1). Вывести наименьшее из целых 
чисел K, для которых сумма 1 + 2 + … + K будет больше или равна 
N, и саму эту сумму.*/

#include <stdio.h>
int main()
{
   int n;
   scanf ("%d", &n);
   int k=0, temp=0;
   while (temp < n) {
       ++k;
        temp += 3;
   }
   printf("%d\n %d\n",k,temp);
   return 0;
}