#include <stdio.h>
int main(void)
{
   int n,k;
   printf("N:");
   scanf ("%i", &n);
   printf("K:");
   scanf ("%i", &k);

   int num=0;
   while (n>=k){
      n -=k;
      ++num;
   }
   printf("int\\int:%i\n",num);

   printf("%%:%i\n",n);

   return 0;
}
