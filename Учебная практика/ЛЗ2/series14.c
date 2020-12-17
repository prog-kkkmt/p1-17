/*Series14. Дано целое число K и набор ненулевых целых чисел;
признак его завершения — число 0. Вывести количество чисел в наборе, 
меньших K.*/
#include <stdio.h>
int main()
{
    int k, r = 1, num=0;
    scanf("%d", &k);
    while (r != 0){
        printf(">");
        scanf("%i", &r);
        if (r < k) ++ num;
    }
    printf("%d\n",num - 1);
 
    return 0;
}