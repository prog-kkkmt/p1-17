// Реализуйте функцию swap_min, которая принимает на вход двумерный массив целых чисел, ищет в этом 
// массиве строку, содержащую наименьшее 
// среди всех элементов массива значение, и меняет эту строку местами с первой строкой массива.
//Выполнил: Богомолов Максим П1-17
//Источник: Stepik Computer Science Center (CS центр)
//Программирование на языке C++
//https://stepik.org/lesson/543/step/10
//25.04.2020
void swap_min(int *m[], unsigned rows, unsigned cols)
{
    int *buff;
    int min = 10000, rowMin;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (m[i][j] < min){
                min = m[i][j];
                rowMin = i;
            }
        }
    }
    
    if (rows > 0) 
        buff = m[rowMin];
        m[rowMin] = m[0];
        m[0] = buff;
}
