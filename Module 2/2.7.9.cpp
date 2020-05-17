// Напишите функцию, которая принимает на вход целочисленную матрицу M
// (другими словами, просто двумерный целочисленный массив) 
// размера rows × cols, и возвращает транспонированную матрицу
//Выполнил: Богомолов Максим П1-17
//Источник: Stepik Computer Science Center (CS центр)
//Программирование на языке C++
//https://stepik.org/lesson/543/step/9
//25.04.2020
int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    int ** t = new int * [cols];
    
    for (int i = 0; i != cols; ++i)
        t[i] = new int[rows];
    
    for (int i = 0; i != rows; i++) {
        for (int j = 0; j != cols; j++) {
            t[j][i] = m[i][j];
        }
    }
    
    return t;
}
