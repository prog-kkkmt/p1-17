#include <cstdlib>

void swap_min(int *m[], unsigned rows, unsigned cols)
{
    int min = m[0][0], minindex = 0;
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < cols; ++j)
            if (min > m[i][j]) {
                min = m[i][j];
                minindex = i;
            }
    int * temp = m[minindex];
    m[minindex] = m[0];
    m[0] = temp;
}
