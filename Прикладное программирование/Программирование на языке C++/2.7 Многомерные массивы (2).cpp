void swap_min(int *m[], unsigned rows, unsigned cols)
{
    int min = m[0][0], index = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (m[i][j] < min)
            {
                min = m[i][j];
                index = i;
            }
    int * a = new int[cols];
    a = m[0];
    m[0] = m[index];
    m[index] = a;
}
