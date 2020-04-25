int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    int ** t = new int * [cols];
    
    for (int i = 0; i != cols; ++i)
        t[i] = new int[rows];
    
    for (int i = 0; i != rows; i++) {
        for (int j = 0; j != cols; j++) {
            t[j][i] = m[i][j];
        }
    }
    
    return t;
}
