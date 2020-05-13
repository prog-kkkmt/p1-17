/*Напишите функцию, которая принимает на вход целочисленную матрицу MM (другими словами, просто
двумерный целочисленный массив) размера rows*cols, и возвращает транспонированную матрицу M^T
(тоже двумерный целочисленный массив) размера cols*rows. Если в M на пересечении i-ой строки
и j-ого столбца стояло число x, то на пересечении  j-ой строки и i-ого столбца в матрице M^T
тоже будет стоять число x, или другими словами M^T[j][i] = M[i][j]
Выполнил: Саполетова Анастасия
Источник: Stepik Computer Science Center (CS центр)
Программирование на языке C++
2.7.9 https://stepik.org/lesson/543/step/9
13.05.2020
*/
int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    unsigned a = cols, b = rows;
    int ** m_New = new int *[a];
    m_New[0] = new int [a * b];
    for(unsigned i = 1; i != a; ++i)
        m_New[i] = m_New[i - 1] + b;

    for(unsigned i = 0; i < a; i++)
        for(unsigned j = 0; j < b; j++)
            m_New[i][j] = m[j][i];
    return m_New;
}
