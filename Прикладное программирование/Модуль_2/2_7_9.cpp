/**Напишите функцию, которая принимает на вход целочисленную матрицу M (другими словами, просто двумерный целочисленный массив) размера rows×cols, и возвращает транспонированную матрицу

Выполнила: Попкова Алена П1-17
Источник: Stepik.org "Программирование на языке C++" Computer Science Center (CS центр) 2.7.9 https://stepik.org/lesson/543/step/9
13.05.2020 **/

#include <iostream>
#include <cstdlib>

using namespace std;

int **create_array2d(size_t a, size_t b)
{
    int **m = new int *[a];
    m[0] = new int [a * b];
    for (size_t i = 1; i != a; i++)
            m[i] = m[i-1] + b;
    return m;
}


int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    int **Tm = create_array2d(cols, rows);
    for (int i = 0; i < rows; i++)
         for (int j = 0; j < cols; j++)
            Tm[i][j] = m[j][i];
    
    return Tm;
}


int main()
{
    unsigned rows, cols;
    cin >> rows >> cols;
    int **m = create_array2d(rows, cols);
    int **Tm;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> m[i][j];
    
    Tm = transpose(m, rows, cols);
   
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
            cout << Tm[i][j] << " ";
        cout << endl;
    }
    return 0;
}
