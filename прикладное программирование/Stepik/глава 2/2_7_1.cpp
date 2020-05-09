/*Транспонирование матрицы
Выполнила : Озерова А.С. П1-17 09.05.2020
Источника : Stepik, программирование на с++ Кринкин, 2.7.9, https://stepik.org/lesson/543/step/9?auth=registration&unit=866
*/

#include <cstdlib>

int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    int **m2 = new int * [cols];
    m2[0] = new int [cols * rows];
    
    for (size_t i = 1; i != cols; ++i)
        m2[i] = m2[i - 1] + rows;

    for (size_t i = 0; i != cols; i++)    
        for (size_t j = 0; j != rows; j++)
            m2[i][j] = m[j][i];
    
    return m2;
}
