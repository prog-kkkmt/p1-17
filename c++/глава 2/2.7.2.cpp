void swap_min(int *m[], unsigned rows, unsigned cols)

{
    int mini = 0, min = m[0][0];
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            if(min > m[i][j])
            {
                min = m[i][j];
                mini = i;
            }

    int  *t = m[0];
    m[0] = m[mini];
    m[mini] = t;
}
/*Реализуйте функцию swap_min, которая принимает на вход двумерный массив целых чисел, ищет в этом массиве строку, содержащую наименьшее среди всех элементов массива значение, и меняет эту строку местами с первой строкой массива. */
/*Величко П1-17*/
/*https://stepik.org/lesson/543/step/10?auth=registration&unit=866*/
