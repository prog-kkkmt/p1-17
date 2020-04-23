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
