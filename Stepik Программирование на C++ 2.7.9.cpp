#include <cstdlib>

int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    int ** mt = new int * [cols];
    mt[0] = new int [cols * rows];
    for (int i = 1; i != cols; i++)
        mt[i] = mt[i - 1] + rows;
    for (int i = 0; i != cols; i++)
        for (int j = 0; j != rows; j++)
            mt[i][j] = m[j][i];
    return mt;
}
