/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
 
void poweraA3(float a, float *b)
{
   *b=a*a*a;
}
 
int main(void)
{
    int i;
    for(i = 1;i <= 5;++i){
        float a;
        scanf("%f", &a);
        float b;
        poweraA3(a, &b);
        printf("%f\n", b);
   }
    return 0;
}