///Задание: Транспонирование матрицы размером rows x cols
///Требования к реализации: при выполнении этого задания вы можете определять любые вспомогательные функции. 
///Вводить или выводить что-либо не нужно. Реализовывать функцию main не нужно.
///Источник: Stepic Программирование на языке C++ https://stepik.org/7 от Computer Science Center(CS центр) 
///Глава 2, раздел 7, шаг 9. https://stepik.org/lesson/543/step/9
///Выполнил: Юшаков Н. Р. 23.04.2020.
#include <cstdlib>

int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    int ** a = new int * [cols];
    a[0] = new int [cols * rows];
    for (size_t i = 1; i != cols; ++i)
        a[i] = a[i - 1] + rows;

    for (size_t i = 0; i != cols; ++i)
        for (size_t j = 0; j != rows; ++j)
            a[i][j] = m[j][i];

    return a;
}
