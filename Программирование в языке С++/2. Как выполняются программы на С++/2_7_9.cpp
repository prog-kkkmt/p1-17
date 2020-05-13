/*
Напишите функцию, которая принимает на вход целочисленную матрицу M (другими словами, просто двумерный целочисленный массив)
размера rows×cols, и возвращает транспонированную матрицу M^T(тоже двумерный целочисленный массив) размера cols×rows.
Если в M на пересечении i-ой строки и j-ого столбца стояло число x, то на пересечении  j-ой строки и i-ого столбца в матрице M^T тоже будет стоять число xx,
или другими словами M^T[j][i] = M[j][i]=M[i][j].
Обратите внимание, что вам неизвестно, каким именно способом выделялась память для массива M.
Выделять память под массив M^T можете любым удобным вам способом. Изменять исходную матрицу нельзя.

Курс Программирование на языке C++ (Степик. Александ Смаль, Михаил Кринкин)
Выполнила: Суркова Валерия П1-17.
Дата: 13 мая 2020 г.
*/


int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    int **mas = new int * [cols];
    mas[0] = new int [cols * rows];
    for(int i = 1; i != cols; i++)
        mas[i] = mas[i - 1] + rows;
    for(int i = 0; i != cols; i++)
        for(int j = 0; j != rows; j++)
            mas[i][j] = m[j][i];
    return mas;
}
