/*Реализуйте функцию swap_min, которая принимает на вход двумерный массив целых чисел, ищет в этом массиве строку, 
содержащую наименьшее среди всех элементов массива значение, и меняет эту строку местами с первой строкой массива.
Подумайте, как обменять строки массива, не обменивая элементы строк по-отдельности.
*/
//https://stepik.org/lesson/543/step/10?unit=866
//Фатеев Д.И.

void swap_min(int *m[], unsigned rows, unsigned cols)
{
    int min=0, mind=m[0][0];
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            if(mind>m[i][j]){
                mind=m[i][j];
                min=i;
            }
    int  *temp=m[0];
    m[0]=m[min];
    m[min] = temp;
}