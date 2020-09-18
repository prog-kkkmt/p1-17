/*Описать процедуру DigitCountSum(K, C, S), находящую количество C цифр целого 
положительного числа K, а также их сумму S (K — входной, C и S — выходные параметры целого типа). 
С помощью этой процедуры найти количество и сумму цифр для каждого из пяти данных целых чисел.*/

#include <stdio.h>
 
void digitcountsum (int k, int *c, int *s){
    *c=0;
    *s=0;
    while(k != 0){
        *s += k % 10;
        ++*c;
        k /= 10;
    }
}
 
int main()
{
    for(int i = 1;i <= 5;++i){
        int k;
        scanf("%d", &k);
        int c,s;
        digitcountsum(k, &c, &s);
        printf("%d %d\n", c, s);
   }
    return 0;
}