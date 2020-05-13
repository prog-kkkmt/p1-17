/**Реализуйте функцию swap_min, которая принимает на вход двумерный массив целых чисел, ищет в этом массиве строку, содержащую наименьшее среди всех элементов массива значение, и меняет эту строку местами с первой строкой массива.

Подумайте, как обменять строки массива, не обменивая элементы строк по-отдельности. 

Выполнила: Попкова Алена П1-17
Источник: Stepik.org "Программирование на языке C++" Computer Science Center (CS центр) 2.7.10  https://stepik.org/lesson/543/step/10
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

void swap_min(int *m[], unsigned rows, unsigned cols)
{
    unsigned  min_row = 0, min_col = 0;

    for ( unsigned  i = 0; i != rows ; i++ )
    {
        for ( unsigned j = 0; j != cols ; j++ )
        {
            if ( m[i][j] < m[min_row][min_col])
            {
                min_row = i;
                min_col = j;
            }
        }
    }

    if ( min_row != 0 )
    {
        int *temp = m[0];
        m[0] = m[min_row];
        m[min_row] = temp;
    }        
}


int main()
{
    unsigned rows, cols;
    cin >> rows >> cols;
    int **m = create_array2d(rows, cols);
    
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> m[i][j];
   
   swap_min(m, rows, cols);    
   for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
    return 0;
}

