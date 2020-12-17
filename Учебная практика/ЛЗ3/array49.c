/**
Array49. Дан целочисленный массив размера N. Если он является 
перестановкой, т. е. содержит все числа от 1 до N, то вывести 0;
в противном случае вывести номер первого недопустимого элемента.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    int *mass = (int*) malloc(sizeof(int) * n);

    for (int i = 0; i != n; ++i)
        scanf("%d", &mass[i]);

    int num = 0;
    for (int i = 0; i != n; ++i)
        if (mass[i] != i+1){
            num = i;
            break;
}

printf("%d\n", num);

free(mass);

return 0;
}